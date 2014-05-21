#include <iostream>
#include <limits>

#include "graph.h"

using namespace std;

int main() {

  string pathFile;
  cout << "Enter in path file: ";
  cin >> pathFile;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  Graph basicGraph(pathFile);
  basicGraph.LoadLocations();

  string start, destination;
  do
  {
    cout << "Enter in starting location: ";
    if (getline(cin, start) && start.empty()) {
      break;
    }

    cout << "Enter destination: ";
    if (getline(cin, destination) && destination.empty()) {
      break;
    }

    vector<Edge> shortestPath = basicGraph.TracePath(start, destination);
    Graph::PrintPath(shortestPath, cout);
  } while(true);

  cout << "Be Happy in your Work!" << endl;
  return 0;
}

