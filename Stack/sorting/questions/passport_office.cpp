#include<iostream>
#include<vector>
using namespace std;
struct passport {
    int psid;
    string name;
    string date ;
};
vector<passport> records; 

 int insertionsort()
 {
      for(int i=1;i<records.size();i++)
      {
        int j=i-1;
        int temp=records[i].psid;
        while(j>=0)
        {
            if(records[j].psid>temp)
            {
                records[j+1].psid=records[j].psid;
            }
            else{
                break;
            }
            j--;
            records[j+1].psid=temp;
        }
      }
 }
 int selectionsort()
 {
    for(int i=0;i<records.size();i++)
    {
        int minindex=i;
        for(int j=i+1 ;j<records.size();j++)
        {
            if(records[minindex].date >records[j].date)
            minindex=j;
        }
        swap(records[minindex],records[i]);
    }

 }
int main()
{  
     records.push_back({ 104, "Samantha Williams", "2022-01-04" });
    records.push_back({ 102, "Jane Smith", "2022-01-02" });
    records.push_back({ 103, "Bob Johnson", "2022-01-03" });
    records.push_back({ 101, "John Doe", "2022-01-01" });
  
    records.push_back({ 105, "Michael Brown", "2022-01-05" });
  

    cout<<"before sorting"<<endl;
    for(int i=0;i<records.size();i++)
    {
        cout<<records[i].psid<<endl;
        cout<<records[i].name<<endl;
        cout<<records[i].date<<endl;
    }

   
    insertionsort();
            cout<<"after insertion sort on id"<<endl;
             for(int i=0;i<records.size();i++)
    {
        cout<<records[i].psid<<endl;
        cout<<records[i].name<<endl;
        cout<<records[i].date<<endl;
    }

        selectionsort();
    cout<<"after selection sort on date "<<endl;
    for(int i=0;i<records.size();i++)
    {
        cout<<records[i].psid<<endl;
        cout<<records[i].name<<endl;
        cout<<records[i].date<<endl;
    }


    

}