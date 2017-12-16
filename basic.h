namespace bas{
  template <typename T>
  void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
  }
  template <typename T>
  void printArray(T arr,int size){
    for(int i=0; i<9; i++)
      printf("%d ",arr[i]);

  }
}
