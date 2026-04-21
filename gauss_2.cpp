#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Fraction {
private:
	long long num;
	long long den;
public:
	Fraction(long long n = 0, long long d = 1) :
		num(n), den(d) {
		normalize();
	}

	void normalize(){
		if (den < 0) {
			num = -num;
			den = -den;
		}
		long long g = gcd(abs(num), abs(den));
		num /= g;
		den /= g;
	}

	friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
		os << f.num;
		if (f.den > 1) {
			os << "/" << f.den;
		}
		return os;
	}

	friend std::fstream& operator>>(std::fstream& fs, const Fraction& f) {
		fs >> 
	}

	Fraction operator+(const Fraction& other) const {
		return Fraction(
			num * other.den + other.num * den,
			den * other.den);
	}

	Fraction operator-(const Fraction& other) const {
		return Fraction(
			num * other.den - other.num * den,
			den * other.den
		);
	}

	Fraction operator*(const Fraction& other) const {
		return Fraction(
			num * other.num,
			den * other.den
		);
	}

	Fraction operator/(const Fraction& other) const {
		return Fraction(
			num * other.den,
			den * other.num
		);
	}

	bool operator>(const Fraction& other) const {
		return num * other.den > other.num * den;
	}
	 
	bool operator<(const Fraction& other) const {
		return num * other.den < other.num * den;
	}

	bool operator==(const Fraction& other) const {
		return num == other.num and den == other.den;
	}

	bool operator!=(const Fraction& other) const {
		return num != other.num or den != other.den;
	}

	long long input() {
		long long value;

		cout << "Введите значение: " << endl;
		cin >> value;

		return value;
	}

	void set_num() { num = input(); }
	void set_den() { den = input(); }
	long long get_num() { return num; }
	long long get_den() { return den; }
};

int main() {
	system("chcp 1251>nul");

	ifstream file("variant8_matrix.txt");

	int matrix_size;
	file >> matrix_size;

	//Fraction a(2, 3);
	//Fraction b(7, 14);

	//cout << a + b << ", " << a - b << ", " << a * b << ", " << a / b << ", " << (a > b) << endl;

	vector<vector<Fraction>> matrix(matrix_size, vector<Fraction>(matrix_size + 1));
	Fraction a;
	if (!file.is_open()) {
		cerr << "Ошибка открытия файла!" << endl;
	}
	else {
		for (int i = 0; i < matrix_size; i++) {
			for (int j = 0; j < matrix_size; j++) {
				file >> matrix[i][j];
			}
			cout << "\n";
		}
		file.close();
	}

	//vector<vector<double>> matrix(matrix_size, vector<double>(matrix_size + 1));

	//int a;
	//if (!file.is_open()) {
	//	cerr << "Ошибка открытия файла!" << endl;
	//}
	//else {
	//	for (int i = 0; i < matrix_size; i++) {
	//		for (int j; j < matrix_size + 1; j++) {
	//			file >> matrix[i][j];
	//		}
	//		cout << "\n";
	//	}
	//	file.close();
	//}

	return 0;
}