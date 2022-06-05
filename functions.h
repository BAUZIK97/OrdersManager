#ifndef FUNKCJE_H
#define FUNKCJE_H
#include <iostream>
#include <string>
#include "order.h"
#include "stringFormats.h"

enum class EMenuCase
{
    eAddOrder,
    eChangeOrder,
    eClearOrder,
    eShowOrders,
    eCloseManager,
    eUndefined,
};

enum class EAttributeChangeCase
{
    eChangeTitle,
    eChangeDate,
    eChangePrice,
    eUndefined
};

static const std::map<char, EAttributeChangeCase> oAttrChangeOptionMap{
    {ONE_CHAR, EAttributeChangeCase::eChangeTitle},
    {TWO_CHAR, EAttributeChangeCase::eChangeDate},
    {THREE_CHAR, EAttributeChangeCase::eChangePrice},
};

static const std::map<char, EMenuCase> oMainOptionMap{
    {ONE_CHAR, EMenuCase::eAddOrder},
    {TWO_CHAR, EMenuCase::eChangeOrder},
    {THREE_CHAR, EMenuCase::eClearOrder},
    {FOUR_CHAR, EMenuCase::eShowOrders},
    {X_CHAR, EMenuCase::eCloseManager}
};

class InterfaceManager
{
public:
    InterfaceManager();
    void menu(/*vector<CZamowienie> orders*/);
    void print_menu();
    void menu_case_2();
    EMenuCase GetMainCaseFromconsole();
    EAttributeChangeCase GetAttrChangeCaseFromConsole();

private:
    OrdersManager m_OrdersManager;
};

#endif