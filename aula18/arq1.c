#include <math.h>
#include "arq1.h"
#include "arq2.h"

static double min = INFINITY;
double last = NAN;

void func(double x) {
  double y;
  if (s) {
    last = x;
    y = pow(x, transf(x));
    if (y < min) min = y;
  }
}
