#include <iostream>
#include "ABC.h"
using namespace std;

int main()
{
    Nod c1;
    ABC ob;
    ob+7;
    ob+3;
    ob+1;
    ob+2;
    ob+6;
    ob+5;
    ob+9;
    cout<<ob;
    ob.frunze(ob.get_root());
    cout<<endl;
    ob.stergere(2);
    ob.stergere(7);
    cin>>ob>>ob>>ob>>ob;
    cout<<endl<<ob.inaltime(ob.get_root());
    cout<<endl<<ob;
    return 0;
}
