#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Vehicle {
protected:
    char type[20];
    char model[60];
    char color[30];
    int year;
    double price;
    double maxSpeed;
public:
    Vehicle();
    Vehicle(const char* typeName, const char* model, const char* color, int year, double price, double maxSpeed);
    virtual ~Vehicle();
    const char* getType() const;
    const char* getModel() const;
    const char* getColor() const;
    int getYear() const;
    double getPrice() const;
    double getMaxSpeed() const;
    void setColor(const char* c);
    void setPrice(double p);
    virtual void show() const = 0;
};