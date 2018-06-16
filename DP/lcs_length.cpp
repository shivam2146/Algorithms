#include<iostream>
#include<unordered_map>
using namespace std;

int lcs(string x,string y){
  int n= x.length();
  int m= y.length();
  int opt[n+1][m+1];
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

int main(){
  string x="XMJYAUZ", y="MZJAWXU";
  cout<<"length of lcs is : "<<lcs(x,y);
  return 0;
}
