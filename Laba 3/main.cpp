#include <cstdlib>
#include<iostream>
#include<iomanip>
#include<vector>
#include"Newton.h"
#include"Explicit_and_Implicit.h"
#include"Gauss_and_LDL.h"
using namespace std;
int main() {
	
	vector<double>u(2);
	u[0] = 0;
	u[1] = -0.412;
        Explicit(u);
        u[0]=10;
        u[1]=22;
        
	return 0;

}


