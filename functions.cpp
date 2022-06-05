#include "functions.h"
#include "UserMessages.h"
#include "stringFormats.h"

InterfaceManager::InterfaceManager()
{

}

void InterfaceManager::menu()
{
    print_menu();
    EMenuCase eCase= EMenuCase::eUndefined;
    
    while(eCase != EMenuCase::eCloseManager)
    {
        print_menu();
        eCase = GetMainCaseFromconsole();
        switch (eCase)
        {
        case EMenuCase::eAddOrder:
        {
            SimpleOrder neworder;
            if(!m_OrdersManager.AddOrder(neworder.getTitle(), neworder))
            {
                printf(STRING_FORMAT, ALREADY_EXISTS);
            }
            break;
        }   
        case EMenuCase::eChangeOrder:
        {
            menu_case_2();
            break;
        }
        case EMenuCase::eClearOrder:
        {
            printf(STRING_FORMAT, CHOOSE_REF_NUM);
            for(OrdersMapPair oPair : m_OrdersManager.GetOrders())
            {
                printf(STRING_FORMAT_ENDL, oPair.first.c_str());
            }
            char *RefNum;
            scanf(STRING_FORMAT, RefNum);
            if(!m_OrdersManager.ClearOrder(RefNum))
            {
                printf(STRING_FORMAT, DOES_NOT_EXIST);
            }
            break;
        }
        case EMenuCase::eShowOrders:
        {
            for( const OrdersMapPair oPair : m_OrdersManager.GetOrders() )
            {
                oPair.second.printall();
            }
            break;
        }
        case EMenuCase::eUndefined:
        default:
            break;
        }
    }
}

void InterfaceManager::print_menu()
{
    system(SYS_CLEAR);
    printf(STRING_FORMAT, CHOOSE_OPTION);
    printf(STRING_FORMAT, ADD_NEW_ORDER);
    printf(STRING_FORMAT, AMEND_EXISTING_ORDER);
    printf(STRING_FORMAT, DELETE_EXISTING_ORDER);
    printf(STRING_FORMAT, PRINTOUT_ORDERS);
    printf(STRING_FORMAT, END_PROGRAM);
}

EMenuCase InterfaceManager::GetMainCaseFromconsole()
{
    EMenuCase eReturn = EMenuCase::eUndefined;
    char choice;
    scanf(CHAR_FORMAT, &choice);
    choice = std::toupper(choice);
    if (oMainOptionMap.find(choice) != oMainOptionMap.end())
    {
        eReturn = oMainOptionMap.at(choice);
    }
    return eReturn;
}


EAttributeChangeCase InterfaceManager::GetAttrChangeCaseFromConsole()
{
    EAttributeChangeCase eReturn = EAttributeChangeCase::eUndefined;
    char choice;
    scanf(CHAR_FORMAT, &choice);
    choice = std::toupper(choice);
    if (oAttrChangeOptionMap.find(choice) != oAttrChangeOptionMap.end())
    {
        eReturn = oAttrChangeOptionMap.at(choice);
    }
    return eReturn;
}

void InterfaceManager::menu_case_2()
{
    printf(STRING_FORMAT, CHOOSE_REF_NUM);
    char *RefNum;
    scanf(STRING_FORMAT, RefNum);
    if(m_OrdersManager.GetOrders().find(RefNum) != m_OrdersManager.GetOrders().end())
    {
        m_OrdersManager.GetOrders().at(RefNum).printall();

        printf(STRING_FORMAT, CHOOSE_ELEMENT_TO_CHANGE);
        EAttributeChangeCase eCase = GetAttrChangeCaseFromConsole();
        switch (eCase)
        {
            case EAttributeChangeCase::eChangeDate:
            {
                std::string oNewDate;
                std::getline(std::cin, oNewDate);
                SimpleOrder oTempOrder = m_OrdersManager.GetOrders().at(RefNum);
                m_OrdersManager.ChangeOrder(RefNum, oNewDate,
                                            oTempOrder.getPrice());
                break;
            }
            case EAttributeChangeCase::eChangePrice:
            {
                std::string oNewPrice;
                std::getline(std::cin, oNewPrice);
                SimpleOrder oTempOrder = m_OrdersManager.GetOrders().at(RefNum);
                m_OrdersManager.ChangeOrder(RefNum, oTempOrder.getDate(),
                                            atof(oNewPrice.c_str()));
                break;
            }
            case EAttributeChangeCase::eChangeTitle:
            case EAttributeChangeCase::eUndefined:
            default:
            {
                printf(STRING_FORMAT, NO_ACTION_MSG);
                break;
            }
        }
    }
    else
    {
        printf(STRING_FORMAT, DOES_NOT_EXIST);
    }
}