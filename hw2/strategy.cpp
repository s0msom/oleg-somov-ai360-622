//программа помогающая считать цену учитывая скидку
#include <iostream>
#include <functional>
using namespace std;

double noDiscount(double price) {
  return price;
}

double studentDiscount(double price) {
  return price * 0.9;
}

double vipDiscount(double price) {
  return price * 0.8;
}

void checkout(double price, function<double(double)> strategy) {
  cout << "Стоимость товаров: " << price << '\n';

  double result = strategy(price);

  cout << "Скидка: " << price - result << '\n';
  cout << "К оплате: " << result << '\n';
}

int main() {
  double price;

  cout << "Введите стоимость покупки: ";
  cin >> price;

  cout << "\nВыберите тип скидки:\n";
  cout << "1 - Без скидки\n";
  cout << "2 - Студенческая скидка (10%)\n";
  cout << "3 - VIP скидка (20%)\n";
  cout << "Введите номер скидки (1-3): ";

  int choice;
  cin >> choice;

  function<double(double)> strategy = noDiscount;

  if (choice == 2) {
    strategy = studentDiscount;
  } else if (choice == 3) {
    strategy = vipDiscount;
  }

  cout << "\nРезультат покупки:\n";
  checkout(price, strategy);
}
