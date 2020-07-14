#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Artifact.h"
#include "Division.h"
#include "Service.h"

using namespace std;

bool AddDivision(vector<Division *> &divisions) {
  string guid, name, phone_number, description;
  cout << "Please enter the Division id" << endl;
  cin.ignore();
  getline(cin, guid);
  cout << "Please enter the Division name" << endl;
  getline(cin, name);
  cout << "Please enter the Division phone number" << endl;
  getline(cin, phone_number);
  cout << "Please enter the Division description" << endl;
  getline(cin, description);

  if (guid == "" || name == "" || phone_number == "" || description == "") {
    cout << "Failed to pushed new artifact" << endl;
    return false;
  } else {
    for (size_t i = 0; i < divisions.size(); ++i) {
      if (divisions[i]->guid == guid) {
        cout << "The guid is already used" << endl;
        return false;
      }
    }

    Division *div;
    if (divisions.size() == 0) {
      div = new Division(guid, name, phone_number, description, NULL);
    } else {
      div = new Division(guid, name, phone_number, description,
                         divisions[divisions.size() - 1]);
    }

    divisions.push_back(div);
    cout << "Pushed a new Division" << endl;
  }

  return true;
}

bool AddArtifcat(vector<Artifact *> &artifacts, vector<Division *> &divisions) {
  string guid;
  string name;
  string description;
  string category;
  Division *division;
  double price;
  double discount;
  DiscountType discountType;
  int quantity;

  int option;

  cout << "Please enter the Artifcat id" << endl;
  cin.ignore();
  getline(cin, guid);
  cout << "Please enter the Artifcat name" << endl;
  getline(cin, name);
  cout << "Please enter the Artifcat description" << endl;
  getline(cin, description);
  cout << "Please enter the Artifcat category" << endl;
  getline(cin, category);
  cout << "Please enter the Artifcat price" << endl;
  cin >> price;
  cout << "Please enter the Artifcat discount" << endl;
  cin >> discount;
  while (1) {
    cout << "Please choose number of the discount type 1: amount or 2: "
            "percentage  "
         << endl;
    cin >> option;
    if (option == 1) {
      DiscountType discountType = amount;
      break;
    } else if (option == 2) {
      DiscountType discountType = percentage;
      break;
    } else {
      cout << "Warning! Wrong input. Please choose amount or percentage"
           << endl;
    }
  }

  cout << "Please enter the Artifcat quantity" << endl;
  cin >> quantity;

  Artifact *art;
  if (divisions.size() == 0) {
    cout << "Division is required to produce artifact!" << endl;
    return false;
  }

  if (guid == "" || name == "" || category == "" || price <= 0 ||
      quantity <= 0) {
    cout << "Invalid artifact parameters!" << endl;
    return false;
  } else {
    while (1) {
      cout
          << "Please enter division id from where you want to produce artifcat:"
          << endl;
      string div_guid;
      cin >> div_guid;
      bool found = false;
      for (size_t i = 0; i < divisions.size(); i++) {
        Division *div = divisions[i];
        if (div->guid == div_guid) {
          found = true;
          art = new Artifact(guid, name, description, category, div, price,
                             discount, discountType, quantity);
        }
      }

      if (found) {
        break;
      }

      cout << "Please enter correct Division guid!" << endl;
    }
  }

  artifacts.push_back(art);
  cout << "Pushed a new Artifact with id and name " << name << " " << guid
       << endl;

  return true;
}

bool AddService(vector<Service *> &services, vector<Artifact *> &artifacts) {
  double duration;
  double rate;
  double rateDiscount;
  DiscountType rateDiscountType;

  cout << "Please enter the Service duration in hours " << endl;
  cin >> duration;
  cout << "Please enter the Service rate " << endl;
  cin >> rate;
  cout << "Please enter the Service rate discount " << endl;
  cin >> rateDiscount;

  int option;
  while (1) {
    cout << "Please choose number of the rate discount type 1: amount or 2: "
            "percentage  "
         << endl;
    cin >> option;
    if (option == 1) {
      DiscountType rateDiscountType = amount;
      break;
    } else if (option == 2) {
      DiscountType rateDiscountType = percentage;
      break;
    } else {
      cout << "Warning! Wrong input. Please choose amount or percentage"
           << endl;
    }
  }

  Service *srv = NULL;
  if (artifacts.size() == 0) {
    cout << "Please create artifact first to apply service. Artifcat is empty "
            "now!"
         << endl;
    return false;
  }

  if (rate < 0 || rateDiscount < 0) {
    cout << "rate or rete discount can't be negative!" << endl;
    return false;
  } else {
    while (1) {
      cout << "Please enter artifact id that you want to apply service:"
           << endl;
      string art_guid;
      cin >> art_guid;
      bool found = false;
      for (size_t i = 0; i < artifacts.size(); ++i) {
        if (artifacts[i]->guid == art_guid) {
          found = true;
          srv = new Service(duration, rate, rateDiscount, rateDiscountType,
                            artifacts[i]);
        }
      }

      if (found) {
        break;
      }

      cout << "Please enter correct artifcat guid!" << endl;
    }
  }

  services.push_back(srv);
  cout << "Pushed a new Service" << endl;

  return true;
}