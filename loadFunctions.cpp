#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Artifact.h"
#include "Division.h"
#include "Service.h"
#include "loadFunctions.h"

using namespace std;

bool checkFile(ifstream &IO){
    //the function checks if the length of the data file is more than 0 to start reading from it
    if(IO.fail())return 0;
    IO.seekg(0,ios::end);
    return (IO.tellg()>0);
}

// Function that provides the ability to read a file
bool loadDivisions(vector<Division *> &divisions) {
    const string divDB = "divDB.txt";
    ifstream fileDB;
    fileDB.open(divDB, ios::in);

    if (fileDB.is_open() && checkFile(fileDB)) {
        fileDB.seekg(0,ios::beg);
        cout << "Division file opened successfully" << endl;
        string guid, name, phoneNumber, description, pDivisionGuid;
        while (getline(fileDB, guid)) {
            getline(fileDB, name);
            getline(fileDB, phoneNumber);
            getline(fileDB, description);
            getline(fileDB, pDivisionGuid);
            Division *pDivision = NULL;
            for (int i = 0; i < divisions.size(); ++i) {
                if (divisions[i]->guid == pDivisionGuid) {
                    pDivision = divisions[i];
                }
            }

            Division *tempDiv =
                new Division(guid, name, phoneNumber, description, pDivision);
            divisions.push_back(tempDiv);
            cout<<"Division with GUID: "<<guid<<" and name: "<<name<<" is loaded"<<endl;
        }

        cout << "*** Divisions loaded ***" <<endl<<endl;
        fileDB.close();
        return true;
    } else {
        // Prompt user with error message
        cout << "*** Fail to read divisions db file. ***" <<endl<<endl;
        return false;
    }
}

bool loadArtifacts(vector<Artifact *> &artifacts,
                   vector<Division *> &divisions) {
    const string artDB = "artDB.txt";
    ifstream fileDB;
    fileDB.open(artDB, ios::in);

    if (fileDB.is_open() && checkFile(fileDB)) {
        fileDB.seekg(0,ios::beg);
        cout << "Artifact file opened successfully" <<endl;
        string guid, name, description, category, divisionGuid;
        string sprice, sdiscount, squantity, discountOption;
        while (getline(fileDB, guid)) {
            getline(fileDB, name);
            getline(fileDB, description);
            getline(fileDB, category);
            getline(fileDB, divisionGuid);
            getline(fileDB, sprice);
            getline(fileDB, sdiscount);
            getline(fileDB, squantity);
            getline(fileDB, discountOption);
            double price = stod(sprice), discount=stod(sdiscount), quantity=stod(squantity);

            DiscountType discType =
                (discountOption == "1" ? DiscountType::amount
                                     : DiscountType::percentage);
            Division *division = NULL;
            for (int i = 0; i < divisions.size(); ++i) {
                if (divisions[i]->guid == divisionGuid) {
                    division = divisions[i];
                }
            }

            Artifact *tempArt =
                new Artifact(guid, name, description, category, division, price,
                             discount, discType, quantity);
            artifacts.push_back(tempArt);
            cout<<"Artifact with GUID: "<<guid<<" and name: "<<name<<" is loaded"<<endl;
        }

        cout << "*** Artifacts loaded ***" <<endl<<endl;
        fileDB.close();
        return true;
    } else {
        // Prompt user with error message
        cout << "*** Fail to read artifact db file. ***" <<endl<<endl;
        return false;
    }
}

bool loadServices(vector<Service *> &services, vector<Artifact *> &artifacts) {
    const string srvDB = "srvDB.txt";
    ifstream fileDB;
    fileDB.open(srvDB, ios::in);

    if (fileDB.is_open() && checkFile(fileDB)) {
        fileDB.seekg(0,ios::beg);
        cout << "Service file opened successfully" <<endl;
        string sduration, srate, srateDiscount, discountOption, artifactGuid;
        while (getline(fileDB, sduration)) {
            getline(fileDB, srate);
            getline(fileDB, srateDiscount);
            getline(fileDB, discountOption);
            getline(fileDB, artifactGuid);

            double duration = std::stod(sduration), rate = std::stod(srate);
            double rateDiscount = std::stod(srateDiscount);

            DiscountType discType =
                (discountOption == "1" ? DiscountType::amount
                                     : DiscountType::percentage);
            Artifact *artifact = NULL;
            for (int i = 0; i < artifacts.size(); ++i) {
                if (artifacts[i]->guid == artifactGuid) {
                    artifact = artifacts[i];
                }
            }

            Service *tempSrv =
                new Service(duration, rate, rateDiscount, discType, artifact);
            services.push_back(tempSrv);
            cout<<"There is a service for Artifact with GUID: "<<artifact->guid<<endl;
        }

        cout << "*** Services loaded ***" <<endl<<endl;
        fileDB.close();
        return true;
    } else {
        // Prompt user with error message
        cout << "*** Fail to read service db file. ***" <<endl<<endl;;
        return false;
    }
}

bool loadFactory(vector<Division *> &divisions, vector<Artifact *> &artifacts,
                 vector<Service *> &services) {
    if (!loadDivisions(divisions)) {
        return false;
    }

    if (!loadArtifacts(artifacts, divisions)) {
        return false;
    }

    if (!loadServices(services, artifacts)) {
        return false;
    }

    return true;
}
