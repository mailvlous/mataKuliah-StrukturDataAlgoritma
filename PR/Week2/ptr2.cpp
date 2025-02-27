#include <stdio.h>
int main()
{
int *pu;
float nu;
int u = 1234;
pu = &u; // alamat u di assign ke pointer pu
nu = *pu; // nilai yang ditunjuk oleh pointer pu di assign ke nu atau nu addressnya sama kayak pu dan u
printf("u = %d\n", u);
printf("nu = %f\n", nu);
return 0;
}