#include<iostream>
using namespace std;
class heap{
 public:
 int arr[100];
 int size;
  heap()
  {
      size=0;
     arr[0]=-1;
    
  }
   void insert( int val)
   {
    // insert in heap
     size=size+1;
      int index= size;
      arr[index]=val;

      // take it to right place
      while(index >1)
      {
        int parent=index/2;
         if(arr[index]> arr[parent])
         {
            swap(arr[index] ,arr[parent]);
            index=parent;

         }
         else{
            return;
         }
      }



   }
   void deleteheap()
   {
    if( size==0)
    {
        cout<<"HEAP is empty"<<endl;
    }
    // swap root and last element
      arr[1]=arr[size];

      // delete last node
      size--;
      // taking it to right place
      int index=1;
      while(index<size)
      {
      int leftindex=2*index;
      int rightindex=2*index+1;
    if( index < size && arr[index]< arr[leftindex])
    {
       swap(arr[index] ,arr[leftindex]);
       index=leftindex;
    }
    else if(index <size && arr[index]<arr[rightindex])
         {
             swap(arr[index] ,arr[rightindex]);
             index=rightindex;
         }
         else{
            return;

         }
      }
      
   } 
    void print()
   {
    for( int i=1;i<=size;i++)
    {
        cout<<arr[i]<<endl;
    }
   }


};

// heapify given array
void heapify( int arr[] , int size , int i)
{
    int largest=i;
    int leftindex=2*i;
    int rightindex=2*i+1;
    
    if(   leftindex <size && arr[largest] <arr[leftindex])
    {
        swap(arr[largest],arr[leftindex]);
        largest= leftindex;
    }
    else if( rightindex < size && arr[largest] < arr[rightindex])
    {
      swap(arr[rightindex] ,arr[largest]);
       largest =rightindex;
    }
    if(largest!=i)
    {
        heapify( arr , size ,i);
    }
}
  
 int main()
 {
    cout<<"heaps"<<endl;
    heap h;
    h.insert(50);
     h.insert(55);

 h.insert(53);

 h.insert(52);
 h.insert(54);
 h.print();
 cout<<"---------After deletion-------"<<endl;
 h.deleteheap();
 h.print();
 cout<<"------------- heapify algorithm for converting array into heap----------"<<endl;
 int arr[6]={-1 ,54,55,53,52,50};
  int n=5;
 for( int i=n/2;i >0;i--)
 { 
   
     heapify( arr , n, i);
 }

 for( int i=1;i<n;i++)
 {
    cout<<arr[i]<<" "<<endl;
 }
 return 0;


 }