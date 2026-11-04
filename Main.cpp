#include <iostream>
#include "Product.h"
#include "CashRegister.h"

using namespace std;

int main() {

    // Объектілер жиымы
    Product products[3] = {
        Product("Нан", 150),
        Product("Сүт", 450),
        Product("Шырын", 600)
    };

    // Жеңілдікпен сатылатын тауар
    DiscountProduct chocolate("Шоколад", 800, 10);

    // Касса объектісі
    CashRegister cash;

    // Тауарларды каталогқа қосу
    for (int i = 0; i < 3; i++) {
        cash.addProduct(products[i]);
    }

    cash.addProduct(chocolate);

    // Каталогты көрсету
    cash.showProducts();

    // Дос функция
    cout << "\n--- ТАУАР АҚПАРАТЫ ---" << endl;
    showProduct(products[0]);

    // Сату
    cout << "\n--- САТУ ---" << endl;

    cash.sellProduct(0, 2);
    cash.sellProduct(1, 1);
    cash.sellProduct(3, 1);

    // Төлем
    cash.pay("Kaspi");

    // Статикалық мүшелер
    cout << "\nҚұрылған тауар объектілерінің саны: "
         << Product::getCount() << endl;

    cout << "Сатылған чектер саны: "
         << CashRegister::getSalesCount() << endl;

    return 0;
}
