﻿// Test_LED_efekt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int8_t tristate_square8(uint8_t x, uint8_t pulsewidth, uint8_t attdec) {
    int8_t a = 127;
    if (x > 127) {
        a = -127;
        x -= 127;
    }

    if (x < attdec) { //inc to max
        return (int16_t)x * a / attdec;
    }
    else if (x < pulsewidth - attdec) { //max
        return a;
    }
    else if (x < pulsewidth) { //dec to 0
        return (int16_t)(pulsewidth - x) * a / attdec;
    }
    return 0;
}
int main()
{
    for (int i = 0; i < 255; i++)
    {
     int a = tristate_square8(i, 90, 15);
    std::cout << a ;
    }
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
