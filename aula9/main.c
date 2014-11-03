
#include <stdio.h>

void printstring(char * p);

int main (void)
{
char string[]="Ai gente";
printstring(&string[0]);

return 0;
}
