#include <cstdio>

#include "../pz03/pz03.h"
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"


TEST_CASE("test1","[false]")
{

    int t1 = task3::copier((char*)"../pz03/data/pz05/test1.1.txt",(char*)"../pz03/data/pz05/test1.2.txt");
    REQUIRE(t1==-1);
}

TEST_CASE("test2", "[und]")
{
    int t2 = task3::copier((char*)"../pz03/data/pz05/eksdi.txt",(char*)"../pz03/data/pz05/test1.3.txt");
    REQUIRE(t2==-2);
}

TEST_CASE("test3", "[true]")
{
    int t3= task3::copier((char*)"../pz03/data/pz05/test1.4.txt",(char*)"../pz03/data/pz05/test1.5.txt");
    REQUIRE(t3==4);
}

TEST_CASE("test4", "[false]")
{
    int t4 = task3::summ((char*)"../pz03/data/pz05/test2.1.txt");
    REQUIRE(t4==-1);
}

TEST_CASE("test5", "[false]")
{
    int t5 = task3::summ((char*)"../pz03/data/pz05/xx.txt");
    REQUIRE(t5==-2);
}

TEST_CASE("test6", "[false]")
{
    double t6 = task3::summ((char*)"../pz03/data/pz05/test2.3.txt");
    REQUIRE(t6==136.9);
}
