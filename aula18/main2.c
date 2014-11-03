#include<stdio.h>
#include<stdlib.h>
struct X {
  int vi;
  double vd;
  struct X *next;
};
typedef struct X listax;

double pack (struct X *px);

listax *listaCria(void) {
  return NULL;
}
listax *listaInsere(listax *l, int vi,double vd) {
  listax *n = (listax *) malloc(sizeof(listax));
  if (n != NULL) {
    n->vi = vi;
	n->vd=vd;
    n->next = l;
  }
  return n;
}
int main (void)
{
int i;
listax* l1= listaCria();
for(i=0;i<10;i++)
  l1 = listaInsere(l1, i,i/10.0);



printf("pack=%lf\n",pack(l1));




return 0;
}
