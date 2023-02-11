#include<iostream>
using namespace std;

void merge( int *arr ,  int s , int e )
{
    //teking length of both arrays
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
     
     // creating two array in which we hava to copy
     int * first= new int[len1];
     int * second= new int[len2];

    
     //copying both array
     // first array;
     int mainindex=s;
     for( int i=0;i<len1 ;i++)
     {
        first[i]=arr[mainindex++];

     }

     //second array
       mainindex=mid+1;
     for( int i=0; i<len2;i++)
     {
       second[i]=arr[mainindex++];

     }


     //merging 2 sorted array
     int index1=0;
     int index2=0;
     mainindex=s;

     while(index1<len1 && index2 < len2)
     {
         if(first[index1] < second[index2])
         {
            arr[mainindex++]=first[index1++];
         }
         else{
            arr[mainindex++]=second[index2++];
         }
     }
       // if values are remaining in first array  or its length is more 
       while(index1<len1)
       {
         arr[mainindex++]=first[index1++];
       }
       while( index2 < len2)
       {
        arr[mainindex++]=second[index2++];
       }

 delete []first;
    delete []second;

}


 void mergesort(int * arr , int s ,int e)
{
    int mid=s+(e-s)/2;
    //base case
    if(s>=e)
    {
        return;
    }
    // lest sub-array

    mergesort(  arr , s ,mid);

    // right sub array
    mergesort( arr ,mid+1 ,e);

    // merging two arrays
    merge(arr , s, e);
    
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



mergesort( arr , 0 , n-1);




cout<<"------------ Merge sort-------"<<endl;
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" "<<endl;
}
}