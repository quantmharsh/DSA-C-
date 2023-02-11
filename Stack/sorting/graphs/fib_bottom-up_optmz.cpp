#include<iostream>
#include<vector>
using namespace std;
int main()
{
    cout<<"enter n"<<endl;
    int n;
    cin>>n;
    int prev1=1;
    int prev2=0;
  
    if(n==0 || n==1)
    {
        return  prev2;
    }
     int curr= 0;
    //3.finding fib from 2 to n
    for(int i=2;i<=n;i++)
    {
        curr= prev1+prev2;
        prev2=prev1;
        prev1=curr;

        
    }
     cout<<curr<<endl;
   

}

// bottom up 
// #include<iostream>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"enter n"<<endl;
//     cin>>n;
// //1. creating dp vector
//     vector<int> dp(n+1);
//     //2. base case
    
//     dp[0]=0;
//     dp[1]=1;
//     //3/create loop from i=2 to i<=n
//     for(int i=2;i<=n;i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     cout<<dp[n]<<endl;
    
// }