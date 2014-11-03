struct X1 {
  int vi;
  float vf;
};
double foo (double a, int b);
double pack1 (struct X1 *px, int n) {
  double acc = 0;
  int i;
  for (i=0;i<n;i++)
    acc += foo(px[i].vf, px[i].vi);
  return acc;
}
