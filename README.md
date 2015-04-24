# LineSimplification
Line simplification algorithm utilizing Douglas-Peucker algorithm.

For more info, visit the wikipedia [entry](http://en.wikipedia.org/wiki/Ramer%E2%80%93Douglas%E2%80%93Peucker_algorithm).

# Requirements:
1. A compiler with c++11 support. This is a template based module, thus you can't really compile it.

That's it!

# How to use:
To be able to do anything, first clone this repository. Copy the ```DouglasPeucker.h``` from ```include/``` directory to your own, and your done. The ```src``` is just a code snippet for helping me debug, so don't bother with that.

## Sample code
The following is the basic use. By default, the point is represented by ```p2d```, which is just a 2d tuple.

```c++
std::list<p2d> points;
DouglasPeucker2D<> dp2d(points);
dp2d.simplify(0.1);  // Pass in an epsilon. The bigger the stronger the effect. Experiment with this.
std::list<p2d> resultLine = dp2d.getLine();  // Retrieve simplified points.
```

To be able to use your own "point type", you can pass in your own point type. Ensure that your point type have a ```getX()``` and ```getY()```.

```c++
struct Point{
  double x, y;

  double getX() const{
    return x;
  }

  double getY() const{
    return y;
  }
};

list<Point> points;
DouglasPeucker2D<Point> dp2d(points);
// An so on...
```

OR, if you're point type don't have ```getX()``` and ```getY()``` defined, and you can't inherit and add those features either, you can define an accessor struct/class, like the following:


```c++
struct Point{
  double x, y;
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
If you are stuck and need help, feel free to contact me at <jandres@ualberta.ca>. I'm always glad to help.
