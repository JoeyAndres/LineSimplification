# LineSimplification
Line simplification algorithm utilizing Douglas-Peucker algorithm.

For more info, visit the wikipedia [entry](http://en.wikipedia.org/wiki/Ramer%E2%80%93Douglas%E2%80%93Peucker_algorithm).

This module contains implementation for both 2D and 3D via ```DouglasPeucker2D``` and ```DouglasPeucker3D``` respectively.

# Requirements:
A compiler with c++11 support. This is a template based module, thus you can't really compile it.

That's it!

# How to use:
To be able to do anything, first clone this repository. Copy the ```DouglasPeucker.h``` from ```include/``` directory to your own, and your done. The ```src``` is just a code snippet for helping me debug, so don't bother with that.

## Basic Example:
2D example:

```cpp
#include <list>
#include "DouglasPeucker.h"

std::list<p2d> line;  // Contains coordinate.
DouglasPuecker2D<p2d, p2dAccessor> dp2d(line);
dp2d.simplify(0.1F);
std::list<p2d> result = dp2d.getLine();
```

3D example:
```cpp
#include <list>
#include "DouglasPeucker.h"

std::list<p3d> line;  // Contains coordinate.
DouglasPuecker3D<p3d, p3dAccessor> dp3d(line);
dp3d.simplify(0.1F);
std::list<p3d> result = dp3d.getLine();
```

Note that ```p2d``` and ```p3d``` are just ```tuple<double, double>``` and ```tuple<double, double, double>``` respectively.

## Using Costum Datatype:
If you have your own 2D class/struct, with ```getX``` and ```getY``` method is defined then:
```cpp
#include <list>
#include "DouglasPeucker.h"

struct Point2D{
       double x, y;

       double getX() const { return x; }
       double getY() const { return y; }
};

std::list<Point2D> line;  // Contains coordinate.
DouglasPuecker2D<Point2D> dp2d(line);
dp2d.simplify(0.1F);
std::list<Point2D> result = dp2d.getLine();
```

If ```getX``` and ```getY``` method is not defined in your 2D class/struct, create an accessor class:
```cpp
#include <list>
#include "DouglasPeucker.h"

struct Point2D{
       double x, y;
};

// Required if methods not defined.
struct Point2DAccessor{
       static double getX(const Point2D& p) { return p.x; }
       static double getY(const Point2D& p) { return p.y; }
};

std::list<Point2D> line;  // Contains coordinate.
DouglasPuecker2D<Point2D, Point2DAccessor> dp2d(line);
dp2d.simplify(0.1F);
std::list<Point2D> result = dp2d.getLine();
```

Same applies for custom 3D data types.

# More Info
If you are stuck and need help, feel free to contact me at <jandres@ualberta.ca>. I'm always glad to help.
