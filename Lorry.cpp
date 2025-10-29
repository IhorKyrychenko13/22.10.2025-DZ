#include "Lorry.h"
Lorry::Lorry() : Vehicle("Lorry", "Unknown", "Unknown", 0, 0, 0) { capacity = 0; }
Lorry::Lorry(const char* model, const char* color, int year, double price, double maxSpeed, double capacity)
    : Vehicle("Lorry", model, color, year, price, maxSpeed) {
    this->capacity = capacity;
}
Lorry::~Lorry() {}
double Lorry::getCapacity() const { return capacity; }
void Lorry::show() const {
    cout << "\n[ÂÀÍÒÀÆ²ÂÊÀ]\n";
    cout << "Ìîäåëü: " << model << endl;
    cout << "Êîë³ð: " << color << endl;
    cout << "Ð³ê: " << year << endl;
    cout << "Ö³íà: " << price << endl;
    cout << "Ìàêñ. øâèäê³ñòü: " << maxSpeed << endl;
    cout << "Âàíòàæîï³äéîìí³ñòü: " << capacity << " ò\n";
}