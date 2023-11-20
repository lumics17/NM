#include <iostream>
#include <vector>
#include "Gauss_and_LDL.h"
using namespace std;
int main(){
    
    vector<vector<double>> A = {{21.547, -95.51, -96.121}, {10.223, -91.065, -7.343}, {51.218, 12.264, 86.457}};
    vector<double> B = {-49.93,-12.465, 60.812};
    printMatrix(A);
    vector<double> result = gaussElimination(A, B);
    printAnswer(result);

    return 0;
}