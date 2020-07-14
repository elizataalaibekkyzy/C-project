#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <string>

#include "Artifact.h"

using namespace std;

class Service: public Artifact {
public:
	double duration;
    double rate;
    double rateDiscount;
    DiscountType rateDiscountType;
	Artifact* art;

    Service(
		double duration,
		double rate,
		double rateDiscount,
		DiscountType rateDiscountType,
		Artifact* art
	);

	double getEffectiveRate();
	double getTotalPrice();
};

#endif 
