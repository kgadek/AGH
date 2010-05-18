/* Dosc skomplikowany test, kompilacja trwa ok. 18sek! */

#ifndef __AVL_TESTCASE1
#define __AVL_TESTCASE1


#include <cstdio>
#include "../avl_kgadek.h"
#include "../common_kgadek.h"
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>


class avl_testCase1 : public CppUnit::TestFixture {		/* podst. testy popr. */
	CPPUNIT_TEST_SUITE( avl_testCase1 );
	CPPUNIT_TEST(testA);
	CPPUNIT_TEST(testB);
	CPPUNIT_TEST(testC);
	CPPUNIT_TEST(testD);
	CPPUNIT_TEST_SUITE_END();
	int balanceCheck(avlNode*);
public:
	avlNode *root;
	void setUp();
	void tearDown();
	void testA();
	void testB();
	void testC();
	void testD();
};

void avl_testCase1::setUp() {
	root = NULL;
}

void avl_testCase1::tearDown() {
	avlFree(root);
}

int avl_testCase1::balanceCheck(avlNode* x) {
	if(x==NULL)
		return 0;
	int r,l;
	l = 1+balanceCheck(x->l[0]);
	r = 1+balanceCheck(x->l[1]);
	if( l>=0 && r>=0 && r - l == x->bal && -1 <= x->bal && x->bal <= 1)
		return l>r?l:r;
	return -1;
}

void avl_testCase1::testA() {		/* testy pustego drzewa */
	CPPUNIT_ASSERT( root == NULL );			/* self test  */
	CPPUNIT_ASSERT( avlQuery(root,5) == NULL );	/* avlQuery */
	CPPUNIT_ASSERT( avlQuery(root,6) == NULL);
	CPPUNIT_ASSERT( avlQuery(root,5) == NULL);
	CPPUNIT_ASSERT( avlQuery(root,6) == NULL);
	CPPUNIT_ASSERT( avlQuery(root,-10000) == NULL);
	CPPUNIT_ASSERT( avlQuery(root,10000) == NULL);
}

void avl_testCase1::testB() {		/* testy drzewa z jednym wierz. */
	CPPUNIT_ASSERT( root == NULL );	/* self test */
	CPPUNIT_ASSERT( avlInsert(&root,7) != NULL );	/* avlInsert */
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,5) == NULL );	/* avlQuery */
	CPPUNIT_ASSERT( avlQuery(root,6) == NULL );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );	/* balans */
}

void avl_testCase1::testC() {		/* testy drzewa z ponad 1 wierzcholkiem */
	CPPUNIT_ASSERT( avlInsert(&root,7) != NULL );	/* dodawanie wierzcholkow */
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlInsert(&root,1) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,1) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,1)->key == 1 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlInsert(&root,2) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,1) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,1)->key == 1 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlQuery(root,2) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,2)->key == 2 );
	CPPUNIT_ASSERT( avlInsert(&root,7) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlInsert(&root,3) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,1) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,1)->key == 1 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlQuery(root,2) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,2)->key == 2 );
	CPPUNIT_ASSERT( avlQuery(root,3) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,3)->key == 3 );
	CPPUNIT_ASSERT( avlInsert(&root,7) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlInsert(&root,4) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,1) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,1)->key == 1 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlQuery(root,2) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,2)->key == 2 );
	CPPUNIT_ASSERT( avlQuery(root,3) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,3)->key == 3 );
	CPPUNIT_ASSERT( avlQuery(root,4) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,4)->key == 4 );
	CPPUNIT_ASSERT( avlInsert(&root,5) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,1) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,1)->key == 1 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlQuery(root,2) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,2)->key == 2 );
	CPPUNIT_ASSERT( avlQuery(root,3) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,3)->key == 3 );
	CPPUNIT_ASSERT( avlQuery(root,4) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,4)->key == 4 );
	CPPUNIT_ASSERT( avlQuery(root,5) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,5)->key == 5 );
	CPPUNIT_ASSERT( avlInsert(&root,6) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,1) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,1)->key == 1 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlQuery(root,2) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,2)->key == 2 );
	CPPUNIT_ASSERT( avlQuery(root,3) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,3)->key == 3 );
	CPPUNIT_ASSERT( avlQuery(root,4) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,4)->key == 4 );
	CPPUNIT_ASSERT( avlQuery(root,5) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,5)->key == 5 );
	CPPUNIT_ASSERT( avlQuery(root,6) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,6)->key == 6 );
	CPPUNIT_ASSERT( avlInsert(&root,7) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlInsert(&root,8) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,1) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,1)->key == 1 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlQuery(root,2) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,2)->key == 2 );
	CPPUNIT_ASSERT( avlQuery(root,3) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,3)->key == 3 );
	CPPUNIT_ASSERT( avlQuery(root,4) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,4)->key == 4 );
	CPPUNIT_ASSERT( avlQuery(root,5) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,5)->key == 5 );
	CPPUNIT_ASSERT( avlQuery(root,6) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,6)->key == 6 );
	CPPUNIT_ASSERT( avlQuery(root,8) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,8)->key == 8 );
	CPPUNIT_ASSERT( avlInsert(&root,9) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,1) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,1)->key == 1 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlQuery(root,2) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,2)->key == 2 );
	CPPUNIT_ASSERT( avlQuery(root,3) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,3)->key == 3 );
	CPPUNIT_ASSERT( avlQuery(root,4) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,4)->key == 4 );
	CPPUNIT_ASSERT( avlQuery(root,5) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,5)->key == 5 );
	CPPUNIT_ASSERT( avlQuery(root,6) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,6)->key == 6 );
	CPPUNIT_ASSERT( avlQuery(root,8) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,8)->key == 8 );
	CPPUNIT_ASSERT( avlQuery(root,9) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,9)->key == 9 );
	CPPUNIT_ASSERT( avlInsert(&root,5) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,5) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,5)->key == 5 );
	CPPUNIT_ASSERT( avlInsert(&root,1) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,1) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,1)->key == 1 );
	CPPUNIT_ASSERT( avlInsert(&root,2) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,2) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,2)->key == 2 );
	CPPUNIT_ASSERT( avlInsert(&root,10) != NULL );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );
	CPPUNIT_ASSERT( avlQuery(root,1) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,1)->key == 1 );
	CPPUNIT_ASSERT( avlQuery(root,7) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,7)->key == 7 );
	CPPUNIT_ASSERT( avlQuery(root,2) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,2)->key == 2 );
	CPPUNIT_ASSERT( avlQuery(root,3) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,3)->key == 3 );
	CPPUNIT_ASSERT( avlQuery(root,4) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,4)->key == 4 );
	CPPUNIT_ASSERT( avlQuery(root,5) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,5)->key == 5 );
	CPPUNIT_ASSERT( avlQuery(root,6) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,6)->key == 6 );
	CPPUNIT_ASSERT( avlQuery(root,8) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,8)->key == 8 );
	CPPUNIT_ASSERT( avlQuery(root,9) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,9)->key == 9 );
	CPPUNIT_ASSERT( avlQuery(root,10) != NULL );
	CPPUNIT_ASSERT( avlQuery(root,10)->key == 10 );
	CPPUNIT_ASSERT( balanceCheck(root) >= 0 );	/* sprawdzenie balansu
							   drzewa */
}

void avl_testCase1::testD() {		/* test usuwania drzewa */
	avlFree(root);
	CPPUNIT_ASSERT( balanceCheck(root) == 0 );	/* self test */
	CPPUNIT_ASSERT( root == NULL );
	CPPUNIT_ASSERT( avlQuery(root,1) == NULL );
	CPPUNIT_ASSERT( avlQuery(root,7) == NULL );
	CPPUNIT_ASSERT( avlQuery(root,1) == NULL );
	CPPUNIT_ASSERT( avlQuery(root,7) == NULL );
	CPPUNIT_ASSERT( avlQuery(root,3) == NULL );
	CPPUNIT_ASSERT( avlQuery(root,-1000) == NULL );
}

CPPUNIT_TEST_SUITE_REGISTRATION( avl_testCase1 );

#endif
