cmake_minimum_required(VERSION 3.29)

set(PROJECT_NAME "cherries")
set(PROJECT_VERSION "1.0")
set(PROJECT_DESCRIPTION "ssh chat")

project(${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    DESCRIPTION ${PROJECT_DESCRIPTION}
    LANGUAGES C
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(LibSSH REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} LIBSSH::LIBSSH)