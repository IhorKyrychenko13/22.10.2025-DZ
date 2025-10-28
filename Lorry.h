#pragma once
#include "Vehicle.h"
class Lorry : public Vehicle {
protected:
    double capacity;
public:
    Lorry() : Vehicle("Lorry", "��������", 0, 0, 0) {
        capacity = 0;
    }
    Lorry(const char* color, int year, double price, double speed, double capacity)
        : Vehicle("Lorry", color, year, price, speed) {
        this->capacity = capacity;
    }
    void setCapacity(double c) { capacity = c; }
    double getCapacity() const { return capacity; }
    void show() const override {
        cout << "\n[�����Ʋ���]\n";
        cout << "����: " << color << endl;
        cout << "г�: " << year << endl;
        cout << "ֳ��: " << price << " ���\n";
        cout << "����. ��������: " << maxSpeed << " ��/���\n";
        cout << "����������������: " << capacity << " �\n";
    }
};