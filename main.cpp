#include <iostream>
#include "ship.h"
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int numship;
    int cnum;
    int cplayer;
    int lrnum;
    int lnum;
    int wnum;

    vector<ship> sp;
    vector<vector<vector<vector<container>>>> ship_num;

    ship * sptr;
    container * cptr;
    vector<container> * rptr;
    vector<vector<container>> * Lptr;
    vector<vector<vector<container>>> * conptr;

    default_random_engine * gptr;
    gptr = new default_random_engine(time(NULL));

    cout<<"How many ships are arriving?"<<endl;
    cin>>numship;

    int k = 100;
    int iter = 0;

    while(iter<numship) {                      /// Creating ships
        cout<<"For Ship #"<<iter<<endl;
        cout<<"Enter the total number of containers you would like to have:"<<endl;
        cin>>cnum;
        cout<<"Enter how many containers should be aligned in width:"<<endl;
        cin>>wnum;
        cout<<"Enter how many containers should be aligned in length:"<<endl;
        cin>>lnum;
        lrnum = cnum / (wnum * lnum);
        conptr = new vector<vector<vector<container>>>;
        for(int W=0; W<wnum; W++) {
            Lptr = new vector<vector<container>>;
            for(int L=0; L<lnum; L++) {
                rptr = new vector<container>;
                for (int LR=0; LR<lrnum; LR++) {
                    cptr = new container(k, gptr);
                    rptr->push_back(*cptr);
                    k++;
                }
                Lptr->push_back(*rptr);
            }
            conptr->push_back(*Lptr);
        }
        ship_num.push_back(*conptr);
        sptr = new ship(iter, cnum, cnum);
        sp.push_back(*sptr);
        iter++;
    }
    for (int S=0; S<numship; S++) {
        sp[S].Display();
        for (int L=0; L<wnum; L++) {
            cout<<"layer #"<<L<<endl;
            for (int r=0; r<lnum; r++) {
                cout<<"       row #"<<r<<endl;
                for (int c=0; c<lrnum; c++) {
                    if(!ship_num[S][L][r].empty()) {
                    ship_num[S][L][r][c].Display(); }
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }

    vector<vector<container>> cranes;
    vector<container> * crane_ptr;
    queue<container> T1[5];
    vector<crane> crane_num;
    crane * craneptr;
    stack<container> siding[5];
    queue<container> shipping[4];   ///0 - 100-199s ; 1 - 300-399s ; ... ; 4 - 900-999s

    cout<<"Cranes are getting read ..."<<endl;
    for(int i=0; i<9; i++) {
        craneptr = new crane(i, false);
        crane_num.push_back(*craneptr);
    }
    cout<<"Cranes are ready"<<endl;
    int temp;

    for(int S=0; S<numship; S++) {
        for(int L=wnum-1; L>-1; L--) {
            for(int r=lnum-1; r>-1; r--) {
                int k = 0;
                for(int c=lrnum-1; c>-1; c--) {
                    if(k<9) {
                        cout<<"loading: ";
                        ship_num[S][L][r][c].Display();
                        cout<<"container loaded to: ";
                        crane_num[k].Setloaded(true);
                        crane_num[k].Display();
                        crane_ptr = new vector<container>;
                        crane_ptr->push_back(ship_num[S][L][r][c]);
                        cranes.push_back(*crane_ptr);
                        ship_num[S][L][r].erase((ship_num[S][L][r].end()--));
                        delete crane_ptr;
                    }
                    else if (k==9) {
                        cout<<"containers loaded:"<<endl;
                        for(int e=0; e<9; e++) {
                            cranes[e][0].Display();
                            cout<<endl;
                        }
                        if(L!=0) { cout<<"Adding containers to switching lines"<<endl; }
                        for(int i=0; i<9; i++) {
                            cout<<"unloading from crane #"<<i<<endl;
                            crane_num[i].Setloaded(false);
                            cranes[i][0].Display();
                            cout<<endl;
                            if(T1[i%5].size() < 40) {
                                T1[i%5].push(cranes[i][0]);
                            }
                            else if(T1[i%5].size() == 40) {
                                cout<<"checking shipping tracks are full"<<endl;
                                if(shipping[0].size() == 100 || shipping[0].size() > 100) {
                                    cout<<"shipping track #0 is full, containers are being shipped ....----------------------------------------------------"<<endl<<endl;
                                    cin>>temp;
                                    while(!shipping[0].empty()) {
                                        shipping[0].pop();
                                        cout<<"container shipped..."<<endl;
                                    }
                                }
                                if(shipping[1].size() == 100 || shipping[1].size() > 100) {
                                    cout<<"shipping track #1 is full, containers are being shipped ....----------------------------------------------------"<<endl<<endl;
                                    cin>>temp;
                                    while(!shipping[1].empty()) {
                                        shipping[1].pop();
                                        cout<<"container shipped..."<<endl;
                                    }
                                }
                                if(shipping[2].size() == 100 || shipping[2].size() > 100) {
                                    cout<<"shipping track #2 is full, containers are being shipped ....----------------------------------------------------"<<endl<<endl;
                                    cin>>temp;
                                    while(!shipping[2].empty()) {
                                        shipping[2].pop();
                                        cout<<"container shipped..."<<endl;
                                    }
                                }
                                if(shipping[3].size() == 100 || shipping[3].size() > 100) {
                                    cout<<"shipping track #3 is full, containers are being shipped ....----------------------------------------------------"<<endl<<endl;
                                    cin>>temp;
                                    while(!shipping[3].empty()) {
                                        shipping[3].pop();
                                        cout<<"container shipped..."<<endl;
                                    }
                                }
                                if(shipping[4].size() == 100 || shipping[4].size() > 100) {
                                    cout<<"shipping track #4 is full, containers are being shipped ....----------------------------------------------------"<<endl<<endl;
                                    cin>>temp;
                                    while(!shipping[4].empty()) {
                                        shipping[4].pop();
                                        cout<<"container shipped..."<<endl;
                                    }
                                }
                                else {
                                    cout<<"Switching Track #"<<i%5<<" is full, sending to shipping tracks"<<endl;
                                    while(!T1[i%5].empty()) {
                                        if(T1[i%5].front().Getdestcode() >= 100 && T1[i%5].front().Getdestcode() <= 199) {
                                            shipping[0].push(T1[i%5].front());
                                            cout<<"container going from switching track #"<<i%5<<" to shipping track #0"<<endl<<endl;
                                        }
                                        else if(T1[i%5].front().Getdestcode() >= 300 && T1[i%5].front().Getdestcode() <= 399) {
                                            shipping[1].push(T1[i%5].front());
                                            cout<<"container going from switching track #"<<i%5<<" to shipping track #1"<<endl<<endl;
                                        }
                                        else if(T1[i%5].front().Getdestcode() >= 500 && T1[i%5].front().Getdestcode() <= 599) {
                                            shipping[2].push(T1[i%5].front());
                                            cout<<"container going from switching track #"<<i%5<<" to shipping track #2"<<endl<<endl;
                                        }
                                        else if(T1[i%5].front().Getdestcode() >= 700 && T1[i%5].front().Getdestcode() <= 799) {
                                            shipping[3].push(T1[i%5].front());
                                            cout<<"container going from switching track #"<<i%5<<" to shipping track #3"<<endl<<endl;
                                        }
                                        else if(T1[i%5].front().Getdestcode() >= 900 && T1[i%5].front().Getdestcode() <= 999) {
                                            shipping[4].push(T1[i%5].front());
                                            cout<<"container going from switching track #"<<i%5<<" to shipping track #4"<<endl<<endl;
                                        }
                                        else {
                                            if(shipping[0].empty()) { shipping[0].push(T1[i%5].front());
                                                                    cout<<"container added to shipping track #0 since it is empty"<<endl<<endl; }
                                            else if(shipping[1].empty()) { shipping[1].push(T1[i%5].front());
                                                                        cout<<"container added to shipping track #1 since it is empty"<<endl<<endl; }
                                            else if(shipping[2].empty()) { shipping[2].push(T1[i%5].front());
                                                                        cout<<"container added to shipping track #2 since it is empty"<<endl<<endl; }
                                            else if(shipping[3].empty()) { shipping[3].push(T1[i%5].front());
                                                                        cout<<"container added to shipping track #3 since it is empty"<<endl<<endl; }
                                            else if(shipping[4].empty()) { shipping[4].push(T1[i%5].front());
                                                                        cout<<"container added to shipping track #4 since it is empty"<<endl<<endl; }
                                            else { siding[i%5].push(T1[i%5].front());
                                                cout<<"container destination code does not qualify the shipping tracks, it has been placed on the siding"<<endl<<endl; }
                                        }
                                        T1[i%5].pop();
                                    }
                                }
                            }
                            cranes[i].clear();
                        }
                        cranes.clear();
                        k = -1;
                    }
                    cout<<endl;
                    k++;
                }
            }
        }
    }

    cout<<endl<<"your shift for today has ended"<<endl;

    cout<<"You are left off with the following:"<<endl;
    for(int i=0; i<5; i++) {
        cout<<"                 Switching Track #"<<i<<" has:"<<T1[i].size()<<" containers left"<<endl;
    }
    cout<<endl;
    for(int i=0; i<5; i++) {
        cout<<"                 Siding #"<<i<<" has:"<<siding[i].size()<<" containers with no corresponding destination code"<<endl;
    }
    cout<<endl;
    for(int i=0; i<5; i++) {
        cout<<"                 Shipping Track #"<<i<<" has:"<<shipping[i].size()<<" containers left"<<endl;
    }

    cout<<"the sum of the above should approximately equal the total number of containers, but remember that some containers already been shipped!"<<endl;

    return 0;
}
