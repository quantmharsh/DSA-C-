#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int prec(char ch)
{
    
   
        if(ch=='+' || ch=='-')
        {
            return 1;

        }
        if(ch=='*'|| ch=='/')
        {
            return 2;
        }
        if(ch=='^')
        {
            return 3;

        }
        else{
            return -1; //for closing bracket
        }
    }

     string infinixtopostfix(string s)
     {
        stack<char> st;
        string ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a'&&s[i]<='z'|| s[i]>='A' &&s[i]<='Z')
            {
                
                ans=ans+s[i];
            }
             else if(s[i]=='(')
            {
                st.push(s[i]);
            }
             else if(s[i]==')')
            {
                while(!st.empty() && st.top()!='(')
                { 
                   
                    ans=ans+st.top();
                    st.pop();

                }
                 if(!st.empty())
                 {
                
                    st.pop();
                 }
            }
            else{//when there  is operator
                  while(!st.empty()&& prec(st.top())>prec(s[i]))
                  {
                     ans=ans+st.top();
                     st.pop();
                  }
                  st.push(s[i]);
            }
             
        }
         while(!st.empty())
         {
            ans=ans+st.top();
            st.pop();
         }
         return ans;
     }

 int main()
 {
    cout<<infinixtopostfix("(a-b/c)*(a/k-l)")<<endl;
 }