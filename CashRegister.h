#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include "Product.h"

class Receipt {
public:

    // Кірістірілген класс
    class PaymentInfo {
    public:
        string method;
        double amount;

        PaymentInfo(string m, double a);
        void showPayment();
    };

private:
    double total;

public:
    Receipt();

    void addAmount(double sum);
    double getTotal() const;

    void printReceipt(PaymentInfo payment);
    void clear();
};

class CashRegister {
private:

    // Агрегация
    Product* products[10];

    int size;

    // Композиция
    Receipt receipt;

    static int salesCount;

public:
    CashRegister();

    void addProduct(Product& p);
    void showProducts();

    void sellProduct(int index, int quantity);

    void pay(string method);

    static int getSalesCount();
};
