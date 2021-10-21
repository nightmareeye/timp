#include "iostream"
#include "../catch.hpp"
#include "../pz03/pz03.cpp"

TEST_CASE("test1","[false]")
{
    //char *p="../pz03/data/pz05/";
    int t1 = task3::copier("../pz03/data/pz05/test1.1.txt","../pz03/data/pz05/test1.2.txt");
    REQUIRE(t1==-1);
}

TEST_CASE("test2", "[und]")
{
    int t2 = task3::copier("../pz03/data/pz05/eksdi.txt","../pz03/data/pz05/test1.3.txt");
    REQUIRE(t2==-2);
}

