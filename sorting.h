#include "basic.h"
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
