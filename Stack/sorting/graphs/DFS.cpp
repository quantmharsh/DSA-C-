#include<iostream>
#include<vector>
using namespace std;
 const int N=1e5+2;
bool vis[N];
vector<int> adj[N];
 
void dfs( int node)
{
   vis[node]=1;
   cout<<node<<endl;

   vector<int> :: iterator i;
   for( i=adj[node].begin();i!=adj[node].end();i++)
{
   if(vis[*i]);

   else
     {
      dfs(*i);
     }
}

}

int main()
{ 
   int n,m;
   cout<<"enter no of nodes"<<endl;
   cin>>n;
   cout<<"enter no of edges"<<endl;
   cin>>m;


    
   int x,y;
   for( int i=0;i<m;i++)
   {
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);


   }
   // marking visited as false
   for( int i=0;i<N;i++)
   {
      vis[i]=0;
   }
   //doing push back o x .y


   dfs(1);

   

}