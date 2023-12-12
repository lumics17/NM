#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;

void printMatrix(const vector<vector<double>>& matrix){
    static int counter=1;
    cout<<"Matrix"<<counter++<<':'<<endl;
    for (const vector<double>& row : matrix) {
        for (const double& val : row) {
            cout<< val<<setw(10);
        }
        cout<<"\n";
    }
    cout<<'\n';
}
void printAnswer(vector<double> result){
    cout << "Solution:";
    for (const auto&value : result) {
        cout <<setprecision(4)<< " " << value;
    }
    cout << endl;
}
// Прямой ход метода Гаусса
void forwardElimination(vector<vector<double>>& augmentedMatrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1;  j < n; j++) {
            double ratio = augmentedMatrix[j][i] / augmentedMatrix[i][i];
            for (int k = 0; k <= n; k++) {
                augmentedMatrix[j][k] -= ratio * augmentedMatrix[i][k];
            }
        }
    }
}

// Обратный ход метода Гаусса
vector<double> backSubstitution(const vector<vector<double>>& augmentedMatrix, int n) {
    vector<double> solution(n);
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = augmentedMatrix[i][n];
        for (int j = i + 1; j < n; j++) {
            solution[i] -= augmentedMatrix[i][j] * solution[j];
        }
        solution[i] /= augmentedMatrix[i][i];
    }
    return solution;
}
vector<double> FVector(const vector<double>& X, const vector<double>& B, vector<double>& AX, const vector<vector<double>>& Acopy){
     vector<double> F;
     int n = Acopy.size();
     double result;
    for(int i = 0; i<n;i++){
           result = 0;
        for(int j = 0; j<n;j++){
            result += Acopy[i][j]*X[j];
        }
        AX.push_back(result);
        F.push_back(AX[i]-B[i]);
    }
    return F;
    
}
double FNorm(const vector<double>& F){
    double max = abs(F[0]);
    for(int i = 1; i<F.size();i++){
        if(max<abs(F[i])){
            max = abs(F[i]);
        }
    }
    return max;
}

// Метод Гаусса для решения системы линейных уравнений
vector<double> gaussElimination(const vector<vector<double>>& A, const vector<double>& B) {
    int n = A.size();
    // Создаем расширенную матрицу [A | B]
    vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmentedMatrix[i][j] = A[i][j];
        }
        augmentedMatrix[i][n] = B[i];
    }

    // Прямой ход
    forwardElimination(augmentedMatrix, n);

    // Обратный ход
    vector<double> solution = backSubstitution(augmentedMatrix, n);

    return solution;
}
double relativeError(vector<vector<double>>&Acopy,vector<double>&AX,vector<double>&X){
    vector<double>newX=gaussElimination(Acopy,AX);
    double maxd = abs(newX[0]-X[0]);
    double maxX = abs(X[0]);
    for(int i = 1; i<X.size();i++){
        if(maxd < abs(newX[i]-X[i])) {
            maxd = abs(newX[i] - X[i]);
        }
        if(maxX < abs(X[i])){
            maxX = abs(X[i]);
        }
    }
    return maxd/maxX;
    
}