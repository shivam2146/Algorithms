#include<iostream>
#include<vector>

using namespace std;

#define M 3
#define N 3

void printPath(vector<pair<int,int>> vec){
  for(auto p : vec){
    cout<<p.first<<" "<<p.second<<"-> ";
  }
  cout<<endl;
}

bool isSafe(int x,int y)
{
  if((x>=0 && x<M) && (y>=0 && y<N))
    return true;
  return false;
}

void paths(int x, int y, int & count,vector<pair<int,int>> path)
{
  if(x == M-1 && y==N-1)
  {
    path.push_back({x,y});
    printPath(path);
    count++;
    return;
  }
  if(isSafe(x,y))
  {
    path.push_back({x,y});
    paths(x,y+1,count,path);
    paths(x+1,y,count,path);
  }
}

int main()
{
  int count = 0;
  vector<pair<int,int>> path;
  paths(0,0,count,path);
  cout<<"Number of paths: "<<count;
  return 0;
}
