#include<iostream>
using namespace std;
namespace sor{

template <typename T>
void swap(T &a, T &b){
  T temp = a;
  a = b;
  b = temp;
}

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
    swap<T>(arr[i],arr[index]);
  }
 }
}
template <typename T>
void printArray(T arr,int size){
  for(int i=0; i<9; i++)
    printf("%d ",arr[i]);

}
int main(){
  int arr[]={2,6,8,9,4,1,25,36,14};
  printf("\nArray before sorting:\n");
  printArray(arr,9);
  sor::selecSort<int>(arr,9,true);
  printf("\nArray after sorting\n");
  printArray(arr,9);
}
