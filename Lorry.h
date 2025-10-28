#pragma once
#include "Vehicle.h"
class Lorry : public Vehicle {
protected:
    double capacity;
public:
    Lorry() : Vehicle("Lorry", "Íåâ³äîìèé", 0, 0, 0) {
        capacity = 0;
    }
    Lorry(const char* color, int year, double price, double speed, double capacity)
        : Vehicle("Lorry", color, year, price, speed) {
        this->capacity = capacity;
    }
    void setCapacity(double c) { capacity = c; }
    double getCapacity() const { return capacity; }
    void show() const override {
        cout << "\n[ÂÀÍÒÀÆ²ÂÊÀ]\n";
        cout << "Êîë³ð: " << color << endl;
        cout << "Ð³ê: " << year << endl;
        cout << "Ö³íà: " << price << " ãðí\n";
        cout << "Ìàêñ. øâèäê³ñòü: " << maxSpeed << " êì/ãîä\n";
        cout << "Âàíòàæîï³äéîìí³ñòü: " << capacity << " ò\n";
    }
};