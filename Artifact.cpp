#include <iostream>
#include <string>
#include <vector>

#include "Artifact.h"

using namespace std;

Artifact::Artifact(Artifact* artifact) {
	this->guid = artifact->guid;
	this->name = artifact->name;
	this->description = artifact->description;
	this->category = artifact->category;
	this->price = artifact->price;
	this->discount = artifact->discount;
	this->quantity = artifact->quantity;
	this->discountType = artifact->discountType;
}

Artifact::Artifact(
	string guid,
	string name,
	string description,
	string category,
	Division *division,
	double price,
	double discount,
	DiscountType discountType,
	int quantity
) {
	if (price < 0) {
		throw;
	} else {
		this->price = price;
	}

	if (discount < 0) {
		throw;
	} else {
		this->discount = discount;
	}
	
	if (quantity < 0) {
		throw;
	} else {
		this->quantity = quantity;
	}

	this->guid = guid;
	this->name = name;
	this->description = description;
	this->category = category;
	this->discountType = discountType;
	this->division = division;
}

double Artifact::getEffectivePrice() {
	if(this->discountType == DiscountType::amount) {
		if(this->price - this->discount<0){
			throw;}
		else{return this->price - this->discount;}
	} else {
		if(this->price - this->price* this->discount/100<0)
			throw;
		else
		{
			return this->price - this->price* this->discount/100;
		}

	}
}

double Artifact:: getTotalPrice() {
	if(this->quantity * this->getEffectivePrice()<0){
		throw;
	}

	return this->quantity * this->getEffectivePrice();
}
