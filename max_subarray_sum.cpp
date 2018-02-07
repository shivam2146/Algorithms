#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(i=a;i<n;i++)
#define max(a,b) (a>b? a : b)
int brute_force(int arr[],int n){   //complexity O(n^3)
      int a,b,k,sum,sum1=0;
      rep(a,0,n){
        rep(b,a,n){
          sum=0;
          rep(k,a,b+1){
            sum+= arr[k];
          }
          sum1 = max(sum,sum1);
        }
      }
      return sum1;
}
int brute_force_improv(int arr[],int n){
  int a,b,sum,best=0;
  rep(a,0,n){
    sum=0;
    rep(b,a,n){
      sum+= arr[b];
      best= max(sum,best);
    }
  }
  return(best);
}
int max_subarray(int arr[], int n){     //most efficient O(n)
  int opt[n],i,m=0;
  opt[-1] = 0;
  rep(i,0,n){
    opt[i]= max((opt[i-1]+arr[i]),arr[i]);
    m= max(m,opt[i]);
  }
  return m;
}

int main(){
  int arr[]= {-1,2,4,-3,5,2,-5,2};
  cout<<brute_force(arr,8);
  cout<<brute_force_improv(arr,8);
  cout<<max_subarray(arr,8);
}
