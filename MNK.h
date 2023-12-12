
#include<vector>
using namespace std;
#pragma once
vector<double> getPOWERX(const int& N, const int& m, const vector<double>& X);
vector<vector<double>> getSUMX(const int& N, const int& m, const vector<double>& X,vector<double>POWERX);
vector<double> getPRAW(const int& N, const int& m, const vector<double>& X,vector<double>Y);
vector<double>getA(vector<double>&PRAW,vector<vector<double>>&SUMX);
double getS(const int& N, const int& m, const vector<double>& X, const vector<double>& Y, const vector<double>& A);
void printResult(const vector<double>& X, const vector<double>& Y, const vector<double>& A, const double& S);
void writeVectorsToFile(const vector<double>& X,const vector<double>& Y,const vector<double>& A,const string& filename);
