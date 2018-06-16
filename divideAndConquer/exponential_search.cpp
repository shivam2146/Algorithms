#include<iostream>
using namespace std;

int binarySearch(int arr[],int first,int last,int ele){
  if(first > last)
    return -1;
  int mid = first + (last-first)/2;
  if(arr[mid] == ele)
    return mid;
  else if(ele > arr[mid])
    binarySearch(arr,mid+1,last,ele);
  else
    binarySearch(arr,first,mid-1,ele);
}


int exponentialSearch(int arr[],int n, int ele){
  int bound = 1;
  while(bound <n && arr[bound] < ele)
    bound = bound*2;
  return binary_search(arr,bound/2,min(bound,n),ele);
}

int main(){
  int arr[]= {2,6,8,9,10,15,19,24,35};
  int n= sizeof(arr)/sizeof(arr[0]);
  int ele = 15;
  int pos = exponentialSearch(arr,n,ele);
  (pos != -1)? printf("element %d found at index %d \n",ele,pos): printf("element %d not found.\n ",ele);
  return 0;
}
