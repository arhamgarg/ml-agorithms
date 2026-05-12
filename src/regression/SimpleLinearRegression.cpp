#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  vector<double> x = {1, 2, 3, 4, 5};
  vector<double> y = {2, 4, 5, 4, 5};
  int n = x.size();

  double mean_x = accumulate(x.begin(), x.end(), 0.0) / n;
  double mean_y = accumulate(y.begin(), y.end(), 0.0) / n;
  double num = 0.0, den = 0.0;

  for (int i = 0; i < n; ++i) {
    num += (x[i] - mean_x) * (y[i] - mean_y);
    den += (x[i] - mean_x) * (x[i] - mean_x);
  }

  double m = num / den;
  double c = mean_y - m * mean_x;

  cout << "Model: y = " << c << " + " << m << "*x\n";
  
  return 0;
}