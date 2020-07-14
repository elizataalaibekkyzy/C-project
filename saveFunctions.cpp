#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Artifact.h"
#include "Division.h"
#include "Service.h"
#include "saveFunctions.h"

using namespace std;

// Function that provides the ability to read a file
bool saveDivisions(vector<Division *> &divisions) {
    const string divDB = "divDB.txt";
    fstream fileDB;
    fileDB.open(divDB, ios::out|ios::trunc);

    if (fileDB.is_open()) {
        cout << "Division file opened successfully to save" <<endl;

        for (size_t i = 0; i < divisions.size(); ++i) {
            fileDB<<divisions[i]->guid<<endl;
            fileDB<<divisions[i]->name<<endl;
            fileDB<<divisions[i]->phoneNumber<<endl;
            fileDB<<divisions[i]->description<<endl;
            fileDB<<(divisions[i]->parent!=NULL? divisions[i]->parent->guid : "NULL")<<endl;
        }

        cout << "Divisions saved" << endl;
        cout<<"Division = ["<<endl;
        for (auto div : divisions) {
            cout << "{" <<endl;
            cout << "   id: " << div->guid << ","<< endl;
            cout << "   name: " << div->name << ","<< endl;
            cout << "   phone number: " << div->phoneNumber << ","<< endl;
            cout << "   description: " << div->description << endl;
            cout<<"},"<<endl;
        }
        cout<<"]"<<endl;
        fileDB.close();
        return true;
    } else {
        // Prompt user with error message
        cout << "Fail save divisions to db file." << endl;
        return false;
    }
}

bool saveArtifacts(vector<Artifact *> &artifacts) {
    const string artDB = "artDB.txt";
    fstream fileDB;
    fileDB.open(artDB, ios::out|ios::trunc);

    if (fileDB.is_open()) {
        cout << "Artifacts file opened successfully to save" <<endl;

        for (size_t i=0; i<artifacts.size(); ++i) {
            fileDB<<artifacts[i]->guid<<endl;
            fileDB<<artifacts[i]->name<<endl;
            fileDB<<artifacts[i]->description<<endl;
            fileDB<<artifacts[i]->category<<endl;
            fileDB<<artifacts[i]->division->guid<<endl;
            fileDB<<artifacts[i]->price<<endl;
            fileDB<<artifacts[i]->discount<<endl;
            fileDB<<artifacts[i]->quantity<<endl;
            fileDB<<(artifacts[i]->discountType == DiscountType::amount? 1 : 2)<<endl;
        }

        cout << "Artifacts saved" << endl;
        for (auto art : artifacts) {
            cout << "name: "<<art->name <<", "<< "the Total Price: " << art->getTotalPrice() << endl;
        }
        fileDB.close();
        return true;
    } else {
        // Prompt user with error message
        cout << "Fail save artifacts to db file." <<endl;
        return false;
    }
}

bool saveServices(vector<Service *> &services) {
    const string srvDB = "srvDB.txt";
    fstream fileDB;
    fileDB.open(srvDB, ios::out|ios::trunc);

    if (fileDB.is_open()) {
        cout << "Services file opened successfully to save" <<endl;

        for (size_t i = 0; i < services.size(); ++i) {
            fileDB<<services[i]->duration<<endl;
            fileDB<<services[i]->rate<<endl;
            fileDB<<services[i]->rateDiscount<<endl;
            fileDB<<(services[i]->rateDiscountType == DiscountType::amount ? 1 : 2)<<endl;
            fileDB<<services[i]->art->guid<<endl;
        }

        cout << "Services saved" << endl;
        for (auto srv : services) {
            cout << "the Total Price: " << srv->getTotalPrice() << endl;
        }
        fileDB.close();
        return true;
    } else {
        // Prompt user with error message
        cout << "Fail save services to db file." <<endl;
        return false;
    }
}

bool saveFactory(vector<Division *> &divisions, vector<Artifact *> &artifacts,
                 vector<Service *> &services) {
    if (!saveDivisions(divisions)) {
        return false;
    }

    if (!saveArtifacts(artifacts)) {
        return false;
    }

    if (!saveServices(services)) {
        return false;
    }

    return true;
}
