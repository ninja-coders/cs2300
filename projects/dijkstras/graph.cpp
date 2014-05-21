#include "graph.h"

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Graph::Graph(string& graphFile) {
  this->_loaded = false;
  this->_filename = graphFile;
}

vector<Edge> Graph::TracePath(string& start, string& end) {
  if (!_loaded) {
    this->LoadLocations();
  }

  map<string, vector<Edge> > vertices = _vertices;
  map<string, PathCost> calculations;

  // Setup Starting Point
  calculations[start].cost = 0;
  string currentVertice;
  do {
    currentVertice = FindLowestCost(calculations);
    if (currentVertice.empty()) {
      break;
    }

    PathCost& currentCost = calculations[currentVertice];
    currentCost.completed = true;
    vector<Edge> edges = vertices[currentVertice];
    
    ApplyCostChanges(currentCost, edges, calculations);
  } while (currentVertice != end);

  if (currentVertice.empty()) {
    vector<Edge> emptyResults;
    return emptyResults;
  } else {
    return calculations[end].path;
  }
}

string Graph::FindLowestCost(map<string, PathCost>& vertices) {
  string result;
  int lowest = INF;

  for (auto itr=vertices.begin(); itr != vertices.end(); ++itr) {
    if (itr->second.cost < lowest && !itr->second.completed) {
      result = itr->first;
      lowest = itr->second.cost;
    }
  }
  
  return result;
}

void Graph::ApplyCostChanges(PathCost& baseCost, vector<Edge>& edges, map<string, PathCost>& runningCost) {
  for_each(edges.begin(), edges.end(), [&baseCost, &runningCost](Edge& e) {
    PathCost& destCost = runningCost[e.dest];
    int newCost = baseCost.cost + e.cost;
    if (newCost < destCost.cost && !destCost.completed) {
      vector<Edge> updatedPath = baseCost.path;
      updatedPath.push_back(e); 
      destCost.cost = newCost;
      destCost.path = updatedPath;
    }
  });
}

void Graph::LoadLocations() {
  ifstream inFile(_filename, ifstream::in);

  while (!inFile.eof()) {
    Edge newEdge;
    inFile >> newEdge.origin >> newEdge.dest >> newEdge.cost;
    if (newEdge.origin.empty() || newEdge.dest.empty()) {
      continue;
    }

    cout << newEdge.origin << "-" << newEdge.dest << ": " << newEdge.cost << endl;

    Edge invertedEdge;
    invertedEdge.origin = newEdge.dest;
    invertedEdge.dest = newEdge.origin;
    invertedEdge.cost = newEdge.cost;

    _edges.push_back(newEdge); 
    _vertices[newEdge.origin].push_back(newEdge);
    _vertices[newEdge.dest].push_back(invertedEdge);
  }

  _loaded = true;
}

void Graph::PrintPath(vector<Edge>& paths, ostream& output) { 
  int cost = 0;
  for_each(paths.begin(), paths.end(), [&cost](Edge& e) {
    cost += e.cost;
    cout << e.origin << " - " << e.dest << ": " << e.cost << endl;
  });
  cout << "Total Cost: " << cost << endl;
}

