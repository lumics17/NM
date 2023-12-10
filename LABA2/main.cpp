#include <cstdlib>
#include<iostream>
#include<vector>
#include"Newton.h"
#include"Gauss_and_LDL.h"
using namespace std;
int main() {

    const double eps = 1e-9;
    const int NIT=150;
    vector<double>x0={1,1},xk1(x0);
    double d1=1,d2=1;
    int k=1;
    int size=2;
    vector<vector<double>> JMatrix(size,vector<double>(size));
    vector<double>F(size);
    
    while(d1>eps||d2>eps){
        if(NIT<=k) {cout<<"IER=2";break;}
        F[0]=-function1(x0[0],x0[1]);
        F[1]=-function2(x0[0],x0[1]);
        J(x0,JMatrix);
        vector<double>result=gaussElimination(JMatrix,F);
        xk1[0]+=result[0];
        xk1[1]+=result[1];
        d1=delta1(x0);
        d2=delta2(x0,xk1);
        cout << "Step" << k++ << " delta1: " << d1 << " delta2: " << d2 << endl;
        x0=xk1;
    }
    PrintAnswer(x0,k);
    
    
    
    return 0;
}

