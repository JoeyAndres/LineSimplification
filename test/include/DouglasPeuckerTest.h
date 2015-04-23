// DouglasPeuckerTest.h
#pragma once

#include <cppunit/extensions/HelperMacros.h>

class DouglasPeuckerTest : public CppUnit::TestFixture{
  CPPUNIT_TEST_SUITE(DouglasPeuckerTest);
  CPPUNIT_TEST(distanceTest);
  CPPUNIT_TEST(pointSegmentDistance);
  CPPUNIT_TEST(simplifyTest);
  CPPUNIT_TEST_SUITE_END();
public:
  void distanceTest();
  void pointSegmentDistance();
  void simplifyTest();
};
