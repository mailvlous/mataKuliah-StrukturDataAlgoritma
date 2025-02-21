#include <stdio.h>
int main()
{
int x, y;
int *px;
x = 87;
px = &x;
y = *px;
printf("Alamat x = %p\n", &x);
printf("Isi px = %d\n", x);
printf("Nilai yang ditunjuk oleh px = %d\n", *px);
printf("Nilai y = %d\n", y);
printf("Alamat y = %p\n", &y);
return 0;
}