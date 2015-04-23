# LineSimplification
Line simplification algorithm utilizing Douglas-Peucker algorithm.

For more info, visit the wikipedia [entry](http://en.wikipedia.org/wiki/Ramer%E2%80%93Douglas%E2%80%93Peucker_algorithm).

# Requirements:
1. cmake 2.8 or greater.
2. compiler with c++11.
3. (Optional) To be able to run test, you might want to install [cppunit](http://sourceforge.net/projects/cppunit/).

# How to use:
To be able to do anything, first clone this repository. Ensure you have ```cmake 2.8``` or greater. Or feel free to convert cmake to your own ```Makefile```.

## Building
To build,


```bash
cd LineSimplification # or wherever you cloned this directory.

# Build
mkdir build
cd build
cmake ..
make

# Acquire the compiled library.
cd src
# In build/src directory, there should be libdouglas_peucker.a file.
# Do whatever you want with it.
```

## Sample code
The following is the basic use. By default, the point is represented by ```p2d```, which is just a 2d tuple.

```c++
std::list<p2d> points;
DouglasPeucker2D<> dp2d(points);
dp2d.simplify(0.1);  // Pass in an epsilon. The bigger the stronger the effect. Experiment with this.
std::list<p2d> resultLine = dp2d.getLine();  // Retrieve simplified points.
```

To be able to use your own "point type", you can pass in your own point type. Doing so requires an accessor object that will allow to obtain x and y coordinates.


```c++
struct Point{
  int x, y;
};

struct PointAccessor{
  inline static double getX(const Point& p){
    return p.x;
  }

  inline static double getY(const Point& p){
    return p.y;
  }
};

std::list<Point> points;
DouglasPeucker2D<Point, PointAccessor> dp2d(points);
// An so on...
```

As you can see, you can easily modify this for your own data type.

# More Info
If you are stuck and need help, feel free to contact me at <jandres@ualberta.ca>.
