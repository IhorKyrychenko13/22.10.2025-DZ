#include "Bicycle.h"
Bicycle::Bicycle() : Vehicle("Bicycle", "Unknown", "Unknown", 0, 0, 0) { hasGears = false; }
Bicycle::Bicycle(const char* model, const char* color, int year, double price, double maxSpeed, bool hasGears)
    : Vehicle("Bicycle", model, color, year, price, maxSpeed) {
    this->hasGears = hasGears;
}
Bicycle::~Bicycle() {}
bool Bicycle::getGears() const { return hasGears; }
void Bicycle::show() const {
    cout << "\n[ÂÅËÎÑÈÏÅÄ]\n";
    cout << "Ìîäåëü: " << model << endl;
    cout << "Êîë³ð: " << color << endl;
    cout << "Ð³ê: " << year << endl;
    cout << "Ö³íà: " << price << endl;
    cout << "Ìàêñ. øâèäê³ñòü: " << maxSpeed << endl;
    cout << "Ïåðåäà÷³: " << (hasGears ? "º" : "íåìà") << endl;
}