#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack <int> st1;
    stack <int> st2;
    stack <int> st3;
    st1.push(10);
    st1.push(20);
    st1.push(30);
     int top=1;
     while(!st1.empty())
     {
            cout<<"enter operation"<<endl;
     cout<<"1 for pushing in st2"<<endl;
     cout<<"2 for pushing in st3"<<endl;
      cout<<"3 for printing  st3"<<endl;
    int op;
    cin>>op;
      
    switch(op)
    {
       
    case 1:
      
     if(!st1.empty())
    {     if( top==1)
        {
         st2.push(st1.top());
         
         cout<<st2.top()<<endl;
         st1.pop();
        
         cout<<"ready to push in st3"<<endl;
         top++;
        }
        else{
            cout<<"clear  track st2"<<endl;
        }
          


    }
    
     break;
    case 2:
     if(!st2.empty())
          {
            cout<<"pushed in stack 3"<<endl;
            st3.push(st2.top());
            st2.pop();
            cout<<st3.top()<<endl;
          }
          
         
          break;
  
     case 3:
        cout<<"printing stack 3"<<endl;
       for( int i=st3.size();i>=0;i--)
       {
        cout<<st3.top()<<endl;
        st3.pop();
         }
         break;
     
       }
     }
     

}