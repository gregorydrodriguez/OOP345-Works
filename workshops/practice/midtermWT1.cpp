// #include <iostream>

// using namespace std;

// enum Vals { AV = 1, BV = 2, CV = 3 };

// struct Foo{
//   Vals val{};

//   Foo& goo() {
//     if (val == AV)
//       val = BV;
//     if (val == BV)
//       val = CV;
//     if (val == CV)
//       val = AV;
//     return *this;
//   }
//   Foo& boo(){
//     if (val == AV)
//       val = CV;
//     if (val == BV)
//       val = AV;
//     if (val == CV)
//       val = BV;
//     return *this;
//   }
// };

// ostream& operator<<(ostream& os, const Foo& f){
//   os << f.val << endl;
//   return os;
// }

// int main(){

//   Foo f{AV};
//   cout << f.goo();
//   cout << f.boo();
//   cout << (f.goo()).boo();
//   cout << (f.boo()).goo(); // 1221
// }

#include <iostream>
using namespace std;

struct Foo{
  void goo(){
    cout << "Hi!" << endl;
  }
  auto moo(unsigned& v) -> decltype(v / 0.0) {
    return v / 2.0;
  }
  auto boo(unsigned&& v) -> decltype(v * 0.0) {
    return v * 2.0;
  }
};
int main() {
  unsigned a[3] = { 1, 3, 5 };
  cout << (a[0] + a[1]) << endl; // 4 \n
  cout << (a[2]) << endl; // 5 \n
  cout << sizeof(a) / sizeof(a[0]) << endl; // 3 \n
  Foo f;
  f.goo(); // "Hi!" \n
  cout << f.moo(a[1]) << endl; // 1.5 \n
  cout << f.boo(8) << endl; // 16 (This is a double) \n
}

// #include <iostream>
// using namespace std;

struct thing {
    std::string name;
    std::string operator*(unsigned v) {
        return name += to_string(v);
    }
    operator string() const { return name; }
};
template <typename T, typename S>
auto foo(T& v1, S v2) -> decltype(v1 * v2) {
    return v1 * v2;
}
template <>
auto foo(thing& v1, unsigned v2) -> decltype(v1 * v2) {
    for (auto i = 0u; i < v2; ++i)
        v1.name += "E";
    return v1 * v2;
}
int main() {
    unsigned x{1}, y{5};
    double a{1.1}, b{2.2};
    thing c{"NA"}, d{"CL"};
    cout << foo(x, y) << endl;  // 5 \n
    cout << foo(x, a) << endl;  // 1.1 \n
    cout << foo(a, b) << endl;  // 2.42 \n
    cout << foo(c, x) << endl;  // NAE1 \n
    cout << foo(d, y) << endl;  // CLEEEEE5 \n
}