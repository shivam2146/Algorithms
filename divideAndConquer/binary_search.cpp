#include<iostream>
using namespace std;

/*time complexity of binary search algorithm is O(log2n) which is very efficient.
Auxiliary space used by it is O(1) for iterative implementation
and O(log2n) for recursive implementation due to call stack.*/
int binarySearch(int arr[],int n,int ele){
  int first = 0,last = n-1,mid;
  while(first<=last){
    mid = (first+last)/2;  //integer overflow may occur so use mid = first+ (last-first)/2
    if(ele > arr[mid])
      first = mid+1;
    else if(ele < arr[mid])
      last = mid-1;
    else
      return mid;
  }
  return -1;
}

int main(){
  int arr[]= {2,6,8,9,10,15,19,24,35};
  int n= sizeof(arr)/sizeof(arr[0]);
  int ele = 24;
  int pos = binarySearch(arr,n,ele);
  (pos != -1)? printf("element %d found at index %d \n",ele,pos): printf("element %d not found.\n ",ele);
  return 0;
}
