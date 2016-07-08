#include "INormalWomen.h"
#include "NormalWomen.h"
#include "INormalHandler.h"
#include "NormalFather.h"
#include "NormalHusband.h"
#include "NormalSon.h"

#include "IWomen.h"
#include "Women.h"
#include "Handler.h"
#include "Father.h"
#include "Husband.h"
#include "Son.h"

#include <iostream>

using std::cout;
using std::endl;

void DoIt()
{
    cout << "----------原来的处理方式----------" << endl;
    //INormalWomen.h, NormalWomen.h, INormalHandler.h, NormalFather.h, NormalHusband.h, NormalSon.h
    INormalWomen *pwomen = new CNormalWomen(1, "我要出去逛街");
    INormalHandler *pfather = new CNormalFather();
    INormalHandler *phusband = new CNormalHusband();
    INormalHandler *pson = new CNormalSon();
    if (pwomen->GetType() == 1)
    {
        cout << "女儿向父亲请示：" << endl;
        pfather->HandleMessage(pwomen);
    }
    else if (pwomen->GetType() == 2)
    {
        cout << "妻子向丈夫请示：" << endl;
        phusband->HandleMessage(pwomen);
    }
    else if (pwomen->GetType() == 3)
    {
        cout << "母亲向儿子请示：" << endl;
        pson->HandleMessage(pwomen);
    }
    else
    {
        //什么也不做
    }
    delete pwomen;
    delete pfather;
    delete phusband;
    delete pson;
}

void DoNew()
{
    cout << "----------使用模式后的处理方式----------" << endl;
    //Handler.h, Handler.cpp, IWomen.h, Women.h, Women.cpp, Father.h, Father,cpp, Husband.h, Husband.cpp, Son.h, Son.cpp
    IWomen *pwomen1 = new CWomen(1, "我要出去逛街");
    IWomen *pwomen2 = new CWomen(2, "我要出去吃饭");
    IWomen *pwomen3 = new CWomen(3, "我也要出去吃饭");
    IWomen *pwomen4 = new CWomen(4, "我也要出去逛街");

    CHandler *pfather = new CFather();
    CHandler *phusband = new CHusband();
    CHandler *pson = new CSon();

    pfather->SetNext(phusband);
    phusband->SetNext(pson);

    pfather->HandleMessage(pwomen1);
    pfather->HandleMessage(pwomen2);
    pfather->HandleMessage(pwomen3);
    pfather->HandleMessage(pwomen4);

    delete pfather;
    delete phusband;
    delete pson;
    delete pwomen1;
    delete pwomen2;
    delete pwomen3;
    delete pwomen4;
}

int main(int argc, char* argv[])
{
    //反面
    DoIt();
    //要实现逻辑判断，即女性的请求先发送到父亲类，父亲类一看是自己要处理的，就回应进行处理。如果女儿已经出嫁了，那就把这个请求转发到女婿类来处理。依此类推，形成了一个责任链。
    DoNew();

    return 0;
}