int bemboba (int num) {
  int local[3];
  int *a;
  int i;

  for (i=0,a=local;i<3;i++) {
    *a = num;
    a++;
  }
  return addl (local, 3);
}
