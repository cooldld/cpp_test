#include <iostream>
#include <string>
#include <vector>

//using namespace std;
using std::cout;
using std::endl;
using std::vector;

//向量是一个能够存放任意类型的动态数组

void vector_print(vector<int>&data)
{
    //std::vector<int>::iterator it; //可以用auto代替。
    for(auto it = data.begin(); it != data.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * vector的构造函数
 * vector<T> data; //使用模板类，默认构造函数
 * vector(data.begin(), data.end()); //将data的【begin(), end())区间中的元素拷贝给本身，注意是数学中的前闭后开 区间
 * vector(n, elem); //将n个elem元素拷贝给本身
 * vector(const vector &data); //拷贝构造
 */
void vector_init()
{
    cout << __FUNCTION__ << " start" << endl;

    vector<int> data1; //默认构造
    data1.push_back(1);
    data1.push_back(2);
    data1.push_back(3);
    vector_print(data1); //打印：1 2 3

    vector<int> data2(data1.begin(), data1.end()); //通过区间进行构造
    vector_print(data2); //打印：1 2 3

    vector<int> data3(4, 1); //4个1构造
    vector_print(data3); //打印：1 1 1 1

    vector<int> data4(data3); //拷贝构造
    vector_print(data4); //打印：1 1 1 1

    cout << __FUNCTION__ << " end" << endl;
}

//vector的赋值函数
void vector_assign()
{
    cout << __FUNCTION__ << " start" << endl;

    vector<int> data1;
    for (int i = 0; i < 6; i++)
    {
        data1.push_back(i);
    }
    vector_print(data1); //打印 0 1 2 3 4 5

    vector<int> data2;
    data2 = data1;
    vector_print(data2); //打印 0 1 2 3 4 5

    vector<int> data3;
    data3.assign(data1.begin(), data1.end());
    vector_print(data3); //打印 0 1 2 3 4 5

    vector<int> data4;
    data4.assign(3, 6);
    vector_print(data4); //打印 6 6 6

    cout << __FUNCTION__ << " end" << endl;
}

/**
 * vector的容量和大小函数
 * empty(); //判断容器是否为空
 * capacity(); //容器的容量    capacity一定会大于等于size
 * size(); //返回容器中元素的个数
 * resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新的位置；若容器变短，则末尾超出的元素被删除
 * resize(int num，elem); //重新指定容器的长度为num，若容器变长，则以elem数值填充新的位置；若容器变短，则末尾超出的元素被删除
 */
void vector_size()
{
    cout << __FUNCTION__ << " start" << endl;

    vector<int> data1;

    cout << "data1.empty()=" << data1.empty() << endl;

    for (int i = 0;i < 6;i++)
    {
        data1.push_back(i);
    }
    cout << "data1.empty()=" << data1.empty() << endl;
    cout << "data1.capacity()=" << data1.capacity() << endl;
    cout << "data1.size()=" << data1.size() << endl;

    data1.resize(10); //填充默认值0
    vector_print(data1); //打印 0 1 2 3 4 5 0 0 0 0

    data1.resize(13,8); //填充数值8
    vector_print(data1); //打印 0 1 2 3 4 5 0 0 0 0 8 8 8

    data1.resize(4);
    vector_print(data1); //打印 0 1 2 3

    data1.resize(0); //清空vector
    cout << "data1.size()=" << data1.size() << endl;

    cout << __FUNCTION__ << " end" << endl;
}

/**
 * vector的插入和删除函数
 * push_back(elem); //尾部插入元素elem
 * pop_back(); //删除最后一个元素
 * insert(const_iterator pos, elem); //迭代器指向位置pos插入元素elem
 * insert(const_iterator pos, int count,elem); //迭代器指向位置pos插入count个元素elem
 * erase(const_iterator pos); //删除迭代器指向的元素
 * erase(const_iterator start,const_iterator end); //删除迭代器start到end之间的元素
 * clear(); //删除容器中所有元素
 */
void vector_add_delete()
{
    cout << __FUNCTION__ << " start" << endl;

    vector<int> data1;
    for(int i = 0; i < 6; i++)
    {
        data1.push_back(i);
    }
    vector_print(data1); //打印 0 1 2 3 4 5

    data1.pop_back(); //尾删
    vector_print(data1); //打印 0 1 2 3 4

    data1.insert(data1.begin(),22); //迭代器位置插入一个22
    vector_print(data1); //打印 22 0 1 2 3 4

    data1.insert(data1.begin(),3,7); //迭代器位置插入三个22
    vector_print(data1); //打印 7 7 7 22 0 1 2 3 4

    data1.erase(data1.begin()); //迭代器位置删除
    vector_print(data1); //打印 7 7 22 0 1 2 3 4

    data1.erase(data1.begin(), data1.end()); //迭代器位置 区间 删除
    cout << "erase(begin, end), data1.empty()=" << data1.empty() << endl;

    data1.clear(); //清空容器
    cout << "data1.clear, data1.empty()=" << data1.empty() << endl;

    cout << __FUNCTION__ << " end" << endl;
}

/**
 * vector的存取操作函数
 * at(int idx); //返回索引idx所指的数据
 * operator []; //返回索引idx所指的数据
 * front(); //返回容器的第一个数据元素
 * back(); //返回容器的最后一个数据元素
 */
void vector_access()
{
    cout << __FUNCTION__ << " start" << endl;

    vector<int> data1;
    for(int i = 0; i < 6; i++)
    {
        data1.push_back(i);
    }
    vector_print(data1); //打印 0 1 2 3 4 5

    //warning: comparison of integer expressions of different signedness: ‘int’ and ‘std::vector<int>::size_type’

    //利用[]方式访问vector中的元素
    for(vector<int>::size_type j = 0;j<data1.size();j++)
    {
        cout << "data1[" << j << "]=" << data1[j] << endl;
    }

    //利用at方式访问vector中的元素
    for(vector<int>::size_type j = 0;j<data1.size();j++)
    {
        cout << "data1.at(" << j << ")=" << data1.at(j) << endl;
    }

    cout << "data1.front()=" << data1.front() << endl;
    cout << "data1.back()=" << data1.back() << endl;

    cout << __FUNCTION__ << " end" << endl;
}

//vector的swap容器函数
void vector_swap()
{
    cout << __FUNCTION__ << " start" << endl;

    vector<int> data1;
    for(int i = 0; i < 6; i++)
    {
        data1.push_back(i);
    }
    cout << "data1" << endl;
    vector_print(data1); //打印 0 1 2 3 4 5

    vector<int> data2;
    for(int i = 10;i > 0; --i)
    {
        data2.push_back(i);
    }
    cout << "data2" << endl;
    vector_print(data2); //打印 6 5 4 3 2 1

    data1.swap(data2);
    cout << "data1.swap(data2)" << endl;

    cout << "data1" << endl;
    vector_print(data1); //打印 6 5 4 3 2 1

    cout << "data2" << endl;
    vector_print(data2); //打印 0 1 2 3 4 5

    cout << __FUNCTION__ << " end" << endl;
}

int main(void)
{
    vector_init();

    vector_assign();

    vector_size();

    vector_add_delete();

    vector_access();

    vector_swap();
    return 0;
}
