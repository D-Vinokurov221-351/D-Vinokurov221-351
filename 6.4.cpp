#include <iostream>
#include <deque>
#include <set>

struct _test_data {
	std::string username;
	uint16_t mark;
};

int main() {
	_test_data test;
	std::deque<_test_data> tests;
	std::set<std::string> tests_usernames;
	int option;
	while (true) {
		std::cout << "Inp choise:\n1. Input\n2. Output\n3. Esc\nYour choise: ";
		std::cin >> option;
		switch (option) {
		case 1:
			std::cout << "Input Name and Mark:\nName: ";
	        std::cin >> test.username;
			std::cout << "Mark: ";
			std::cin >> test.mark;
			if (tests_usernames.find(test.username) == tests_usernames.end()) {
				tests_usernames.insert(test.username);
				tests.push_back(test);
			}
			else std::cout << "Error:this account done test already\n";
			break;
		case 2:
			for (auto x : tests) {
				std::cout << "Name: ";
				std::cout << x.username;
				std::cout << "\nMark: " << x.mark << std::endl;
			}
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}
}