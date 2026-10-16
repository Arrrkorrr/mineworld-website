#include "pages.hpp"

#include "../routes.hpp"
#include "../../utils/database/database.hpp"
#include "../../utils/files/files.hpp"

#include <map>
#include <mysql/mysql.h>
#include <string>
#include <vector>

/*
    Demonstration home page.

    Tasks:
        1) Query some information from the database.
            a. Get all news from the database.
            b. Prepare backend data to show to the user.
            c. If we retrieved some news from the query, we start preparing the generation of the news feed.
            d. Register each piece of news using the defined HTML format.
            e. Add a separating line in case it's not the last piece of news.
            f. Define the backend data.
        2) Prepare the page to display.
            a. Read the content of the home.html file.
            b. Render the page by removing custom tags with the actual backend data.

    Parameters (variable_name / type / description):
        - database  / MYSQL* / MineWorld database.

    Returns (type + description):
        A string containing the HTML page to send back to the client.
*/
std::string Pages::page_home
(
    MYSQL* &database
)
{
    ////////////////// 1) //////////////////
    ///////// a. /////////
    Database::Output news = Database::db_query(database, "SELECT title, content FROM news ORDER BY news_id DESC");

    ///////// b. /////////
    std::string news_feed = "<p>No news available.</p>";

    if (news.size() != 0)
    {
        news_feed.clear();
        int i = 1;

        ///////// c. /////////
        for (std::map<std::string, std::string> &news_piece : news)
        {
            const std::string title = news_piece["title"];
            const std::string content = news_piece["content"];

            ///////// d. /////////
            news_feed +=
            (
                std::string("\n<div class=\"news\">\n") +
                            "    <h4 class=\"news-title\">" + title + "</h4>\n" +
                            "    <p>" + content + "</p>\n" +
                            "</div>"
            );

            ///////// e. /////////
            if (i < news.size())
                news_feed += " <hr style=\"margin-top: 25px;\">";

            i++;
        }
    }

    ///////// f. /////////
    const std::vector<BackendData> backend
    {
        { "news_feed", news_feed }
    };

    ////////////////// 2) //////////////////
    ///////// a. /////////
    std::vector<std::string> html_page = Files::read_file("./website/home.html");

    ///////// b. /////////
    const std::string rendering = Routes::replace_custom_tags(backend, html_page);

    return rendering;
}
