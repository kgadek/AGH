#include <iostream>		/* tylko by ustawic ios_base::sync_with_stdio() */
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

int main() {
	std::ios_base::sync_with_stdio(0);
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	runner.run();
	return 0;
}
