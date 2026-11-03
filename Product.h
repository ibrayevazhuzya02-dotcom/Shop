#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;

    static int count;

public:
    Product(string n, double p);

    string getName() const;
    double getPrice() const;

    virtual void showInfo() const;

    static int getCount();

    friend void showProduct(Product p);
};

// Мұрагерлік
class DiscountProduct : public Product {
private:
    double discount;

public:
    DiscountProduct(string n, double p, double d);

    double getPrice() const override;
    void showInfo() const override;
};
