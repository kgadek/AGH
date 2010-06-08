#include <cstdio>
#include "../lider_kgadek.cpp"
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class lider_testCase1 : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE( lider_testCase1 );
        CPPUNIT_TEST( testA );
        CPPUNIT_TEST_SUITE_END();
public:
        void setUp();
        void tearDown();
        void testA();
};

CPPUNIT_TEST_SUITE_REGISTRATION( lider_testCase1 );

void lider_testCase1::testA() {
        int in1[] = {5,4,3,22,22,12,22,1,2};
        CPPUNIT_ASSERT( lider(in1,9) == -1 );
	int in2[] = {6,7,6,7,6,7,6,7,6,5,5,6,6};
        CPPUNIT_ASSERT( lider(in2,13) != -1 );
        CPPUNIT_ASSERT( in2[lider(in2,13)] == 6 );
	int in3[] = { 121,120,119,120,121,120,120,121,120,121};
        CPPUNIT_ASSERT( lider(in3,10) == -1 );
	int in4[] = {1,1,1,1,1,2,2,2,2,2};
        CPPUNIT_ASSERT( lider(in4,10) == -1 );
	int in5[] = {1,1,1,1,1,2,2,2,2,2,1};
        CPPUNIT_ASSERT( lider(in5,11) != -1 );
        CPPUNIT_ASSERT( in5[lider(in5,11)] == 1 );
	int in6[] = {8,7,6,5,5,5,5,5,5,5,8,8,5,8};
        CPPUNIT_ASSERT( lider(in6,14) != -1 );
        CPPUNIT_ASSERT( in6[lider(in6,14)] == 5 );
}

void lider_testCase1::setUp() {}
void lider_testCase1::tearDown() {}

