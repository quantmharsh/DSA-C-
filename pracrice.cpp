#include<iostream>
using namespace std;
int main()
{
  int n;
  cout<<"enter n"<<endl;
  cin>>n;
  int arr[n];
  cout<<"push on arr"<<endl;
  for(int i=0;i<n;i++)
{
  cin>>arr[i];
}

cout<<"bubble sort"<<endl;
for(int i=1;i<n;i++)
{
  for(int j=0;j<n-i;j++)
  {
    if(arr[j]>arr[j+1])
    {
      swap(arr[j],arr[j+1]);
    }
  }

}
for(int i=0;i<n;i++)
{
  cout<<arr[i]<<endl;
}
cout<<"insertion sort"<<endl;
for(int i=0;i<n;i++)
{
  int j=i-1;
  int temp=arr[i];
  while(j>=0)
  {
    if(arr[j]>temp)
    arr[j+1]=arr[j];
  
  else{
    break;
  }
  j--;
  arr[j+1]=arr[j];
}
}
for(int i=0;i<n;i++)
{
  cout<<arr[i]<<endl;
}

cout<<"selection sort"<<endl;
for(int i=0;i<n;i++)
{
  int minindex=i;
  for(int j=i+1;j<n;j++)
  {
    if(arr[minindex]>arr[j])
    {
      minindex=j;
    }
  }
  swap(arr[minindex],arr[i]);
}
for(int i=0;i<n;i++)
{
  cout<<arr[i]<<endl;
}
}