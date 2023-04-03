#include <string>
#include <iostream>
#include <memory>

//using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class DelTest
{
public:
    DelTest(string name) : mName(name)
    {
        cout << "DelTest(), name=" << mName << endl;
    }
    ~DelTest()
    {
        cout << "~DelTest(), name=" << mName << endl;
    }
    void printName()
    {
        cout << __FUNCTION__ << ", mName=" << mName << endl;
    }
    string getName()
    {
        return mName;
    }
private:
    string mName;
};

/*shared_ptr类的构造函数*/
void shared_ptr_init()
{
    cout << __FUNCTION__ << " start" << endl;

    //方式一
    shared_ptr<DelTest> pTom1;
    pTom1.reset(new DelTest("tom_reset"));

    //方式二
    shared_ptr<DelTest> pTom2{new DelTest("tom_new")};

    //方式三，推荐，更快（一次复制），更安全
    shared_ptr<DelTest> pTom3 = make_shared<DelTest>("tom_make_shared");

    cout << __FUNCTION__ << " end" << endl;
}

/*shared_ptr类的use_count函数，查看一个对象的引用计数*/
/*shared_ptr类的reset函数，减少对象的一个引用计数*/
void shared_ptr_use_count()
{
    cout << __FUNCTION__ << " start" << endl;

    //default use_count=0
    shared_ptr<DelTest> pTom;
    cout << "pTom " << (pTom ? "not" : "is") << " nullptr" << endl;

    //use_count=1
    pTom.reset(new DelTest("tom_use_count"));
    cout << "pTom " << (pTom ? "not" : "is") << " nullptr" << endl;

    //++use_count
    auto pTom1 = pTom;
    //++use_count
    auto pTom2 = pTom;
    //++use_count
    auto pTom3 = pTom;

    //--use_count
    pTom3.reset();
    //--use_count
    pTom2.reset();
    cout << "pTom3 and pTom2 reset, pTom.use_count()=" << pTom.use_count() << endl;

    //--use_count
    pTom1.reset();
    //--use_count
    pTom.reset();
    cout << "pTom " << (pTom ? "not" : "is") << " nullptr" << endl;
    cout << "pTom1 and pTom reset, pTom.use_count()=" << pTom.use_count() << endl;

    cout << __FUNCTION__ << " end" << endl;
}

/*shared_ptr类的get函数，获取原始指针*/
void shared_ptr_get()
{
    cout << __FUNCTION__ << " start" << endl;

    shared_ptr<DelTest> pTom = make_shared<DelTest>("tom_get");

    //直接使用shared_ptr操作对象
    pTom->printName();

    /*用原始指针来操作对象*/
    DelTest *p = pTom.get();
    p->printName();

    cout << __FUNCTION__ << " end" << endl;
}

/**
 * shared_ptr类的比较运算符
 * 支持==、!=、<、<=、>、>=
 * 同类型的共享指针才能使用比较运算符
 * 同类型的共享指针才能使用比较运算符
 * 只比较对象的指针，不比较对象的内容
 */
void shared_ptr_compare()
{
    shared_ptr<DelTest> pTom3 = make_shared<DelTest>("a");
    shared_ptr<DelTest> pTom4 = make_shared<DelTest>("a");
    cout << "pTom3 == pTom4 is " << (pTom3 == pTom4) << endl;

    auto pTom5 = pTom3;
    cout << "pTom3 == pTom5 is " << (pTom3 == pTom5) << endl;

    shared_ptr<int> pTom2 = make_shared<int>(2);
    shared_ptr<int> pTom1 = make_shared<int>(1);
    cout << "pTom1 < pTom2 is " << (pTom1 < pTom2) << endl;
}

/**
 * 多个共享指针不能拥有同一个对象
 * 编译没有报错
 * 运行时报错"double free detected"
 */
void shared_ptr_debug1()
{
    DelTest *p = new DelTest("tom_debug1");

    //不建议这种方式，仅在调试时使用
    //把一个已经存在的对象，绑定到shared_ptr上
    shared_ptr<DelTest> pTom(p);
    cout << "pTom.use_count()=" << pTom.use_count() << endl;

#if 0
    //debug1
    //再绑定一次，编译没有报错
    shared_ptr<DelTest> pTom2(p);
    cout << "pTom2.use_count()=" << pTom2.use_count() << endl;
#endif

    //这里只是增加shared_ptr引用次数，不是绑定
    shared_ptr<DelTest> pTom3(pTom);
    cout << "pTom3.use_count()=" << pTom3.use_count() << endl;

    //运行到这里，pTom和pTom2都会执行free p操作，然后异常退出
}

/*shared_ptr类的delete删除器*/
/*方式一，定义function删除器*/
void delFun(DelTest *p)
{
    cout << "Fun delete " << p->getName() << endl;
    delete p;
}
void shared_ptr_delete()
{
    shared_ptr<DelTest> pTom(new DelTest("tom_delete"), delFun);

    /*方式二，定义lamda删除器*/
    shared_ptr<DelTest> pTom2(new DelTest("tom_delete2"), [](DelTest *p) {
        cout << "Lamda delete " << p->getName() << endl;
        delete p; });
}

int main()
{
    shared_ptr_init();

    shared_ptr_use_count();

    shared_ptr_get();

    shared_ptr_compare();

    shared_ptr_debug1();

    shared_ptr_delete();

    return 0;
}
