#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]
NumericVector PTriC(
    NumericVector q, double min, double max, double mode, bool lower_tail,
    bool log_p
) {
  int n = q.size();

  if (min >= max || mode > max || min > mode)
  {
    warning("\nNaN(s) produced."
              "\n* min must be less than max"
              "\n* min must be less than or equal to mode"
              "\n* mode must be less than or equal to max.");
    return NumericVector(n, R_NaN);
  }

  NumericVector p(n);
  for (int i = 0; i < n; i++)
  {
    if (q[i] <= min)
    {
      p[i] = 0.0;
    }
    else if (min < q[i] && q[i] <= mode)
    {
      p[i] = pow((q[i] - min), 2) / ((max - min) * (mode - min));
    }
    else if (mode < q[i] && q[i] < max)
    {
      p[i] = 1.0 - pow((max - q[i]), 2) / ((max - min) * (max - mode));
    }
    else // if (max <= q[i])
    {
      p[i] = 1.0;
    }
  }

  if (!lower_tail)
  {
    p = 1.0 - p;
  }

  if (log_p)
  {
    p = Rcpp::log(p);
  }

  return p;
}

// [[Rcpp::export]]
NumericVector PTriC2(
    NumericVector q, NumericVector min, NumericVector max, NumericVector mode,
    bool lower_tail, bool log_p
) {
  int n = q.size();

  NumericVector p(n);
  for (int i = 0; i < n; i++)
  {
    if (min[i] >= max[i] || mode[i] > max[i] || min[i] > mode[i])
    {
      warning("\nNaN produced."
                "\n* min must be less than max"
                "\n* min must be less than or equal to mode"
                "\n* mode must be less than or equal to max");
      p[i] = R_NaN;
    }
    else if (q[i] <= min[i])
    {
      p[i] = 0.0;
    }
    else if (min[i] < q[i] && q[i] <= mode[i])
    {
      p[i] = pow((q[i] - min[i]), 2) / ((max[i] - min[i]) * (mode[i] - min[i]));
    }
    else if (mode[i] < q[i] && q[i] < max[i])
    {
      p[i] = 1.0 - pow((max[i] - q[i]), 2) /
        ((max[i] - min[i]) * (max[i] - mode[i]));
    }
    else // if (max[i] <= q[i])
    {
      p[i] = 1.0;
    }
  }

  if (!lower_tail)
  {
    p = 1.0 - p;
  }

  if (log_p)
  {
    p = Rcpp::log(p);
  }

  return p;
}

/*** R

*/
