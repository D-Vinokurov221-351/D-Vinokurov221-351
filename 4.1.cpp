#include <iostream>

void func1(char *text, int &length)
{
std::cout << "Int your line: " << std::endl;
char first;
for (int i = 0 ; i < 255; i ++)
{
text[i] = '0';
}
int i = 0;
std::cin.get(first);
text[i] = first;
while (text[i] != '.')
{
i++;
std::cin.get(text[i]);
}
text[i] = '0';
length = i - 1;
}

void func2(char *text, int &length)
{
int j = length;
int i = 1;
bool end = true;
while(i < j)
{
while(text[i] == ' ' || text[i] == '0')
{
i ++;
}
while(text[j] == ' ' || text[j] == '0')
{
j --;
}

if (text[i] < 97) text[i] += 40;
if (text[j] < 97) text[j] += 40;

if (text[i] == text[j])
{
    i ++;
    j --;
}
else
{
    i = j + 2;
    end = false;
}
}
if (end) std::cout << std::endl << "palindrom" << std::endl;
else std::cout << std::endl << "not palindrom" << std::endl;
}

void func3(char *text , int &length)
{
int key;
std::cout << "Int key 1 - 25: ";
std::cin >> key;
for (int i = 0 ; i <= length; i ++)
{
if (text[i] != 32)
{
if (int(text[i]) + key > 122)
{
text[i] -= (26-key);
}
else text[i] += key;
}
}
}

void func4(char *text , int &length)
{
bool in = false;
for (int i = 1 ; i < length; i ++)
{
if (in)
{
if (text[i] != 34)
{
std::cout << text[i];
}
else
{
in = false;
}
}
else
{
if (text[i] == 34)
{
in = true;
}
}
}
std::cout << std::endl;
}

int main()
{
int length = 0, choise;
char text[255];
while (true)
{
std::cout << "1.input 2.palindrom 3.encript 4.output""";
std::cin >> choise;
switch(choise)
{
case 1:
{
func1(text , length);
std::cout << std::endl;
for (int i = 1 ; i <= length; i ++)
{
std::cout << text[i];
}
std::cout << std::endl;
break;
}
case 2:
{
func2(text, length);
break;
}
case 3:
{
func3(text , length);
std::cout << std::endl;
for (int i = 0 ; i <= length; i ++)
{
std::cout << text[i] << " ";
}
std::cout << std::endl;
break;
}
case 4:
{
func4(text , length);
break;
}
default: return 0;
}
}
}