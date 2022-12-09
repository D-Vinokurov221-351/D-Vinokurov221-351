#include <iostream>

void task1()
{
    int length;
    std::cout << "The length of array is: " ;
    std::cin >> length;
    int arr[length];
    std::cout << "Enter all array" << std::endl ; 
    for (int i = 0 ; i < length; i ++)
    {
        std::cin >> arr[i];
    }
    
    bool end = false;
    while (!end)
    {
        end = true;
        for (int i = 1 ; i < length; i ++)
        {
            if (arr[i-1] > arr[i])
            {
                int x = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = x;
                end = false;
            }
        }
    }
    for (int i = 0 ; i < length; i ++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void task2() 
{
    int length;
    std::cout << "The length of array is: " ;
    std::cin >> length;
    int arr[length];
    std::cout << "Enter all array" << std::endl ; 
    char x;
    for (int i = 0 ; i < length; i ++)
    {
        arr[i] = 0;
    }
    for (int i = 0 ; i < length; i ++)
    {
        std::cin >> x;
        arr[x-97] ++;
    }
    for (int i = 0 ; i < length; i ++)
    {
        while (arr[i] != 0)
        {
            arr[i] --;
            std::cout << char(i + 97) << " ";
        }
    }
    std::cout << std::endl;
}

int sort(int *arr, int &left, int &right)
{
    int x = 0, z = 0;
    
    int middle = (right + left) / 2;
    if (right - left == 1)
    {
        if (arr[right] < arr[left])
        {
            x = arr[right];
            arr[right] = arr[left];
            arr[left] = x;
        }
        return 0;
    }
    else if (right == left) return 0;
    sort(arr, left, middle);
    middle++;
    sort(arr, middle, right);
    middle--;
    
    int arr1[middle - left + 1];
    int arr2[right - middle];
    for (int i = 0 ; i < middle - left + 1 ; arr1[i] = arr[i + left], i ++)
    for (int i = 0 ; i < right - middle ; arr2[i] = arr[i + middle + 1], i ++)
    
    x = 0;
    for (int i = left ; i <= right ; i ++)
    {
        if ((arr1[x] > arr2[z] && z < right - middle) || (x > middle - left))
        {
            arr[i] = arr2[z];
            z++;
        }
        else
        {
            arr[i] = arr1[x];
            x++;
        }
    }
    return 0;
    
}

void task3()
{
    int length;
    std::cout << "The length of array is: " ;
    std::cin >> length;
    int arr[length];
    std::cout << "Enter all array" << std::endl ; 
    for (int i = 0 ; i < length; i ++)
    {
        std::cin >> arr[i];
    }
    
    int left = 0, right = length - 1;
    
    sort(arr, left, right);
    
    for (int i = 0 ; i < length; i ++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}




int main()
{
    int choice;
    while (true)
    {
        std::cout << "What are you wonna do?" << std::endl << "1.пузырь" << std::endl << "2.подсчет" << std::endl << "3.слияние" << std::endl << "4.выход" << std::endl;
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
