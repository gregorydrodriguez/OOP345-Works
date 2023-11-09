#include "A.h"

/*
  this supposed to allow something like:
  double x = 2.0;
  A a = { 2.1 }
  x += a;
  converts A to double, modifies double& val reference, then return that reference
  RETURN TYPE SHOULD JUST BE double& ?!?!?!?!?!?
*/
decltype(A().getValue()) operator+=(double& val, const A& other) {
    return val += other.getValue();
}