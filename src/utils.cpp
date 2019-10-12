
#include "../include/utils.hpp"

using namespace std;

bool compareByX(const shared_ptr<Point> &p1, const shared_ptr<Point> &p2) {
  return p1->x < p2->x;
}

bool compareByY(const shared_ptr<Point> &p1, const shared_ptr<Point> &p2) {
  return p1->y < p2->y;
}

// Save data from input file to Point List
std::vector<shared_ptr<Point>> InputPoints() {
  //Input points
  ifstream PointFile("Points.txt");
  auto points = vector<shared_ptr<Point>>();

  string line;

  int tt=0;
  while(!PointFile.eof()){
    getline(PointFile, line);
    stringstream linestream(line);
    string word;
    int idx = 0;
    auto point = make_shared<Point>(Point());

    while (getline(linestream, word, '\t')) {
      double inputNum = atof((word).c_str());
      if(idx%2==0) {
//        new_pt->x= inputnum;
        point->x = inputNum;
      } else {
//        new_pt->y= inputnum;
        point->y = inputNum;
      }
      if (++idx ==2) break;
    }
    points.push_back(point);
    tt++;
  }
  PointFile.close();

  auto lastPoint = make_shared<Point>(Point());
  lastPoint->x = numeric_limits<float>::infinity();
  lastPoint->y = numeric_limits<float>::infinity();
  float epsilon = 0.001;
//  Point* last_pt = new Point();
//  last_pt->x = INF;
//  last_pt->y = INF;
//  double epsilon = 0.001;

  //Sort Points
  sort(points.begin(), points.end(), compareByX);
//  sort(PointList.begin(), PointList.end(), compare_x);

  //If there are two same points, move one point little bit.
  for (size_t i = 0; i < points.size(); ++i) {
    shared_ptr<Point> p = points[i];
    if (lastPoint->x == p->x || lastPoint->y == p->y) {
      points[i]->x += ((float) rand()/(float)RAND_MAX*epsilon);
      points[i]->y += ((float) rand()/(float)RAND_MAX*epsilon);
    }
    lastPoint = p;
  }

//  for(int i=0;i<PointList.size();i++){
//    Point* current  = PointList[i];
//    if(last_pt->x == current->x || last_pt->y==current->y){
//      PointList[i]->x+=((double)rand()/(double)RAND_MAX*epsilon );
//      PointList[i]->y+=((double)rand()/(double)RAND_MAX*epsilon );
//    }
//    last_pt=current;
//  }

  return points;
}
