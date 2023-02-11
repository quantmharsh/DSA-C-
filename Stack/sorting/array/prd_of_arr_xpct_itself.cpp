#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"push in array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
 }     


//  for( int i=0;i<n;i++)
//  {  long long mul=1;
//     for( int j=0 ;j<n;j++)
//        {   
      
//             if(arr[i]!=arr[j])
//             {
//                  mul=arr[j]*mul;
//             }
//        }
int  left =1;
    int right =1;
    long long result[n];
   for( int i=0 ;i<n ;i++)
   {
    
     result[i]=left* right;
    left=left*arr[i];
    right=right/arr[n-1-i];
   

     cout<<" multiplication of"<<arr[i]<<endl;
       cout<<result[i];
    

   }
    //    cout<<" multiplication of"<<arr[i]<<endl;
    //    cout<<mul;
       
 }

// }