#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <string>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

namespace Socket
{
    ////////////////////////
    ///// requests.cpp /////
    ////////////////////////

    void handle_request
    (
        const int &client,
        const int &max_request_length
    );

    //////////////////////////////
    ///// socket.handler.cpp /////
    //////////////////////////////

    bool create_socket_server
    (
        const std::string &address,
        const int &max_retries,
        const int &port,
        int       &server_socket
    );
}

#endif
