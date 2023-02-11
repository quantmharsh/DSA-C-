#include<iostream>
using namespace std;
 int  partition( int arr[] , int s , int e )
 {
  int pivot=arr[s];
  int cnt=0;
  
  for(int i=s+1;i<=e;i++)
  {
    if(arr[i]<=pivot)
    {
      cnt++;
    }
  }
   // take pivot to right place
   int pivotindex=s+cnt;
    swap(arr[s] , arr[pivotindex]);
     
    // left right sambhalo
    int i=s;
    int j= e;
      while( i< pivotindex &&  j > pivotindex)
      {
         while(arr[i]<= pivot)
         {
            i++;
         }
         while(arr[j]>pivot)
         {
            j--;
         }
         if(i< pivotindex && j> pivotindex)
         {
            swap(arr[i++] ,arr[j--]);
         }

      }
      return pivotindex;


 }
 void quicksort(int arr[] , int s , int e)
 {
  // base case
  if(s>=e)
  {
    return;
  }
  // do partition
  int p=partition( arr , s,e);

  // left part sambahalo
  quicksort( arr , s, p-1);
  // right part sambhalo
  quicksort( arr , p+1 , e);
   
  

   

 }


int main()
{
int n;
cout<<"enter array length"<<endl;
cin>>n;
int arr[n];
cout<<"push in array"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
quicksort( arr , 0,n);


cout<<"------------quick sort-------"<<endl;
for(int j=0;j<n;j++)
{
    cout<<arr[j]<<" "<<endl;
}
}