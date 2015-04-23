// testRunner.cpp

#include <iostream>
#include <cppunit/ui/text/TestRunner.h>
#include <utility>

#include "DouglasPeuckerTest.h"

using namespace std;

int main(){
  CppUnit::TextUi::TestRunner runner;

  runner.addTest(DouglasPeuckerTest::suite());
  runner.run();
  return 0;
}
