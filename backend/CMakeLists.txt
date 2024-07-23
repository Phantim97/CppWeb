cmake_minimum_required(VERSION 3.28)
project(CppWeb)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

# Configure FetchContent to download Crow only if it's not already downloaded
FetchContent_Declare(
        crow
        GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
        GIT_TAG master
)

# Download Crow only if it's not already downloaded
FetchContent_GetProperties(crow)
if(NOT crow_POPULATED)
    FetchContent_Populate(crow)
endif()

# Fetch Asio
FetchContent_Declare(
        asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG master
)

FetchContent_GetProperties(asio)
if(NOT asio_POPULATED)
    FetchContent_Populate(asio)
endif()

add_executable(CrowServer src/main.cpp)

# Include Crow headers
target_include_directories(CrowServer PRIVATE ${crow_SOURCE_DIR}/include)
target_include_directories(CrowServer PRIVATE ${asio_SOURCE_DIR}/asio/include)