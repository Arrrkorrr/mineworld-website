cmake_minimum_required(VERSION 3.10)
project(mw_website)
set(CMAKE_CXX_STANDARD 17)

include_directories (
    ${CMAKE_SOURCE_DIR}/routes
    ${CMAKE_SOURCE_DIR}/routes/pages
    ${CMAKE_SOURCE_DIR}/socket
    ${CMAKE_SOURCE_DIR}/tls
    ${CMAKE_SOURCE_DIR}/utils/files
    ${CMAKE_SOURCE_DIR}/utils/logs
    ${CMAKE_SOURCE_DIR}/utils/miscellaneous
    ${CMAKE_SOURCE_DIR}/utils/parsers
    ${CMAKE_SOURCE_DIR}/utils/text
)

file(GLOB MAIN main.cpp)
file(GLOB ROUTES routes/*.cpp)
file(GLOB ROUTES_PAGES routes/pages/*.cpp)
file(GLOB SOCKET socket/*.cpp)
file(GLOB UTILS_FILES utils/files/*.cpp)
file(GLOB UTILS_LOGS utils/logs/*.cpp)
file(GLOB UTILS_MISCELLANEOUS utils/miscellaneous/*.cpp)
file(GLOB UTILS_PARSERS utils/parsers/*.cpp)
file(GLOB UTILS_TEXT utils/text/*.cpp)

set(ALL_SOURCES
    ${MAIN}
    ${ROUTES}
    ${ROUTES_PAGES}
    ${SOCKET}
    ${UTILS_FILES}
    ${UTILS_LOGS}
    ${UTILS_FILES}
    ${UTILS_MISCELLANEOUS}
    ${UTILS_PARSERS}
    ${UTILS_TEXT}
)

add_executable(mw_website ${ALL_SOURCES})
set(SOs libgcc_s-15-20251211.so.1 libpthread.so.0 libstdc++.so.6.0.34)

foreach (SO IN LISTS SOs)
    add_custom_command (TARGET mw_website POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/bin/${SO}" "${CMAKE_SOURCE_DIR}/build/out/${SO}"
    )
endforeach()
