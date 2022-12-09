#include <iostream>
#include <cstring>
#include <string> 
#include <fstream> 
#include <bitset>

std::string file_format(const std::string file_path_full) {   // выводим расширение
    int number;
    std::string abc;
    number = file_path_full.find_first_of('.');
    abc = file_path_full.substr(number, file_path_full.size()-number);
    return abc;
}

std::string file_name(const std::string file_path_full) { //  выводим название
    int number, number1;
    std::string abc;
    number = file_path_full.find_last_of('.');
    number1 = file_path_full.find_last_of("\\");
    int a = file_path_full.size() - number1 - 1 - (file_path_full.size() - number);
    abc = file_path_full.substr(number1+1, a);
    return abc;
}

std::string file_path(const std::string file_path_full) { // выводим расположение
    int number;
    std::string abc;
    number = file_path_full.find_last_of("\\");
    abc = file_path_full.substr(0, number);
    return abc;
}

char file_disk(const std::string file_path_full) {   // выводим название диска
    return file_path_full.at(0);
}

std::string file_rename(std::string file_path_full) { // переименовываем файл
    std::string new_name;
    std::cin >> new_name;
    file_path_full = file_path_full.substr(0, file_path_full.find_last_of("\\")+1) + new_name + file_format(file_path_full);
    return file_path_full;
}

void file_copy(const std::string file_path_full) { // копируем файл 
    int number;
    std::fstream fs;
    std::fstream out;
    std::string s1;
    number = file_path_full.find_first_of('.');
    fs.open(file_path_full, std::fstream::in);
    out.open(file_path_full.substr(0, number) + "_copy" + file_path_full.substr(number, file_path_full.size() - number),std::fstream::out);
    while (!fs.eof()) {
        fs >> s1;
        out << s1 << '\n';
    }
}

int main()
{
    std::string file_path_name;
    int a = 0;
    int choise;
    while (a == 0) {
        std::cout << "What do you wanna do?\n1. Inp\n2. task 1\n3. task 2\n4. task 3\n5. task 4\n6. task 5\n7. task 6\n8. Exit\n";
        std::cin >> choise;
        switch (choise)
        {
        case 1:
            std::cout << "Int file_path_name: "; std::cin >> file_path_name;
            break;
        case 2:
            std::cout << file_format(file_path_name) << std::endl;
            break;
        case 3:
            std::cout << file_name(file_path_name) << std::endl;
            break;
        case 4:
            std::cout << file_path(file_path_name) << std::endl;
            break;
        case 5:
            std::cout << file_disk(file_path_name) << std::endl;
            break;
        case 6:
            std::cout << file_rename(file_path_name) << std::endl;
            break;
        case 7:
            file_copy(file_path_name);
            break;
        default:
            break;
        }


    }
}
