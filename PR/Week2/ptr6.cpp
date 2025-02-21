#include <stdio.h>
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
static int tgl_lahir[] = {18, 6, 1989};
int *ptgl;
ptgl = tgl_lahir;
printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl);
for (int i = 0; i < 3; i++)
{
    printf("Data tgl_lahir = %d\n", tgl_lahir[i]);
}
return 0;
}