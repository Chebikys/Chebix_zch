ЗАДАНИЕ:
Вариант 1
Defer
Реализуйте класс Defer, non-movable, non-copyable, non-copyable, non-default-constructable
Его логика:
- При конструировании принимает лямбда-функцию
- При разрушении вызывает ее
Пример использования

void func() {
    int* array = new int[16];
    Defer to_be_deleted([array]() {
        delete[] array;
    });
    //some logic with array
}

РЕШЕНИЕ:
Я создала 2 файла: zachet.hpp и zachet.cpp. Класс реализован в .hpp файле, в .cpp файле написан пример использования + main() функция 
Что делать с моим кодом:
1. открыть термирнал и скомпилировать .cpp файл: g++ -o testfile zachet.cpp (testfile - просто запускаемый файлик, можно назвать по другому)
2. запустить ./testfile
3. должно вывестись Массив удалён! Оно работает!!!
