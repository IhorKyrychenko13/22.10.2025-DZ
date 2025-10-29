#include "Garage.h"
#include <iostream>
using namespace std;
Garage::Garage() {
    arr = nullptr;
    size = 0;
}
Garage::~Garage() {
    deleteAll();
}
void Garage::add(Vehicle* v) {
    Vehicle** tmp = new Vehicle * [size + 1];
    for (int i = 0; i < size; i++) tmp[i] = arr[i];
    tmp[size] = v;
    delete[] arr;
    arr = tmp;
    size++;
}
void Garage::showAll() const {
    if (size == 0) {
        cout << "Гараж порожній.\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "\nНомер #" << i + 1 << endl;
        arr[i]->show();
    }
}
void Garage::deleteByIndex(int index) {
    if (index < 0 || index >= size) {
        cout << "Невірний індекс.\n";
        return;
    }
    delete arr[index];
    if (size == 1) {
        delete[] arr;
        arr = nullptr;
        size = 0;
        return;
    }
    Vehicle** tmp = new Vehicle * [size - 1];
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (i == index) continue;
        tmp[k++] = arr[i];
    }
    delete[] arr;
    arr = tmp;
    size--;
}
void Garage::searchByType(const char* t) const {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i]->getType(), t) == 0) {
            arr[i]->show();
            found = true;
        }
    }
    if (!found) cout << "Не знайдено об'єктів типу " << t << endl;
}
Vehicle* Garage::findByIndex(int index) const {
    if (index < 0 || index >= size) return nullptr;
    return arr[index];
}
void Garage::searchByTypeAndSpeed(const char* t, double s) const {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i]->getType(), t) == 0 && arr[i]->getMaxSpeed() >= s) {
            arr[i]->show();
            found = true;
        }
    }
    if (!found) cout << "Не знайдено.\n";
}
void Garage::edit(int index) {
    if (index < 0 || index >= size) {
        cout << "Невірний індекс.\n";
        return;
    }
    double newPrice;
    char newColor[30];
    cout << "Нова ціна: "; cin >> newPrice; cin.ignore(32767, '\n');
    cout << "Новий колір: "; cin.getline(newColor, 30);
    arr[index]->setPrice(newPrice);
    arr[index]->setColor(newColor);
    cout << "Збережено.\n";
}
void Garage::sortBySpeed() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i]->getMaxSpeed() > arr[j]->getMaxSpeed()) {
                Vehicle* tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
void Garage::deleteAll() {
    for (int i = 0; i < size; i++) delete arr[i];
    delete[] arr;
    arr = nullptr;
    size = 0;
}
bool Garage::loadFromFile(const char* filename) {
    ifstream f(filename);
    if (!f.is_open()) return false;

    char typeLine[20];
    while (true) {
        if (!f.getline(typeLine, sizeof(typeLine))) break;
        if (strlen(typeLine) == 0) continue;

        if (strcmp(typeLine, "Car") == 0) {
            char model[60], color[30];
            int year; double price, speed; int seats;
            f.getline(model, sizeof(model));
            f.getline(color, sizeof(color));
            f >> year;
            f >> price;
            f >> speed;
            f >> seats;
            f.ignore(32767, '\n');
            add(new Car(model, color, year, price, speed, seats));
        }
        else if (strcmp(typeLine, "Bicycle") == 0) {
            char model[60], color[30];
            int year; double price, speed; int gears;
            f.getline(model, sizeof(model));
            f.getline(color, sizeof(color));
            f >> year;
            f >> price;
            f >> speed;
            f >> gears;
            f.ignore(32767, '\n');
            add(new Bicycle(model, color, year, price, speed, gears != 0));
        }
        else if (strcmp(typeLine, "Lorry") == 0) {
            char model[60], color[30];
            int year; double price, speed, capacity;
            f.getline(model, sizeof(model));
            f.getline(color, sizeof(color));
            f >> year;
            f >> price;
            f >> speed;
            f >> capacity;
            f.ignore(32767, '\n');
            add(new Lorry(model, color, year, price, speed, capacity));
        }
        else {
        }
    }
    f.close();
    return true;
}
bool Garage::saveToFile(const char* filename) const {
    ofstream f(filename);
    if (!f.is_open()) return false;
    for (int i = 0; i < size; i++) {
        f << arr[i]->getType() << "\n";
        f << arr[i]->getModel() << "\n";
        f << arr[i]->getColor() << "\n";
        f << arr[i]->getYear() << "\n";
        f << arr[i]->getPrice() << "\n";
        f << arr[i]->getMaxSpeed() << "\n";
        if (strcmp(arr[i]->getType(), "Car") == 0) {
            Car* c = (Car*)arr[i];
            f << c->getSeats() << "\n\n";
        }
        else if (strcmp(arr[i]->getType(), "Bicycle") == 0) {
            Bicycle* b = (Bicycle*)arr[i];
            f << (b->getGears() ? 1 : 0) << "\n\n";
        }
        else if (strcmp(arr[i]->getType(), "Lorry") == 0) {
            Lorry* l = (Lorry*)arr[i];
            f << l->getCapacity() << "\n\n";
        }
    }
    f.close();
    return true;
}