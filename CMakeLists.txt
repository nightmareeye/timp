cmake_minimum_required(VERSION 3.13)
project(test_empty)

set(CMAKE_CXX_STANDART 14)


find_package(SFML 2.4.2 COMPONENTS graphics audio REQUIRED)


add_executable(SfmlApp pz06/main.cpp)

target_link_libraries(SfmlApp sfml-graphics sfml-audio sfml-window sfml-system)

add_executable(example_test example/example_tests.cpp example/example.cpp)
add_executable(example_main example/example_main.cpp example/example.cpp pz06/main.cpp)
add_executable(pz03_main pz03/pz03.cpp pz03/main.cpp pz03/pz03.h)
add_executable(pz05_test pz05/pz05.cpp pz03/pz03.cpp pz05/pz05_main.cpp)