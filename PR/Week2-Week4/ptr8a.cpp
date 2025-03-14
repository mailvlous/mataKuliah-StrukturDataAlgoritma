#include <stdio.h>
#include <string.h>
#define PANJANG 20
int main()
{
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
char nama1[PANJANG] = "DEWI SARTIKA";
char nama2[PANJANG] = "SULTAN HASANUDDIN";
char namaX[PANJANG];
puts("Nama semula : ");
printf("Nama 1 --> %s\n", nama1);
printf("Nama 2 --> %s\n", nama2);
/* Pertukaran string */
strcpy(namaX, nama1); // char *strcpy(char *dest, const char *src);
strcpy(nama1, nama2); // strcpy adalah function yang berfungsi untuk mengcopy string
strcpy(nama2, namaX); // mempunyai 2 parameter yaitu dest(destination/tujuan) dan src(sumber)
puts("Nama sekarang : ");
printf("Nama 1 --> %s\n", nama1); // output harusnya "SULTAN HASANUDDIN"
printf("Nama 2 --> %s\n", nama2); // output harusnya "DEWI SARTIKA"
return 0;
}

char *strcpy(char *dest, const char *src) {
    char *ptr = dest;  // Save the starting address of dest

    while (*src != '\0') {  // Copy characters until null terminator
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Add null terminator

    return ptr;  // Return pointer to destination
}
