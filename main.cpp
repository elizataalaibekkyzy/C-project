#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Artifact.h"
#include "Division.h"
#include "Service.h"
#include "loadFunctions.h"
#include "saveFunctions.h"
#include "addFunctions.h"

using namespace std;

int main() {
  vector<Division *> divisions;
  vector<Artifact *> artifacts;
  vector<Service *> services;

  loadFactory(divisions, artifacts, services);

  while (1) {
    int wanted_to_enter;
    cout << "Choose what do you want to enter" << endl;
    cout << "1 Add Division" << endl;
    cout << "2 Add Artifcat" << endl;
    cout << "3 Add Service" << endl;
    cout << "0 Exit" << endl;
    cin >> wanted_to_enter;
    if (wanted_to_enter == 1) {
      AddDivision(divisions);
    } else if (wanted_to_enter == 2) {
      AddArtifcat(artifacts, divisions);
    } else if (wanted_to_enter == 3) {
      AddService(services, artifacts);
    } else {
      break;
    }
  }

  saveFactory(divisions, artifacts, services);

  return 0;
}
