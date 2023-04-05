#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "Trip.h"

using namespace std;

unordered_map<string, string> fromNode, toNode;
std::vector<Trip> trips;

void createNode(){

    ifstream inFile("info.txt");
    if (!inFile) {
        cerr << "Could not open file info.txt" << endl;
        return;
    }

    string line, nodeType;
    while (getline(inFile, line)) {
        if (line == "fromNode") {
            nodeType = "from";
        }
        else if (line == "toNode") {
            nodeType = "to";
        }
        else {
            size_t pos = line.find(": ");
            if (pos != string::npos) {
                string node = line.substr(0, pos);
                string id = line.substr(pos + 2);
                if (nodeType == "from") {
                    fromNode[node] = id;
                }
                else if (nodeType == "to") {
                    toNode[node] = id;
                }
            }
        }
    }
    inFile.close();
}

void createTrips(){
    ifstream testFile("test.txt");
    int identifier = 0;
    if (testFile.is_open()) {
        string from, to, line;
        int numTrips;
        while (getline(testFile, line)) {
            istringstream iss(line);
            getline(iss, from, '-');
            getline(iss, to, ':');
            iss >> numTrips;

            string fromNodeId = fromNode[from];
            string toNodeId = toNode[to];

            for (int i = 0; i < numTrips; i++) {
                int id = identifier++;
                double depart = double(i)/10;

                trips.push_back(Trip(id, depart, fromNodeId, toNodeId));
            }
        }
        testFile.close();
    } else {
        cout << "Unable to open file test.txt" << endl;
        return;
    }
}

void generateTrips(){

    ofstream ouFile("map_nttd.trips.xml");
    ouFile << "<trips>" << endl;
    for (const auto& trip : trips) {
        ouFile << "    <trip id=\"" << trip.GetId() << "\" depart=\"" << trip.GetDepart()
                  << "\" from=\"" << trip.GetFrom() << "\" to=\"" << trip.GetTo() << "\"/>" << endl;
    }
    ouFile << "</trips>" << endl;
    system("duarouter -n map_nttd.net.xml --route-files map_nttd.trips.xml -o map_nttd.rou.xml");
}

int main()
{
    createNode();
    createTrips();
    generateTrips();
    return 0;
}

