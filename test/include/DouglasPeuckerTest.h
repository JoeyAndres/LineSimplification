/**
 * DouglasPeuckerTest.h
 * 
 * Copyright (C) 2015  Joey Andres

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#pragma once

#include <cppunit/extensions/HelperMacros.h>

class DouglasPeuckerTest : public CppUnit::TestFixture{
  CPPUNIT_TEST_SUITE(DouglasPeuckerTest);
  CPPUNIT_TEST(distanceTest);
  CPPUNIT_TEST(distanceTest2);
  CPPUNIT_TEST(pointSegmentDistance);
  CPPUNIT_TEST(pointSegmentDistance2);
  CPPUNIT_TEST(pointSegmentDistance3D);
  CPPUNIT_TEST(pointSegmentDistance3D2);
  CPPUNIT_TEST(simplifyTest);
  CPPUNIT_TEST_SUITE_END();
 public:
  void distanceTest();
  void distanceTest2();
  void pointSegmentDistance();
  void pointSegmentDistance2();
  void pointSegmentDistance3D();
  void pointSegmentDistance3D2();
  void simplifyTest();
};
