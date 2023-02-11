#include<iostream>
using namespace std;
struct employee
{
    string name;
    int emp_no;
    int  salary;
};
int  employee_details(employee arr[] ,int key, int n , int &comparision)
{
 int left=0;
 int right=n-1;

 while(left<=right)
 {
    comparision++;
     int mid=(left+right)/2;
    if(arr[mid].emp_no<key)
    {
        left=mid+1;
    }
    if(arr[mid].emp_no>key)
    {
        right=mid-1;
    }
    if(key==arr[mid].emp_no)
    {
        return mid;
    }
 }
 return -1;
}
int main()
{
     employee arr[]={
        { "harsh",1,600000},
        { "aman",2,50000},
        {"amit",3,500000}
     };
     int n=3;
     cout<<n<<endl;
     int key =3;
     int comparison=0;

     int index=employee_details( arr , key,n , comparison);
     if(index==-1)
     {
        cout<<"no record found"<<endl;

     }
      cout<<"employee name"<<arr[index].name<<endl;
      cout<<"employee id"<<arr[index].emp_no<<endl;
      cout<<"employee salary"<<arr[index].salary<<endl;
}
