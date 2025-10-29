#pragma once
#include "Car.h"
#include "Bicycle.h"
#include "Lorry.h"
#include <fstream>
class Garage {
    Vehicle** arr;
    int size;
public:
    Garage();
    ~Garage();
    void add(Vehicle* v);
    void showAll() const;
    void deleteByIndex(int index);
    void searchByType(const char* t) const;
    Vehicle* findByIndex(int index) const;
    void searchByTypeAndSpeed(const char* t, double s) const;
    void edit(int index);
    void sortBySpeed();
    void deleteAll();

    bool loadFromFile(const char* filename);
    bool saveToFile(const char* filename) const;
};