#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int simpleDpsol(int v[],int n,int sum){
  int opt[sum+1],min;
  opt[0]= 0;
  fill(opt+1,opt+sum+1,INT_MAX);
  for(int i=1;i<=sum;i++){
      min = opt[i];
      for(int j=0;j<n;j++){
        if(v[j]<=i)
          if(opt[i-v[j]]+1 < min)
            min = opt[i-v[j]]+1;
      }
      opt[i] = min;
    }
    return opt[sum];
}
int anotherDpsol(int v[],int n,int sum){
  int opt[sum+1],min;
  opt[0]= 0;
  fill(opt+1,opt+sum+1,INT_MAX);
  for(int i=0;i<n;i++){
    for(int j=0;j<=sum;j++){
      if(opt[j]!= INT_MAX && j+v[i] <=sum)
        opt[j+v[i]] = (opt[j]+1 < opt[j+v[i]]? opt[j]+1 : opt[j+v[i]]);
    }
    for(int k=0;k<=sum;k++)
      cout<<opt[k]<<" ";
      cout<<endl;
  }
  return opt[sum];
}
int noOfWays(int v[],int n,int sum){
  int opt[sum+1]={0},min;
  opt[0]= 1;   //only 1 way to form a sum of 0 by not selecting any coin
  for(int i=1;i<=sum;i++){
    for(int j=0;j<n;j++){
      if(i>=v[j]){
        opt[i]+= opt[i-v[j]];
      }
    }
  }
  return opt[sum];

}
int main(){
  int n=3,v[n]= {1,3,4}, sum=5;
  cout<<simpleDpsol(v,n,sum)<<endl;
  cout<<anotherDpsol(v,n,sum)<<endl;
  cout<<noOfWays(v,n,sum);
  return 0;
}
