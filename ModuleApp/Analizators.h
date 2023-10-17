#include <iostream>
using namespace std;

#pragma once
#ifndef ANALIZATORS_H
#define ANALIZATORS_H

class Analizators
{
public:
    bool UserAnalizator(string login, string password);
    bool UserAnalizator(string login);
    string CardRec(string login, string password);
};

#endif // !ANALIZATORS_H
