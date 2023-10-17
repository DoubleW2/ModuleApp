#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <list>
#include "Catalog.h"
#include "InitUser.h"

using namespace std;


    string login = ""; //логин пользователя (используется в качестве идентификатора)
    string req = "отсутствуют";
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
        cout << "Ваш профиль: \n";
        cout << "Имя пользователя: " << login << endl;
        cout << "Реквизиты для оплаты: " << req;
        _getch();
        OutputMenu();
    }

    void Catalog::OutputMenu() //открытие основного меню каталога/пользователя
    {
        system("cls");
        //Вывод меню
        cout << "Здравствуйте, " << login << endl;
        cout << "Вы были авторизованы!\nВыберите вариант дальнейших действий!\n\n";
        cout << "1. Каталог\n";
        cout << "2. Корзина\n";
        cout << "3. Добавление нового товара\n";
        cout << "4. Профиль\n";
        cout << "5. Смена пользователя\n\n";
        cout << "Выберите вариант...";
        char c = _getch();
        if (c == '1') //если выбран 1
        {
            InitCatalog();
            return;
        }
        if (c == '2')//если выбран 2
        {
            InitBasket();
            return;
        }
        if (c == '3')//если выбран 3
        {
            AddNewProduct();
            return;
        }
        if (c == '4')//если выбран 4
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

    void Catalog::InitBasket() //открытие корзины пользователя
    {
        system("cls");
        cout << "Ваша корзина.\n\n";
        for (string n: basketList)
        {
            cout << n << endl;
        }
        cout << endl << "0 - Покинуть корзину.\n1 - Подтвердить оплату";
        char c = _getch();
        if (c == '0')
        {
            OutputMenu();
        }
        else if (c == '1')
        {
            cout << endl << endl << "Поздравляю, вы приобрели все, что было в вашей корзине.\nСрок доставки: 30 февраля 2077 года.\nДля возвращения в главное меню нажмите любую кнопку...";
            _getch();
            basketList.clear();
            OutputMenu();
        }
    }

    void Catalog::AddNewProduct() //метод добавления нового товара
    {
        system("cls");
        string nameProduct = "";
        string descriptionProduct = "";
        string costProduct = "";
        cout << "Вы перешли на форму добавления нового товара.\nДанная функция доступна только администрации приложения и для подтверждения требуется ввсети проверочный код.\n\n";
        cin.ignore();
        cout << "Введите наименование товара:  ";
        getline(cin, nameProduct);
        cout << "Введите описание товара:  ";
        getline(cin, descriptionProduct);
        cout << "Введите стоимость (руб.):  ";
        getline(cin, costProduct);
        //Запись информации о новом товаре в файл
        ofstream out("Catalog.txt", ios::app);
        if (out.is_open())
        {
            out << nameProduct << " | " << descriptionProduct << " | " << costProduct << " руб." << endl;
        }
        out.close();
        cout << "Нажмите любую кнопку, чтобы вернуться в меню...";
        char c = _getch();
        OutputMenu();
    }

    void Catalog::InitCatalog() //метод инициализации каталога (вывод всех товаров на экран)
    {
        system("cls");
        string str;
        cout << "Каталог товаров...\n";
        cout << "Для добавления товаров в корзину необходимо ВВЕСТИ ее номер.\nЕсли вы НЕ ХОТИТЕ ничего добавлять, то введите 0...\n\n";
        ifstream read("Catalog.txt");
        if (read.is_open())
        {
            for (int i = 1; getline(read, str); i++)
            {
                cout << i << ") " << str << endl << endl;
            }
        }
        int input = 0;
        cout << "Введите выбранное значение: ";
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
                        cout << "Товар успешно добавлен в корзину!\n0 - Покинуть каталог\n1 - продолжить покупки";
                        cout << endl << "Ваш выбор...";
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

