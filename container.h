#ifndef CONTAINER_H
#define CONTAINER_H
#include <random>
#include <ctime>
#include <iostream>

using namespace std;

class container
{
    public:
        container();
        virtual ~container();
        container(int i, default_random_engine * gptr);
        container(const container &old_obj);

        int Getid() { return id; }
        void Setid(int val) { id = val; }

        int Getdestcode() { return destcode; }
        void Setdestcode(int val) { destcode = val; }

        void Display() { cout<<"container id = "<<id<<endl;
                        cout<<"          destination code = "<<destcode<<endl; }

    protected:

    private:
        int id;
        int destcode;
};

#endif // CONTAINER_H
