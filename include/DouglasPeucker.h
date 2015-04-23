// DouglasPeucker.h
#pragma once

#include <cmath>
#include <list>
#include <utility>
#include <tuple>
#include <iostream>

using namespace std;

template <typename T>
using listIter = typename list<T>::iterator;

/*!@class DouglasPeucker
 * @brief Line simplification algorithm.
 */
template<typename T>
class DouglasPeuckerAbstract{
public:
  // No-arg constructor.
  DouglasPeuckerAbstract(){}
  DouglasPeuckerAbstract(list<T>& line) : _line(line){}

  list<T>& getLine(){ return _line; }
  const list<T>& getLine() const{ return _line; }
  
  void simplify(double epsilon){
    listIter<T> endIter = _line.end();
    _simplify(epsilon, _line.begin(), --endIter);
  }

protected:
  virtual double _distance(const T& p1, const T& p2) const = 0;
  virtual double _pointSegmentDistance(const T& p1, const T& p2, const T& p) const = 0;

  /**
   * @param i1 index of first point.
   * @param i2 index of second point.
   * @param pMaxDist pointer to the maximum distance of _line[return index].
   * @return the index of the point farthest fromthe segment (t1,t2).
   */
  listIter<T> _getFarthestPointFromSegment(listIter<T> it1,
					   listIter<T> it2,
					   double* pMaxDist = nullptr){
    listIter<T> maxIt = it1;  // Keep track of the point with the maximum distance.
    maxIt++;
    double maxDist = _pointSegmentDistance(*it1, *it2, *maxIt);

    listIter<T> it = it1;
    it++;
    while(it != it2){
      double dist = _pointSegmentDistance(*it1, *it2, *it);
      
      if(dist > maxDist){
	maxIt = it;
	maxDist = dist;
      }

      it++;
    }
    
    if(pMaxDist){ *pMaxDist = maxDist; }
    return maxIt;
  }

  void _simplify(double epsilon,
		 listIter<T> it1,
		 listIter<T> it2){
    if(distance(it1, it2) <= 1) return;
    
    double dist = 0.0f;
    listIter<T> index = _getFarthestPointFromSegment(it1, it2, &dist);

    // If the farthest point exceeds epsilon, recurse, with index as pivot.
    if(dist > epsilon){
      _simplify(epsilon, it1, index);
      _simplify(epsilon, index, it2);
    }else{
      // Delete everything except it1 and it2.
      auto it = it1;
      it++;
      for(; it != it2; ){
	_line.erase(it++);
      }
    }
  }
  
protected:
  list<T> _line;
};

using p2d = tuple<double, double>;

struct p2dAccessor{
  inline static double getX(const p2d& p){
    return get<0>(p);
  }

  inline static double getY(const p2d& p){
    return get<1>(p);
  }
};

template <typename T=p2d, typename TAccessor2D=p2dAccessor>
class DouglasPuecker2D final : public DouglasPeuckerAbstract<T>{
 public:
  using DouglasPeuckerAbstract<T>::DouglasPeuckerAbstract;
  virtual double _distance(const T& p1,
			   const T& p2) const override{
    double x2 = TAccessor2D::getX(p1) - TAccessor2D::getX(p2);
    double y2 = TAccessor2D::getY(p1) - TAccessor2D::getY(p2);
    return std::sqrt(x2*x2 + y2*y2);
  }
  
  virtual double _pointSegmentDistance(const T& p1,
				       const T& p2,
				       const T& p) const override{
    // Ax + By + C = 0. A = slope, B = 1, C = (-y1+slope*x1).
    // (m, n) is in itp.
    double slope = (TAccessor2D::getY(p2) - TAccessor2D::getY(p1))/
      (TAccessor2D::getX(p2) - TAccessor2D::getX(p1));
    double A = slope;
    double Am = A*TAccessor2D::getX(p);
    double B = -1;
    double Bn = B*TAccessor2D::getY(p);
    double C = TAccessor2D::getY(p1) - slope*TAccessor2D::getX(p1);

    return std::abs(Am + Bn + C)/std::sqrt(A*A+B*B);
  }
};
