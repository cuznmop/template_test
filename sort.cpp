//使用模板进行排序
//选择排序, 由大到小
#include <iostream>
using namespace std;

template <typename T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len-1; i++)
    {
        int max = i;
        for (int j = i+1; j < len; j++)
        {
            if(arr[j] > arr[max])
            {
                max = j;                
            }
        }
        if(max != i)
        {
            swap(arr[i], arr[max]);
        }
    }    
}

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    char arr[] = {'a','b','c','d','e','f','g','h','i','j'};
    mySort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    test01();
    // for (int i=10; i<11; i++)
    // {
    //     printf("haha\n");
    // }
}