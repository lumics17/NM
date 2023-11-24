#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;

void printMatrix(const vector<vector<double>>& matrix){
    for (const vector<double>& row : matrix) {
        for (const double& val : row) {
            cout<< val<<setw(35);
        }
        cout<<"\n";
    }
    cout<<'\n';
}
// Прямой ход метода Гаусса
void forwardElimination(vector<vector<double>>& augmentedMatrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio = augmentedMatrix[j][i] / augmentedMatrix[i][i];
            for (int k = 0; k <= n; k++) {
                augmentedMatrix[j][k] -= ratio * augmentedMatrix[i][k];
            }
        }
         printMatrix(augmentedMatrix);
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
void relativeError(){
    
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
void printAnswer(vector<double> result){
    cout << "Solution:";
    for (double value : result) {
        cout << " " << value;
    }
    cout << endl;
}
