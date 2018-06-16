#include<iostream>
using namespace std;

int lcs(string x, string y){
  int m= x.length(), n= y.length();
  int curr[n+1],prev[n+1];
  for(int i=0;i<=n;i++)
    prev[i] = 0;
  curr[0] = 0;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(x[i-1]==y[j-1])
        curr[j] = prev[j-1] + 1;
      else{
        curr[j] = max(curr[j-1],prev[j]);
      }
    }
    for(int k=0;k<=n;k++)
      prev[k] = curr[k];
  }

return curr[n];
}

int main(){
  string x="XMJYAUZ", y="MZJAWXU";
  if(x.length()>=y.length())
    cout<<"length of lcs is : "<<lcs(x,y);
  else
    cout<<"length of lcs is : "<<lcs(y,x);
  return 0;
}
