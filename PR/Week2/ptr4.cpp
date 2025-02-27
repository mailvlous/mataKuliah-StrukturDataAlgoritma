#include <stdio.h>
int main()
{
int z, s, *pz, *ps;
z = 20;
s = 30;
pz = &z; // alamat pz diganti dengan alamat z
ps = &s; // alamat ps diganti dengan alamat s
*pz = *pz + *ps; // sama aja kayak z = z + s
printf("z = %d, s = %d\n", z , s);
return 0;
}