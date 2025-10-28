#include <iostream>
#include <Windows.h>
#include "Garage.h"
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Garage garage;
    int choice;
    do {
        cout << "\n========== МЕНЮ ==========\n";
        cout << "1. Додати автомобіль\n";
        cout << "2. Додати велосипед\n";
        cout << "3. Додати вантажівку\n";
        cout << "4. Показати всі\n";
        cout << "5. Видалити за номером\n";
        cout << "6. Пошук за типом\n";
        cout << "7. Пошук за типом і швидкістю\n";
        cout << "8. Редагування\n";
        cout << "9. Сортування за швидкістю\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            char color[20]; int year; double price, speed; int seats;
            cout << "Колір: "; cin.getline(color, 20);
            cout << "Рік: "; cin >> year;
            cout << "Ціна: "; cin >> price;
            cout << "Швидкість: "; cin >> speed;
            cout << "Кількість місць: "; cin >> seats;
            cin.ignore();
            garage.add(new Car(color, year, price, speed, seats));
        }
        else if (choice == 2) {
            char color[20]; int year; double price, speed; char ans;
            cout << "Колір: "; cin.getline(color, 20);
            cout << "Рік: "; cin >> year;
            cout << "Ціна: "; cin >> price;
            cout << "Швидкість: "; cin >> speed;
            cout << "Є передачі (y/n)? "; cin >> ans;
            cin.ignore();
            garage.add(new Bicycle(color, year, price, speed, ans == 'y' || ans == 'Y'));
        }
        else if (choice == 3) {
            char color[20]; int year; double price, speed, cap;
            cout << "Колір: "; cin.getline(color, 20);
            cout << "Рік: "; cin >> year;
            cout << "Ціна: "; cin >> price;
            cout << "Швидкість: "; cin >> speed;
            cout << "Вантажопідйомність (т): "; cin >> cap;
            cin.ignore();
            garage.add(new Lorry(color, year, price, speed, cap));
        }
        else if (choice == 4) garage.showAll();
        else if (choice == 5) {
            int n;
            cout << "Номер для видалення: "; cin >> n;
            garage.deleteByIndex(n - 1);
        }
        else if (choice == 6) {
            char t[20];
            cout << "Тип (Car / Bicycle / Lorry): ";
            cin.getline(t, 20);
            garage.searchByType(t);
        }
        else if (choice == 7) {
            char t[20]; double s;
            cout << "Тип: "; cin.getline(t, 20);
            cout << "Мінімальна швидкість: "; cin >> s;
            garage.searchBySpeedType(t, s);
        }
        else if (choice == 8) {
            int n;
            cout << "Номер для редагування: "; cin >> n;
            garage.edit(n - 1);
        }
        else if (choice == 9) {
            garage.sortBySpeed();
            cout << "Відсортовано!\n";
        }
    } while (choice != 0);
    garage.deleteAll();
    cout << "Вихід з програми.\n";
    return 0;
}