#include <iostream>
using namespace std;
#include "MyArray.hpp"
#include <string>

void printIntArray(MyArray <int>& arr)
{
    for(int i=0; i< arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}

void test01()
{
    MyArray <int>arr1(5);

    for (int i=0; i<5; i++)
    {
        arr1.Push_Back(i);
    }
    // MyArray<int>arr2(arr1);  // 拷贝构造函数
    // MyArray <int>arr3(100);
    // arr3 = arr1;
    cout << "arr1的打印输出为: " << endl;

    printIntArray(arr1);

    cout << "arr1的容量为: " << arr1.getCapacity() << endl;
    cout << "arr1的大小为: " << arr1.getSize() << endl;

    MyArray <int>arr2(arr1);

    cout << "arr2的打印输出为: " << endl;
    printIntArray(arr2);
    // cout << "arr2的容量为: " << arr2.getCapacity() << endl;
    // cout << "arr2的大小为: " << arr2.getSize() << endl;

    // 尾删
    arr2.Pop_Back();
    cout << "arr2的容量为: " << arr2.getCapacity() << endl;
    cout << "arr2的大小为: " << arr2.getSize() << endl;

    // cout << arr1 << endl;
}


// 测试自定义数据类型
class Person
{
    public:
        // 因为hpp文件中用new开辟了person类的堆区空间 而这些new出来的对象没有参数所以调用了无参构造
        // 需要默认构造是因为，创造数组的时候，数组中的每个默认元素都是用默认构造创造出来的，所以不能少默认构造
        Person() {};  // 不能少默认构造 是因为 你提供的有参构造会让编译器不再提供原有的默认构造
        Person(string name, int age)
        {
            this->m_Name = name;
            this->m_Age = age;
        }

        string m_Name;
        int m_Age;
};


void printPersonArray(MyArray<Person>& arr)
{
    for (int i=0; i< arr.getSize(); i++)
    {
        cout << "姓名: " << arr[i].m_Name << "年龄: " << arr[i].m_Age << endl;
    }
}


void test02()
{
    MyArray<Person> arr(10);

    Person p1("孙悟空", 999);
    Person p2("韩信", 30);
    Person p3("妲己", 20);
    Person p4("赵云", 25);
    Person p5("安其拉", 27);

    //将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    //打印数组
    printPersonArray(arr);

    cout << "arr的容量为: " << arr.getCapacity() << endl;
    cout << "arr的大小为: " << arr.getSize() << endl;

    cout << arr << endl;
}


int main()
{
    // cout << "aaaaa" << endl;
    // test01();
    test02();
    system("pause");
    return 0;
}