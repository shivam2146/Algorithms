#include<iostream>
#include "basic.h"
using namespace std;

template <typename T>
int partition(T arr[],int first,int last){
  T pivot;
  pivot = arr[first];
  int i= first + 1;
  while(i<=last-1){
    if(arr[i] <= pivot){
      bas :: swap(arr[i],arr[first]);
      i++;
      first++;
    }else if(arr[i] > pivot){
      bas :: swap(arr[i],arr[last-1]);
      last--;
    }
  }
  arr[i-1]=pivot;
  return i-1;
}
template <typename T>
void quicksort(T arr[],int last,int first=0){

      if(first < last){
          int p = partition(arr,first,last);
          quicksort(arr,p,first);
          quicksort(arr,last,p+1);
      }
}

int main(){
  int arr[]={5,2,6,3,4,1,8,56,12,45,32,56,15,45,65,42,34,49};
  printf("Array before sorting\n" );
  bas::printArray(arr,18);
  quicksort(arr,18);
  printf("Array after sorting\n" );
  bas::printArray(arr,18);

}
