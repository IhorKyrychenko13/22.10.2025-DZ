#pragma once
#include "Vehicle.h"
class Lorry : public Vehicle {
    double capacity;
public:
    Lorry();
    Lorry(const char* model, const char* color, int year, double price, double maxSpeed, double capacity);
    ~Lorry();
    double getCapacity() const;
    void show() const override;
};