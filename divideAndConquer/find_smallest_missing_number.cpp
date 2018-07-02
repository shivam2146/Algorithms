#include<iostream>
using namespace std;

int find_smallest_missing_number(int arr[],int first,int last){
    if(first > last)
      return first;
    int mid = first + (last-first)/2;
    if(arr[mid] == mid)
      find_smallest_missing_number(arr,mid+1,last);
    else
      find_smallest_missing_number(arr,first,mid-1);
}

int main(){
  int arr[] = {0,1,2,3,4,5,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"smallest missing number is : "<<find_smallest_missing_number(arr,0,n-1);
  return 0;
}
