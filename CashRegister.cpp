#include "CashRegister.h"

int CashRegister::salesCount = 0;

// PaymentInfo конструкторы
Receipt::PaymentInfo::PaymentInfo(string m, double a) {
    method = m;
    amount = a;
}

void Receipt::PaymentInfo::showPayment() {
    cout << "Төлем түрі: " << method << endl;
    cout << "Төленген сома: " << amount << " тг" << endl;
}

// Receipt конструкторы
Receipt::Receipt() {
    total = 0;
}

void Receipt::addAmount(double sum) {
    total += sum;
}

double Receipt::getTotal() const {
    return total;
}

void Receipt::printReceipt(PaymentInfo payment) {
    cout << "\n----- ЧЕК -----" << endl;
    cout << "Жалпы сома: " << total << " тг" << endl;

    payment.showPayment();

    cout << "---------------" << endl;
}

void Receipt::clear() {
    total = 0;
}

// CashRegister конструкторы
CashRegister::CashRegister() {
    size = 0;
}

// Тауар қосу
void CashRegister::addProduct(Product& p) {
    if (size < 10) {
        products[size] = &p;
        size++;
    }
}

// Каталог көрсету
void CashRegister::showProducts() {
    cout << "\n--- ТАУАРЛАР ---" << endl;

    for (int i = 0; i < size; i++) {
        cout << i << ". ";
        products[i]->showInfo();
    }
}

// Тауар сату
void CashRegister::sellProduct(int index, int quantity) {

    if (index < 0 || index >= size || quantity <= 0) {
        cout << "Қате енгізілді!" << endl;
        return;
    }

    double sum = products[index]->getPrice() * quantity;

    receipt.addAmount(sum);

    cout << products[index]->getName()
         << " x " << quantity
         << " = " << sum << " тг" << endl;
}

// Төлем жасау
void CashRegister::pay(string method) {

    if (receipt.getTotal() <= 0) {
        cout << "Алдымен тауар сатыңыз!" << endl;
        return;
    }

    Receipt::PaymentInfo payment(method, receipt.getTotal());

    receipt.printReceipt(payment);

    salesCount++;

    receipt.clear();
}

// Статикалық әдіс
int CashRegister::getSalesCount() {
    return salesCount;
}
