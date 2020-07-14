#include <iostream>
#include <string>

#include "Service.h"

using namespace std;

Service::Service(
        double duration,
        double rate,
        double rateDiscount,
        DiscountType rateDiscountType,
        Artifact* artifcat
) : Artifact(artifcat) {
    if (rateDiscount < 0) {
        throw;
    } else {
        this->rateDiscount = rateDiscount;
    }
    if (rate < 0) {
        throw;
    } else {
        this->rate = rate;
    }
    if (duration < 0) {
        throw;
    } else {
        this->duration = duration;
    }
    this->rateDiscountType = rateDiscountType;
    this->art = artifcat;
}
double Service::getEffectiveRate() {
    if (rateDiscountType == amount) {
        return this->rate - this->rateDiscount;
    } else {
        return this->rate - this->rate * this->rateDiscount / 100;
    }
}

double Service::getTotalPrice() {
    return Artifact::getTotalPrice() + this->getEffectiveRate() * this->duration;
}

