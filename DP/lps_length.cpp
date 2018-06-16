#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int lpsLength(string x,int i,int j,auto &opt){
  if(i>j)
    return 0;
  if(i==j)
    return 1;
  string key = to_string(i) + '|' + to_string(j);
  if(opt.find(key) == opt.end()){
    if(x[i] == x[j]){
      opt[key] = lpsLength(x,i+1,j-1,opt) + 2;
    }
    else
      opt[key] = max(lpsLength(x,i,j-1,opt),lpsLength(x,i+1,j,opt));
  }
    return opt[key];
}

int main(){
  string x= "ABBDCACB";
  unordered_map<string,int> opt;
  cout<<"length of lps  in "<<x<<" is : "<<lpsLength(x,0,x.length()-1,opt);
  return 0;
}
