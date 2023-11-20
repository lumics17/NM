#pragma once
double TPIntegral(double a,double b,double(*func)(double),double esp);
double Task(double x);
void printAnswer(double answer);
double SMIntegral(double a,double b,double(*func)(double),double eps);
double DISMIntegral(double a,double A,double b,double B,double(*func)(double,double),int N,int M);
double TaskDoubleIN(double x,double y);
double yj(int j,double widthy,double b);
double xi(int i,double widthx,double a);