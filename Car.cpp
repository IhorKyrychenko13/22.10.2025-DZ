#include "Car.h"
Car::Car() : Vehicle("Car", "Unknown", "Unknown", 0, 0, 0) { seats = 0; }
Car::Car(const char* model, const char* color, int year, double price, double maxSpeed, int seats)
    : Vehicle("Car", model, color, year, price, maxSpeed) {
    this->seats = seats;
}
Car::~Car() {}
int Car::getSeats() const { return seats; }
void Car::show() const {
    cout << "\n[����������]\n";
    cout << "������: " << model << endl;
    cout << "����: " << color << endl;
    cout << "г�: " << year << endl;
    cout << "ֳ��: " << price << endl;
    cout << "����. ��������: " << maxSpeed << endl;
    cout << "ʳ������ ����: " << seats << endl;
}