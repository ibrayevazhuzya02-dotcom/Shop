#include "Product.h"

int Product::count = 0;

Product::Product(string n, double p) {
    name = n;
    price = p;
    count++;
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::showInfo() const {
    cout << name << " - " << price << " тг" << endl;
}

int Product::getCount() {
    return count;
}

// Дос функция
void showProduct(Product p) {
    cout << "Тауар: " << p.name << endl;
    cout << "Бағасы: " << p.price << " тг" << endl;
}

// DiscountProduct класы
DiscountProduct::DiscountProduct(string n, double p, double d)
    : Product(n, p) {
    discount = d;
}

double DiscountProduct::getPrice() const {
    return Product::getPrice() * (100 - discount) / 100;
}

void DiscountProduct::showInfo() const {
    cout << getName() << " - "
         << getPrice() << " тг (жеңілдік)" << endl;
}
