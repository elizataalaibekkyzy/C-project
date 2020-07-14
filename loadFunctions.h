#include <iostream>
#include <string>
#include <vector>

#include "Artifact.h"
#include "Division.h"
#include "Service.h"
#include <fstream>

bool loadFactory(vector<Division *> &divisions, vector<Artifact *> &artifact,
                 vector<Service *> &services);
bool loadDivisions(vector<Division *> &divisions);
bool loadArtifacts(vector<Artifact *> &artifacts,
                   vector<Division *> &divisions);
bool loadServices(vector<Service *> &services, vector<Artifact *> &artifacts);
