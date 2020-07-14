#ifndef DIVISION_H
#define DIVISION_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Division {
public:
    vector<std::string> art_ids;
    string guid;
    string name;
    string phoneNumber;
    string description;
    Division* parent;
    
	Division(){};
    Division(string guid, string name, string phoneNumber, string description, Division* parent);
};

#endif

