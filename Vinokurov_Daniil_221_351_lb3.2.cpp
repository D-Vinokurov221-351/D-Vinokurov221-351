#include

void task1(int &arr, int &arr_size)
{
if (arr != nullptr) delete [] arr;
stdcout  Int the length of array   stdendl;
stdcin  arr_size;

arr = new int[arr_size];

for (int i = 0 ; i  arr_size; i ++)
{
    stdcin  arr[i];
}
}

void task2(int arr, int &arr_size)
{
stdcout  Your array is  ;
for (int i = 0 ; i  arr_size; i ++)
{
stdcout  arr[i]   ;
}
stdcout  stdendl;

}

void task3(int arr, int &arr_size)
{
int arr_sum[arr_size];
for (int i = 0 ; i  arr_size ;i ++)
{
arr_sum[i] = 0;
}

for (int i = 0 ; i  arr_size; i ++)
{
    int last_char;
    long long big_boy = 1;
    for (int j = 1 ; j  11 ; j ++)
    {
        if ((arr[i]  big_boy  0) && (arr[i]  big_boy  10)) 
        {
            last_char = j;
        }
        big_boy = 10;
    }
    long long int max = 1;
    for (int j = 1 ; j  last_char ; j ++)
    {
        max = 10;
    }
    if (last_char % 2 == 0) big_boy = 1;
    else big_boy = 10;
    while (max = big_boy) 
    {
        arr_sum[i] += (arr[i]  big_boy) % 10;
        big_boy = 100;
    }
}
bool end = false;
while(!end)
{
    end = true;
    for (int i = 1 ; i  arr_size; i ++)
    {
        if (arr_sum[i]  arr_sum[i-1])
        {
            int x = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = x;
            x = arr_sum[i-1];
            arr_sum[i-1] = arr_sum[i];
            arr_sum[i] = x;
            end = false;
        }
    }
}
}

void task4(int arr, int &arr_size)
{
bool end = false;
while (!end)
{
end = true;
for (int i = 1 ; i  arr_size ; i ++)
{
if (arr[i] % 10 = arr[i-1] % 10)
{
if (arr[i] % 10 == arr[i-1] % 10)
{
if (arr[i]  arr[i-1])
{
int x = arr[i-1];
arr[i-1] = arr[i];
arr[i] = x;
}
}
else
{
int x = arr[i-1];
arr[i-1] = arr[i];
arr[i] = x;
}
end = false;
}
}
}
}

int main()
{
int choice;
int arr_size = 0;
int arr = nullptr;
while (true)
{
stdcout  What are you wonna do  stdendl  1.Input  stdendl  2.Output  stdendl  3.Sort po 2-m  stdendl  4.Sort_last  stdendl;
stdcin  choice;
switch (choice)
{
case 1
{
task1(arr,arr_size);
break;
}
case 2
{
task2(arr,arr_size);
break;
}
case 3
{
task3(arr,arr_size);
break;
}
case 4
{
task4(arr,arr_size);
break;
}
default return 0;
}
}
}