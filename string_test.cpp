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
    string str = "123abc";
    printf("printf, str=%s\n", str.c_str());
}

/*string的大小写转换*/
#include <algorithm>
void string_transform()
{
    string str = "123Abc";

    /*大写转换*/
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "transform toupper, str=" << str << endl;

    /*小写转换*/
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "transform tolower, str=" << str << endl;
}

//string类的字符操作
void string_char()
{
    string str = "123abc";

    cout << "str[3]=" << str[3] << endl;
    cout << "str.at(3)=" << str.at(3) << endl;

    char array[10] = {0};
    str.copy(array, 3, 1);
    cout << "array=" << array << endl;
}

//string的特性描述
void string_size()
{
    string str = "123abc";

    cout << "str.capacity()=" << str.capacity() << endl;
    cout << "str.max_size()=" << str.max_size() << endl;
    cout << "str.size()=" << str.size() << endl;
    cout << "str.length()=" << str.length() << endl;
    cout << "str.empty()=" << str.empty() << endl;
    str.resize(15, 'r');
    cout << "str.resize=" << str << endl;
}

//string的赋值
void string_assign()
{
    string str = "123abc";
    string str1;

    str1 = str;
    cout << "str1=" << str1 << endl;

    str1.assign("123ABC");
    cout << "str1=" << str1 << endl;

    str1.assign("123abc", 3);
    cout << "str1=" << str1 << endl;

    str1.assign(9, 'a');
    cout << "str1=" << str1 << endl;

    str1.assign(str, 2, 4);
    cout << "str1=" << str1 << endl;

    str1.assign(str.begin(), str.end());
    cout << "str1=" << str1 << endl;
}

//string的连接
void string_append()
{
    string str1 = "123";
    string str = "abc";

    str1 += str;
    cout << "str1=" << str1 << endl;

    str1.append("ABC");
    cout << "str1=" << str1 << endl;

    str1.append("ABC", 2);
    cout << "str1=" << str1 << endl;

    str1.append(9, 'a');
    cout << "str1=" << str1 << endl;

    str1.append(str, 1, 2);
    cout << "str1=" << str1 << endl;

    str1.append(str.begin(), str.end());
    cout << "str1=" << str1 << endl;

    str1.push_back('A');
    cout << "str1=" << str1 << endl;
}

//string的比较
void string_compare()
{
    string str = "123abc";
    string str1 = "0123ABC";

    cout << "str and str1 are " << ((str == str1) ? "same" : "different") << endl;

    cout << "str and str1 are " << ((str == str1) ? "same" : "different") << endl;
    cout << "str.compare(str1), ret=" << str.compare(str1) << endl;
    cout << "str.compare(0, 3, str1, 1, 3), ret=" << str.compare(0, 3, str1, 1, 3) << endl;

    const char *str2 = "0123ABC";
    cout << "str.compare(str2), ret=" << str.compare(str2) << endl;
    cout << "str.compare(0, 3, str2, 1, 3), ret=" << str.compare(0, 3, str2, 1, 3) << endl;
}

/**
 * string的子串
 * 如果pos>=str.size()，程序异常退出
 * terminate called after throwing an instance of 'std::out_of_range'
 */
void string_substr()
{
    string str = "123abc";

    cout << "str.substr(0, string::npos), ret=" << str.substr(0, string::npos) << endl;
    cout << "string::npos=" << string::npos << endl; //string::npos=18446744073709551615
    cout << "str.substr(2, 3), ret=" << str.substr(2, 3) << endl;
}

//string的交换
void string_swap()
{
    string str = "123abc";
    string str1 = "0123ABC";

    str.swap(str1);
    cout << "swap, str=" << str << ", str1=" << str1 << endl;
}

//string的查找函数
void string_find()
{
    string str = "123abc";
    string::size_type ret;

    ret = str.find('b');
    cout << "str.find('b'), ret=" << ret << endl;

    ret = str.find("23");
    cout << "str.find('23'), ret=" << ret << endl;

    ret = str.find("23aaa");
    cout << "str.find('23aaa'), ret=" << (ret == string::npos ? "nops" : std::to_string(ret)) << endl;

    ret = str.find("23aaa", 1, 2);
    cout << "str.find('23aaa', 1, 2), ret=" << ret << endl;

    ret = str.rfind('b');
    cout << "str.rfind('b'), ret=" << ret << endl;

    str = "123abc23";
    ret = str.rfind("23"); //return 6
    cout << "str.rfind('23'), ret=" << ret << endl;

    ret = str.find_first_of("23");
    cout << "str.find_first_of('23'), ret=" << ret << endl;

    //注意：find_last_of与rfind()有区别
    ret = str.find_last_of("23"); //return 7
    cout << "str.find_last_of('23'), ret=" << ret << endl;

    ret = str.find_first_not_of("123");
    cout << "str.find_first_not_of('123'), ret=" << ret << endl;

    ret = str.find_last_not_of("23");
    cout << "str.find_last_not_of('23'), ret=" << ret << endl;
}

//string类的替换函数
void string_replace()
{
    string str = "123abc";

    str.replace(1, 3, "RPLACE");
    cout << "str.replace, str=" << str << endl;

    //用replace实现insert功能
    str.replace(0, 0, "INSERT");
    cout << "str.replace, str=" << str << endl;

    str.replace(1, 3, 5, 'R');
    cout << "str.replace, str=" << str << endl;
}

//string类的插入函数
void string_insert()
{
    string str = "123abc";

    str.insert(1, "INSERT");
    cout << "str.insert, str=" << str << endl;

    str.insert(1, 5, 'R');
    cout << "str.insert, str=" << str << endl;
}

//string类的删除函数
void string_erase()
{
    string str = "123abc";

    str.erase(1, 2);
    cout << "str.erase(1, 2), str=" << str << endl;

    str.erase(); //empty string
    cout << "str.erase(), str=" << str << endl;
}

//string类的迭代器处理
void string_iterator()
{
    string str = "123abc";

    auto it_b = str.begin();
    cout << "*it_b=" << *it_b << endl;

    auto it_e = str.end();
    cout << "*(--it_e)=" << *(--it_e) << endl;

    auto it_cb = str.cbegin();
    cout << "*it_cb=" << *it_cb << endl;

    auto it_ce = str.cend();
    cout << "*(--it_ce)=" << *(--it_ce) << endl;

    auto it_rb = str.rbegin();
    cout << "*it_rb=" << *it_rb << endl;

    auto it_re = str.rend();
    cout << "*(--it_re)=" << *(--it_re) << endl;

    auto it_crb = str.crbegin();
    cout << "*it_crb=" << *it_crb << endl;

    auto it_cre = str.crend();
    cout << "*(--it_cre)=" << *(--it_cre) << endl;

    for(string::reverse_iterator it = str.rbegin(); it != str.rend(); ++it)
    {
        cout << "*it=" << *it << endl;
    }
}

//string的int与string相互转换函数
void string_to_string()
{
    int i = 1;
    long l = 20;
    float f = 3.14;
    double d = 3.14159;

    //把整型转成string类型
    cout << std::to_string(i) << endl;
    cout << std::to_string(l) << endl;
    cout << std::to_string(f) << endl;
    cout << std::to_string(d) << endl;

    //把string类型转成整型
    string str = "123abc";
    cout << atoi(str.c_str()) << endl;
}

//字符串流处理
#include <sstream>
using std::istringstream;
using std::ostringstream;
void string_sstream()
{
    string input("hello,this is a test");
    istringstream is(input);
    string s1,s2,s3,s4;
    is>>s1>>s2>>s3>>s4;//s1="hello,this",s2="is",s3="a",s4="test"
    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    cout << "s3=" << s3 << endl;
    cout << "s4=" << s4 << endl;

    ostringstream os;
    os<<s1<<s2<<s3<<s4;
    cout <<os.str() << endl;
}

int main(void)
{
    string_init();

    string_printf();

    string_transform();

    string_char();

    string_size();

    string_assign();

    string_append();

    string_compare();

    string_substr();

    string_swap();

    string_find();

    string_replace();

    string_insert();

    string_erase();

    string_iterator();

    string_to_string();

    string_sstream();

    return 0;
}
