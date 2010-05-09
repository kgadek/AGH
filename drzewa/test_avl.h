#ifndef __TEST_RB_H
#define __TEST_RB_H

#include <cstdio>
/* pliki naglowkowe CppUnit */
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>


/* testowane implementacje */
#include "avl_bst_splay_tree_mmk.h"
#include "avl_bst_splay_tree_mmk.cpp"


/*****************************************************
 * Klasy testujace                                   *
 ****************************************************/
class avl_mmk_testCase1 : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE( avl_mmk_testCase1 );
	CPPUNIT_TEST(testA);
	CPPUNIT_TEST_SUITE_END();
	mmk::AVL<int> *R1;
	mmk::AVL<double> *R2;
	mmk::AVL<char> *R3;
	mmk::AVL<char*> *R4;
public:
	void setUp();
	void tearDown();
	void testA();
};


#endif
