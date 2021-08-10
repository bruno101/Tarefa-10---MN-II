#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

tuple<double, vector<double>> potReg(vector<vector<double>> A, vector<double> v0, double epsilon) {

}

int main() {

  int n;

  cout << "Digite a dimensão da matriz: ";
  cin >> n;

  vector<double> v0(n);
  vector<vector<double>> A(n, vector<double>(n));
  vector<double> v(n);
  double lambda;
  double epsilon;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "Digite o valor de A[" << i+1 << "][" << j+1 << "]: ";
      cin >> A[i][j];
    }
  }

  cout << "Digite o valor da precisão desejada: ";
  cin >> epsilon;

  auto res = potReg(A, v0, epsilon);

  cout << "Autovalor dominante:" << get<0>(res) << "\n Autovetor correspondente: (";
  for (int i = 0; i < n; i++) {
    cout << get<1>(res)[i];
  }

}