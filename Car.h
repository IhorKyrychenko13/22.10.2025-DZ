#pragma once
#include "Vehicle.h"
class Car : public Vehicle {
protected:
    int seats;
public:
    Car() : Vehicle("Car", "Íåâ³äîìèé", 0, 0, 0) {
        seats = 0;
    }
    Car(const char* color, int year, double price, double speed, int seats)
        : Vehicle("Car", color, year, price, speed) {
        this->seats = seats;
    }
    void setSeats(int s) { seats = s; }
    int getSeats() const { return seats; }
    void show() const override {
        cout << "\n[ÀÂÒÎÌÎÁ²ËÜ]\n";
        cout << "Êîë³ğ: " << color << endl;
        cout << "Ğ³ê: " << year << endl;
        cout << "Ö³íà: " << price << " ãğí\n";
        cout << "Ìàêñ. øâèäê³ñòü: " << maxSpeed << " êì/ãîä\n";
        cout << "Ê³ëüê³ñòü ì³ñöü: " << seats << endl;
    }
};