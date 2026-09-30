#include "pages.hpp"

#include "../routes.hpp"
#include "../../utils/files/files.hpp"

#include <string>
#include <vector>

/*
    Handle requests made to the "/page" route.

    Tasks:
        1) Read the play.html file content.
        2) Convert the vector list into a string.

    Parameters (variable_name / type / description):
        No parameters.

    Returns (type + description):
        A string containing the HTML page to send back to the client.
*/
std::string Pages::page_play()
{
    ////////////////// 1) //////////////////
    std::vector<std::string> html_page = Files::read_file("./website/play.html");
    std::string output;

    for (const std::string &line : html_page)
        output += line;

    return output;
}
