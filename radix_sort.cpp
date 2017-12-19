#include<iostream>
#include "basic.h"
using namespace std;
template <typename T>
void countSort(T arr[],int size,int place){
  T max = arr[0]%place, min = arr[0]%10;
  for(int i=1 ; i<size; i++){
    max = (max < arr[i]%place) ? arr[i] : max;
    min = (min > arr[i]%place) ? arr[i] : min;
  }
  int k = max-min+1;
  int count[k] = {0};
  for(int i = 0; i < size; i++)
    count[(arr[i]-min)%place]++;

  for(int j=1 ; j < k; j++)
    count[j]+= count[j-1];

  T output[size];
  for(int i=0; i<size; i++){
      output[count[(arr[i]-min)%place]-1]= arr[i];
      --count[(arr[i]-min)%place];
    }

  for(int j=0 ; j<size ; j++)
    arr[j] = output[j];

}
namespace sor{
  template <typename T>
  void radixSort(T arr[],int size){
    int max,r=10;
    for(int i=1 ; i<size; i++)
      max = (max < arr[i]) ? arr[i] : max;

    while(max){
      countSort(arr,size,r);
      max=max/10;
      r=r*10;
    }

  }
}


int main(){
  int arr[]={2,6,8,9,4,1,25,36,24,14};
  printf("\nArray before sorting:\n");
  bas::printArray<int>(arr,10);
  sor::radixSort<int>(arr,10);
  printf("\nArray after sorting\n");
  bas::printArray<int>(arr,10);
}
