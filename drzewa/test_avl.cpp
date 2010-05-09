#include "test_avl.h"

CPPUNIT_TEST_SUITE_REGISTRATION( avl_mmk_testCase1 );

void avl_mmk_testCase1::setUp() {
	R1 = new mmk::AVL<int>;
	R2 = new mmk::AVL<double>;
	R3 = new mmk::AVL<char>;
	R4 = new mmk::AVL<char*>;
}

void avl_mmk_testCase1::tearDown() {
	delete R1;
	delete R2;
	delete R3;
	delete R4;
}

void avl_mmk_testCase1::testA() {
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
}
