#include <iomanip>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

double xi(int i,double widthx,double a){
    double xi=a+i*widthx;
    return xi;
}

double yj(int j,double widthy,double b){
    double yj=b+j*widthy;
    return yj;  
}
double TPIntegral(double a,double b,double(*func)(double),double eps){
    int N=1;
    double width=(b-a)/N;
    double Integral=func(a) + func(b);
    double Integral2;
   while (abs(Integral-Integral2)>3*eps){
        N*=2;
        Integral2=Integral;
        width=(b-a)/N;
        for(int i=0;i<N-1;i++){
            Integral+=2*func(a+i*width);
        }
        Integral*=width/2;
    }
    return Integral;
}
double SMIntegral(double a,double b,double(*func)(double),double eps){
    
     int N=1;
    double width=(b-a)/N;
    double Integral=func(a) + func(b);
    double Integral2;
   while (abs(Integral-Integral2)>15*eps){
        N*=2;
        Integral2=Integral;
        width=(b-a)/N;
        for(int i=1;i<N/2;i++){
            Integral+=4*func(a+(2*i-1)*width);
        }
        for(int i=1;i<N/2-1;i++){
            Integral+=2*func(a+(2*i)*width);   
        }
        Integral*=width/3;
    }
    return Integral;
}
double DISMIntegral(double a,double A,double b,double B,double(*func)(double,double),int N,int M){
    double answer=0;
//    double xi=0,yj=0;
    double widthx=(A-a)/(2*N);
    double widthy=(B-b)/(2*M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
             answer += func(xi(2*i,widthx,a),yj(2*j,widthy,b)) 
                     
                     + 4*func(xi(2*i+1,widthx,a),yj(2*j,widthy,b)) 
                     
                     + func(xi(2*i+2,widthx,a),yj(2*j,widthy,b)) 
                     
                     + 4*func(xi(2*i,widthx,a),yj(2*j+1,widthy,b)) 
                     
                     + 16*func(xi(2*i+1,widthx,a)+1,yj(2*j+1,widthy,b))
                     
                     + 4*func(xi(2*i+2,widthx,a),yj(2*j+1,widthy,b)) 
                     
                     + func(xi(2*i,widthx,a),yj(2*j+2,widthy,b)) 
                     
                     + 4*func(xi(2*i+1,widthx,a),yj(2*j+2,widthy,b))
                     
                     + func(xi(2*i+2,widthx,a),yj(2*j+2,widthy,b));
        }
    }
   answer*=((widthx*widthy)/9);
    return answer;
}


double Task(double x){
    return (exp(x/2))/sqrt(x+1);
}
double TaskDoubleIN(double x,double y){
    return sin(x+y);
}
void printAnswer(double answer){
    cout<<setprecision(10)<<"Answer = "<<answer<<endl;
}

