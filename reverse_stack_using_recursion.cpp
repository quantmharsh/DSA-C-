
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
stack <int> reverseStack(stack<int> st) {
  	//base case
    if(st.empty()) {
        
    }
    else{

    
    int num = st.top();
    st.pop();
    
    //recursive call
    reverseStack(st);
    
     st=bottomofstack(st,num);
    }

    return st;
}
    void  print(stack <int> st )
    {
         st=reverseStack(  st );
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
    print(st );
    return 0;
    
   
    }