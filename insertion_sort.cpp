#include<iostream>
#include "basic.h"
using namespace std;

namespace sor{
  template < typename T >
  void inserSort(T arr[], int size){
    T temp;
    int j;
    for(int i = 1 ;i < size ;i++){
        j=i-1;
        temp=arr[i];
        while(arr[j] > temp && j>=0){
          arr[j+1]=arr[j];
          j--;
        }
        arr[j+1]=temp;
    }
  }
}
int main(){
  int arr[]={2,6,8,9,4,1,25,36,14};
  printf("\nArray before sorting:\n");
  bas::printArray(arr,9);
  sor::inserSort<int>(arr,9);
  printf("\nArray after sorting\n");
  bas::printArray(arr,9);
}
