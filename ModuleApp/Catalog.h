#include <iostream>;
using namespace std;

#pragma once
#ifndef CATALOG_H
#define CATALOG_H


class Catalog //�������� ������ �������� � ������� ������������ (���� Catalog.cpp)
{
public:
    Catalog(string _login, string _req);
    void Profile();
    void OutputMenu();
    void InitBasket();
    void AddNewProduct();
    void InitCatalog();
};

#endif
