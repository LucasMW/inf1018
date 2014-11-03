#include<stdlib.h>
double foo (double a, int b);
struct X {
  int vi;
  double vd;
  struct X *next;
};
double pack (struct X *px) {
  double acc = 0;
  while (px != NULL) {
    acc += foo(px->vd, px->vi);
    px = px->next;
  }
  return acc;
}
