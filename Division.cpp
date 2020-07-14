#include <iostream>

#include "Division.h"

using namespace std;

Division::Division(
    string guid,
    string name,
    string phoneNumber,
    string description,
    Division* parent
) {
    this->guid = guid;
    this->name = name;
    this->parent = parent;
    this->phoneNumber = phoneNumber;
    this->description = description;
}
