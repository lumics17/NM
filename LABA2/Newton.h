#ifndef NEWTON_H
#define NEWTON_H
#include<vector>
#pragma once
double function1(const double& x01, const double& x02);

double function2(const double& x01, const double& x02);

double J1Dx01(const double& x01, const double& x02);

double J1Dx02(const double& x01, const double& x02);

double J2Dx01(const double& x01, const double& x02);

double J2Dx02(const double& x01, const double& x02);
void J(std::vector<double>& x0,std::vector<std::vector<double>> &matrix);
void J1(std::vector<double>& x0,std::vector<std::vector<double>>& matrix,double M);
double delta1(const std::vector<double>& x0);
double delta2(const std::vector<double>& x0,const std::vector<double>& xk1);
void PrintAnswer(const std::vector<double> x0,int k);
#endif /* NEWTON_H */

