#include<iostream>
using namespace std;

int binarySearch(int *arr,int n,int x,bool searchFirst){
  int first=0,last=n-1,result=-1;
  while(first<=last){
    int mid = (first+last)/2;
    if(arr[mid] == x){
      result = mid;
      if(searchFirst)
        last = mid-1;
      else
        first = mid+1;
    }else if(arr[mid]>x)
      last =  mid-1;
      else
      first =  mid+1;
  }
  return result;
}

int main(){
  int arr[]= {2,5,5,5,6,6,8,9,9,9,9};
  int n= sizeof(arr)/sizeof(arr[0]);
  int x = 9;
  int first = binarySearch(arr,n,x,1);
  int last = binarySearch(arr,n,x,0);
  cout<<"number of occurances are : "<<last-first+1;
  return 0;
}
