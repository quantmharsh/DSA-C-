#include<iostream>
#include<queue>

using namespace std;
queue<int> ride_q;

void startride()
{
    if(ride_q.size()>=20)
    {
        cout<<"riders ready for ride"<<endl;
          for(int i=0;i<20 ;i++)
          {
            
       cout<<ride_q.front()<<endl;
       ride_q.pop();
          }
    }
    else{
        cout<<"bring more riders"<<endl;
    }
}
int main()
{
    int n;
    startride();
    cout<<"enter rider"<<endl;
for(int i=0;i<20;i++)
{
    cin>>n;
    ride_q.push(n);
}
startride();



}
  
