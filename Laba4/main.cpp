#include <cstdlib>
#include<iostream>
#include<iomanip>
#include<vector>
#include"MNK.h"
#include"Gauss_and_LDL.h"
using namespace std;
int main() {
    vector<double> t = {19.1,25,30.1,36,40,45.1,50};
    vector<double> r = {76.3,77.8,79.75,80.80,82.35,83.9,85};
    int N=t.size(),m=1;
    vector<double> POWERX=getPOWERX(N,m,t);
    vector<vector<double>> SUMX(getSUMX(N,m,t,POWERX));
    vector<double> PRAW=getPRAW(N,m,t,r);
    vector<double>A=getA(PRAW,SUMX);
    double S=getS(N,m,r,t,A);
    printResult(r,t,A,S);
     writeVectorsToFile(r,t,A,"/home/surik/NetBeansProjects/CppApplication_3_1/file1.txt");
    return 0;
}

