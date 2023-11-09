#ifndef A_H
#define A_H
struct A {
   public:
    double m_val;
   public:
    // Return type should be A&, and should return "this"
    // This overload should also be implemented in a .cpp file
    A operator+=(const A& other) {
        this->m_val += other.m_val;
        // return this;
    }
    double getValue() const {
        return m_val;
    }
};

/*
  this is supposed to allow something like:
  double x = 2.0;
  A a = { 2.1 }
  x += a;
  converts A to double, modifies double& val reference, then return that reference
  RETURN TYPE SHOULD JUST BE double& ?!?!?!?!?!?
*/
decltype(A().getValue()) operator+=(double& val, const A&);

template <typename T /*, double N*/>
// Floating-point template parameters aren't allowed?
// The second parameter is also never used
T process(const T* data/*, size_t size*/) {
    T sum{};
    for (const auto& elem : data)
        // data is a pointer and not an array
        // can't use range-based for loop on something without begin/end functions defined
        // compilers define those automatically for static arrays (int arr[] = { 1, 2, 3 })
        // but can't for dynamically allocated arrays/pointers, so the loop doesn't know how big it is
        sum += elem;
    return sum;
}
#endif

template <typename T, char* x>
struct B { };