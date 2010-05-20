/* Podstawowy test poprawnosciowy. */

#include "../avl_bst_splay_tree_mmk.h"
#include "../avl_bst_splay_tree_mmk.cpp"
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>


class avl_mmk_testCase1 : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE( avl_mmk_testCase1 );
        CPPUNIT_TEST(testA);
        CPPUNIT_TEST_SUITE_END();
        mmk::AVL<int> *R1;
        mmk::AVL<double> *R2;
        mmk::AVL<char> *R3;
public:
        void setUp();
        void tearDown();
        void testA();
};


void avl_mmk_testCase1::setUp() {
	R1 = new mmk::AVL<int>;
	R2 = new mmk::AVL<double>;
	R3 = new mmk::AVL<char>;
}

void avl_mmk_testCase1::tearDown() {
	delete R1;
	delete R2;
	delete R3;
}

void avl_mmk_testCase1::testA() {
	/* self */
	CPPUNIT_ASSERT( R1 != NULL );
	CPPUNIT_ASSERT( R2 != NULL );
	CPPUNIT_ASSERT( R3 != NULL );
	/* testy <int> */
	CPPUNIT_ASSERT( R1->search(3) == NULL );
	CPPUNIT_ASSERT( R1->search(0) == NULL );
	R1->insert(3);
	CPPUNIT_ASSERT( R1->search(3) != NULL );
	CPPUNIT_ASSERT( R1->search(0) == NULL );
	R1->insert(0);
	CPPUNIT_ASSERT( R1->search(3) != NULL );
	CPPUNIT_ASSERT( R1->search(0) != NULL );
	CPPUNIT_ASSERT( R1->successor(R1->search(0)) == R1->search(3) );
	CPPUNIT_ASSERT( R1->predecessor(R1->search(3)) == R1->search(0) );
	CPPUNIT_ASSERT( R1->predecessor(R1->search(0)) == NULL );
	CPPUNIT_ASSERT( R1->successor(R1->search(3)) == NULL );
	int x = 0;
	CPPUNIT_ASSERT( R1->successor(x) == R1->search(3) );
	CPPUNIT_ASSERT( R1->predecessor(0) == NULL );
	CPPUNIT_ASSERT( x == 0 );
	x = 3;
	CPPUNIT_ASSERT( R1->successor(x) == NULL );
	CPPUNIT_ASSERT( R1->predecessor(x) == R1->search(0) );
	CPPUNIT_ASSERT( x == 3 );
	R1->insert(3);
	R1->insert(3);
	R1->insert(3);
	R1->insert(1);
	R1->insert(2);
	R1->insert(3);
	R1->insert(4);
	R1->insert(5);
	R1->insert(6);
	R1->insert(-10000);
	R1->insert(+10000);
	CPPUNIT_ASSERT( R1->search(-10000) != NULL );
	CPPUNIT_ASSERT( R1->search(0) != NULL );
	CPPUNIT_ASSERT( R1->search(1) != NULL );
	CPPUNIT_ASSERT( R1->search(2) != NULL );
	CPPUNIT_ASSERT( R1->search(3) != NULL );
	CPPUNIT_ASSERT( R1->search(3)->value == 3 );
	CPPUNIT_ASSERT( R1->predecessor(R1->search(4)) == R1->search(3) );
	CPPUNIT_ASSERT( R1->search(4) != NULL );
	CPPUNIT_ASSERT( R1->search(5) != NULL );
	CPPUNIT_ASSERT( R1->search(6) != NULL );
	CPPUNIT_ASSERT( R1->search(6)->value == 6 );
	CPPUNIT_ASSERT( R1->successor(6)->value == +10000 );
	CPPUNIT_ASSERT( R1->search(+10000) != NULL );
}

CPPUNIT_TEST_SUITE_REGISTRATION( avl_mmk_testCase1 );

