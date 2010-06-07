#include <cstdio>
#include <string>

using namespace std;
int main()
{
    string mystr = "123456";
    int perm = 1, digits = mystr.size();
    for (int i = 1; i <= digits; perm *= i++);
    printf("#define CA(x) CPPUNIT_ASSERT(avlInsert(&root,(x)) != NULL)\n");
    printf("#define CB(x) CPPUNIT_ASSERT(avlQuery(root,(x)) != NULL)\n\n");
    printf("#include <cstdio>\n");
    printf("#include \"../avl_kgadek.h\"\n");
    printf("#include \"../common_kgadek.h\"\n");
    printf("#include <cppunit/TestAssert.h>\n");
    printf("#include <cppunit/TestFixture.h>\n");
    printf("#include <cppunit/extensions/HelperMacros.h>\n");
    printf("#include <cppunit/extensions/TestFactoryRegistry.h>\n\n");
    printf("class avl_testCase2 : public CppUnit::TestFixture {\n");
    printf("\tCPPUNIT_TEST_SUITE( avl_testCase2 );\n");
    for (int i = perm; i > 0; --i)
	printf("\tCPPUNIT_TEST( test%d );\n", i);
    printf("\tCPPUNIT_TEST_SUITE_END();\n");
    printf("\tint balanceCheck(avlNode*);\n");
    printf("public:\n");
    printf("\tavlNode *root;\n");
    printf("\tvoid setUp();\n");
    printf("\tvoid tearDown();\n");
    for (int i = perm; i > 0; --i)
	printf("\tvoid test%d();\n", i);
    printf("};\n");
    printf("int avl_testCase2::balanceCheck(avlNode* x) {\n");
    printf("	if(x==NULL)\n");
    printf("		return 0;\n");
    printf("	int r,l;\n");
    printf("	l = 1+balanceCheck(x->l[0]);\n");
    printf("	r = 1+balanceCheck(x->l[1]);\n");
    printf
	("	if( l>=0 && r>=0 && r - l == x->bal && -1 <= x->bal && x->bal <= 1)\n");
    printf("		return l>r?l:r;\n");
    printf("	return -1;\n");
    printf("}\n");

    printf("void avl_testCase2::setUp() {\n");
    printf("	root = NULL;\n");
    printf("}\n");
    printf("\n");
    printf("void avl_testCase2::tearDown() {\n");
    printf("}\n");
    printf("\n");
    printf("\n");
    for (int a = 0; a < perm; a++) {
	std::string avail = mystr;
	printf("void avl_testCase2::test%d() {\n\t", a + 1);
	for (int b = digits, div = perm; b > 0; b--) {
	    div /= b;
	    int index = (a / div) % b;
	    printf("\tCPPUNIT_ASSERT(avlInsert(&root,(%c)) != NULL);\n", avail[index]);
	    printf("\tCPPUNIT_ASSERT(avlInsert(&root,(%c)) != NULL);\n", avail[index]);
	    avail[index] = avail[b - 1];
	}
	printf("\n\t");
	for (int b = digits; b > 0; --b)
	    printf("\tCPPUNIT_ASSERT(avlQuery(root,(%d)) != NULL);\n", b);
	printf("\n\tavlFree(root); ");
	printf("root = NULL;\n");
	printf("}\n");
    }
    printf("CPPUNIT_TEST_SUITE_REGISTRATION( avl_testCase2 );\n");
    return 0;
}
