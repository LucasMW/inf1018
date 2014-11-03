struct X {
  int c;
  struct X *next;
};

int add (struct X *x) {
  int a = 0;
  for (; x != 0; x = x->next)
    a += x->c;
  return a;
}
