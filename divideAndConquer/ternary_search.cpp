#include<iostream>
using namespace std;

int ternarySearch(int arr[],int n,int ele){
  int first = 0, last = n-1, leftMid , rightMid;
  while(first<=last){
    leftMid = first + (last-first)/3;
    rightMid = last - (last-first)/3;
    if(arr[leftMid] == ele)
      return leftMid;
    else if(arr[rightMid] == ele)
      return rightMid;
    else if(ele < arr[leftMid])
      last = leftMid-1;
    else if(ele > arr[rightMid])
      first = rightMid+1;
    else if(ele > arr[leftMid] && ele < arr[rightMid]){
      first = leftMid+1;
      last = rightMid-1;
    }
  }
  return -1;
}

int main(){
  int arr[]= {2,6,8,9,10,15,19,24,35};
  int n= sizeof(arr)/sizeof(arr[0]);
  int ele = 11;
  int pos = ternarySearch(arr,n,ele);
  (pos != -1)? printf("element %d found at index %d \n",ele,pos): printf("element %d not found.\n ",ele);
  return 0;
}
