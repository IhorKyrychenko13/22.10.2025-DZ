#pragma once
#include "Vehicle.h"
class Bicycle : public Vehicle {
protected:
    bool hasGears;
public:
    Bicycle() : Vehicle("Bicycle", "��������", 0, 0, 0) {
        hasGears = false;
    }
    Bicycle(const char* color, int year, double price, double speed, bool gears)
        : Vehicle("Bicycle", color, year, price, speed) {
        hasGears = gears;
    }
    void setGears(bool g) { hasGears = g; }
    bool getGears() const { return hasGears; }
    void show() const override {
        cout << "\n[���������]\n";
        cout << "����: " << color << endl;
        cout << "г�: " << year << endl;
        cout << "ֳ��: " << price << " ���\n";
        cout << "����. ��������: " << maxSpeed << " ��/���\n";
        cout << "��������: " << (hasGears ? "�" : "����") << endl;
    }
};