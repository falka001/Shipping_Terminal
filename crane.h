#ifndef CRANE_H
#define CRANE_H
#include "ship.h"

using namespace std;

class crane
{
    public:
        crane();
        virtual ~crane();
        crane(int i, bool l);

        int Getindex() { return index; }
        void Setindex(int val) { index = val; }

        bool Getloaded() { return loaded; }
        void Setloaded(bool val) { loaded = val; }

        Display();

    protected:

    private:
        int index;
        bool loaded;
};

#endif // CRANE_H
