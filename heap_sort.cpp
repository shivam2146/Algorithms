#include<iostream>
#include "basic.h"
using namespace std;

namespace sor{
template <typename T>
void heapSort(int arr[],int size){
  bas::buildHeap<int>(arr,size);
  while(size-1 > 0)
  {
    bas::swap(arr[0],arr[size-1]);
    --size;
    bas::maxHeapify(arr,size,0);
  }
}

}

int main(){
  int arr1[]={2,9,6,3,4,8,2,5,1,95,45,12,65,54,23,25,15,61};
  printf("array before sorting\n");
  bas::printArray<int>(arr1,18);
  sor::heapSort<int>(arr1,18);
  printf("array after sorting\n");
  bas::printArray<int>(arr1,18);
}
