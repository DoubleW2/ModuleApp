#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <list>
#include "Catalog.h"
#include "InitUser.h"

using namespace std;


    string login = ""; //����� ������������ (������������ � �������� ��������������)
    string req = "�����������";
    list<string> basketList;

    Catalog::Catalog(string _login, string _req)
    {
        login = _login;
        req = _req;
        OutputMenu();
    }

    void Catalog::Profile()
    {
        system("cls");
        cout << "��� �������: \n";
        cout << "��� ������������: " << login << endl;
        cout << "��������� ��� ������: " << req;
        _getch();
        OutputMenu();
    }

    void Catalog::OutputMenu() //�������� ��������� ���� ��������/������������
    {
        system("cls");
        //����� ����
        cout << "������������, " << login << endl;
        cout << "�� ���� ������������!\n�������� ������� ���������� ��������!\n\n";
        cout << "1. �������\n";
        cout << "2. �������\n";
        cout << "3. ���������� ������ ������\n";
        cout << "4. �������\n";
        cout << "5. ����� ������������\n\n";
        cout << "�������� �������...";
        char c = _getch();
        if (c == '1') //���� ������ 1
        {
            InitCatalog();
            return;
        }
        if (c == '2')//���� ������ 2
        {
            InitBasket();
            return;
        }
        if (c == '3')//���� ������ 3
        {
            AddNewProduct();
            return;
        }
        if (c == '4')//���� ������ 4
        {
            Profile();
            return;
        }
        if (c == '5')
        {
            Initialization init;
            init.UnknownMenuUser();
        }
    }

    void Catalog::InitBasket() //�������� ������� ������������
    {
        system("cls");
        cout << "���� �������.\n\n";
        for (string n: basketList)
        {
            cout << n << endl;
        }
        cout << endl << "0 - �������� �������.\n1 - ����������� ������";
        char c = _getch();
        if (c == '0')
        {
            OutputMenu();
        }
        else if (c == '1')
        {
            cout << endl << endl << "����������, �� ��������� ���, ��� ���� � ����� �������.\n���� ��������: 30 ������� 2077 ����.\n��� ����������� � ������� ���� ������� ����� ������...";
            _getch();
            basketList.clear();
            OutputMenu();
        }
    }

    void Catalog::AddNewProduct() //����� ���������� ������ ������
    {
        system("cls");
        string nameProduct = "";
        string descriptionProduct = "";
        string costProduct = "";
        cout << "�� ������� �� ����� ���������� ������ ������.\n������ ������� �������� ������ ������������� ���������� � ��� ������������� ��������� ������ ����������� ���.\n\n";
        cin.ignore();
        cout << "������� ������������ ������:  ";
        getline(cin, nameProduct);
        cout << "������� �������� ������:  ";
        getline(cin, descriptionProduct);
        cout << "������� ��������� (���.):  ";
        getline(cin, costProduct);
        //������ ���������� � ����� ������ � ����
        ofstream out("Catalog.txt", ios::app);
        if (out.is_open())
        {
            out << nameProduct << " | " << descriptionProduct << " | " << costProduct << " ���." << endl;
        }
        out.close();
        cout << "������� ����� ������, ����� ��������� � ����...";
        char c = _getch();
        OutputMenu();
    }

    void Catalog::InitCatalog() //����� ������������� �������� (����� ���� ������� �� �����)
    {
        system("cls");
        string str;
        cout << "������� �������...\n";
        cout << "��� ���������� ������� � ������� ���������� ������ �� �����.\n���� �� �� ������ ������ ���������, �� ������� 0...\n\n";
        ifstream read("Catalog.txt");
        if (read.is_open())
        {
            for (int i = 1; getline(read, str); i++)
            {
                cout << i << ") " << str << endl << endl;
            }
        }
        int input = 0;
        cout << "������� ��������� ��������: ";
        cin >> input;
        if (input != 0)
        {
            ifstream read("Catalog.txt");
            if (read.is_open())
            {
                for (int i = 1; getline(read, str); i++)
                {
                    if (i == input) {
                        basketList.push_back(str);
                        cout << "����� ������� �������� � �������!\n0 - �������� �������\n1 - ���������� �������";
                        cout << endl << "��� �����...";
                        char c = _getch();
                        if (c == '1')
                        {
                            InitCatalog();
                        }
                        else if (c == '0')
                        {
                            OutputMenu();
                        }
                        
                    }
                }
            }
        }
        else if (input == 0)
        {
            OutputMenu();
        }
    }

