//делаем функцию для подсчета простых делителей
#include <iostream>
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

int main() {
    int n;
    cin >> n;

    task(n);
}
