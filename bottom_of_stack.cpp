#include<iostream>
#include<stack>
using namespace std;
stack <int> bottomofstack( stack <int> st , int x)
{
    //base case
    if(st.empty())
    {
        st.push(x);
        
        
    }
    else{
    int num=st.top();
    st.pop();
     st = bottomofstack(st ,x);
    st.push(num);
    }
    return st;
    
    
}
    void  print(stack <int> st , int x)
    {
         st=bottomofstack(  st ,x);
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
int main()
{
    stack <int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    int x=6;
    print(st ,x);
    return 0;
    
   
    }