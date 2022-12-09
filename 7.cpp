#include <iostream>
#include <string>
#include <vector>

struct MyStruct
{
    std::string Name;
    std::string Surname;
    int Age;
};

template <typename T>

int f_middle(std::vector<T>& elem, int left, int right) {
    int middle = left + (right - left) / 2;
    auto middle_elem = elem[middle];
    int i = left, j = right;
    while (i <= j) {
        while (elem[i] < middle_elem) {
            i++;
        }
        while (elem[j] > middle_elem) {
            j--;
        }
        if (i <= j) {
            auto temp = elem[i];
            elem[i] = elem[j];
            elem[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

template <typename T>

void dar_sort(std::vector<T>& elem, int left, int right) {
    if (left < right) {
        int middle = f_middle(elem, left, right);
        dar_sort(elem, left, middle - 1);
        dar_sort(elem, middle, right);
    }
}



int main()
{
    int a = 0;
    std::vector <MyStruct> db;
    std::vector <MyStruct> dbmir;
    std::vector <int> Ages;
    std::vector <std::string> Names;
    std::vector <std::string> Surnames;
    std::string Surname, Name;
    int Age;
    MyStruct dbin;
    int Choise = 0;
    while (1) {
        std::cout << "What do you wanna do?\n1. Sort double\n2. Sort int\n3. Sort char\n4. Int arr for 5-7\n5. Sort arr by age\n6. Sort arr by name\n7. Sort arr by surname\n8. Esc\n";
        std::cin >> Choise;
        switch(Choise)
        {
        case 1:
        {
            std::vector <double> Doubles;
            std::cout << "Int arr, in the end inp -1 ";
            while (true) {
                double temp;
                std::cin >> temp;
                if (temp == -1) break;
                Doubles.push_back(temp);
            }
            dar_sort(Doubles, 0, (Doubles.size() - 1));
            for (auto i : Doubles) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
            break;
        }
        case 2:
        {
            std::vector <int> Ints;
            std::cout << "Int arr, in the end inp -1 ";
            while (true) {
                int temp;
                std::cin >> temp;
                if (temp == -1) break;
                Ints.push_back(temp);
            }
            dar_sort(Ints, 0, (Ints.size() - 1));
            for (auto i : Ints) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
            break;
        }
        case 3:
        {
            std::vector <char> Chars;
            std::cout << "Int arr, in the end inp A ";
            while (true) {
                char temp;

                std::cin >> temp;
                if (temp == 'A') break;
                Chars.push_back(temp);
              
            }
            dar_sort(Chars, 0, (Chars.size() - 1));
            for (auto i : Chars) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "Inp arr of peoples like \"Name, Surnmae, Age\" ";
            while (a == 0)
            {
                std::cin >> Name >> Surname >> Age;
                if (Age == -1) break;
                dbin.Name = Name;
                dbin.Surname = Surname;
                dbin.Age = Age;
                db.push_back(dbin);
            }
            break;
        }
        case 5:
        {
            dbmir = db;
            for (int i = 0; i < db.size(); i++) Ages.push_back(db[i].Age);
            dar_sort(Ages, 0, (Ages.size() - 1));
            for (int i = 0; i < Ages.size(); i++) {
                for (int j = 0; j < dbmir.size(); j++) {
                    if (dbmir[j].Age == Ages[i]) {
                        std::cout << dbmir[j].Name << " " << dbmir[j].Surname << " " << db[j].Age << std::endl;
                        dbmir[j].Age = -1;
                    }
                }
            }
            break;
        }
        case 6:
        {
            dbmir = db;
            for (int i = 0; i < db.size(); i++) Names.push_back(db[i].Name);
            dar_sort(Names, 0, (Names.size() - 1));
            for (int i = 0; i < Names.size(); i++) {
                for (int j = 0; j < dbmir.size(); j++) {
                    if (dbmir[j].Name == Names[i]) {
                        std::cout << dbmir[j].Name << " " << dbmir[j].Surname << " " << db[j].Age << std::endl;
                        dbmir[j].Name = -1;
                    }
                }
            }
            break;
        }
        case 7:
        {
            dbmir = db;
                for (int i = 0; i < db.size(); i++) Surnames.push_back(db[i].Surname);
                dar_sort(Surnames, 0, (Surnames.size() - 1));
                for (int i = 0; i < Surnames.size(); i++) {
                    for (int j = 0; j < dbmir.size(); j++) {
                        if (dbmir[j].Surname == Surnames[i]) {
                            std::cout << dbmir[j].Name << " " << dbmir[j].Surname << " " << db[j].Age << std::endl;
                            dbmir[j].Surname = -1;
                        }
                    }
                }
            break;
        }
        case 8: return 0;
        default: break;
        }
    }
 
}