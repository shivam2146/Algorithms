#include<iostream>
#include<string.h>
#include "basic.h"
using namespace std;

namespace sor{
  template <typename T>
  void countSort(T arr[],int size){
    T max = arr[0], min = arr[0];
    for(int i=1 ; i<size; i++){
      max = (max < arr[i]) ? arr[i] : max;
      min = (min > arr[i]) ? arr[i] : min;
    }
    int k = max-min+1;
    int count[k] = {0};
    for(int i = 0; i < size; i++)
      count[arr[i]-min]++;

    for(int j=1 ; j < k; j++)
      count[j]+= count[j-1];

    T output[size];
    for(int i=0; i<size; i++){
        output[count[arr[i]-min]-1]= arr[i];
        --count[arr[i]-min];
      }

    for(int j=0 ; j<size ; j++)
      arr[j] = output[j];

  }
}

int main(){
  //int arr[]={2,6,8,9,4,1,25,36,14};
  char arr[] = "herecomesthepain";
  printf("\nArray before sorting:\n");
  bas::printArray<char>(arr,strlen(arr));
  sor::countSort<char>(arr,strlen(arr));
  printf("\nArray after sorting\n");
  bas::printArray(arr,strlen(arr));
}
