#ifndef ROUTES_PAGES_HPP
#define ROUTES_PAGES_HPP

#include <mysql/mysql.h>
#include <string>

namespace Pages
{
    ////////////////////
    ///// home.cpp /////
    ////////////////////

    std::string page_home
    (
        MYSQL* &database
    );

    ////////////////////
    ///// play.cpp /////
    ////////////////////

    std::string page_play();
}

#endif
