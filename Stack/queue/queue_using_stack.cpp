#include<iostream>
#include<stack>
using namespace std;
class queue {
    public:
    int n;
    stack <int> s1;
    stack <int> s2;
    queue()
    {
        n=0;
    }

 void push(int x)
 {
    s1.push(x);
    n++;
 }
 int pop()
 {
    if(s1.empty() && s2.empty())
    {
        cout<<" no data"<<endl;
        return -1;
    }
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
        n--;


    }
    
        int topvalue=s2.top();
        // cout<<"-"<<topvalue<<endl;
        s2.pop();
    
    return topvalue;

 }
 bool empty()
 {
    if(s1.empty() && s2.empty())
    {
        return true;
    }
    else{
        return false;
    }
 }
  void traverse()
  {
    for( int i=n;i>=0;i++)
    {
        cout<<s1.top()<<endl;
        s1.pop();
 


    }
  }
};
int main()
{
    queue q;
    q.push(10);
     q.push(20);
      q.push(30);
       q.push(40);
        q.push(50);
         q.push(60);
        // q.traverse();
           cout<<q.pop()<<endl;
            cout<<q.pop()<<endl;
             cout<<q.pop()<<endl;
              cout<<q.pop()<<endl;
              cout<<q.pop()<<endl;
}