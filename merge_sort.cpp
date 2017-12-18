#include<iostream>
#include "basic.h"
using namespace std;

namespace sor{
template <typename T>
void merge(T arr[],int l,int m,int r){
  int i = l, j = m+1 , c=0;
  T temp[r-l+1];
  while(i <= m && j <= r){
    if(arr[i]< arr[j])
      temp[c++] = arr[i++];
    else
      temp[c++]= arr[j++];
  }
  while(i<=m)
      temp[c++]=arr[i++];
  while(j<=r)
      temp[c++]=arr[j++];
  int k=0;
  for(i=l;i<=r;i++)
      arr[i]= temp[k++];
}


template <typename T>
void mergeSort(T arr[],int l,int r){
  if(l<r){
    int m= (l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
  }
 }
}
int main(){
  int arr[]={5,2,6,3,4,1,8,56,12,45,32,56,15,45,65,42,34,49};
  printf("Array before sorting\n" );
  bas::printArray(arr,18);
  sor::mergeSort(arr,0,17);
  printf("Array after sorting\n" );
  bas::printArray(arr,18);
}
