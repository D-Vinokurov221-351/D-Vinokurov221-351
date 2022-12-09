#include <iostream>
#include <string>
#include <limits>
#include <list>

void input() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool compare(std::string st1, std::string st2) {
	int num1 = std::stoi(st1.substr(0, st1.find(" ")).erase(st1.find("-"), 1));
	int num2 = std::stoi(st2.substr(0, st2.find(" ")).erase(st2.find("-"), 1));

	return num1 < num2;
}

int main() {
	std::string s;
	std::string groupname = "";
	std::list<std::string> students;
	int option;
	while (true) {
		std::cout << "Inp choise:\n1. Add more\n2. Cout students\n3. Exit\nYour choise: ";
		std::cin >> option;
		switch (option) {
		case 1:
			input();
			std::cout << "Inp group and surname: ";
			std::getline(std::cin, s);
			students.push_back(s);
			break;
		case 2:
			students.sort(compare);
			for (auto student : students) {
				if (groupname != student.substr(0, student.find(" "))) {
					groupname = student.substr(0, student.find(" "));
					std::cout << groupname << std::endl;
				}
				std::cout << student.substr(student.find(" ")) << std::endl;
			}
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}
}