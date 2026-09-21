#include "pages.hpp"

#include "../routes.hpp"
#include "../../utils/files/files.hpp"

#include <string>
#include <vector>

/*
    Demonstration home page.

    Tasks:
        1) Declare all tags that we wish to replace with some data.
        2) Read the page.html file content.
        3) Replace the tags in the html page with the desired data and return it.

    Parameters (variable_name / type / description):
        No parameters.

    Returns (type + description):
        A string containing the HTML page to send back to the client.
*/
std::string Pages::page_home()
{
    ////////////////// 1) //////////////////
    std::vector<std::string> html_page = Files::read_file("./website/home.html");
    std::string output;

    for (const std::string &line : html_page)
        output += line;

    return output;
}
