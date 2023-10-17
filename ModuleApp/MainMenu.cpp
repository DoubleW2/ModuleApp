#include <iostream>
#include <conio.h>
#include <windows.h>
#include <winuser.h>
#include "InitUser.h"
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Initialization init;
    init.UnknownMenuUser();
    return 0;
}

