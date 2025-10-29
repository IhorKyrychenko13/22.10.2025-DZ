#pragma once
#include "Vehicle.h"
class Car : public Vehicle {
    int seats;
public:
    Car();
    Car(const char* model, const char* color, int year, double price, double maxSpeed, int seats);
    ~Car();
    int getSeats() const;
    void show() const override;
};