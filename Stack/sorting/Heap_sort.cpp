#include<iostream>
using namespace std;



void heapify( int arr[] , int n , int i)
{
    int largest=i;
    int leftindex=2*i;
    int rightindex=2*i+1;
    
    if(   leftindex <=n && arr[largest] <arr[leftindex])
    {
        // swap(arr[largest],arr[leftindex]);
        largest= leftindex;
    }
     if( rightindex <= n && arr[largest] <  arr[rightindex])
    {
    //   swap(arr[rightindex] ,arr[largest]);
       largest =rightindex;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify( arr , n ,largest);
    }
}
void heapsort( int arr[] , int n )
{
     int size=n;  
     while(size>1)
     {
        
        //step-1 swapping first element with last element
        swap(arr[size] , arr[1]);
        size--;
        //step-2 taking it to right place 
        heapify(arr ,size ,1);


     }
 
}
 int main()
 {
    
 cout<<"------------- heapify algorithm for converting array into heap----------"<<endl;
 int arr[10]={-1 ,54,58,55,52,99 ,1,3,28,13};
  int n=9;
 for( int i=n/2; i>0;i--)
 { 
   
     heapify( arr , n, i);
 }
  heapsort( arr , n);
 for( int i=1;i<=n;i++)
 {
    cout<<arr[i]<<" "<<endl;
 }
 return 0;


 }