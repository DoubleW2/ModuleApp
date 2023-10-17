#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include "Catalog.h"
#include "InitUser.h"
#include "Analizators.h"

using namespace std;


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Analizators analizData;
    void Initialization::OutputRegistrationMenu() //����������� ������������
    {
        system("cls");
        VisibleCursor(true);

        string login = "";
        string password = "";
        string confirmPassword = "";
        string cardRec = "";

        cout << "���� ����������� ������ ������������...\n";
        cout << "��� ������������ ������ �������� ��������� ��������� ����� � ������.\n\n";
        cout << "�����: ";
        cin >> login;
        cout << "������: ";
        cin >> password;
        cout << "��������� ������: ";
        cin >> confirmPassword;
        if (analizData.UserAnalizator(login))
        {
            cout << "����� ������������ ��� ����������.\n��������� ������� �����������!";
            _getch();
            OutputRegistrationMenu();
        }
        if (password == confirmPassword)
        {
            string kostyl = "";
            cout << "����������� ������� ���������. ����������, ������� ����� ��������, ���� �������� � CVC/CVV-��� ��� ��������!\n ";
            cout << "������: ";
            cin >> cardRec;
            cout << "���� ��������: ";
            cin.clear();
            cin >> kostyl;
            cardRec += " " + kostyl;
            kostyl = "";
            cout << "CVC/CVV-���: ";
            cin.clear();
            cin >> kostyl;
            cardRec += " " + kostyl;
            ofstream out("Users.txt", ios::app);
            if (out.is_open())
            {
                out << login << "|" << password << "|" << cardRec << endl;
            }
            out.close();
            _getch();
            UnknownMenuUser();
        }
        else
        {
            cout << "������ �� ���������! ��������� ������� �����������!";
            _getch();
            OutputRegistrationMenu();
        }

    }

    void Initialization::OutputAuthorizationMenu()//����������� ������������
    {
        system("cls");
        VisibleCursor(true);
        string login = "";
        string password = "";
        cout << "����������� ������������.\n������ �����������, ���� ����� � ������ ������������� � ��������.\n\n";
        cout << "������� �����: ";
        cin >> login;
        cout << "������� ������: ";
        cin >> password;
        
        if (analizData.UserAnalizator(login, password)) {
            cout << endl << "���������� ������ �������!\n������� ����� ������, ����� ����������...";
            char c = _getch();
            Catalog::Catalog(login, analizData.CardRec(login, password));
        }
        else {
            cout << "������������ ����� ��� ������!\n���� �� ��� �� ����������������, �� �������� ��� � ��������� �� ����� �����������.\n������� ����� ������, ����� ����������...";
            char c = _getch();
            UnknownMenuUser();
        }
    }
    
    

    void Initialization::UnknownMenuUser() //������� ����
    {
        system("cls");
        VisibleCursor(false);

        cout << "����������� � ���������� \"���������\".\n������ ���������� ������������� ��� ������ ������������ �������������.\n����� ������� ��� ���������� ��������������.\n���� �� ����� ������������, �� ��������� ���������� �����������." << endl << endl;
        cout << "1. �����������\n2. �����������" << endl << endl;
        cout << "�������� �������...";
        char c = _getch();
        if (c == '1')
        {
            OutputAuthorizationMenu();
        }
        else if (c == '2')
        {
            OutputRegistrationMenu();
        }
    }

    void Initialization::VisibleCursor(bool visibility)
    {
        CONSOLE_CURSOR_INFO cci;
        visibility == true ? cci.dwSize = 99 : cci.dwSize = 0;
        cci.bVisible = visibility;
        SetConsoleCursorInfo(hConsole, &cci);
    }
