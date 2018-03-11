#include <iostream>
#include<algorithm>
using namespace std;

int b_search(int arr[],int n,int ele){
  int first = 0, last = n-1;
  int mid = (first+last)/2;
  while(first <= last){
    if(arr[mid] == ele)
      return mid+1;
    if(arr[mid] > ele)
      last = mid-1;
    else
      first = mid+1;
    mid = (first+last)/2;
  }
  return -1;
}

int main(){
  int a[]= {1,5,5,5,25,36,45};
  cout<<b_search(a,7,25);
  //lower bound can be used to check existence of element in array
  cout<<lower_bound(a,a+7,20)-a;      //uses binary search concept to return a pointer to element in array with value atleast x(20)
  cout<<upper_bound(a,a+7,44)-a;  //returns pointer to element larger than x (44)
  //to count of element use both lower and upper bound
  auto b= equal_range(a,a+7,5);  //combines both lower and upper_bound
  cout<<b.second-b.first;  //calculates count of no x(5) in array
  return 0;
}
