#include<iostream>
using namespace std;
//creating a  safe function(bool type) during which mouse will be able to move
bool issafe( int **arr , int x, int y , int  n)
{
  if(arr[x][y]==1 && x<n && y<n  && x>=0 && y>=0)
  {
    return true;

  }
  return false;
}

// now creating a main function 
 // arr is original array that we are taking as an input and solarr is an array which will provide us with the right path
bool RatinMaze(int **arr , int x, int y, int n , int ** solarr)
{  
    //base case
if((x==(n-1)) && (y==(n-1)))
{
    solarr[x][y]=1;
    return true;
}
 // if it is safe to move then
   if(issafe(arr ,x,y,n))
   {
    //assigning 1 befre going front
    solarr[x][y]=1;
      //then going right side
      if(RatinMaze(arr,x,y+1 ,n,solarr))
      {
                return true;

      }
      //going downside
      if(RatinMaze(arr ,x+1,y,n,solarr))
      {
         return true;

      }
     

      //when unablt to meet right side and down side then marking this again as 0
      solarr[x][y]=0;
      return false;
   }
   return false;
}
int main()
{
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    //creating array dynamically
    int** arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }
    //taking input
    for( int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
        cout<<endl;
        
    }
    //creating solarr dynamically
    int **solarr=new int*[n];
    for( int i=0;i<n;i++)
    {
        solarr[i]=new int[n];
        //assigning 0 so that it does not accept garbage value
        for(int j=0;j<=n;j++)
        {
            solarr[i][j]=0;
        }
    }

    if(RatinMaze(arr,0,0,n,solarr))
    {
        for(int i=0;i<=n;i++)
            {
                for(int j=0;j<n;j++)
                {
                      cout<<solarr[i][j]<< " ";
                }
                cout<<endl;
            }
    }
}

// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1



// 1 0 0 1 0 1
// 1 0 0 1 1 1
// 1 0 1 1 1 0
// 1 0 1 0 1 0
// 1 1 1 0 1 0
// 0 0 0 0 1 1

