#include <stdio.h>
int main()
{
int x, y;
int *px; //pointer hanya berisi alamat, cuma nunjuk
x = 87;
px = &x; //alamat pointer px menunjuk ke x
y = *px; //y menunjuk ke nilai yang ditunjuk oleh px yaitu x
printf("Alamat x = %p\n", &x);
printf("Isi px = %d\n", x);
printf("Nilai yang ditunjuk oleh px = %d\n", *px);
printf("Nilai y = %d\n", y);
printf("Alamat y = %p\n", &y);
return 0;
}