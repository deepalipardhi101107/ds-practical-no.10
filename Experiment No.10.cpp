#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class FlightGraph {
    map<string, vector<pair<string, float> > > adjList;

public:
    void addFlight(string u, string v, float time) {
        adjList[u].push_back(make_pair(v, time));
        adjList[v];
    }

    void displayAdjacencyList() {
        cout << "\n--- Flight Network Adjacency List ---\n";

        map<string, vector<pair<string, float> > >::iterator it;

        for (it = adjList.begin(); it != adjList.end(); ++it) {
            cout << it->first << " -> ";

            for (int i = 0; i < it->second.size(); i++) {
                cout << "[" << it->second[i].first << ", "
                     << it->second[i].second << " hrs] ";
            }

            cout << endl;
        }
    }

    void DFS(string currentCity, set<string>& visited) {
        visited.insert(currentCity);
        cout << currentCity << " -> ";

        vector<pair<string, float> > neighbors = adjList[currentCity];

        for (int i = 0; i < neighbors.size(); i++) {
            string nextCity = neighbors[i].first;

            if (visited.find(nextCity) == visited.end()) {
                DFS(nextCity, visited);
            }
        }
    }

    bool checkConnectivity(string startCity, int totalCities) {
        set<string> visited;

        if (adjList.find(startCity) == adjList.end()) {
            cout << "\nStarting city does not exist in the graph.\n";
            return false;
        }

        cout << "\nDFS Traversal starting from " << startCity << ":\n";
        DFS(startCity, visited);
        cout << "END\n";

        if (visited.size() == totalCities) {
            cout << "\nResult: All " << totalCities
                 << " cities are reachable! The graph is connected.\n";
            return true;
        } else {
            cout << "\nResult: Only " << visited.size() << " out of "
                 << totalCities
                 << " cities are reachable. Graph is not fully connected.\n";
            return false;
        }
    }
};

int main() {
	cout << "------------------------------" << endl;
    cout << "Name: Deepali Pardhi" << endl;
    cout << "Class: FY B.Tech" << endl;
    cout << "Roll No.: 214" << endl;
    cout << "------------------------------" << endl;

    FlightGraph network;
    int totalCities = 5;

    network.addFlight("Mumbai", "Delhi", 2.0);
    network.addFlight("Mumbai", "Pune", 0.5);
    network.addFlight("Delhi", "Bangalore", 2.5);
    network.addFlight("Pune", "Bangalore", 1.5);
    network.addFlight("Bangalore", "Chennai", 1.0);

    network.displayAdjacencyList();
    network.checkConnectivity("Mumbai", totalCities);

    return 0;
}
