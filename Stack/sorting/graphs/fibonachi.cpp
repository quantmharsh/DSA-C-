#include<iostream>
#include<vector>
using namespace std;
 int fib( int n , vector<int> &dp)
 {
      //base case
      if(n<=1)
      {
        return n;
      }
      //step3 after base case check whether we have already found dp[i] value
      if(dp[n] != -1)
      {
        return dp[n];
      }
      //step2 store dp[n]
      dp[n]=fib(n-1 ,dp)+ fib(n-2 ,dp);
      return dp[n];
 }

int main()
{
    cout<<"enter no to find fibonachi series"<<endl;
    int n;
    cin>>n;
    vector<int> dp(n+1);
   
    for(int i=0;i<=n;i++)
    dp[i] = -1;
    cout<<fib(n,dp)<<endl;
    return 0;
    

}
