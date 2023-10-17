#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "Analizators.h"
using namespace std;

string Analizators::CardRec(string login, string password)
{
    string _login = "";
    string _password = "";
    string _cardRec = "";
    string str;

    ifstream read("Users.txt");
    if (read.is_open())
    {
        while (getline(read, str))
        {
            bool loginAut = false;
            bool passAut = false;
            for (int index = 0; index < str.length(); index++)
            {
                if (str[index] != '|' && !loginAut)
                {
                    _login += str[index];
                    continue;
                }
                else if (str[index] == '|' && !loginAut)
                {
                    loginAut = true;
                }
                else if (str[index] != '|' && loginAut && !passAut)
                {
                    _password += str[index];
                }
                else if (str[index] == '|')
                {
                    passAut = true;
                }
                else if (str[index] != str.length() - 1)
                {
                    _cardRec += str[index];
                    cout << str[index];
                }
            }
            cout << endl;
            if (_login == login && _password == password)
            {
                return _cardRec;
            }
            else
            {
                _cardRec = "";
                _login = "";
                _password = "";
            }
        }
    }
    read.close();
    return "отсутсвует";
}
bool Analizators::UserAnalizator(string login, string password)//сверка логина и пароля
{
    string _login = "";
    string _password = "";
    string str;

    ifstream read("Users.txt");
    if (read.is_open())
    {
        while (getline(read, str))
        {
            bool loginAut = false;
            bool passAut = false;
            for (int index = 0; index < str.length(); index++)
            {
                if (str[index] != '|' && !loginAut)
                {
                    _login += str[index];
                }
                else if (str[index] == '|' && !loginAut)
                {
                    loginAut = true;
                }
                else if (str[index] != '|' && loginAut && !passAut)
                {
                    _password += str[index];
                }
                else if (str[index] == '|') passAut = true;
            }
            if (_login == login && _password == password)
            {
                return true;
            }
            else
            {
                _login = "";
                _password = "";
            }
        }
    }
    read.close();
    return false;
}
bool Analizators::UserAnalizator(string login)//сверка логина
{
    string _login = "";
    string str;

    ifstream read("Users.txt");
    if (read.is_open())
    {
        while (getline(read, str))
        {
            bool loginAut = false;
            for (int index = 0; index < str.length(); index++)
            {
                if (str[index] != '|' && !loginAut)
                {
                    _login += str[index];
                    continue;
                }
                else if (str[index] == '|')
                {
                    index = index + 1;
                    loginAut = true;
                }
            }
            if (_login == login)
            {
                return true;
            }
            else
            {
                _login = "";
            }
        }
    }
    read.close();
    return false;
}