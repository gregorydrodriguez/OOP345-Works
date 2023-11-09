#include <iostream>

#include "A.h"

using namespace std;

int main() {
    int arrI[5]{0, 1, 2, 3, 4/*, 5*/};
    // Initialized with excess elements
    //compile, process func lacks tem param
    //for it to use here. process<int>(arrI)
    cout << process(arrI) << endl;
    A arrA[5]{{1.2}, {2.3}, {3.4}, {4.5}};
    cout << process(arrA) << endl;
    // No left shift operator overload for A
}