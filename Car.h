#pragma once
#include "Vehicle.h"
class Car : public Vehicle {
protected:
    int seats;
public:
    Car() : Vehicle("Car", "��������", 0, 0, 0) {
        seats = 0;
    }
    Car(const char* color, int year, double price, double speed, int seats)
        : Vehicle("Car", color, year, price, speed) {
        this->seats = seats;
    }
    void setSeats(int s) { seats = s; }
    int getSeats() const { return seats; }
    void show() const override {
        cout << "\n[����������]\n";
        cout << "����: " << color << endl;
        cout << "г�: " << year << endl;
        cout << "ֳ��: " << price << " ���\n";
        cout << "����. ��������: " << maxSpeed << " ��/���\n";
        cout << "ʳ������ ����: " << seats << endl;
    }
};