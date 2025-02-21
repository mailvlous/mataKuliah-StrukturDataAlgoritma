#include <stdio.h>
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
char *pkota = "BANDUNG";
*pkota = 'JAKARTA';
int size = sizeof(pkota);
printf("Ukuran pkota = %d\n", size);
puts(pkota);
return 0;
}