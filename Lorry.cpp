#include "Lorry.h"
Lorry::Lorry() : Vehicle("Lorry", "Unknown", "Unknown", 0, 0, 0) { capacity = 0; }
Lorry::Lorry(const char* model, const char* color, int year, double price, double maxSpeed, double capacity)
    : Vehicle("Lorry", model, color, year, price, maxSpeed) {
    this->capacity = capacity;
}
Lorry::~Lorry() {}
double Lorry::getCapacity() const { return capacity; }
void Lorry::show() const {
    cout << "\n[�����Ʋ���]\n";
    cout << "������: " << model << endl;
    cout << "����: " << color << endl;
    cout << "г�: " << year << endl;
    cout << "ֳ��: " << price << endl;
    cout << "����. ��������: " << maxSpeed << endl;
    cout << "����������������: " << capacity << " �\n";
}