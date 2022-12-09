#include <iostream>
#include <bitset>
int main()
{
     // 1
    std::cout << "1" << std::endl << "Vinokurov Daniil Alexandrovich, 221-351" << std::endl;
    std::cout << "2" << std::endl << "min int = -2147483648, max int = 2147483647, size of int = 2 " << std::endl;
    
    // 2
    std::cout << "min int = "            << sizeof(int)            << ", max int = "            << int(0b10000000000000000000000000000000)                                                                                                  << ", size of int = "            << int(0b01111111111111111111111111111111)                                                                                                 << std::endl;
    std::cout << "min unsigned int = "   << sizeof(unsigned int)   << ", max unsigned int = "   << int(0b100000000000000000000000000000000)                                                                                                 << ", size of unsigned int = "   << int(0b011111111111111111111111111111111)                                                                                                << std::endl;
    std::cout << "min short = "          << sizeof(short)          << ", max short = "          << int(0b1000000000000000)                                                                                                                  << ", size of short = "          << int(0b0111111111111111)                                                                                                                 << std::endl;
    std::cout << "min unsigned short = " << sizeof(unsigned short) << ", max unsigned short = " << int(0b10000000000000000)                                                                                                                 << ", size of unsigned short = " << int(0b01111111111111111)                                                                                                                << std::endl; 
    std::cout << "min long = "           << sizeof(long)           << ", max long = "           << int(0b1000000000000000000000000000000000000000000000000000000000000000)                                                                  << ", size of long = "           << int(0b01111111111111111111111111111111)                                                                                                 << std::endl;
    std::cout << "min long long = "      << sizeof(long long)      << ", max long long= "       << int(0b10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)  << ", size of long long = "      << int(0b01111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111) << std::endl;
    std::cout << "min double = "         << sizeof(double)         << ", max double = "         << int(0b10000000)                                                                                                                          << ", size of double = "         << int(0b01111111)                                                                                                                         << std::endl;
    std::cout << "min char = "           << sizeof(char)           << ", max char = "           << int(0b10000000)                                                                                                                          << ", size of char = "           << int(0b01111111)                                                                                                                         << std::endl;
    std::cout << "min bool = "           << sizeof(bool)           << ", max bool = "           << int(0b1)                                                                                                                                 << ", size of bool = "           << int(0b0)                                                                                                                                << std::endl;
    
    
    
     // 3
    std::cout << "Введите число: ";
    int num;
    std::cin >> num;
    
    //3.1
    int num1 = num , num2 = num;
    int arr[32];
    for (int i = 0 ; i < 32 ; i ++)
    {
        if (num1 % 2 == 0 ) arr[i] = 0;
        else arr[i] = 1;
        num1 /= 2;
    }
    bool a = false;
    std::cout << std::endl << "В бинарном виде: ";
    for (int i = 31 ; i >= 0 ; i --)
    {
        if (arr[i] == 1 || a == true)
        {
            a = true;
            std::cout << arr[i]; 
        }
    }
    
    //3.2
    std::cout << std::endl << "В шестнадцатиричном виде: ";
    for (int i = 0 ; i < 32 ; i ++){arr[i] = 0;}
    for (int i = 0 ; i < 32 ; i ++)
    {
        if (num2 % 16 > 9 ) arr[i] = num2 % 16 + 55;
        else arr[i] = num2 % 16;
        num2 /= 16;
    }
    a = false;
    char c;
    for (int i = 31 ; i >= 0 ; i --)
    {
        if (arr[i] != 0 || a == true)
        {
            a = true;
            if (arr[i] > 9)
            {
                c = arr[i];
                std::cout << c; 
            }
            else 
            {
                std::cout << arr[i];
            }
        }
    }
    
    //3.3
    std::cout << std::endl << "bool " << bool(num) << std::endl; // %2
    
    //3.4
    std::cout << "double " << double(num) << std::endl;
    
    //3.5
    std::cout << "char " << char(num) << std::endl;    
    
    //4 
    std::cout << "Введите коэффициенты a * x = b: ";
    double n, m;
    std::cin >> n >> m;
    std::cout << n << " * x = " << m << std::endl << "x = " << m << " / " << n << std::endl;
    std::cout << "x = " << m / n << std::endl << "Ответ: " << double(m) / double(n) << "." << std::endl;
    
    // 5
    std::cout << "Введите координаты отрезка на прямой: ";
    double x , z;
    std::cin >> x >> z;
    std::cout << "Середина отрезка находится в точке с координатой " << (x + z) / 2 << ".";
}
