#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "Time.h"

using namespace std;

// här lägger ni era testfall.
// Jobba enligt TDD;
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE ("Default constructor")
{
    Time t;
    
    CHECK(t.hour() == 0);
    CHECK(t.minute() == 0);
    CHECK(t.second() == 0);
}

// the following line will halt the compilation process. Move it
// one test case at the time and then start creating your own test
// cases

TEST_CASE ( "Constructor with numeric arguments" )
{
    Time t{12,13,14};
    CHECK(t.hour() == 12);
    CHECK(t.minute() == 13);
    CHECK(t.second() == 14);
}

TEST_CASE ("Constructor with faulty argument")
{
    CHECK_THROWS( Time{41,0,0} );
    CHECK_THROWS( Time{0,99,0} );
    CHECK_THROWS( Time{0,0,99} );
    CHECK_THROWS( Time{-12,0,0} );
    CHECK_THROWS( Time{0,-13,0} );
    CHECK_THROWS( Time{0,0,-2} );
}

TEST_CASE ("String constructor")
{
    Time t{"12:23:12"};
    CHECK(t.hour() == 12);
    CHECK(t.minute() == 23);
    CHECK(t.second() == 12);
    
    SECTION ("Throws as well")
    {
        CHECK_THROWS( Time{"02:11:74"} );
    }
}

TEST_CASE ("am or pm")
{
    Time t{12,12,31};
    CHECK_FALSE(t.is_am());
    Time t2{1,2,3};
    CHECK(t2.is_am());
}

TEST_CASE ("Convert to string" )
{
    CHECK( Time{12,12,12}.to_string()     ==    "12:12:12" );
    CHECK( Time{12, 1, 2}.to_string()     ==    "12:01:02" );
    CHECK( Time{14,33,12}.to_string(true) == "02:33:12 pm" );
}
TEST_CASE ("Conversion to string" )
{
    CHECK( string(Time{2,4,1}) == "02:04:01" );
}

TEST_CASE ("Output operator" )
{
    stringstream ss;
    SECTION("Simple output")
    {
        ss << Time{2,5,1};
        CHECK(ss.str() == "02:05:01");
    }
    SECTION("Chained output")
    {
        ss << Time{23,10,32} << "---";
        CHECK(ss.str() == "23:10:32---");
    }
    SECTION("Const time")
    {
        Time const t{23,23,23};
        ss << t;
        CHECK(ss.str() == "23:23:23");
    }
    
}
TEST_CASE ("plus operator"){
    
    Time DAVID{12,43,42};
    CHECK( (DAVID+2).second()==44);
    CHECK( (DAVID+1337).second()==1);
    CHECK(DAVID.minute()==6);
    CHECK(DAVID.hour()==13);
}

TEST_CASE("Minus operator"){
    
    Time DAVID{12,43,42};
    CHECK( (DAVID-2).second()==40);
    CHECK( (DAVID-1337).second()==23);
    CHECK(DAVID.minute()==21);
    CHECK(DAVID.hour()==12);
    
}
TEST_CASE("INK OCH DEC TEST"){
    
    Time Oskar{13,37,59};
    ++Oskar;
    CHECK( Oskar.second()==0 );
    CHECK( Oskar.minute()==38 );
    --Oskar;
    CHECK( Oskar.second()==59);
    CHECK( Oskar.minute()==37);
    Time Davva{23,59,59};
    CHECK( Davva++.second()==59 );
    CHECK( Davva.second()==0 );
    CHECK( Davva.minute()==0 );
    CHECK( Davva.hour()==0 );
    
    CHECK( Davva--.second()==0 );
    CHECK( Davva.second()==59 );
    CHECK( Davva.minute()==59);
    CHECK( Davva.hour()==23);
}
TEST_CASE("COMP OPERATORS"){
    Time Oskar{12,12,12};
    Time Davva{13,13,13};
    
    CHECK_FALSE( Davva<Oskar);
    CHECK_FALSE(Oskar>Davva);
    Time Oskar2{13,13,13};
    CHECK(Oskar2==Davva);
    CHECK_FALSE(Oskar>=Davva);
    CHECK(Oskar<=Davva);
    CHECK_FALSE(Oskar2!=Davva);
    
    
    
}
TEST_CASE("STREAMS"){
    string s = "12:10:57";
    stringstream ss{s};
    Time Davvamannen{};
    //cout<<ss.str();
    ss>>Davvamannen;
    CHECK_FALSE(ss.fail());
    CHECK(Davvamannen.to_string()=="12:10:57");
    ss<<Davvamannen;
    CHECK(ss.str()=="12:10:57");
    
}

