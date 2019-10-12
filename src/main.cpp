
#include "../include/utils.hpp"
#include <iostream>
#include <random>

using namespace std;

int main(){
  //InputPoints
  ofstream coutFile;
  coutFile.open("Cout.txt");
  srand((unsigned int)time(NULL));
  auto points = InputPoints();
  coutFile.close();

  for(size_t i = 0; i < points.size(); ++i) {
    cout << points[i]->x << " " << points[i]->y << " " << points[i]->angle << endl;
  }

  // Make Matrix for Edges
  int pointSize = points.size();
  auto adj = make_shared<vector<size_t>>(vector<size_t>(pointSize));

  //give indicies and save newPoints.txt with sorted points in x
  ofstream newPoints;
  newPoints.open("newPoints.txt");
  for(size_t i = 0; i < points.size(); ++i) {
    newPoints << points[i]->x << "\t" << points[i]->y << endl;
    points[i]->index = i;
  }
  newPoints.close();

  return 0;
}
