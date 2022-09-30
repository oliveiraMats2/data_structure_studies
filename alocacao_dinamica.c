#include <stdio.h>
#include <stdlib.h>
#define tam_vet 10

void field_vet_random(float *vet, unsigned tam){
    unsigned cont;
    srand(100);
    for(cont = 0; cont < tam; cont++){
        vet[cont] = rand();

    }
}

void copia_vet(float *vet_1, float *vet_2, int tam){
    for(unsigned i = 0; i < tam; i++){
        vet_2[i] = vet_1[i];
    }
}

void print_vet(float *vet, int tam){
    for(unsigned i = 0; i < tam; i++){
        printf(" %f", vet[i]);
    }
    printf("\n");
}

int check_sort(float *vet, int n){
    for(unsigned i = 0; i < (n-1); i++){
        if(vet[i] > vet[i + 1]){
            return 0;
        }
    }
    return 1;
}

// void quickSortR(float v[], int start, int end){
//     int i, j;
//     float pivot, tmp;
//     if((start < end)){
//         pivot = v[]
//     }
// }

// int same_elements_in_vet(float vet_1[], float vet_2[], int n){
//     for(int i = 0; i < n-1; i++){
//         if()
//     }
// }

int main(){

    float *vetBig1 = (float*) malloc(tam_vet*sizeof(float));
    float *vetBig2 = (float*) malloc(tam_vet*sizeof(float));

    field_vet_random(vetBig1, tam_vet);
    copia_vet(vetBig1, vetBig2, tam_vet);

    print_vet(vetBig1, tam_vet);
    print_vet(vetBig2, tam_vet);
    
    // create function that generate vector rand
    return 0;
}