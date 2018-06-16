#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int max(int a, int b){
  return ((a>b)?a : b);
}

int lIncSubSeq(int arr[],int n){
    int opt[n+1];
    opt[0]=0;
    fill(opt+1,opt+n,INT_MIN);
    for(int i=1;i<=n;i++){
      for(int j=0;j<i;j++){
        if(j==0 || arr[i]>arr[j])
          opt[i]= max(opt[j]+1,opt[i]);
        else
          opt[i] = max(opt[j],opt[i]);
      }
      /*
      for(int i=0;i<=n;i++)
        cout<<opt[i]<<" ";
        cout<<endl;*/

    }
    return opt[n];
}
int main(){
  int n=8 ,arr[]={-1,6,2,5,1,7,4,8,3};  //to use array from index 1
  cout<<lIncSubSeq(arr,n);
}
