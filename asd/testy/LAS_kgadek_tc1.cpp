#include <cstdio>
#include "../LAS_kgadek.cpp"
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class LAS_testCase1 : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE( LAS_testCase1 );
	CPPUNIT_TEST( testA );
	CPPUNIT_TEST_SUITE_END();
	int isAsc(int *, int *, int);
	int *F,*W,M;
public:
	void setUp();
	void tearDown();
	void testA();
};

CPPUNIT_TEST_SUITE_REGISTRATION( LAS_testCase1 );

int LAS_testCase1::isAsc(int *fi, int *w, int mi) {
	/* Zwraca -1 gdy znaleziony ciag nie jest silnie rosnacy
	   lub dlugosc znalezionego ciagu */
	int i,j(0);
	if(mi<0 || fi == NULL || w == NULL)
		return 0;
	for(i=mi;i>=0;) {
		if(w[i]>=0 && fi[w[i]]>=fi[i])
			return -1;
		++j;
		i=w[i];
	}
	return j;
}

void LAS_testCase1::setUp() {
}
void LAS_testCase1::tearDown() {
}
void LAS_testCase1::testA() {
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	CPPUNIT_ASSERT( isAsc(NULL,NULL,-1) == 0 );	/* self */
	LAS(a,15,&F,&W,&M);
	CPPUNIT_ASSERT( isAsc(F,W,M) == 15 );
	free(F);
	free(W);
	a[6] = 0;
	LAS(a,15,&F,&W,&M);
	CPPUNIT_ASSERT( isAsc(F,W,M) == 14 );
	free(F);
	free(W);
	a[0] = 100;
	LAS(a,15,&F,&W,&M);
	CPPUNIT_ASSERT( isAsc(F,W,M) == 13 );
	free(F);
	free(W);
	a[14] = 0;
	LAS(a,15,&F,&W,&M);
	CPPUNIT_ASSERT( isAsc(F,W,M) == 12 );
	free(F);
	free(W);
	a[0] = 0;
	LAS(a,15,&F,&W,&M);
	CPPUNIT_ASSERT( isAsc(F,W,M) == 13 );
	free(F);
	free(W);
	a[13] = 0;
	LAS(a,15,&F,&W,&M);
	CPPUNIT_ASSERT( isAsc(F,W,M) == 12 );
	free(F);
	free(W);
	a[13] = 1000;
	LAS(a,15,&F,&W,&M);
	CPPUNIT_ASSERT( isAsc(F,W,M) == 13 );
	free(F);
	free(W);
	a[13] = -150;
	LAS(a,15,&F,&W,&M);
	CPPUNIT_ASSERT( isAsc(F,W,M) == 12 );
	free(F);
	free(W);
	a[7] = 1234234;
	LAS(a,15,&F,&W,&M);
	CPPUNIT_ASSERT( isAsc(F,W,M) == 11 );
	free(F);
	free(W);
}

