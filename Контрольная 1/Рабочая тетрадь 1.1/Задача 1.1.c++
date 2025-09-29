#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a=1;
    double b=2;
    double eps=0.0001;
    double c;
    if((cos(2/a)-2*sin(1/a)+1/a) * (cos(2/b)-2*sin(1/b)+1/b) >= 0) {
        cout<<"No roots | roots 2x"<<endl;
        return 1;
    }

    int cut=0;
    while((b-a)>eps){
        cut++;
        c=(a+b)/2;
        cout<<cut<<" : "<<c<<endl;
        double f_c= cos(2/c)-2*sin(1/c)+1/c;
        if(fabs(f_c)<eps){
            break;
        }
        if((cos(2/a)-2*sin(1/a)+1/a) * f_c<0){
            b=c;
        }
        else{
            a=c;
        }
    }
    cout<<"result: "<<c;
    return 0;
}