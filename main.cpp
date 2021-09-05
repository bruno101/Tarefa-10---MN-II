#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>

using namespace std;

tuple<double, vector<double> > potReg(double n, vector<vector<double>> A, vector<double> v0, double epsilon) {

  double lambdaNovo = 0;
  double lambdaVelho;
  vector<double> vNovo(n);
  vector<double> vVelho(n);
  vector<double> xVelho(n);
  double erro = epsilon+1;

  for (int i = 0; i < n; i++) {
    vNovo[i] = v0[i];
  }

  while (erro > epsilon) {

    lambdaVelho = lambdaNovo;
    double size = 0;
    for (int i = 0; i < n; i++) {
      vVelho[i] = vNovo[i];
      size += vVelho[i]*vVelho[i];
    }
    size = pow(size,0.5);
    for (int i = 0; i < n; i++) {
      vVelho[i] /= size;
    }
    for (int i = 0; i < n; i++) {
      vNovo[i] = 0;
      for (int j = 0; j < n; j++) {
        vNovo[i] += A[i][j]*vVelho[j];
      }
    }
    lambdaNovo = 0;
    for (int i = 0; i < n; i++) {
      lambdaNovo += vVelho[i]*vNovo[i];
    }
    
    erro = abs((lambdaNovo-lambdaVelho)/lambdaNovo);
    if (lambdaNovo == 0) {
      if (abs(lambdaNovo-lambdaVelho) < erro) {
        erro = 0;
      } else {
        erro = epsilon+1;
      }
    }

  }

  return make_tuple(lambdaNovo, vNovo);

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
    v0[i] = 1;
    for (int j = 0; j < n; j++) {
      cout << "Digite o valor de A[" << i+1 << "][" << j+1 << "]: ";
      cin >> A[i][j];
    }
  }

  cout << "Digite o valor da precisão desejada: ";
  cin >> epsilon;

  auto res = potReg(n, A, v0, epsilon);

  cout << "Autovalor dominante: " << get<0>(res) << "\nAutovetor correspondente: (";
  for (int i = 0; i < n; i++) {
    cout << get<1>(res)[i] << ", ";
  }
  cout << "\b\b)";

}