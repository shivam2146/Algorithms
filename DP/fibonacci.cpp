#include<iostream>
#include<unordered_map>
using namespace std;

//memoized approach top down
int fib(int n, auto &lookup){
  if(n<=1)
    return n;
  else{
    if(lookup.find(n) == lookup.end())
      lookup[n] = fib(n-1,lookup)+fib(n-2,lookup);
    return lookup[n];
  }
}

//tabulated approach bottom up
int fib(int n){
  if(n<=1)
    return n;
  int prev=0,curr=1 , newf;
  for(int i=2;i<=n;i++){
    newf = prev+curr;
    prev = curr;
    curr = newf;
  }
  return curr;
}

int main(){
    unordered_map<int,int> lookup;
    cout<<"8th fibo term is : "<<fib(8,lookup);
    cout<<"\n8th fibo term is : "<<fib(8);
    return 0;
}
