#include<iostream>
#include<cstring>
using namespace std;

int max1(int a,int b,int c){
    return max(max(a,b),c);
}

int lcsKSeq(string X,string Y,string Z){
  int m = X.length(), n= Y.length(), o= Z.length();
  int opt[m+1][n+1][o+1];
  memset(opt,0,sizeof(opt));
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      for(int k=1;k<=o;k++){
          if(X[i-1] == Y[j-1] && Y[j-1] == Z[k-1])
            opt[i][j][k] = opt[i-1][j-1][k-1] + 1;
          else{
            opt[i][j][k] = max1(opt[i-1][j][k],opt[i][j-1][k],opt[i][j][k-1]);
          }
      }
    }
  }
  return opt[m][n][o];
}

int main(){
  string X= "ABCBDAB", Y="BDCABA", Z="BADACB";
  cout<<"lcs is of length: "<<lcsKSeq(X,Y,Z);
  return 0;
}
