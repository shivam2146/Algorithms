#include<iostream>
#include "basic.h"
using namespace std;
namespace sor{
template <typename T>
void selecSort(T arr[],int size,bool asc = true){    //keep asc true for ascending
  T temp;
  int index;
  for(int i=0 ;i < size ;i++){
    temp=arr[i];
    for(int j=i+1; j < size ;j++){
        if(arr[j] < temp){
          if(asc == 1){
            temp = arr[j];
            index = j;
          }
        }
        else if(arr[j] > temp){
            if(asc == 0){
              temp = arr[j];
              index = j;
              }
           }
    }
    bas::swap<T>(arr[i],arr[index]);
  }
 }
}
int main(){
  int arr[]={2,6,8,9,4,1,25,36,14};
  printf("\nArray before sorting:\n");
  bas::printArray(arr,9);
  sor::selecSort<int>(arr,9,true);
  printf("\nArray after sorting\n");
  bas::printArray(arr,9);
}
