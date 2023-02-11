#include<iostream>
using namespace std;
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

// in selection sort we bring the minimum element at its right place
for(int i=0;i<n-1;i++)
{
    int minindex=i;
    for( int j=i+1;j<n;j++)
    {
        if(arr[j]<arr[minindex])
        {
            minindex=j;
        }

    }
    swap (arr[i] ,arr[minindex]);
}

cout<<"------------selection sort-------"<<endl;
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" "<<endl;
}
}