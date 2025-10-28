#pragma once
#include "Car.h"
#include "Bicycle.h"
#include "Lorry.h"
class Garage {
    Vehicle** arr;
    int size;
public:
    Garage() {
        arr = nullptr;
        size = 0;
    }
    ~Garage() {
        deleteAll();
    }
    void add(Vehicle* v) {
        Vehicle** tmp = new Vehicle * [size + 1];
        for (int i = 0; i < size; i++)
            tmp[i] = arr[i];
        tmp[size] = v;
        delete[] arr;
        arr = tmp;
        size++;
    }
    void showAll() const {
        if (size == 0) {
            cout << "Гараж порожній!\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << "\nНомер #" << i + 1 << endl;
            arr[i]->show();
        }
    }
    void deleteByIndex(int index) {
        if (index < 0 || index >= size) return;
        delete arr[index];
        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }
    void searchByType(const char* t) const {
        for (int i = 0; i < size; i++) {
            if (strcmp(arr[i]->getType(), t) == 0)
                arr[i]->show();
        }
    }
    void searchBySpeedType(const char* t, double s) const {
        for (int i = 0; i < size; i++) {
            if (strcmp(arr[i]->getType(), t) == 0 && arr[i]->getMaxSpeed() >= s)
                arr[i]->show();
        }
    }
    void sortBySpeed() {
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
    void edit(int index) {
        if (index < 0 || index >= size) return;
        double newPrice;
        char newColor[20];
        cout << "Нова ціна: "; cin >> newPrice;
        cin.ignore();
        cout << "Новий колір: "; cin.getline(newColor, 20);
        arr[index]->setPrice(newPrice);
        arr[index]->setColor(newColor);
    }
    void deleteAll() {
        for (int i = 0; i < size; i++)
            delete arr[i];
        delete[] arr;
        arr = nullptr;
        size = 0;
    }
};