#ifndef __GRAPH_H
#define __GRAPH_H

#include <string>
#include <map>
#include <vector>
#include <ostream>

#define INF 123456789

struct Edge {
  std::string origin;
  std::string dest;
  int cost;
};

struct PathCost
{
  int cost;
  bool completed;
  std::vector<Edge> path;

  PathCost() {
    this->cost = INF;
    this->completed = false;
  }
};

class Graph
{
  private:
    std::string _filename;
    std::map<std::string, std::vector<Edge> > _vertices;
    std::vector<Edge> _edges;
    bool _loaded;

    void ApplyCostChanges(PathCost&, std::vector<Edge>&, std::map<std::string, PathCost>&);
    std::string FindLowestCost(std::map<std::string, PathCost>&);

  public:
    Graph(std::string& graphFile);
    void LoadLocations();
    std::vector<Edge> TracePath(std::string& start, std::string& end);

    static void PrintPath(std::vector<Edge>& paths, std::ostream& output);
};

#endif

