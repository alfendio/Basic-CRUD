#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    int nilai;
    char nilai1;
    struct data *next;
}*head, *tail, *current;

insertKepala(int nilaiMasukkan, char nilaiHuruf){
    current = (struct data*)malloc(sizeof(struct data));
    current->nilai = nilaiMasukkan;
    current->nilai1 = nilaiHuruf;

    if(head==NULL){
        head=tail=current;
    }else{
        current->next = head;
        head=current;
    }
}

insertAkhir(int nilaiMasukkan, char nilaiHuruf){
    current = (struct data*)malloc(sizeof(struct data));
    current->nilai = nilaiMasukkan;
    current->nilai1 = nilaiHuruf;

    if(head==NULL){
        head = tail = current;
    }else{
        tail->next = current;
        tail = current;
    }
    tail->next = NULL;
}

void tampil(){
    current = head;
    while(current!=NULL){
        printf("\nnilainya %i", current->nilai);
        printf("\nnilainya dalam huruf %c", current->nilai1);
        current = current->next;
    }
}

void update(int ak, int aw) {
    if (head==NULL) {
        printf("Tidak ada data");
        return;
    }
    current = head;
    while(current->nilai!=NULL){
        if(current->nilai==aw){
            current->nilai=ak;
            printf("\n%d diganti dengan %d\n\n", aw, ak);
            return;
        }
        current = current->next;
    }
    printf("%d Tidak terdapat nilai tersebut\n\n", aw);
}

void delete(){
    int sv;
    int del;
    if(head==NULL){
        printf("Tidak ada data yang dihapus\n");
    }
    else{
        sv = head->nilai;
        printf("Nilai yang dihapus : %i \n", sv);
        int del = head;
        head = head->next;
    }
}

void main(){
    int menu=1;
    int nilainya;
    int nil1;
    int nil2;
    while(menu!=0){
        printf("\n1.insert");
        printf("\n2.tampil");
        printf("\n3.update");
        printf("\n4.delete");
        printf("\n masukkan menu : ");
        scanf("%i", &menu);

        switch(menu){
            case 1:
                    printf("\nmasukkan nilai : ");
                    scanf("%i", &nilainya);
                    if(nilainya>80){
                        insertAkhir(nilainya, 'A');
                    }else if(nilainya>70){
                        insertAkhir(nilainya, 'B');
                    }else{
                        insertAkhir(nilainya, 'E');
                    }
                break;
            case 2: tampil();
                break;
            case 3:
                printf("Masukkan nilai baru : ");
                scanf("%i", &nil1);
                printf("Masukkan nilai yang akan diubah : ");
                scanf("%i", &nil2);
                update(nil1, nil2);
                break;
            case 4: delete();
            break;

            default : printf("\nmenunya gaaada nih kak");
            break;
        }
    }
    return 0;
}
