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
//in bubble sort we take the largest element at its     right place
//we compare j with j+1 till n-i element 
for( int i=1;i<n;i++)
{
    for( int j=0;j<n-i;j++)
    {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
        }
    }
}


cout<<"------------bubble sort-------"<<endl;
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" "<<endl;
}
}
