#include <iostream>
#include "magazin.h"
#include "ABC.H"
using namespace std;
int main()
{
    ABC tree;
    vector <Produs*> stoc,t,cos;
    stoc.push_back(new Varza(1.6,1,50));
    stoc.push_back(new Faina(2,1.7,30,"II"));
    stoc.push_back(new Faina(2,1.8,20,"I"));
    stoc.push_back(new Faina(2,1.6,40,"III"));
    stoc.push_back(new Bere(4,2.5,70,"Desperados","blonda"));
    stoc.push_back(new Bere(3.6,2.4,45,"Carlsberg","blonda"));
    stoc.push_back(new Bere(3.6,2.4,1,"Ursus","bruna"));
    stoc.push_back(new Varsat(6.5,5,30,"rosu sec"));
    stoc.push_back(new Soi(35,28,5,"rosu dulce","2017","Franta","Merlot"));
    stoc.push_back(new Soi(120,100,3,"alb sec","2011","Italia","Bianco"));
    stoc.push_back(new Cartofi(3,2,25,"rosii"));
    stoc.push_back(new Cartofi(2,1.5,25,"albi"));
    stoc.push_back(new Jucarie(50,40,"papusa"));
    stoc.push_back(new Jucarie(50,40,"masina"));
    string text="da";
    unsigned profit_total=0;
    while(text == "da"){
        getline(cin, text);
        unsigned k,m=0,pret=0,profit=0;
        while(text!=""){
            istringstream iss(text);
            vector<string> results(istream_iterator<string>{iss},istream_iterator<string>());
            for(auto it:stoc){
                k = it->match(results);
                if(k>m && it->get_stoc()>0){
                    t.clear();
                    t.push_back(it);
                    m = k;
                }
                else if(k==m && it->get_stoc()>0)
                    t.push_back(it);
            }
            if(m==0){
                cout<<"produsul nu exista";
                cout<<endl;
            }
            else{
                Produs *aux;
                unsigned p = 1;
                for(auto it:t)
                    if(it->profit()>p)
                    {
                        p = it->profit();
                        aux = it;
                    }
                profit += aux->sell(1);
                pret += aux->get_pret();
                cos.push_back(aux);
            }
            t.clear();
            m = 0;
            getline(cin, text);
        }

        cout<<"Pret total:"<<pret<<endl;
        getline(cin, text);
        for(auto it:cos)
            cout<<*it<<endl;
        if(text=="nu")
        {
            for(auto it:cos)
                it->remake();
        }
        else
            profit_total += profit;
        cos.clear();
        cout<<"alt cos?";
        getline(cin, text);
    }
    cout<<"profit total:"<<profit_total;
    return 0;
}
