#define BOOST_TEST_MODULE const_string dirk_test
#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "testclass.h"


int add( int i, int j ) { return i+j; }

BOOST_AUTO_TEST_CASE( Testclass )
{
	CTestclass test;
    // seven ways to detect and report the same error:
	test.setI(4);
    BOOST_CHECK( test.getI() == 4 );        // #1 continues on error
}


BOOST_AUTO_TEST_CASE( Test1 )
{
    // seven ways to detect and report the same error:
    BOOST_CHECK( add( 2,2 ) == 4 );        // #1 continues on error
}

BOOST_AUTO_TEST_CASE( Test2 )
{
    BOOST_REQUIRE( add( 2,2 ) == 4 );      // #2 throws on error
}
BOOST_AUTO_TEST_CASE( Test3 )
{
    if( add( 2,2 ) != 4 )
      BOOST_ERROR( "Ouch..." );            // #3 continues on error
}
BOOST_AUTO_TEST_CASE( Test4 )
{
    if( add( 2,2 ) != 4 )
      BOOST_FAIL( "Ouch..." );             // #4 throws on error
}
BOOST_AUTO_TEST_CASE( Test5 )
{
    if( add( 2,2 ) != 4 ) throw "Ouch..."; // #5 throws on error
}
BOOST_AUTO_TEST_CASE( Test6 )
{
    BOOST_CHECK_MESSAGE( add( 2,2 ) == 4,  // #6 continues on error
                         "add(..) result: " << add( 2,2 ) );
}
BOOST_AUTO_TEST_CASE( Test7 )
{
    BOOST_CHECK_EQUAL( add( 2,2 ), 4 );	  // #7 continues on error
}
