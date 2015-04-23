// DouglasPeuckerTest.cpp

#include <cppunit/TestAssert.h>
#include <list>

#include "DouglasPeucker.h"
#include "DouglasPeuckerTest.h"

using namespace std;

void DouglasPeuckerTest::distanceTest(){
  DouglasPuecker2D<p2d> dp2d;
  CPPUNIT_ASSERT_DOUBLES_EQUAL(5.0,
			       dp2d._distance(p2d(-2, 1),
					      p2d(1, 5)), 0.001F);
}

void DouglasPeuckerTest::pointSegmentDistance(){
  DouglasPuecker2D<p2d> dp2d;
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3.328F,
			       dp2d._pointSegmentDistance(p2d(1.0F, -2.0F/3.0F),
							  p2d(2.0F, 0.0F),
							  p2d(5.0F, 6.0F)), 0.001F);
}

void DouglasPeuckerTest::simplifyTest(){
  list<p2d> points({
      p2d(0, 0.0),
	p2d(1, 0.309131817589506),
	p2d(2, 0.5879805879072467),
	p2d(3, 0.8092298394264411),
	p2d(4, 0.9512056416056028),
	p2d(5, 0.9999998177893362),
	p2d(6, 0.9508324124380243),
	p2d(7, 0.808519943217477),
	p2d(8, 0.5870035672249242),
	p2d(9, 0.30798338294249766)
    });
  DouglasPuecker2D<p2d> dp2d(points);
  dp2d.simplify(0.01);

  for(auto i : dp2d.getLine()){
    cout << get<0>(i) <<  ", " << get<1>(i) << endl;
  }
}
