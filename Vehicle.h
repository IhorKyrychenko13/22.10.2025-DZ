#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Vehicle {
protected:
    char type[20];
    char color[20];
    int year;
    double price;
    double maxSpeed;
public:
    Vehicle() {
        strcpy_s(type, "Vehicle");
        strcpy_s(color, "Невідомий");
        year = 0;
        price = 0;
        maxSpeed = 0;
    }
    Vehicle(const char* type, const char* color, int year, double price, double maxSpeed) {
        strcpy_s(this->type, type);
        strcpy_s(this->color, color);
        this->year = year;
        this->price = price;
        this->maxSpeed = maxSpeed;
    }
    virtual ~Vehicle() {}
    const char* getType() const { return type; }
    const char* getColor() const { return color; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    double getMaxSpeed() const { return maxSpeed; }
    void setColor(const char* c) { strcpy_s(color, c); }
    void setYear(int y) { year = y; }
    void setPrice(double p) { price = p; }
    void setMaxSpeed(double s) { maxSpeed = s; }
    virtual void show() const = 0;
};