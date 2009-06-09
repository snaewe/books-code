/* cppbuch/k18/tdd/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#define BOOST_TEST_MAIN
// dynamisches Linken erwünscht:
#define BOOST_TEST_DYN_LINK
#include<boost/test/unit_test.hpp>
#include"datum.h"


BOOST_AUTO_TEST_SUITE( datum_operator_plus_plus )

BOOST_AUTO_TEST_CASE( tag )
{
   Datum d(1, 1, 2010);
   for(int tag = 2; tag <= 31; ++tag) {
      ++d;
      BOOST_CHECK( d.tag() == tag );
   }
}

BOOST_AUTO_TEST_CASE( einfacher_monatswechsel )
{
   Datum d(31, 1, 2010);
   ++d;
   BOOST_CHECK( d.tag() == 1 );
   BOOST_CHECK( d.monat() == 2 );
}

BOOST_AUTO_TEST_CASE( alle_monatswechsel )
{
   int monate[]={31,28,31,30,31,30,31,31,30,31,30,31};
   for(int monat = 1; monat <= 12; ++monat) {
      Datum d(monate[monat-1], monat, 2010);
      ++d;
      BOOST_CHECK( d.tag() == 1 );
      if(monat < 12) {
         BOOST_CHECK( d.monat() == monat+1 );
      }
      else {
         BOOST_CHECK( d.monat() == 1 );
      }
   }
}

BOOST_AUTO_TEST_CASE( schaltjahr )
{
   for(int jahr = 1800; jahr < 2300; ++jahr) {
      bool schaltjahr =  // durch 4 teilbar, aber nicht durch 100,
         // es sei denn, durch 400
         ((jahr % 4 == 0) && (jahr % 100 != 0)) || (jahr % 400 == 0); 
      Datum d(28, 2, jahr);
      ++d;
      if(schaltjahr) {
         BOOST_REQUIRE( d.tag() == 29 );
         BOOST_REQUIRE( d.monat() == 2 );
      }
      else {
         BOOST_REQUIRE( d.tag() == 1 );
         BOOST_REQUIRE( d.monat() == 3 );
      }
   }
}

BOOST_AUTO_TEST_SUITE_END()
