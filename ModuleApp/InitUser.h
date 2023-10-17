#include <iostream>
#include <string>
using namespace std;

#pragma once
#ifndef INITUSER_H
#define INITUSER_H
class Initialization { //Описание класса инициализации пользователя (файл InitUser.cpp)
public:
    void UnknownMenuUser();
    void OutputRegistrationMenu();
    void OutputAuthorizationMenu();
    void VisibleCursor(bool visibility);
    
};

#endif