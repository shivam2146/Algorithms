#include<iostream>
#include<cstring>
#define MAX 25
using namespace std;

int opt[MAX][MAX];

int max(int a ,int b){
  return (a>b? a:b);
}

int lps(string str){
  int m = str.length();
  memset(opt,0,sizeof(opt));
  for(int i=0;i<m;i++)
    opt[i][i] = 1;
  int c= 0;
  for(int i=1;i<=m;i++){
    for(int j=0;j<m;j++){
      if(j+i < m){
        if(str[j] == str[j+i])
          opt[j][j+i] = opt[j+1][j+i-1]+2;
        else
          opt[j][j+i] = max(opt[j+1][j+i],opt[j][j+i-1]);
      }
    }
  }
  return opt[0][m-1];
}

int main(){
  string x= "ABBDCACB";
  cout<<"lps of length: "<<lps(x)<<endl;
  return 0;
}
