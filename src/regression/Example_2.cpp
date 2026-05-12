// #include "matplotlibcpp.h"
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
// namespace plt = matplotlibcpp;

int main() {
  vector<double> ad_hours = {10, 20, 30, 40, 50};
  vector<double> weekly_sales = {200, 420, 650, 800, 950};
  int n = ad_hours.size();

  double mean_x = accumulate(ad_hours.begin(), ad_hours.end(), 0.0) / n;
  double mean_y = accumulate(weekly_sales.begin(), weekly_sales.end(), 0.0) / n;
  double num = 0.0, den = 0.0;

  for (int i = 0; i < n; ++i) {
    num += (ad_hours[i] - mean_x) * (weekly_sales[i] - mean_y);
    den += (ad_hours[i] - mean_x) * (ad_hours[i] - mean_x);
  }

  double m = num / den;
  double c = mean_y - m * mean_x;

  cout << fixed << setprecision(2);
  cout << "Sales = " << c << " + " << m << "*Ad_Hours\n";

  vector<double> y_pred(n);

  for (int i = 0; i < n; ++i) {
    y_pred[i] = c + m * ad_hours[i];
  }

  //   plt::scatter(ad_hours, weekly_sales, 30.0, {{"color", "blue"}});
  //   plt::plot(ad_hours, y_pred, {{"color", "red"}});
  //   plt::xlabel("Ad Hours");
  //   plt::ylabel("Weekly Sales");
  //   plt::title("Hours of advertisement vs. Weekly Sales");
  //   plt::save("static/images/plot.png");

  return 0;
}