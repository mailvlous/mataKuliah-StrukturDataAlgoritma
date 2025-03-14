#include <stdio.h>
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
static int tgl_lahir[] = {18, 6, 1989};
int *ptgl;
ptgl = tgl_lahir;

printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl); //nilai yang ditunjuk oleh pointer adalah index ke-0
printf("Nilai yang ditunjuk oleh ptgl = %d\n", *(ptgl+1)); //nilai yang ditunjuk oleh pointer adalah index ke-1
printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl+1); // nilai yang ditunjuk oleh pointer adalah index ke-0 + 1
for (int i = 0; i < 3; i++)
{
    printf("Data tgl_lahir = %d\n", tgl_lahir[i]);
}
return 0;
}