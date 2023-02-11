#include<iostream>
using  namespace std;

int main()
{
  int n;
  cout<<"enter array length"<<endl;
  cin>>n;
  int arr[n];
   for(  int i=0;i<n;i++)
   {
    cout<<"enter element at index="<<i<<endl;
    cin>>arr[i];

   }
 int k;
   cout<<"enter the k th smallest no. you want to find"<<endl;
    cin>>k;

    int cnt=0;
    // bubble sorting
    for( int i=1;i<n;i++)
    {
        for( int j=0; j<n-i;j++)
        {
        if(arr[j]> arr[j+1])
        {
            swap(arr[j] ,arr[j+1]);
        }
        }
    }
    cout<<" after sorting"<<endl;
    for( int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

        cout<<"kth smallest no is"<<endl;
         cout<<arr[k-1]<<endl;
        // for( int i=0;i<n;i++)
        // {

        // if( i==k-1)
        // cout<<arr[i]<<endl;
        // }
}