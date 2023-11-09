#include <iostream>
template <typename T>
T* insertAtEnd(T* array, const size_t size, const T item) {
    T* newArray = new T[size + 1];
    for (auto i = 0u; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = nullptr;
    newArray[size] = item;
    return newArray;
}
template <>
char* insertAtEnd<char>(char* array, const size_t size, const char item) {
    char* newArray = new char[size + 2];
    for (auto i = 0u; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = nullptr;
    newArray[size] = item;
    newArray[size + 1] = '\0';
    return newArray;
}
int main() {
        int* arrI = nullptr;
        arrI = insertAtEnd(arrI, 0, 1);   // 1
        arrI = insertAtEnd(arrI, 1, 5);   // 1, 5
        arrI = insertAtEnd(arrI, 2, -3);  // 1, 5, -3
        for (size_t i = 0; i < 3; i++) {
            std::cout << arrI[i] << " ";
        }
        std::cout << std::endl;
        delete[] arrI;

    {
        double* arrD = nullptr;
        arrD = insertAtEnd(arrD, 0, 1.2);  // 1.2
        arrD = insertAtEnd(arrD, 1, 2.3);  // 1.2, 2.3
        arrD = insertAtEnd(arrD, 2, 3.4);  // 1.2, 2.3, 3.4
        for (size_t i = 0; i < 3; i++) {
            std::cout << arrD[i] << " ";
        }
        std::cout << std::endl;
        delete[] arrD;
    }
    {
        char* arrC = nullptr;
        arrC = insertAtEnd(arrC, 0, 'a');  // a\0
        arrC = insertAtEnd(arrC, 1, 'b');  // ab\0
        arrC = insertAtEnd(arrC, 2, 'c');  // abc\0
        std::cout << arrC << std::endl;
        delete[] arrC;
    }
    return 0;
}