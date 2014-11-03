struct X {
  int c;
  struct X *next;
};
int add2 (struct X *x) {
  if (x == 0) 
	return 0;
  else 
	return x->c + add2(x->next);
}
