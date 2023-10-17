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
    void Initialization::OutputRegistrationMenu() //регистрация пользователя
    {
        system("cls");
        VisibleCursor(true);

        string login = "";
        string password = "";
        string confirmPassword = "";
        string cardRec = "";

        cout << "Меню регистрации нового пользователя...\n";
        cout << "Для формирования нового аккаунта требуется придумать логин и пароль.\n\n";
        cout << "Логин: ";
        cin >> login;
        cout << "Пароль: ";
        cin >> password;
        cout << "Повторите пароль: ";
        cin >> confirmPassword;
        if (analizData.UserAnalizator(login))
        {
            cout << "Такой пользователь уже существует.\nПовторите попытку регистрации!";
            _getch();
            OutputRegistrationMenu();
        }
        if (password == confirmPassword)
        {
            string kostyl = "";
            cout << "Регистрация успешно завершена. Пожалуйста, введите номер карточки, срок действия и CVC/CVV-код без пробелов!\n ";
            cout << "Данные: ";
            cin >> cardRec;
            cout << "Срок действия: ";
            cin.clear();
            cin >> kostyl;
            cardRec += " " + kostyl;
            kostyl = "";
            cout << "CVC/CVV-код: ";
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
            cout << "Пароли не совпадают! Повторите попытку регистрации!";
            _getch();
            OutputRegistrationMenu();
        }

    }

    void Initialization::OutputAuthorizationMenu()//авторизация пользователя
    {
        system("cls");
        VisibleCursor(true);
        string login = "";
        string password = "";
        cout << "Авторизация пользователя.\nБудьте внимательны, поля Логин и Пароль чувствительны к регистру.\n\n";
        cout << "Введите логин: ";
        cin >> login;
        cout << "Введите пароль: ";
        cin >> password;
        
        if (analizData.UserAnalizator(login, password)) {
            cout << endl << "Аторизация прошла успешно!\nНажмите любую кнопку, чтобы продолжить...";
            char c = _getch();
            Catalog::Catalog(login, analizData.CardRec(login, password));
        }
        else {
            cout << "Неправильный логин или пароль!\nЕсли вы еще не зарегистрированы, то сделайте это и вернитесь на форму авторизации.\nНажмите любую кнопку, чтобы продолжить...";
            char c = _getch();
            UnknownMenuUser();
        }
    }
    
    

    void Initialization::UnknownMenuUser() //главное меню
    {
        system("cls");
        VisibleCursor(false);

        cout << "Приветсвуем в приложении \"КомпьюТех\".\nДанное приложение предназначено для заказа компьютерных комплектующих.\nПеред началом вам необходимо авторизоваться.\nЕсли Вы новый пользователь, то требуется произвести регистрацию." << endl << endl;
        cout << "1. Авторизация\n2. Регистрация" << endl << endl;
        cout << "Выберите вариант...";
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
