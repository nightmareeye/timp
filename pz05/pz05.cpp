#include <cstdio>

#include "../pz03/pz03.h"
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"


TEST_CASE("test1","[false]")
{

    int t1 = task3::copier((char*)"../pz03/data/pz05/test1.1.txt",(char*)"../pz03/data/pz05/test1.2.txt");
    REQUIRE(t1==0);
}

TEST_CASE("test2", "[und]")
{
    int t2 = task3::copier((char*)"../pz03/data/pz05/eksdi.txt",(char*)"../pz03/data/pz05/test1.3.txt");
    REQUIRE(t2==-1);
}

TEST_CASE("test3", "[true]")
{
    int t3= task3::copier((char*)"../pz03/data/pz05/test1.4.txt",(char*)"../pz03/data/pz05/test1.5.txt");
    REQUIRE(t3==4);
}

