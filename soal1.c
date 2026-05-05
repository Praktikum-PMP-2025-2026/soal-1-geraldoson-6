/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 * Modul               : 04 Dynamic Structures
 * Hari dan Tanggal    : Selasa, 5 Mei 2026
 * Nama (NIM)          : Geraldo Son Luther Silalahi (13224018)
 * Nama File           : soal1.c
 * Deskripsi           : Program ini adalah sistem validasi struktur segel dengan 
 * mengimplementasikan struktur data stack berbasis memori dinamis. Proses validasi tersebut 
 * dieksekusi dengan mengevaluasi pasangan simbol kurung secara sekuensial dari aliran input, 
 * sementara karakter alfabet huruf kecil diabaikan sepenuhnya. Melalui mekanisme penambahan 
 * dan pencabutan node struct Simbol secara konsisten pada tumpukan memori, program ini mendeteksi anomali 
 * penutupan simbol untuk menetapkan status validitas akhir segel.
 */

/*
Komentar variabel
krg = char kurung
Simbol * bwh adalah pointer menuju node berikutnya (dibawahnya)
SImbol * tmpk adalah pointer untuk tumpukan
ats = atas
bwh = bawah
bk = buka kurung
tk = tutup kurung
hps = hapus
pjg = panjang
tmpk = tumpukan
msk[2000] = input string dengan ruangan sampai dengan indeks 2000
br = baru sebagai pointer alokasi memori node baru
k = karakter yaitu nilai karakter kurung yang sedang diproses

referensi: https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* referensi: https://www.tutorialspoint.com/cprogramming/c_structures.htm */
typedef struct Simbol {
    char krg;
    struct Simbol * bwh;
} Simbol;


/* referensi: https://www.tutorialspoint.com/data_structures_algorithms/stack_algorithm.htm */
void push (Simbol ** ats, char k){
    Simbol * br = (Simbol*)malloc(sizeof(Simbol));
    br->krg =  k;
    br->bwh = * ats;
    * ats = br;
}

/* referensi: https://www.tutorialspoint.com/data_structures_algorithms/stack_algorithm.htm */
char pop(Simbol ** ats){
    if (* ats == NULL){
        return '\0';
    } 
    Simbol * hps = * ats;
    char k = hps->krg;
    * ats = hps->bwh;
    free(hps);
    return k;
}

/* referensi: https://www.tutorialspoint.com/cprogramming/c_decision_making.htm */
int cocok(char bk, char tk){
    if (bk == '(' && tk == ')'){
        return 1;}
    if (bk == '[' && tk == ']'){
        return 1;}
    if (bk == '{' && tk == '}'){
        return 1;}
    return 0;
}

int main (){
    char msk[2000];
    int i;
    int pjg;
    int valid = 1;
    Simbol * tmpk = NULL;

    if(scanf("%1999s", msk) != 1){
        return 0;}
    pjg = strlen(msk);

    /* referensi: https://www.tutorialspoint.com/cprogramming/c_loops.htm */
    for (i = 0; i < pjg; i++){
        if(msk[i] == '(' || msk[i] == '[' || msk[i] == '{'){
            push(&tmpk, msk[i]);
        } else if(msk[i] == ')' || msk[i] == ']' || msk[i] == '}'){
            if(tmpk == NULL){
                valid = 0;
                break;
            }
            char bk = pop(&tmpk);
            if (!cocok(bk, msk[i])){
                valid = 1;
                break;
            }
        }
    }

    /* referensi: https://www.tutorialspoint.com/cprogramming/c_while_loop.htm */
    if (tmpk != NULL){
        valid = 0;
        while(tmpk != NULL){
            pop(&tmpk);
        }
    }

    if(valid){
        printf("VALID\n");
    } else{
        printf("INVALID\n");
    }

    return 0;
}

