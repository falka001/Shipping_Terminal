#include "ship.h"

ship::ship()
{
    //ctor
}

ship::ship(int i, int c, int cc)
{
    id = i;
    capacity = c;
    curr_cont = cc;
}

ship::~ship()
{
    //dtor
}

ship::Display()
{
    cout<<"Ship id = "<<id<<endl;
    cout<<"     capacity = "<<capacity<<endl;
    cout<<"     current number of containers = "<<curr_cont<<endl;
}

