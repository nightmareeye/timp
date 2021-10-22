#include <cstdio>

#include "../pz03/pz03.h"

#include "../catch.hpp"


TEST_CASE("test1","[false][copier]")
{

    int t1 = task3::copier((char*)"../pz03/data/pz05/test1.1.txt",(char*)"../pz03/data/pz05/test1.2.txt");
    REQUIRE(t1==-1);
}

TEST_CASE("test2", "[und][copier]")
{
    int t2 = task3::copier((char*)"../pz03/data/pz05/eksdi.txt",(char*)"../pz03/data/pz05/test1.3.txt");
    REQUIRE(t2==-2);
}

TEST_CASE("test3", "[true][copier]")
{
    int t3= task3::copier((char*)"../pz03/data/pz05/test1.4.txt",(char*)"../pz03/data/pz05/test1.5.txt");
    REQUIRE(t3==4);
}

TEST_CASE("test4", "[false][summ]")
{
    int t4 = task3::summ((char*)"../pz03/data/pz05/test2.1.txt");
    REQUIRE(t4==-1);
}

TEST_CASE("test5", "[und][summ]")
{
    int t5 = task3::summ((char*)"../pz03/data/pz05/xx.txt");
    REQUIRE(t5==-2);
}

TEST_CASE("test6", "[true][summ]")
{
    double t6 = task3::summ((char*)"../pz03/data/pz05/test2.3.txt");
    REQUIRE(t6==136.9);
}

TEST_CASE("test7", "[false][crypto]")
{
    int t7 = task3::crypto((char*)"../pz03/data/pz05/test3.1.txt", (char*)"../pz03/data/pz05/test3.txt", (char*)"111111");
    REQUIRE(t7==-1);
}

TEST_CASE("test8", "[und][crypto]")
{
    int t8 = task3::crypto((char*)"../pz03/data/pz05/xxxx.txt", (char*)"../pz03/data/pz05/test3.txt", (char*)"111111");
    REQUIRE(t8==-2);
}

TEST_CASE("test9", "[true][crypto]")
{
    int t9 = task3::crypto((char*)"../pz03/data/pz05/test3.2.txt", (char*)"../pz03/data/pz05/test3.txt", (char*)"111111");
    REQUIRE(t9==53);
}
