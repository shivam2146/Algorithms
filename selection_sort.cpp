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
int main(){
  int arr[]={2,6,8,9,4,1,25,36,14};
  cout<<"\nArray before sorting";
  for(int i=0; i<9; i++)
    cout << arr[i] << " ";
  sor::selecSort<int>(arr,9,true);
  cout<<"\nArray after sorting";
  for(int i=0; i<9; i++)
    cout << arr[i] << " ";
}
