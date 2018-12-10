/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite1_init = false;
#include "VectorTestSuite.hpp"

static MyTestSuite1 suite_MyTestSuite1;

static CxxTest::List Tests_MyTestSuite1 = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite1( "VectorTestSuite.hpp", 7, "MyTestSuite1", suite_MyTestSuite1, Tests_MyTestSuite1 );

static class TestDescription_suite_MyTestSuite1_testVectors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testVectors() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 10, "testVectors" ) {}
 void runTest() { suite_MyTestSuite1.testVectors(); }
} testDescription_suite_MyTestSuite1_testVectors;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
