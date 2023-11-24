#pragma once
#include<vector>
using namespace std;
void forwardElimination(vector<vector<double>>& augmentedMatrix, int n);

// Обратный ход метода Гаусса
vector<double> backSubstitution(const vector<vector<double>>& augmentedMatrix, int n);

// Метод Гаусса для решения системы линейных уравнений
vector<double> gaussElimination(const vector<vector<double>>& A, const vector<double>& B);
void printAnswer(vector<double> result);
void printMatrix(const vector<vector<double>>& matrix);
