
#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H
#include <string>
#include <map>
// the entire file
class SimpleOrder
{
private:
    /* data */
    std::string m_title;
    std::string m_date;
    float m_price;

public:
    SimpleOrder();
    SimpleOrder(std::string newName, std::string newDate, float newPrice);
    void changeDate(std::string newDate);
    void changePrice(float newPrice);
    void changeTitle(std::string newName);
    std::string getTitle() const;
    std::string getDate() const;
    float getPrice() const;
    void printall() const;
    ~SimpleOrder();
    SimpleOrder &operator=(SimpleOrder Incoming);
};

typedef std::map<std::string, SimpleOrder> OrdersMap;
typedef std::pair<std::string, SimpleOrder> OrdersMapPair;

class OrdersManager
{
public:
    OrdersManager();
    const OrdersMap &GetOrders() const;
    bool AddOrder(std::string oOrderId, const SimpleOrder& oOrder);
    bool ClearOrder(std::string oOrderId);
    void ChangeOrder(std::string oOrderId, std::string oDate,
                     float fPrice);

private:
    OrdersMap m_OrdersMap;
};
#endif