#ifndef ABC_H_INCLUDED
#define ABC_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

class Nod{
friend class ABC;
private:
    int val;
    Nod *st;
    Nod *dr;
public:
    Nod(int val=0);
    int get_val()const;
    Nod& get_st()const;
    Nod& get_dr()const;
};
class ABC{
private:
    Nod *root;
    void preordine(Nod *);
    void inordine(Nod *);
    void postordine(Nod *);
public:
    inline ABC(){root=NULL;}
    Nod* get_root()const;
    void operator +(int);
    friend ostream& operator<<(ostream&, ABC&);
    friend istream & operator>>(istream &,ABC&);
    void stergere(int);
    int inaltime(Nod *);
    void frunze(Nod*);
};
#endif // ABC_H_INCLUDED
