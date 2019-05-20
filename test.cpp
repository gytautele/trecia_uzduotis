#define CATCH_CONFIG_MAIN
#include "headers/catch.h"
#include "headers/main_header.h"
#include "headers/time.h"

TEST_CASE("Testas1")
{
    CHECK(kazkas("0") == 0);
    CHECK(kazkas("ABC") == 0);
    CHECK(kazkas("Test1234") == 0);
}

duomenys stud1;
duomenys stud2;

TEST_CASE("Testas2")
{
    stud1.galutinis() == 5;
    CHECK(tikrinimas_5(stud1) == true);
    stud2.galutinis() == 17;
    CHECK(tikrinimas_5(stud2) == false);
    stud2.galutinis() == 5;
    CHECK(tikrinimas_5(stud2) == false);
}