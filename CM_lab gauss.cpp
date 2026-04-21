#if 0
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    system("chcp 1251>nul");

    ifstream file("variant8_matrix.txt");
    if (!file) {
        cout << "Файл variant8_matrix.txt не найден\n";
        return 1;
    }

    int n;
    file >> n;

    vector<vector<double>> m(n, vector<double>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            file >> m[i][j];
        }
    }
    file.close();

    cout << "Матрица из файла:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << setw(10) << m[i][j] << "| ";
        }
        cout << "\n";
    }

    // Прямой ход
    for (int k = 0; k < n; ++k) {
        if (fabs(m[k][k]) < 1e-12) {
            cout << "Нельзя продолжить: диагональный элемент равен нулю.\n";
            return 1;
        }

        for (int i = k + 1; i < n; ++i) {
            double c = m[i][k] / m[k][k];
            for (int j = k; j <= n; ++j) {
                m[i][j] -= c * m[k][j];
            }
        }
    }

    cout << "\nВерхнетреугольная матрица:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << setw(10) << fixed << setprecision(6) << m[i][j] << "| ";
        }
        cout << "\n";
    }

    // Обратный ход
    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; --i) {
        double right = m[i][n];
        for (int j = i + 1; j < n; ++j) {
            right -= m[i][j] * x[j];
        }
        x[i] = right / m[i][i];
    }

    cout << "\nНайденные неизвестные:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << "\n";
    }

    return 0;
}
#endif