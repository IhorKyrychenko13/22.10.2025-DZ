#include <iostream>
#include <Windows.h>
#include "Garage.h"
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Garage garage;
    int choice;
    if (garage.loadFromFile("garage.txt"))
        cout << "Завантажено дані з garage.txt\n";
    else
        cout << "garage.txt не знайдено або порожній\n";
    do {
        cout << "\n========== МЕНЮ ==========\n";
        cout << "1. Додати автомобіль\n";
        cout << "2. Додати велосипед\n";
        cout << "3. Додати вантажівку\n";
        cout << "4. Показати всі\n";
        cout << "5. Видалити за номером\n";
        cout << "6. Пошук за типом\n";
        cout << "7. Пошук за типом і швидкістю\n";
        cout << "8. Редагування (ціна/колір)\n";
        cout << "9. Сортування за швидкістю\n";
        cout << "10. Зберегти в файл garage_out.txt\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore(32767, '\n');
        if (choice == 1) {
            char model[60], color[30];
            int year; double price, speed; int seats;
            cout << "Модель: "; cin.getline(model, 60);
            cout << "Колір: "; cin.getline(color, 30);
            cout << "Рік: "; cin >> year; cin.ignore(32767, '\n');
            cout << "Ціна: "; cin >> price; cin.ignore(32767, '\n');
            cout << "Швидкість: "; cin >> speed; cin.ignore(32767, '\n');
            cout << "Кількість місць: "; cin >> seats; cin.ignore(32767, '\n');
            garage.add(new Car(model, color, year, price, speed, seats));
        }
        else if (choice == 2) {
            char model[60], color[30];
            int year; double price, speed; char ans;
            cout << "Модель: "; cin.getline(model, 60);
            cout << "Колір: "; cin.getline(color, 30);
            cout << "Рік: "; cin >> year; cin.ignore(32767, '\n');
            cout << "Ціна: "; cin >> price; cin.ignore(32767, '\n');
            cout << "Швидкість: "; cin >> speed; cin.ignore(32767, '\n');
            cout << "Є передачі (y/n)? "; cin >> ans; cin.ignore(32767, '\n');
            garage.add(new Bicycle(model, color, year, price, speed, ans == 'y' || ans == 'Y'));
        }
        else if (choice == 3) {
            char model[60], color[30];
            int year; double price, speed, cap;
            cout << "Модель: "; cin.getline(model, 60);
            cout << "Колір: "; cin.getline(color, 30);
            cout << "Рік: "; cin >> year; cin.ignore(32767, '\n');
            cout << "Ціна: "; cin >> price; cin.ignore(32767, '\n');
            cout << "Швидкість: "; cin >> speed; cin.ignore(32767, '\n');
            cout << "Вантажопідйомність (т): "; cin >> cap; cin.ignore(32767, '\n');
            garage.add(new Lorry(model, color, year, price, speed, cap));
        }
        else if (choice == 4) {
            garage.showAll();
        }
        else if (choice == 5) {
            int n;
            cout << "Номер для видалення: "; cin >> n; cin.ignore(32767, '\n');
            garage.deleteByIndex(n - 1);
        }
        else if (choice == 6) {
            char t[20];
            cout << "Тип (Car / Bicycle / Lorry): "; cin.getline(t, 20);
            garage.searchByType(t);
        }
        else if (choice == 7) {
            char t[20]; double s;
            cout << "Тип: "; cin.getline(t, 20);
            cout << "Мінімальна швидкість: "; cin >> s; cin.ignore(32767, '\n');
            garage.searchByTypeAndSpeed(t, s);
        }
        else if (choice == 8) {
            int n;
            cout << "Номер для редагування: "; cin >> n; cin.ignore(32767, '\n');
            garage.edit(n - 1);
        }
        else if (choice == 9) {
            garage.sortBySpeed();
            cout << "Відсортовано.\n";
        }
        else if (choice == 10) {
            if (garage.saveToFile("garage_out.txt"))
                cout << "Збережено в garage_out.txt\n";
            else
                cout << "Не вдалося зберегти файл.\n";
        }
    } while (choice != 0);
    garage.deleteAll();
    cout << "Вихід.\n";
    return 0;
}