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

for( int i=1 ;i<n;i++)
{
     int j=i-1;
     int temp=arr[i];
     while(j>=0)
     {
        if(arr[j]>temp)
        {
            arr[j+1]=arr[j]; // creating space to insert 

        }
        else{
            break;

        }
           j--;
     
     arr[j+1]=temp;
     }
       
}

cout<<"------------insertion sort-------"<<endl;
for(int j=0;j<n;j++)
{
    cout<<arr[j]<<" "<<endl;
}
}