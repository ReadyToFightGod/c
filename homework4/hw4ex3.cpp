#include <iostream>
using namespace std;

struct t{
    unsigned h:5, m:6 ,s:6 , ms:10;
};

enum names{
    hours, minutes, seconds, ms
} ;

struct time{
    void set_time(unsigned v, names b);
    void put_time();
private:
    t x;
};

void time::set_time(unsigned v, names b){
    switch(b)
    {
        case hours: x.h = v; break;
        case minutes: x.m = v; break;
        case seconds: x.s = v; break;
        case ms: x.ms = v; break;
    }
}

void time::put_time(){
    cout << "Entered time is " << x.h << ":" << x.m << ":" << x.s << ":" << x.ms << endl;
}

int main()
{
    unsigned x;
    time ent;
    cout << "Enter hours: "; cin >> x; ent.set_time(x,hours);
    cout << "Enter minutes: "; cin >> x; ent.set_time(x,minutes);
    cout << "Enter seconds: "; cin >> x; ent.set_time(x,seconds);
    cout << "Enter milliseconds: "; cin >> x; ent.set_time(x,ms);
    ent.put_time();
}