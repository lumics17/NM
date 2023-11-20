#include <iostream>
#include <iomanip>
#include <vector>
#include "newfile.h" 
#include "math.h"
using namespace std;
int main() {
    double a=0,b=1.047;
    double(*func)(double)=Task;
    double eps1=pow(10,-4),eps2=pow(10,-5);
    printAnswer(TPIntegral(a,b,func,eps1));
    printAnswer(SMIntegral(a,b,func,eps2));
//  cout<<TPIntegral(a,b,func,N);
    a=0,b=0;
    double A=M_PI/2,B=M_PI/3;
     cout<<"Enter N:"<<endl;
    int N=0;
    cin>>N;
     cout<<"Enter M:"<<endl;
    int M=0;
    cin>>M;
    double (*func2)(double,double)=TaskDoubleIN;
    printAnswer(DISMIntegral(a,A,b,B,func2,N,M));
} 