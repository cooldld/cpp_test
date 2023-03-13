#include <iostream>
#include <string>

//using namespace std;
using std::cout;
using std::endl;
using std::string;

/*string类的构造函数*/
void string_init()
{
    //方式一
    string s1;

    //方式二
    string s2("this is a string");

    //方式三
    string s3(s2);

    //方式四
    string s4 = s3;
}

/*printf输出string字符串的方法*/
void string_printf()
{
    string str="123abc";
    printf("printf, str=%s\n", str.c_str());
}

/*string的大小写转换*/
#include <algorithm>
void string_transform()
{
    string str="123Abc";

    /*大写转换*/
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "transform toupper, str=" << str << endl;

    /*小写转换*/
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "transform tolower, str=" << str << endl;
}

int main(void)
{
    string_init();
    string_printf();
    string_transform();

    return 0;
}
