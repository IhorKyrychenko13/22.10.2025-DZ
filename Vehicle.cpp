#include "Vehicle.h"
Vehicle::Vehicle() {
    strcpy_s(type, sizeof(type), "Vehicle");
    strcpy_s(model, sizeof(model), "Unknown");
    strcpy_s(color, sizeof(color), "Unknown");
    year = 0; price = 0; maxSpeed = 0;
}
Vehicle::Vehicle(const char* typeName, const char* model, const char* color, int year, double price, double maxSpeed) {
    strcpy_s(this->type, sizeof(this->type), typeName);
    strcpy_s(this->model, sizeof(this->model), model);
    strcpy_s(this->color, sizeof(this->color), color);
    this->year = year;
    this->price = price;
    this->maxSpeed = maxSpeed;
}
Vehicle::~Vehicle() {}
const char* Vehicle::getType() const { return type; }
const char* Vehicle::getModel() const { return model; }
const char* Vehicle::getColor() const { return color; }
int Vehicle::getYear() const { return year; }
double Vehicle::getPrice() const { return price; }
double Vehicle::getMaxSpeed() const { return maxSpeed; }
void Vehicle::setColor(const char* c) { strcpy_s(color, sizeof(color), c); }
void Vehicle::setPrice(double p) { price = p; }