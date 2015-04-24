// DouglasPeuckerTest.h
#pragma once

#include <cppunit/extensions/HelperMacros.h>

class DouglasPeuckerTest : public CppUnit::TestFixture{
  CPPUNIT_TEST_SUITE(DouglasPeuckerTest);
  CPPUNIT_TEST(distanceTest);
  CPPUNIT_TEST(distanceTest2);
  CPPUNIT_TEST(pointSegmentDistance);
  CPPUNIT_TEST(pointSegmentDistance2);
  CPPUNIT_TEST(pointSegmentDistance3D);
  CPPUNIT_TEST(simplifyTest);
  CPPUNIT_TEST_SUITE_END();
public:
  void distanceTest();
  void distanceTest2();
  void pointSegmentDistance();
  void pointSegmentDistance2();
  void pointSegmentDistance3D();
  void simplifyTest();
};
