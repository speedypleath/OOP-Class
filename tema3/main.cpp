#include <iostream>
#include <bits/stdc++.h>
#include <exception>
#include "parc.h"
using namespace std;

int main()
{
    unique_ptr<User> a(User::get_instance());
    a->create();
    a->vanzare();
    a->vanzare();
    a->stoc();
}
