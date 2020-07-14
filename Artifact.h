#ifndef ARTIFACT_H
#define ARTIFACT_H

#include <iostream>
#include <string>
#include <vector>

#include "Division.h"

enum DiscountType {
    amount,
    percentage
};

class Artifact{
public:
    std::string guid;
    std::string name;
    std::string description;
    std::string category;
    Division *division;
    double price;
    double discount;
    int quantity;
    DiscountType discountType;

    Artifact(Artifact* artifact);
    Artifact(std::string guid,
             std::string name,
             std::string description,
             std::string category,
             Division *division,
             double price,
             double discount,
             DiscountType discountType,
             int quantity);

    double getEffectivePrice();
    double getTotalPrice();
};
#endif

