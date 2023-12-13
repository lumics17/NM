   
#include<vector>
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;

double u1d(vector<double> u, double t, int n)
{ 
    double Om=2.5+1/40;
	if (n == 0) {
		return -u[0] * u[1] + ((t < 1e-9) ? 0.0 : (sin(t) / t));
	}
	else if (n == 1) {
		return -u[1] * u[1] + (Om*t) / (1 + t * t);
	}
	return 0;
}
double u2d(double u1,double u2,double t,double a){
    return -u2*u2+(a*t)/(1+t*t);
}
void Explicit(vector<double> u){
    double tau = 0, tk = 0;
    double Eps = 0.001, T = 1, tauMax = 0.01;
    vector<double> yk(u);
    do {
        vector<double> tmp(yk.size());
		for (int i = 0; i < yk.size(); i++)
		{
			tmp[i] = u1d(yk, tk, i);
		}
		
		if (Eps / (abs(tmp[0]) + Eps / tauMax) > Eps / (abs(tmp[1]) + Eps / tauMax))
		{
			tau = Eps / (abs(tmp[1]) + Eps / tauMax);
		}
		else 
		{
			tau = Eps / (fabs(tmp[0]) + Eps / tauMax);
		}
			
		for (int i = 0; i < yk.size(); i++) //yk=yk+Tau*f[yk,tk]
		{
			yk[i] += tau * fabs(tmp[i]);
		}
		tk += tau;
                       cout << "tk" << setw(15);
		       cout << setw(15) << "yk[0]";
                       cout << setw(15) << "yk[1]";
		       cout << "\n\n";
		for (int i = 0; i < yk.size(); i++) 
		{
			if (i == 0)
		cout << tk << setw(15);
			cout << setw(15) << yk[i];
			if (i == yk.size() - 1)
				cout << endl;
		
		}
		if (tk + tau > T && tk < T) 
		{
			tk = T - tau;
		}
	} while (tk < T);
}
