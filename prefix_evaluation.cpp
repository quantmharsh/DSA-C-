#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int  prefix_Evaluation(string s)
{
    stack <int> st;
    for(int i=s.length()-1; i>=0;i--)
    {
        if(s[i]>='0' && s[i] <='9')
        {
            st.push(s[i]-'0');// converting dtring to integer
        }

        else{
            int op1=st.top();
            st.pop();
            
            int op2=st.top();
            st.pop();

            switch(s[i])
            {
                case '+': 
                st.push(op1+op2);
                break;
                case '-':
                st.push(op1-op2);
                break;
                case '*':
                st.push(op1*op2);
                break;
                case '/':
                st.push(op1/op2);
                break;
                case '^':
                st.push(pow(op1 ,op2));
                break;
            }
        }
    }
    return st.top();

}
int main()
{
    cout<<prefix_Evaluation("-+7*45+20")<<endl;
    cout<<"harsh"<<endl;
    
}
