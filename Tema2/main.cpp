#include <iostream>
#include "magazin.h"

using namespace std;
int main()
{
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

    unsigned n;
    string text;
    cout<<"produse de adaugat in stoc:";
    try{
    if (!(cin >> n))
        throw(n);
    }
    catch(unsigned n){cout<<"Numar nevalid!!";return 0;}
    for(int i=0;i<n;i++){
        cin.ignore();
        cout<<"tip produs:";
        getline(cin, text);
        if(text=="cartofi"){
            Cartofi *c = new Cartofi;
            cin>>*c;
            stoc.push_back(c);
        }
        else if(text=="varza"){
            Varza *v = new Varza;
            cin>>*v;
            stoc.push_back(v);
        }
        else if(text=="bere"){
            Bere *b = new Bere;
            cin>>*b;
            stoc.push_back(b);
        }
        else if(text=="vin varsat"){
            Varsat *v = new Varsat;
            cin>>*v;
            stoc.push_back(v);
        }
        else if(text=="vin de soi"){
            Soi *s = new Soi(0,0,0,"","","","");
            cin>>*s;
            stoc.push_back(s);
        }
        else if(text=="jucarie"){
            Jucarie *j = new Jucarie;
            cin>>*j;
            stoc.push_back(j);
        }
        }

    for(auto&it:stoc)
    {
        if(Cartofi* c = dynamic_cast<Cartofi*>(it))
        cout<<*c<<"\n";
        else if(Varza* v = dynamic_cast<Varza*>(it))
        cout<<*v<<"\n";
        else if(Bere* b = dynamic_cast<Bere*>(it))
        cout<<*b<<"\n";
        else if(Varsat* v = dynamic_cast<Varsat*>(it))
        cout<<*v<<"\n";
        else if(Soi* v = dynamic_cast<Soi*>(it))
        cout<<*v<<"\n";
        else if(Jucarie* v = dynamic_cast<Jucarie*>(it))
        cout<<*v<<"\n";
    }

    text="da";
    cin.ignore();
    unsigned profit_total=0;
    while(text == "da"){
        unsigned k,m=0,pret=0,profit=0;
        cout<<"produs:";
        getline(cin, text);
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
            try{
            if(m==0)
                throw(m);
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
            catch(...){cout<<"Produsul nu exista\n";}
            t.clear();
            m = 0;
            cout<<"produs:";
            getline(cin, text);
        }

        cout<<"Pret total:"<<pret<<endl;
        cout<<"Cumparati?";
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
