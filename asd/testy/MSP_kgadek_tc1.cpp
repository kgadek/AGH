#include <cstdio>
#include "../MSP_kgadek.cpp"
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class MSP_testCase1 : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE( MSP_testCase1 );
        CPPUNIT_TEST( testA );
        CPPUNIT_TEST_SUITE_END();
public:
        void setUp();
        void tearDown();
        void testA();
};

CPPUNIT_TEST_SUITE_REGISTRATION( MSP_testCase1 );

void MSP_testCase1::testA() {
	/* tak, to jest JEDYNY test :P */
	int in1[] = {-3,2,4,5,-2};
	CPPUNIT_ASSERT( MSP(in1,5) == 11 );
}

void MSP_testCase1::setUp() {}
void MSP_testCase1::tearDown() {}
