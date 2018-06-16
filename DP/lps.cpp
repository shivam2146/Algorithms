#include<iostream>
#include<string>
#include<algorithm>
#define MAX 25
using namespace std;

int opt[MAX][MAX];
int lcs(string x,string y){
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

string lps(string x,string y,int m,int n){
    if(m==0 || n==0)
      return "";
    if(x[m-1] == y[n-1])
      return lps(x,y,m-1,n-1)+ x[m-1];
    else if(opt[m-1][n] > opt[m][n-1])
      return lps(x,y,m-1,n);
    else
      return lps(x,y,m,n-1);
}

int main(){
  string x= "ABBDCACB";
  string y =x;
  reverse(y.begin(),y.end());
  cout<<"length of lps  in "<<x<<" is : "<<lcs(x,y);
  cout<<"\nlps is "<<lps(x,y,x.length(),y.length())<<endl;
  return 0;
}
