#include <cstdlib>
#include<iostream>
#include<iomanip>
#include<vector>
#include"Newton.h"
#include"Gauss_and_LDL.h"
using namespace std;
int main() {
    setprecision(8);
    const double eps = 1e-9;
    const int NIT=150;
    vector<double>x0={1,1},xk1(x0);
    double d1=1,d2=1;
    int k=1;
    int size=2;
    vector<vector<double>> JMatrix(size,vector<double>(size));
    vector<double>F(size);
     // int ch=0;
        // double M=0;
        // switch(ch){
        //     case 1:{
        //         M=0.01;
        //         break;
        //     }
        //     case 2:{
        //         M=0.05;
        //         break;
        //     }
        //     case 3:{
        //         M=0.1;
        //         break;
        //     }
        //     default:
        //     M=0.01;
        // }
    while(d1>eps||d2>eps){
        if(NIT<=k) {cout<<"IER=2";break;}
        F[0]=-function1(x0[0],x0[1]);
        F[1]=-function2(x0[0],x0[1]);
        J(x0,JMatrix);// or use function J1 with M 
        vector<double>result=gaussElimination(JMatrix,F);
        xk1[0]+=result[0];
        xk1[1]+=result[1];
        d1=delta1(x0);
        d2=delta2(x0,xk1);
        cout << "Step" << k++ <<" ///////////////////////\n"<< " delta1: " << d1 << "\n delta2:" << d2 << endl;
        x0=xk1;
    }
    PrintAnswer(x0,k);
    
    
    
    return 0;
}


