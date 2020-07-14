#include <iostream>
#include <string>
#include <vector>

#include "Artifact.h"
#include "Division.h"
#include "Service.h"
#include <fstream>

bool saveFactory(vector<Division *> &divisions, vector<Artifact *> &artifact,
                 vector<Service *> &services);
bool saveDivisions(vector<Division *> &divisions);
bool saveArtifacts(vector<Artifact *> &artifacts);
bool saveServices(vector<Service *> &services);
