#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
   
   public:
    unordered_map < int , list<int>> adj;
   // u and v is node in which we have to create edge
   //  bool direction is used to show that whether direction will be directed or undirected
   void addedge( int u , int v,bool direction)
   {
      // direction = 0 -> undirected
      // direction=1 -> directed
      adj[u].push_back(v);
       if( direction==0)
       {
        adj[v].push_back(u);
       }
    
   }
   void printedge()
   {
      for( auto i: adj )
      {
        cout<<i.first<<"->";
        for( auto j :i.second )
        {
            cout<<j<<",";
        }
        cout<<endl;
      }
   }

};
int main()
{
    graph g;
    int n ,m;
    cout<<"enter no. of nodes"<<endl;
    cin>>n;
    cout<<"enter no of edges"<<endl;
    cin>>m;
    for( int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u ,v, 0);
    }

   g.printedge();
     
}