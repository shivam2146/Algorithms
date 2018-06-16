#include<iostream>
#include<cstring>
#include<string>
using namespace std;

string longestCommonSubstring(string x, string y){
  int m= x.length(), n= y.length();
  int opt[m+1][n+1];
  memset(opt,0,sizeof(opt));
  int maxlen = 0 ,endIndex;
  for(int i=1; i<=m ; i++){
    for(int j=1; j<=n ;j++){
      if(x[i-1] == y[j-1])
        opt[i][j] = opt[i-1][j-1] + 1;
        if(maxlen <= opt[i][j]){
          maxlen = opt[i][j];
          endIndex = i;
        }
        else{
        opt[i][j] = 0;
      }
    }
  }
  return x.substr(endIndex-maxlen,maxlen);
}

int main(){
  string x= "ABC", y="BABA";
  cout<<"longest common substring in "<<x<<" and "<<y<<" is :  "<<longestCommonSubstring(x,y)<<endl;
  return 0;
}
