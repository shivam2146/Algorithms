#include  <iostream>
#include "basic.h"
using namespace std;

namespace sor{
  template <typename T>
void shellSort(int arr[], int n)
{

    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}
}

int main(){
  int arr[]={2,6,8,9,4,1,25,36,14};
  printf("\nArray before sorting:\n");
  bas::printArray<int>(arr,9);
  sor::shellSort<int>(arr,9);
  printf("\nArray after sorting\n");
  bas::printArray<int>(arr,9);
}
