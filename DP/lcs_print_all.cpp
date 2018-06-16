#include<iostream>
#include<set>
#include<vector>
#define MAX 20
using namespace std;

int opt[MAX][MAX];

vector<string> lcsAll(string x,string y,int m,int n){
  if(m==0||n==0){
    vector<string> v(1);
    return v;
  }
  if(x[m-1]==y[n-1]){
    vector<string> v = lcsAll(x,y,m-1,n-1);
    for(string &str : v){
      str.push_back(x[m-1]);      //to append to string
    }
    return v;
  }
  if(opt[m-1][n] > opt[m][n-1])
    return lcsAll(x,y,m-1,n);

  if(opt[m-1][n] < opt[m][n-1])
  return lcsAll(x,y,m,n-1);

  vector<string> top = lcsAll(x,y,m-1,n);
  vector<string> left= lcsAll(x,y,m,n-1);

  top.insert(top.end(),left.begin(),left.end());    //to merge vectors
  return top;

}

int lcsLen(string x,string y){
  int n= x.length();
  int m= y.length();
  for(int i=0; i<(m+1) ; i++)
    opt[0][i] = 0;
  for(int j=0; j<(n+1) ; j++)
    opt[j][0] = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(x[i-1]==y[j-1])
        opt[i][j] = opt[i-1][j-1]+1;
      else{
        opt[i][j] = max(opt[i-1][j],opt[i][j-1]);
      }
    }
  }
  return opt[n][m];
}

set<string> lcs(string x,string y){
  int m= x.length();
  int n = y.length();
  lcsLen(x,y);
  vector<string> lcsStr = lcsAll(x,y,m,n);
  set<string> s (lcsStr.begin(),lcsStr.end());
  //set<string> s (make_move_iterator(lcsStr.begin()),make_move_iterator(lcsStr.end()));
  return s;
}

int main(){
    string x="ABCBDAB", y="BDCABA";
    set<string> s = lcs(x,y);
    for(string str : s)
      cout<<str<<endl;
    return 0;
}
