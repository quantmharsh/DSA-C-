#include<iostream>
#include<cmath>
using namespace std;
class SimpleCalculator {
   public:
    int a, b;
    public:
        void getDataSimple()
        {
            cout<<"Enter the value of a"<<endl;
            cin>>a;
            cout<<"Enter the value of b"<<endl;
            cin>>b;
        }

        void performOperationsSimple(){
            cout<<"The value of a + b is: "<<a + b<<endl;
            cout<<"The value of a - b is: "<<a - b<<endl;
            cout<<"The value of a * b is: "<<a * b<<endl;
            cout<<"The value of a / b is: "<<a / b<<endl;
        }
};
class ScientificCalculator:public SimpleCalculator{
    

    public:
        

        void performOperationsScientific()
        { 
            cout << "The value of cos(a) is: " << cos(a) << endl;
            cout << "The value of sin(a) is: " << sin(a) << endl;
            cout << "The value of exp(a) is: " << exp(a) << endl;
            cout << "The value of tan(a) is: " << tan(a) << endl;
        }
};
int main()
{ 
    SimpleCalculator calc = SimpleCalculator();
    calc.getDataSimple();
    calc.performOperationsSimple();
    ScientificCalculator sincalc;      //both are right
    sincalc.getDataSimple();
    sincalc.performOperationsScientific();


}