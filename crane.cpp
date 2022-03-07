#include "crane.h"

crane::crane()
{
    //ctr
}

crane::crane(int i, bool l)
{
    index = i;
    loaded = l;
}

crane::~crane()
{
    //dtor
}

crane::Display()
{
    cout<<"available crane index = "<<index<<endl;
    cout<<"                loaded = "<<loaded<<endl;
}
