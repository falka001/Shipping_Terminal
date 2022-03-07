#include "container.h"

container::container()
{
    //ctor
}

container::container(int i, default_random_engine * gptr)
{
    normal_distribution<double> dcdist(500, 100);
    id = i;
    destcode = int(dcdist(*gptr));
}

container::~container()
{
    //dtor
}

container::container(const container &old_obj)
{
    id = old_obj.id;
    destcode = old_obj.destcode;
}
