/* cppbuch/k18/datum/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
/**
 * Diese Datei definiert keine systematischen Tests, sondern ist
 * ein Sammelsurium der Beispiele für Testmakros.
 */

#define BOOST_TEST_MAIN
// dynamisches Linken erwünscht: (gibt aber bei BOOST_TEST_CHECKPOINT
// unter Windows Vista einen Fehler (nicht bei Linux oder WinXP)
//#define BOOST_TEST_DYN_LINK
//#include<boost/test/unit_test.hpp>
// oder Header-only (compiliert langsamer)
#include<boost/test/included/unit_test.hpp>
#include<fstream>  // Logging
#include<memory>   // shared_ptr
#include<vector>   //  eq_collection
#include"datum.h"

// Log-Datei definieren
// Level siehe /boost/test/detail/log_level.hpp
class LogKonfiguration {
public:
   LogKonfiguration() 
      : test_log("test.log") { 
      boost::unit_test::unit_test_log.set_stream(test_log); 
      boost::unit_test::unit_test_log.set_threshold_level(
                       boost::unit_test::log_test_units);
   }
   ~LogKonfiguration() { // schließen und zurücksetzen
      test_log.close();
      boost::unit_test::unit_test_log.set_stream(std::cout); 
   }
private:
   std::ofstream test_log;
};

class FalscheException : public std::exception {};

bool checkException(const std::exception& e) {
   return typeid(e) == typeid(UngueltigesDatumException);
}

//BOOST_GLOBAL_FIXTURE( LogKonfiguration );

BOOST_AUTO_TEST_SUITE( test_suite_datum )

BOOST_AUTO_TEST_CASE( konstruktor_mit_fixture )
{  
   // shared_ptr<Datum> als Fixture
   std::shared_ptr<Datum> p(new Datum(1, 1, 2010));
   BOOST_CHECK( p->jahr() == 2010 );
}  // delete automatisch durch shared_ptr-Destruktor

BOOST_AUTO_TEST_CASE( konstruktor )
{
   Datum d(1, 1, 2010);
   BOOST_CHECK( d.jahr() == 2010 );
}

BOOST_AUTO_TEST_CASE( schaltjahrtest )
{
   BOOST_CHECK_PREDICATE( istSchaltjahr, (2012) );
}

BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES( konstruktor_ungueltiges_Datum, 1 )

BOOST_AUTO_TEST_CASE( konstruktor_ungueltiges_Datum )
{
   BOOST_CHECK_THROW( Datum(30, 2, 2010),  UngueltigesDatumException );
   BOOST_TEST_MESSAGE( "Gegenprobe: " );   // soll fehlschlagen, kein Fehler
   BOOST_CHECK_THROW( Datum(1, 2, 2010),  UngueltigesDatumException );
}


BOOST_AUTO_TEST_CASE( konstruktor_exception )
{
   BOOST_CHECK_EXCEPTION( Datum(30, 2, 2010),  UngueltigesDatumException, 
                                               checkException);
   //BOOST_CHECK_EXCEPTION( Datum(30, 2, 2010),  FalscheException, checkException);
}

BOOST_AUTO_TEST_CASE( konstruktor_nothrow )
{
   BOOST_CHECK_NO_THROW( do {
                           int tag = 3; 
                           Datum(tag, 2, 2010);
                         } while(0));
}

BOOST_AUTO_TEST_CASE( relational )
{
   BOOST_CHECK_EQUAL( 17, 17);
}

BOOST_AUTO_TEST_CASE( close )
{
   double toleranzInProzent = 2.0;
   BOOST_CHECK_CLOSE( 1.25, 1.27, toleranzInProzent);
}

BOOST_AUTO_TEST_CASE( close_fraction )
{
   double toleranzAlsBruch = 0.016001;
   BOOST_CHECK_CLOSE_FRACTION( 1.25, 1.27, toleranzAlsBruch);
}

BOOST_AUTO_TEST_CASE( eq_collection )
{
   std::vector<int> v;
   for(int i=1; i <= 8; ++i)
      v.push_back(i);
   int arr [] = { 1, 2, 3, 5, 5, 6, 7, 9};
    BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), arr, arr+8 );
}

BOOST_AUTO_TEST_CASE( eq_bit )
{
   BOOST_CHECK_BITWISE_EQUAL( 7, 9);
}

BOOST_AUTO_TEST_CASE( funktion_ungueltiges_Datum )
{
   Datum d;
   BOOST_CHECK_THROW( d.set(30, 2, 2010),  UngueltigesDatumException );
}

// Der folgende Testfall schlägt beabsichtigt fehl, damit
// BOOST_TEST_CHECKPOINT wirksam wird
BOOST_AUTO_TEST_CASE( konstruktor_ungueltiges_Datum_checkpoint )
{
   for(int tag = 1; tag < 30; ++tag) {
     BOOST_TEST_CHECKPOINT( "Datum mit Tag = " << tag );
     Datum d(tag, 2, 2010);  // Exception bei tag == 29: Fehler
   }
}

BOOST_AUTO_TEST_CASE( differenz )
{
   Datum d(1, 1, 1800);
   Datum vortag;
   Datum ende(31, 12, 2300);
   while( d != ende) {
      vortag = d;
      ++d;
      BOOST_REQUIRE(vortag < d);                     // operator<() testen
      BOOST_REQUIRE(datumDifferenz(vortag, d) == 1);
   }

}


BOOST_AUTO_TEST_SUITE_END()
