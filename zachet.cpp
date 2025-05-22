#include <iostream>
#include "zachet.hpp"

void func() {
    int* array = new int[16];
    Defer to_be_deleted([array]() {
        delete[] array;
        std::cout << "Массив удалён! Оно работает!!!\n"; 
    });
    //some logic with array 
}

int main() {
    func();  
    return 0;
}