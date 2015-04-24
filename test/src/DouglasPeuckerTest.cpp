// DouglasPeuckerTest.cpp

#include <cppunit/TestAssert.h>
#include <list>

#include "DouglasPeucker.h"
#include "DouglasPeuckerTest.h"

using namespace std;

struct point2d{
  point2d(double x, double y) : _x(x), _y(y){}

  double getX() const{return _x;}
  double getY() const{return _y;}
  
  double _x, _y;
};

struct point3d{
  point3d(double x, double y, double z) : _x(x), _y(y), _z(z){}
  double _x, _y, _z;
};

struct point3dAccessor{
  static double getX(const point3d& p){return p._x;}
  static double getY(const point3d& p){return p._y;}
  static double getZ(const point3d& p){return p._z;}
};

void DouglasPeuckerTest::distanceTest(){
  DouglasPuecker2D<p2d, p2dAccessor> dp2d;
  CPPUNIT_ASSERT_DOUBLES_EQUAL(5.0,
			       dp2d._distance(p2d(-2, 1),
					      p2d(1, 5)), 0.001F);
}

void DouglasPeuckerTest::distanceTest2(){
  DouglasPuecker2D<point2d> dp2d;
  CPPUNIT_ASSERT_DOUBLES_EQUAL(5.0,
			       dp2d._distance(point2d(-2, 1),
					      point2d(1, 5)), 0.001F);
}


void DouglasPeuckerTest::pointSegmentDistance(){
  DouglasPuecker2D<p2d, p2dAccessor> dp2d;
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3.328F,
			       dp2d._pointSegmentDistance(p2d(1.0F, -2.0F/3.0F),
							  p2d(2.0F, 0.0F),
							  p2d(5.0F, 6.0F)), 0.001F);
}

void DouglasPeuckerTest::pointSegmentDistance2(){
  DouglasPuecker2D<point2d> dp2d;
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3.328F,
			       dp2d._pointSegmentDistance(point2d(1.0F, -2.0F/3.0F),
							  point2d(2.0F, 0.0F),
							  point2d(5.0F, 6.0F)), 0.001F);
}

// For simplicity, we are just going to test if this is consistent with the 2D, by just
// adding 0 as the magntide of 3rd dimension.
void DouglasPeuckerTest::pointSegmentDistance3D(){
  DouglasPuecker3D<point3d, point3dAccessor> dp3d;
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3.328F,
			       dp3d._pointSegmentDistance(point3d(1.0F, -2.0F/3.0F, 0.0f),
							  point3d(2.0F, 0.0F, 0.0f),
							  point3d(5.0F, 6.0F, 0.0f)), 0.001F);
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
  DouglasPuecker2D<p2d, p2dAccessor> dp2d(points);
  dp2d.simplify(0.1);

  for(auto p : dp2d.getLine()){
    if((int)get<0>(p) == 0) continue;
    CPPUNIT_ASSERT(1 == ((int)get<0>(p) % 2));  // Only odd vertices remained.
  }
  
  CPPUNIT_ASSERT(5 == dp2d.getLine().size());
}
