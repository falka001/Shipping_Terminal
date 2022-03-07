#ifndef SHIP_H
#define SHIP_H
#include "container.h"
#include "crane.h"

using namespace std;

class ship
{
    public:
        ship();
        virtual ~ship();
        ship(int i, int c, int cc);

        int Getid() { return id; }
        void Setid(int val) { id = val; }

        int Getcurr_cont() { return curr_cont; }
        void Setcurr_cont(int val) { curr_cont = val; }

        int Getcapacity() { return capacity; }
        void Setcapacity(int val) { capacity = val; }

        int Getlength() { return length; }
        void Setlength(int val) { length = val; }

        int Getwidth() { return width; }
        void Setwidth(int val) { width = val; }

        int Getlayer() { return layer; }
        void Setlayer(int val) { layer = val; }

        Display();

    protected:

    private:
        int id;
        int curr_cont;
        int capacity;
        int length;
        int width;
        int layer;
};

#endif // SHIP_H
