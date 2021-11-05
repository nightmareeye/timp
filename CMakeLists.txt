cmake_minimum_required(VERSION 3.13)
project(test_empty)

enable_language(C)
enable_language(CXX)

set(CMAKE_CXX_STANDART 14)
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH}})
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Poco REQUIRED COMPONENTS Foundation Util Net XML JSON)
if(MSVC)
    SET(Poco_INCLUDE_DIRS "C:/Program Files/Poco/include")
else()
    SET(Poco_INCLUDE_DIRS "/usr/local/include/Poco")
endif(MSVC)
include_directories(
        ${MY_SRC_INCLUDE}
        ${Poco_INCLUDE_DIRS}
)

link_directories(${CMAKE_BINARY_DIR})


MESSAGE( [Main] " Poco_INCLUDE_DIRS = ${Poco_INCLUDE_DIRS}")
MESSAGE( [Main] " Poco_LIBRARIES = ${Poco_LIBRARIES}")


find_package(SFML 2.4.2 COMPONENTS graphics audio REQUIRED)


add_executable(SfmlApp pz06/main.cpp)

target_link_libraries(SfmlApp sfml-graphics sfml-audio sfml-window sfml-system)

add_executable(example_test example/example_tests.cpp example/example.cpp)
add_executable(example_main example/example_main.cpp example/example.cpp pz06/main.cpp)
add_executable(pz03_main pz03/pz03.cpp pz03/main.cpp pz03/pz03.h)
add_executable(pz05_test pz05/pz05.cpp pz03/pz03.cpp pz05/pz05_main.cpp)