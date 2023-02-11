#include<iostream>
using namespace std;
void heapify(int arr[] , int n, int i )
{
   int largest=i;
   int leftindex=2*i;
   int rightindex=2*i+1;
   if(  leftindex<=n && arr[largest]<arr[leftindex])
   {
      largest=leftindex;
   }
   if(rightindex <=n && arr[largest]<arr[rightindex])
   {
      largest=rightindex;
   }
   if(largest!=i)
   {
      swap(arr[largest],arr[i]);
      heapify(arr,n,largest);
   }
}
void heapsort(int arr[] , int n)
{
    int size=n;
   while(size>1)
   {
     
       swap(arr[size],arr[1]);
         size--;
       heapify(arr,size,1);
   }
}
int main()
{
    int arr[10]={-1 ,8,7,6,5,4,3,2,11,1};
    int n=9;

    for(int i=n/2;i>0;i--)
    {
      heapify(arr, n,i);
    }
    heapsort(arr,n);
    cout<<"after sorting"<<endl;
    for(int i=1;i<=n;i++)
    {
      cout<<arr[i]<<endl;
    }

}