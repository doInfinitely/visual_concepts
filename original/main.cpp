#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Graph.h"
using namespace std;

vector<string>* delimit(string text) {
  string space_delimiter = "\t";
  static vector<string> words;

  size_t pos = 0;
  while ((pos = text.find(space_delimiter)) != string::npos) {
      words.push_back(text.substr(0, pos));
      text.erase(0, pos + space_delimiter.length());
  }
  words.push_back(text);
  return &words;
}

int main () {
  string line;
  ifstream myfile ("adjacency_matrix.txt");
  vector<string> cities;
  string capitol;
  Graph myGraph;
  if (myfile.is_open())
  {
    bool first_line = true;
    int i = 0; 
    vector<string>* vec;
    while ( getline (myfile,line) )
    {
      vec = delimit(line);
      if (first_line) {
        //cout << vec->size() << std::endl;
        for (string x: *vec) {
          myGraph.Add(x);
          cities.push_back(x);
        }
        first_line = false;
      } else {
        capitol = line;
        if (i == cities.size()+1) {
          break;
        }
        bool first_token = true;
        string source;
        int j = 0;
        for (string x: *vec) {
          if (first_token) {
            source = x;
            first_token = false;
          } else {
            int y;
            try {
              y = stoi( x );
            } catch (...) {}
            //cout << source << " " << cities[j] << " " << x << " " << y << endl;
            myGraph.Connect(source, cities[j+1], y);
            ++j;
          }
        }
      }
      vec->clear();
      ++i;
    }
    myfile.close();
    //cout << cities.size() << std::endl;
  }
  else cout << "Unable to open file"; 
  myGraph.Remove("");
  //myGraph.Dump();
  //cout << capitol << std::endl;
  int maxi = 0;
  for (string x: cities) {
    list<string> path;
    //cout << x << myGraph.BestDistance(capitol.c_str(), x, &path) << std::endl;
    maxi = max(maxi, myGraph.BestDistance(capitol.c_str(), x, &path));
  }
  cout << maxi << endl;
  return 0;
}
