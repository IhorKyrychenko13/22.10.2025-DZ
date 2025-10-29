#pragma once
#include "Vehicle.h"
class Bicycle : public Vehicle {
    bool hasGears;
public:
    Bicycle();
    Bicycle(const char* model, const char* color, int year, double price, double maxSpeed, bool hasGears);
    ~Bicycle();
    bool getGears() const;
    void show() const override;
};