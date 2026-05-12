// #include "matplotlibcpp.h"
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
// namespace plt = matplotlibcpp;

int main() {
  vector<double> advertising_costs = {100, 200, 300, 400, 500};
  vector<double> sales = {300, 500, 600, 700, 800};
  int n = advertising_costs.size();

  double mean_adv =
      accumulate(advertising_costs.begin(), advertising_costs.end(), 0.0) / n;
  double mean_sales = accumulate(sales.begin(), sales.end(), 0.0) / n;
  double num = 0.0, den = 0.0;

  for (int i = 0; i < n; ++i) {
    num += (advertising_costs[i] - mean_adv) * (sales[i] - mean_sales);
    den +=
        (advertising_costs[i] - mean_adv) * (advertising_costs[i] - mean_adv);
  }

  double m = num / den;
  double c = mean_sales - m * mean_adv;

  cout << "Model: Sales = " << fixed << setprecision(2) << c << " + " << m
       << "*Advertising_Costs\n";

  vector<double> y_pred(n);

  for (int i = 0; i < n; ++i) {
    y_pred[i] = c + m * advertising_costs[i];
  }

  // plt::scatter(advertising_costs, sales, 30.0, {{"color", "blue"}});
  // plt::plot(advertising_costs, y_pred, {{"color", "red"}});
  // plt::xlabel("Advertising Costs");
  // plt::ylabel("Sales");
  // plt::title("Advertising Costs vs Sales");
  // plt::save("static/images/plot.png");

  return 0;
}