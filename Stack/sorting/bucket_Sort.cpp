#include<iostream>
using namespace std;
int main()
{
    int  n;
    
    cout<<"enter length of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"push data in array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"enter data at index="<<i<<endl;
        cin>>arr[i];

    }
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    // creating bucketof size max
    int bucket[max];
    //assigning 0 value to bucket
    for(int i=0;i<=max;i++)
    {
        bucket[i]=0;

    }
    // assigning arr values in bucket
    for(int i=0;i<n;i++)
    {
        bucket[arr[i]]++;
    }

   for( int i=0 , j=0;i<=max;i++)
    {
        while(bucket[i]>0)
        {
                 arr[j++]=i;
                 bucket[i]--;
        }
    }
    //printing
    cout<<"after sorting"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<endl;
    }

}