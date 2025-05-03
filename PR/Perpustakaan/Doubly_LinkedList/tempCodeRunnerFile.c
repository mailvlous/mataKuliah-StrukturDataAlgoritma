int main() {
    addressBuku ListBuku = NULL;

    ins_Awal_Buku(&ListBuku, createBuku("The Hobbit", 4));

    printList(ListBuku);
    


    Queue A;

    createQueue(&A);

    enqueueAnggota(&A, createAnggota("Mad", 2));
    enqueueAnggota(&A, createAnggota("Ken", 1));
    enqueueAnggota(&A, createAnggota("Andressa", 1));
    enqueueAnggota(&A, createAnggota("Liam", 3));
    enqueueAnggota(&A, createAnggota("Nadila", 3));

    printQueueAnggota(A);

    sambungkanQueueKeBuku(&ListBuku, "The Hobbit", A);

    printList(ListBuku);

    urutkanAntrianBerdasarLevel(ListBuku, "The Hobbit");

    printList(ListBuku);


    // Queue A;
    // createQueue(&A);

    // enqueueAnggota(&A, createAnggota("Mad", 2));
    // enqueueAnggota(&A, createAnggota("Ken", 1));
    // enqueueAnggota(&A, createAnggota("Andressa", 1));
    // enqueueAnggota(&A, createAnggota("Liam", 3));
    // enqueueAnggota(&A, createAnggota("Nadila", 3));

    // sambungUrutProsesAntrian(ListBuku, "The Hobbit", A);

    // printList(ListBuku);



}