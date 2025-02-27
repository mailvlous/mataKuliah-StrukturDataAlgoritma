#include <stdio.h>
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
int var_x = 273;
int *ptr1; /* ptr1 adl pointer yang menunjuk ke objek bertipe integer */
/* (Boleh disebut pointer integer saja) */
int **ptr2; /* ptr2 adl pointer yang menunjuk ke pointer yang menunjuk */
/* ke objek bertipe integer (Boleh disebut : pointer menunjuk ke pointer integer

saja) */
ptr1 = &var_x; // ptr1 mengakses address var_x
ptr2 = &ptr1; // ptr2 karena pointer to pointer maka mengakses address ptr1(pointer)
/* Mengakses nilai var_x melalui ptr1 dan ptr2 */
printf("Nilai var_x = %d\n", *ptr1); // output harusnya 273
printf("Nilai var_x = %d\n", **ptr2); // output harusnya 273
return 0;
}