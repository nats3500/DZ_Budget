#pragma once
#include "Account.h"
class CreditCard :
    public Account
{
public:
    CreditCard(std::string nameAccaunt ="Кредитная карта", const float maxCreditLimit = 0.0f) : Account(nameAccaunt, maxCreditLimit), maxCreditLimit{maxCreditLimit}
    {
        debt = 0.0f;
    }
    //Установка кредитного лимита
    void setMaxCreditLimit(float maxCreditLimit);
    
    //пополнение счета кошелька или карты
    virtual void refill(std::string& discription,
        const float money, const unsigned year, const unsigned month, const unsigned day) override;
    //расходные операции
    virtual void expenditure( std::string& discription,
        const float money, const unsigned year, const unsigned month, const unsigned day, const int categorie) override;
    //показать данные по счёту
    virtual void showAccaunt()const override ;

private:
    float maxCreditLimit;
    float debt;
};

