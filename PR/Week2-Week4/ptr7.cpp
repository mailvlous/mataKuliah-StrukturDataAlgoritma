#include <stdio.h>
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
char *pkota = "BANDUNG"; // kalo pake pointer char gaperlu deklarasi jumlah index array //kalo pake pointer itu satu kesatuan bukan array of characters, jadi tidak bisa dipecah
*pkota = 'JAKARTA'; // karena dinamis
int size = sizeof(pkota);
printf("Ukuran pkota = %d\n", size);
puts(pkota);
return 0;
}