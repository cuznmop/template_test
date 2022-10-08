#include <iostream>
#include <string.h>
using namespace std;

//函数模板注意事项

template <typename T> // typename可以替换成class
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
// 1.自动类型推导, 必须推到出一致的数据类型T才可以使用
void test01()
{
    int a = 10;
    int b = 20;
    char c = 'a';
    // mySwap(a, c);
    cout << a << " " << b << endl;
}
// 2.模板必须要确定出T的数据类型, 才可以使用
template <typename T>
void func()
{
    cout << "func 调用" << endl;
}

void test02()
{
    func<int>();
}

// test03和模板没有关系g
void test03()
{
    string a = "test";
    const char *b = a.c_str();

    cout << b << endl;
}

void myprint(int a, int b)
{
    int c = a + b;
    cout << c << endl;
}

void test04()
{
    char a = 'a';
    char b = 'b';
    myprint(a, b);
}

void chartest(string a)
{
    cout << a << endl;
}

void chartest_a(const char *a)
{
    cout << a << endl;
}

void test05()
{
    // const char a[] = "hello";
    // chartest_a(a);

    string a = "hello";
    const char *b = a.c_str();
    chartest_a(b);
}

class CHARTEST
{
private:
    string ip;

public:
    // const char * ip[];
    // char ip[];
    void SetIP(string c) { ip = c; }
    string GetIP() const { return ip; }
};

void test06()
{
    CHARTEST ctest;
    string b = "hahahaha";
    // ctest.ip = b;
    ctest.SetIP(b);
    cout << ctest.GetIP() << endl;
}

int main()
{
    // test01();
    // test03();
    // test04();
    // test05();
    test06();
    // system("pause");
}