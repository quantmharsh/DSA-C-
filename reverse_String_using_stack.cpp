#include<iostream>
#include<stack>
using namespace std;
int main()
{
  string str="harsh";
  stack<char> s;
  //push into stack
  for(int i=0;i<str.length();i++)
  {
     char ch=str[i];
     s.push(ch);

  }
  //popping out from stack
   string  ans=" ";
   while(!s.empty())
   {
    char ch=s.top();
    ans.push_back(ch);
    s.pop();
   }
   cout<<"reverse is"<<ans<<endl;
   return 0 ;
}