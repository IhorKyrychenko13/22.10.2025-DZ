#include "Bicycle.h"
Bicycle::Bicycle() : Vehicle("Bicycle", "Unknown", "Unknown", 0, 0, 0) { hasGears = false; }
Bicycle::Bicycle(const char* model, const char* color, int year, double price, double maxSpeed, bool hasGears)
    : Vehicle("Bicycle", model, color, year, price, maxSpeed) {
    this->hasGears = hasGears;
}
Bicycle::~Bicycle() {}
bool Bicycle::getGears() const { return hasGears; }
void Bicycle::show() const {
    cout << "\n[���������]\n";
    cout << "������: " << model << endl;
    cout << "����: " << color << endl;
    cout << "г�: " << year << endl;
    cout << "ֳ��: " << price << endl;
    cout << "����. ��������: " << maxSpeed << endl;
    cout << "��������: " << (hasGears ? "�" : "����") << endl;
}