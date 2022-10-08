//使用模板进行排序
//插入排序, 由大到小
#include <iostream>
using namespace std;

template <typename T>
void mySort(T arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = arr[i];  // 当前要插入的元素
        while((arr[i-1] < key) && (i > 0))  // 与插入元素进行比较
        {
            arr[i] = arr[i-1];
            i--;
        }
        arr[i] = key;
        
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
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    // char arr[] = {'a','b','c'};
    mySort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test02()
{
    char arr[] = "badcfe";
    int num = sizeof(arr) / sizeof(char);
    cout << "num = " << num << endl;

    mySort(arr, num);
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // test01();
    test02();
    // for (int i=10; i<11; i++)
    // {
    //     printf("haha\n");
    // }
}