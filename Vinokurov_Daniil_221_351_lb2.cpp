#include <iostream>

void task1()
{
    int num;
    std::cout << "What number are you want?" << std::endl;
    std::cin >> num;
    for (int i = 0 ; i <= num ; i ++)
    {
        for (int j = 0 ; j <= i ; j ++) std::cout << j;
        std::cout << std::endl;
    }
}

void task2() // max true num = 67!
{
    int num;
    std::cout << "What number are you want?" << std::endl;
    std::cin >> num;
    long long int arr[num][num];
    for(int i = 0 ; i < num ; i ++)
    {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }
    for(int i = 0 ; i < num ; i ++)
    {
        for (int j = 1 ; j < i ; j ++)
        {
            if (j <= i/2) arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            else arr[i][j] = arr[i][i-j];
        }
    }
    for (int i = 0 ; i < num ; i ++)
    {
        std::cout << "K = " << i << "; C = " << arr[num-1][i] << ";" << std::endl;
    }
    
}

void task3()
{
    long long int sum = 0;
    int num = 1, amount = 0;
    std::cout << "What number are you want? To stop program enter (0)!" << std::endl;
    while (num != 0)
    {
        std::cin >> num;
        sum += num;
        amount ++;
    }
    amount --;
    std::cout << "The midle arithmetic is: " << double(sum) / amount << std::endl;
}




int main()
{
    int choice;
    while (true)
    {
        std::cout << "What are you wonna do?" << std::endl << "1.triangle" << std::endl << "2.binomal" << std::endl << "3.midle arithmetic" << std::endl << "4.exit" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
            case 1:
            {
                task1();
                break;
            }
            case 2:
            {
                task2();
                break;
            }
            case 3:
            {
                task3();
                break;
            }
            default: return 0;
        }
    }
}
