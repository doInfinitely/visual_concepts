#include <stdio.h>
#include <string>
#include "Graph.h"
using namespace std;


int main () {
  string line;
  vector<string> cities;
  string capitol = "0";
  Graph myGraph;
  if (true)
  {
    bool first_line = true;
    int i = 1;
    int j = 0;
    int num_cities; 
    while (cin >> line)
    {
      if (first_line) {
        num_cities = stoi(line);
        for (int j = 0; j < num_cities; ++j) {
          //cout << to_string(j) << endl;
          myGraph.Add(to_string(j));
          cities.push_back(to_string(j)); 
        }
        first_line = false;
      } else {
        if (i == cities.size()+1) {
          break;
        }
        bool first_token = true;
        string source;
        //cout << line << " " << i << " " << j << endl;
        myGraph.Connect(cities[i], cities[j], stoi(line));
        myGraph.Connect(cities[j], cities[i], stoi(line));
        ++j;
        if (j == i) {
            ++i;
            j = 0;
        }
      }
    }
  }
  else cout << "Unable to open file"; 
  myGraph.Remove("");
  int maxi = 0;
  for (string x: cities) {
    list<string> path;
    //cout << x << myGraph.BestDistance(capitol.c_str(), x, &path) << std::endl;
    maxi = max(maxi, myGraph.BestDistance(capitol.c_str(), x, &path));
  }
  cout << maxi << endl;
  return 0;
}
