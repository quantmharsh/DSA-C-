#include<iostream>
#include<stack>
using namespace std;
bool isvalidornot( string exp)
{
 stack <char> st;
    for( int i=0;i<exp.length() ;i++)
    {
        char ch=exp[i];
        if(ch=='(' || ch=='{'||ch=='[')
        {
            st.push(ch);
        }
        else{
             
            if(!st.empty())
            {
                char top=st.top();
                if((ch ==')' && top=='(') || (ch==']' && top=='[') || (ch=='}' && top=='{'))
                { st.pop();
                }
                else{
                    return false;
                }
                
                

            }
            else{
                return false;
            }

        }
    }
    if(st.empty())
    {
     
     cout<<"balanced in bool"<<endl;
    
    return true;
    }
    else{
        cout<<"unbalanced in bool"<<endl;
    return false;
    }
}
int main()
{
    string exp="{[]}[";
    if(isvalidornot(exp))
    {
        cout<<"balanced"<<endl;

    }
    else{
        cout<<"unbalanced"<<endl;
    }
}