#include "ABC.h"
#include <bits/stdc++.h>
int lala=0;
Nod::Nod(int val){this->val=val;st=dr=NULL;}
int Nod::get_val()const{return val;}
Nod& Nod::get_st()const{return *st;}
Nod& Nod::get_dr()const{return *dr;}


void ABC::operator +(int x){
    if(root==NULL)
        root = new Nod(x);
    else{
        Nod *cur=root;
        Nod *nou;
        nou = new Nod(x);
        while(true)
        {
            if(x>cur->get_val())
                if(cur->dr==NULL){
                    cur->dr=nou;
                    break;
                }
                else
                    cur=cur->dr;
        else
            if(cur->st==NULL){
                cur->st=nou;
                break;
            }
            else
                cur=cur->st;
        }
    }
}
void ABC::preordine(Nod *a)
{
    cout<<a->val<<" ";
    if(a->st!=NULL)
        preordine(a->st);
    if(a->dr!=NULL)
        preordine(a->dr);
}
void ABC::inordine(Nod *a)
{
    if(a->st!=NULL)
        inordine(a->st);
    cout<<a->val<<" ";
    if(a->dr!=NULL)
        inordine(a->dr);
}
void ABC::postordine(Nod *a)
{
    if(a->st!=NULL)
        postordine(a->st);
    if(a->dr!=NULL)
        postordine(a->dr);
    cout<<a->val<<" ";
}
Nod* ABC::get_root()const{return root;}
istream &operator >>(istream& in,ABC& a)
{
    int k;
    in>>k;
    a+k;
    return in;
}
ostream &operator<<(ostream& out, ABC& a)
{
    if(a.root==NULL)
        out<<"lista vida";
    else{
        a.preordine(a.get_root());
        out<<endl;
        a.inordine(a.get_root());
        out<<endl;
        a.postordine(a.get_root());
        out<<endl;
    }
    return out;
}
void ABC::stergere(int x)
{
    Nod *cur=root,*cur2;
    if(cur->dr==NULL&&cur->st==NULL)
    {
        root=NULL;
        delete cur;
        return;
    }
    while(cur->val!=x)
    {
        cur2=cur;
        if(cur->val>x)
            cur=cur->st;
        else if(cur->val<x)
            cur=cur->dr;
        if(cur==NULL)
        {
            cout<<"nu exista";
            break;
        }
    }
    if(cur->dr==NULL&&cur->st==NULL){
        cur2->dr=NULL;
        cur2->st=NULL;
        delete cur;
    }
    else if(cur->dr!=NULL&&cur->st!=NULL){
        cur2=cur;
        cur=cur->st;
        while(cur->dr->dr!=NULL){
            cur=cur->dr;
        }
        cur2->val=cur->dr->val;
        cur2=cur;
        cur=cur->dr;
        cur2->dr=cur->st;
        delete cur;
    }
    else if(cur!=NULL){
        cur2=cur;
        if(cur->dr!=NULL)
            cur=cur->dr;
        else
            cur=cur->st;
        cur2->val=cur->val;
        cur2->dr=NULL;
        cur2->st=NULL;
        delete cur;
    }
}
int ABC::inaltime(Nod *a)
{
        if(a==NULL)
            return 0;
        return 1+max(inaltime(a->st),inaltime(a->dr));
}
void ABC::frunze(Nod *a)
{
    if(a->st!=NULL)
        frunze(a->st);
    if(a->dr!=NULL)
        frunze(a->dr);
    if(a->dr==NULL&&a->st==NULL)
        cout<<a->val<<' ';
}
