#include<iostream>
using namespace std;

/*time complexity is O(log2 (log2n)) which is very efficient.
but worst case is O(n).*/
int exponentialSearch(int arr[],int n,int ele){
  int first = 0,last = n-1,mid;
  while(arr[last] != arr[first] && ele >= arr[first] && ele <=arr[last]){
    mid = first+ ((ele - arr[first])*(last-first)/(arr[last]-arr[first]));  //integer overflow may occur so use mid = first+ (last-first)/2
    if(ele > arr[mid])
      first = mid+1;
    else if(ele < arr[mid])
      last = mid-1;
    else
      return mid;
  }
  if(ele == arr[first])
    return first;
  else
    return -1;
}

int main(){
  int arr[]= {2,6,8,9,10,15,19,24,35};
  int n= sizeof(arr)/sizeof(arr[0]);
  int ele = 25;
  int pos = exponentialSearch(arr,n,ele);
  (pos != -1)? printf("element %d found at index %d \n",ele,pos): printf("element %d not found.\n ",ele);
  return 0;
}
