#include <iostream>
#include <string>
#include <vector>

#include "Artifact.h"
#include "Division.h"
#include "Service.h"
#include <fstream>

bool AddDivision(vector<Division *> &divisions);
bool AddArtifcat(vector<Artifact *> &artifacts, vector<Division *> &divisions);
bool AddService(vector<Service *> &services, vector<Artifact *> &artifacts);