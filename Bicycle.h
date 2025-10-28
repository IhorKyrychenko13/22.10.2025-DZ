#pragma once
#include "Vehicle.h"
class Bicycle : public Vehicle {
protected:
    bool hasGears;
public:
    Bicycle() : Vehicle("Bicycle", "Невідомий", 0, 0, 0) {
        hasGears = false;
    }
    Bicycle(const char* color, int year, double price, double speed, bool gears)
        : Vehicle("Bicycle", color, year, price, speed) {
        hasGears = gears;
    }
    void setGears(bool g) { hasGears = g; }
    bool getGears() const { return hasGears; }
    void show() const override {
        cout << "\n[ВЕЛОСИПЕД]\n";
        cout << "Колір: " << color << endl;
        cout << "Рік: " << year << endl;
        cout << "Ціна: " << price << " грн\n";
        cout << "Макс. швидкість: " << maxSpeed << " км/год\n";
        cout << "Передачі: " << (hasGears ? "є" : "нема") << endl;
    }
};