#include <cmath>
#include <vector>
#include<iostream>
#include"Gauss_and_LDL.h"
#include <fstream>
using namespace std;
vector<double> getPOWERX(const int& N, const int& m, const vector<double>& X){
    vector<double> POWERX(2 * m);
    for (int k = 0; k < 2 * m; k++) {
        double sum = 0.0;
        for (int i = 0; i < N; i++) {
            sum += pow(X[i], k);
        }
        POWERX[k] = sum;
    }
    return POWERX;
}

vector<vector<double>> getSUMX(const int& N, const int& m, const vector<double>& X,vector<double>POWERX){
    vector<vector<double>> SUMX(m+1, vector<double>(m+1));
    for (int l = 0; l <m+1; l++) {
        for (int j = 0; j <m+1; j++) {
            SUMX[l][j] = POWERX[l + j];
        }
    }
    SUMX[0][0] = N;\
    return SUMX;
}
vector<double> getPRAW(const int& N, const int& m, const vector<double>& X,vector<double>Y){
    vector<double> PRAW(m+1);
    for (int l = 0; l <m+1; l++) {
        for (int i = 0; i < N; i++) {
            PRAW[l] += (Y[i] * pow(X[i], l));
        }
    }
    return PRAW;
}

vector<double>getA(vector<double>&PRAW,vector<vector<double>>&SUMX){
    return gaussElimination(SUMX,PRAW);
}
double getS(const int& N, const int& m, const vector<double>& X, const vector<double>& Y, const vector<double>& A){
    double S = 1.0/(N-m-1);
    double sum = 0;
    for(int i=0; i<N; i++){
        double yi = Y[i];
        for(int j = 0; j<m+1;j++){
            yi-= A[j] * pow(X[i],j);
        }
        sum += yi*yi;
    }
    S*=sum;
    S = sqrt(S);
    return S;
}
void printResult(const vector<double>& X, const vector<double>& Y, const vector<double>& A, const double& S){
    cout << "r: ";
    for(const double& elem: X){
        cout << elem << " ";
    }
    cout<<"C";
    cout << endl << "t: ";
    for(const double& elem: Y){
        cout << elem << " ";
    }
    cout<<"мкОм";
    cout << endl;

    cout << "r = ";
    for(int j = A.size()-1; j >= 0; --j){
        cout << A[j];
        if(j > 0) {
            if(A[j - 1] >= 0) cout << "t + ";
            else cout << " ";
        }
    }

    cout << endl << "S: " << S << endl;
}
void writeVectorsToFile(const vector<double>& r,const vector<double>& t,const vector<double>& A,const string& filename){
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        return;
    }
    int xSize = r.size();
    for(int i = 0; i<xSize; i++){
        out << r[i] << " ";
    }
    out << "\n";
    int ySize = t.size();
    for(int i = 0; i<ySize; i++){
        out << t[i] << " ";
    }
    out << "\n";
    int aSize = A.size();
    for(int i = 0; i<aSize; i++){
        out << A[i] << " ";
    }
    out << "\n";
    out.close();
    cout << "Данные успешно записаны в файл: " << filename << endl;
}