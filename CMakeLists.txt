cmake_minimum_required(VERSION 3.29)

set(PROJECT_NAME "cherries")
set(PROJECT_VERSION "1.0")
set(PROJECT_DESCRIPTION "ssh chat")

project(${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    DESCRIPTION ${PROJECT_DESCRIPTION}
    LANGUAGES C
)

add_executable(${PROJECT_NAME} src/main.c)
