#include <stdio.h>
int main()
{
int *pu;
float nu;
int u = 1234;
pu = &u;
nu = *pu;
printf("u = %d\n", u);
printf("nu = %f\n", nu);
return 0;
}