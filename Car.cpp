#include "Car.h"
Car::Car() : Vehicle("Car", "Unknown", "Unknown", 0, 0, 0) { seats = 0; }
Car::Car(const char* model, const char* color, int year, double price, double maxSpeed, int seats)
    : Vehicle("Car", model, color, year, price, maxSpeed) {
    this->seats = seats;
}
Car::~Car() {}
int Car::getSeats() const { return seats; }
void Car::show() const {
    cout << "\n[ÀÂÒÎÌÎÁ²ËÜ]\n";
    cout << "Ìîäåëü: " << model << endl;
    cout << "Êîë³ğ: " << color << endl;
    cout << "Ğ³ê: " << year << endl;
    cout << "Ö³íà: " << price << endl;
    cout << "Ìàêñ. øâèäê³ñòü: " << maxSpeed << endl;
    cout << "Ê³ëüê³ñòü ì³ñöü: " << seats << endl;
}