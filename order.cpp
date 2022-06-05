#include "order.h"
#include "orderDefinitions.h"
#include <iostream>
#include "stringFormats.h"

SimpleOrder::SimpleOrder()
{
    char* oTempBuffer;  
    printf(STRING_FORMAT, REF_NUM_REQUEST);
    std::scanf(STRING_FORMAT, oTempBuffer);
    m_title = oTempBuffer;
    printf(STRING_FORMAT, DATE_REQUEST);
    std::scanf(STRING_FORMAT, oTempBuffer);
    m_date = oTempBuffer;
    printf(STRING_FORMAT, PRICE_REQUEST);
    scanf(FLOAT_FORMAT, &m_price);
}

SimpleOrder::SimpleOrder(std::string newName, std::string newDate, float newPrice)
{
    m_title = newName;
    m_date = newDate;
    m_price = newPrice;
}

void SimpleOrder::changeDate(std::string newDate)
{
    m_date=newDate;
}

void SimpleOrder::changePrice(float newPrice)
{
    m_price=newPrice;
}

void SimpleOrder::changeTitle(std::string newTitle)
{
    m_title=newTitle;
}

std::string SimpleOrder::getDate() const
{
    return m_date;
}

std::string SimpleOrder::getTitle() const
{
    return m_title;
}

float SimpleOrder::getPrice() const
{
    return m_price;
}

void SimpleOrder::printall() const
{
    printf(REF_NUM_PRINTOUT, m_title.c_str());
    printf(DATE_PRINTOUT, m_date.c_str());
    printf(PRICE_PRINTOUT, m_price);
    std::cin.ignore();
    std::cin.get();
}

SimpleOrder::~SimpleOrder()
{
}

OrdersManager::OrdersManager()
{
}

const OrdersMap& OrdersManager::GetOrders() const
{
    return m_OrdersMap;
}
bool OrdersManager::AddOrder(std::string oOrderId, const SimpleOrder& oOrder)
{
    bool bReturn = false;
    if(m_OrdersMap.find(oOrderId) == m_OrdersMap.end())
    {
        m_OrdersMap.insert({oOrderId, oOrder});
        bReturn = true;
    }
    return bReturn;
}
bool OrdersManager::ClearOrder(std::string oOrderId)
{
    bool bReturn = false;
    if(m_OrdersMap.find(oOrderId) != m_OrdersMap.end())
    {
        m_OrdersMap.erase(oOrderId);
        bReturn = true;
    }
    return bReturn;
}

void OrdersManager::ChangeOrder(std::string oOrderId,
                    std::string oDate, float fPrice)
{
    m_OrdersMap.emplace(std::make_pair(oOrderId, SimpleOrder(oOrderId, oDate, fPrice)));
}


SimpleOrder& SimpleOrder::operator=(SimpleOrder Incoming)
{
        std::swap(m_date, Incoming.m_date);
        std::swap(m_price,Incoming.m_price);
        std::swap(m_title,Incoming.m_title);
        return *this;
}
