#include <stdio.h>
int main()
{
int z, s, *pz, *ps;
z = 20;
s = 30;
pz = &z;
ps = &s;
*pz = *pz + *ps;
printf("z = %d, s = %d\n", z , s);
return 0;
}