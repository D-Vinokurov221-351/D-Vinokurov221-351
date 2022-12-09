#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

bool isLetter(char it) {
	if ((it >= 65 && it <= 90) || (it >= 97 && it <= 122))  return true;
	else return false;
}

std::map <std::string, int> countWords(std::string filename, int& wordsCount) {
	std::map<std::string, int> words;
	std::string word;
	std::string error;
	std::ifstream input(filename);
	if (input.is_open()) {
		while (input >> word) {
			if (isLetter(word[0])) {
				while (!isLetter(word[word.length() - 1])) word.erase(word.length() - 1);
				word = tolower(word.length() - 1);
				if (words.find(word) == words.end()) words[word] = 1;
				else words[word]++;
				wordsCount++;
			}
		}
		return words;
	}
	else 
	{
	    words["hfdhjdfghj"] = 1;
	}
	input.close();
	wordsCount = 0;
}

int main() {
	std::map<std::string, int> words;
	std::ofstream out;
	std::string filename = "";
	int count = 0;
	int option;
	while (true) {
		std::cout << "Choises:\n1. Select file\n2. Cout statistic\n3. Esc\nInp choise: ";
		std::cin >> option;
		switch (option) {
		case 1:
			std::cout << "Inp file full name: ";
			std::cin >> filename;
			words = countWords(filename, count);
			if (words.find("hfdhjdfghj") != words.end())
			{
			    std::cout << "File couldn`t be found"<<"\n";
			}
			break;
		case 2:
			out.open("D:\\results.txt");
			if (out.is_open()) {
				out << "Words in all: " << count << std::endl;
				for (auto word : words) out << word.first << ": " << word.second << ", " << word.second / (double)count * 100.0 << "%\n";
				out.close();
			}
			std::cout << "Output finished. The results in: D:\\results.txt\n";
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}
}