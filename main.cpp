//#include <iostream>
//#include <cstdlib>
//#include <cmath>
//#include <iomanip>

#include "iostream"
#include "Vector0.h"

using namespace std;

int main() {
    auto array1 = new double[1];
    array1[0] = 0;
    auto array2 = new double[2];
    array2[0] = 1;
    array2[1] = 1;
    auto array3 = new double[2];
    array3[0] = 2;
    array3[1] = 2;

    // Тесты операторов ввода и вывода для вектора
    /*{
        cout << "Тест операторов ввода и вывода\n";
        Vector0 test_vector0;
        Vector0 test_vector1(2, array2); // 1 1
        cin >> test_vector0;
        cin >> test_vector1;
        cout << test_vector0 << test_vector1 << endl;
    }*/

    // Другие тесты для вектора
    {
        Vector0 test_vector2(1, array1); // 0
        Vector0 test_vector3(1, array1); // 0
        Vector0 test_vector4(2, array3); // 2 2
        if (test_vector2 == test_vector3)
            cout << "Operator '==' works. ";
        else if (test_vector2 != test_vector4)
            cout << "Operator '!=' works. ";
        else
            cout << "Operators are broken. ";
        cout << endl;

        // Тесты оператора присваивания
        Vector0 test_vector5(1, array1); // 0
        Vector0 test_vector6(2, array3); // 2 2
        Vector0 test_vector7;
        test_vector7 = test_vector5;
        cout << test_vector7; // ( 0 )
        test_vector7 = test_vector6;
        cout << test_vector7; // ( 2 2 )
        test_vector7 = test_vector7;
        cout << test_vector7; // ( 2 2 )
        Vector0 test_vector8(2, array2); // 1 1
        Vector0 test_vector9(test_vector8);
        cout << test_vector9 << endl; // ( 1 1 )

        // Сложение
        test_vector9 += test_vector7;
        cout << test_vector9; // ( 3 3 )
        cout << test_vector9 + test_vector6 << endl; // ( 5 5 )
        //cout << test_vector9 + test_vector2; // ( 3 3 ) + Error

        // Умножение
        test_vector9 *= 5;
        cout << test_vector9; // ( 15 15 )
        cout << test_vector9 * 5 << endl; // ( 75 75 )

        // Вычитание
        cout << test_vector9 - test_vector8 << endl; // ( 14 14 )

        Vector0 test_vector10(test_vector9);
    }

    // Тест работы деструктора для вектора
    {
        Vector0 test_vector0;
        if (test_vector0.HowMany() == 1)
            cout << "\n\tДеструктор работает (честно).\n";
        else
            cout << "\n\tДеструктор сломался.\n";
    }
    cout << "Вектор всё\n\n";
    cout << endl << "That's all, folks!" << endl;
    return 0;
}
