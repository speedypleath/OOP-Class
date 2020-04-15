#include <iostream>
#include "ABC.h"
using namespace std;

int main()
{
    int n,x,i,j;
    cout<<"nr obiecte:";cin>>n;
    ABC ob[n];
    for(i=0;i<n;i++)
    {
        cout<<"nr noduri:";cin>>x;
        for(j=0;j<x;j++)
            cin>>ob[i];
        cout<<ob[i];
    }
    return 0;
}
