// 自己通用的数组类
#pragma once
#include <iostream>
using namespace std;
#include <string.h>

template<class T>  // 这是类模板
class MyArray
{
public:
    // 有参构造  参数 容量
    MyArray(int capcaity)
    {   
        cout << "MyArray有参构造调用" << endl;
        this->m_Capacity = capcaity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    // 拷贝构造 (防止浅拷贝 详见课程P110 深拷贝与浅拷贝)
    MyArray(const MyArray& arr)
    {
        cout << "MyArray拷贝构造调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // this->pAddress = arr.pAddress; 这是浅拷贝的问题, 会使得堆区内容重复释放

        //深拷贝 
        this->pAddress = new T[arr.m_Capacity];

        //将arr中的数据都拷贝过来
        for (int i=0; i < this->m_Size; i++)  // 类内可以访问私有成员
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //  operator= 防止浅拷贝问题
    MyArray& operator=(const MyArray& arr)
    {
        cout << "MyArray的operate=调用" << endl;
        //先判断原来堆区是否有数据, 如果有先释放
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        // 深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i=0; i< this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }
    
    // 尾插法
    void Push_Back(const T & val)
    {
        // 判断容量是否等于大小
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val;  // 在数组末尾插入数据
        this->m_Size++;  // 更新数组的大小
    }

    // 尾删法
    void Pop_Back()
    {
        //让用户访问不到最后一个元素, 即为尾删, 逻辑删除
        if(this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;
    }

    // 通过下标方式访问数组中的元素
    T& operator[](int index) const
    {
        return this->pAddress[index];
    }

    // friend ostream& operator<<(ostream& output, const MyArray& arr)    
    friend ostream& operator<<(ostream& output, const MyArray& arr)    
    {

        for (int i=0; i< arr.m_Size; i++)
        {
            output << "姓名: " << arr[i].m_Name << " 年龄: " << arr[i].m_Age << endl;
        }
        
        // if (strstr(typeid(arr).name(), "Person"))
        // {
        //     for (int i=0; i< arr.m_Size; i++)
        //     {
        //         output << "姓名: " << arr[i].m_Name << " 年龄: " << arr[i].m_Age << endl;
        //     }
        // }
        // else
        // {
        //     for (int i=0; i< arr.m_Size; i++)
        //     {
        //         output << arr[i] << endl;
        //     }
        // }
        return output;
    }


    // 返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    // 返回数组大小
    int getSize()
    {
        return this->m_Size;
    }

    // 析构函数
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            cout << "MyArray析构调用" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T * pAddress;  // 指针指向堆区开辟的真实的数组

    int m_Capacity;  // 数组容量

    int m_Size;  // 数组大小
};