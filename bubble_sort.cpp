#include<iostream>
#include "basic.h"
using namespace std;

namespace sor{
  template <typename T>
  void bubbleSort(T arr[],int size){
    for(int i = 0 ;i < size-1; i++){
      bool flag = false;
      for(int j=0 ;j < size-i-1 ;j++){
        if(arr[j] > arr[j+1]){
          bas :: swap <T> (arr[j],arr[j+1]);
          flag = true;
        }
      }
      if(flag==false)
        break;
    }
  }
}
int main(){
  int arr[]={2,9,6,3,4,8,2,5,1,95,45,12,65,54,23,25,15,61};
  printf("array before sorting: \n");
  bas::printArray<int>(arr,18);
  sor::bubbleSort<int>(arr,18);
  printf("\narray after sorting: \n");
  bas::printArray<int>(arr,18);
  printf("\n");

}
