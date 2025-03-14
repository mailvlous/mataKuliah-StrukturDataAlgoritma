#include <stdio.h>
int main()
{
float d, *pd;
d = 54.5;
printf("Isi d semula = %g\n", d);
pd = &d; // address pointer pd menunjuk ke d
*pd = *pd + 10; // karena menunjuk ke d maka pd akan mengakses d, dalam hal ini d akan bertambah 10
printf("Isi d kini = %g\n", d);
return 0;
}