#include <iostream>
#include <robot.h>
using namespace std;

float x1,x2,x3,x4,x5,x6,x7,x8;
float p=3.14159125;

int main()
{
    cout<<"Inserte los valores articulares en °"<<endl;

    cout<<"q1---->";
    cin>>x1;
    x1=(p/180)*x1;//Conversion de grados a radianes

    cout<<"q2---->";
    cin>>x2;
    x2=(p/180)*x2;//Conversion de grados a radianes

    cout<<"q3---->";
    cin>>x3;
    x3=(p/180)*x3;//Conversion de grados a radianes

    cout<<"q4---->";
    cin>>x4;
    x4=(p/180)*x4;//Conversion de grados a radianes

    cout<<"q5---->";
    cin>>x5;
    x5=(p/180)*x5;//Conversion de grados a radianes

    cout<<"q6---->";
    cin>>x6;
    x6=(p/180)*x6;//Conversion de grados a radianes

    cout<<"q7---->";
    cin>>x7;
    x7=(p/180)*x7;//Conversion de grados a radianes

    cout<<"q8---->";
    cin>>x8;
    x8=(p/180)*x8;//Conversion de grados a radianes

    kuka v1("KUKA V_1");

    cout<<"Version:---- "<<v1.reference<<endl;



    cout<<v1.dh(x1,x2,x3,x4,x5,x6,x7,x8)<<endl;

    return 0;
}

