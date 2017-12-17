namespace bas{

  template <typename T>
  void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
  }

  template <typename T>
  void printArray(T arr[],int size){
    for(int i=0; i<size; i++)
      printf("%d ",arr[i]);
    printf("\n");
  }

  int lChild(int index){
    return 2*index+1;
  }
  int rChild(int index){
    return 2*index+2;
  }

  template <typename T>
  void maxHeapify(T arr[],int size, int ind){
          int largest=ind;
          int l= lChild(ind);
          int r= rChild(ind);
          if( l < size && arr[largest] < arr[l])
              largest= l;
          if (r<size && arr[largest] < arr[r])
            largest= r;
          if(largest != ind)
            {
              swap(arr[largest],arr[ind]);
              maxHeapify(arr,size,largest);
            }
    }

    template <typename T>
    void buildHeap(T arr[],int size, int ind=0) {
      if(ind > size-1)
        return;
      int l= lChild(ind);
      int r= rChild(ind);
      buildHeap(arr,size,l);
      buildHeap(arr,size,r);
      maxHeapify(arr,size,ind);
    }
    
}
