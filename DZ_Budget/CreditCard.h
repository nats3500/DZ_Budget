#pragma once
#include "Account.h"
class CreditCard :
    public Account
{
public:
    CreditCard(std::string nameAccaunt ="��������� �����", const float maxCreditLimit = 0.0f) : Account(nameAccaunt, maxCreditLimit), maxCreditLimit{maxCreditLimit}
    {
        debt = 0.0f;
    }
    //��������� ���������� ������
    void setMaxCreditLimit(float maxCreditLimit);
    
    //���������� ����� �������� ��� �����
    virtual void refill(std::string& discription,
        const float money, const unsigned year, const unsigned month, const unsigned day) override;
    //��������� ��������
    virtual void expenditure( std::string& discription,
        const float money, const unsigned year, const unsigned month, const unsigned day, const int categorie) override;
    //�������� ������ �� �����
    virtual void showAccaunt()const override ;

private:
    float maxCreditLimit;
    float debt;
};

