//добавлем к предыдущей функции декоратор
#include <iostream>
#include <functional>
#include <chrono>
#include <iomanip>
using namespace std;

void task(int n) {
  int cnt = 0;

  for (int i = 2; 1LL * i * i <= n; i++) {
    if (n % i == 0) {
      cnt++;

      while (n % i == 0) {
        n /= i;
      }
    }
  }

  if (n > 1) {
    cnt++;
  }

  cout << "Количество простых делителей: " << cnt << '\n';
}

function<void(int)> decorator(function<void(int)> f) {
  return [f](int n) {
    cout << "Начало выполнения\n";

    auto start = chrono::steady_clock::now();

    f(n);

    auto finish = chrono::steady_clock::now();

    cout << "Время: "
         << fixed << setprecision(30) << chrono::duration<double>(finish - start).count()
         << " секунд\n";

    cout << "Конец выполнения\n";
  };
}

int main() {
  int n;
  cin >> n;

  function<void(int)> decoratedTask = decorator(task);

  decoratedTask(n);

  cout << '\n';

  task(n);
}
