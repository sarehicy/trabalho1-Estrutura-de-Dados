#include <stdio.h>

//Função para inversao dos elementos do vetor(1)
void inversaoDoVetor(int vetor[], int size){
    // c: começo do vetor (indice 0); f: final do vetor (tamanho menos 1)
    int c = 0; 
    int f = size-1; 
    while (f>c) {
        int aux = vetor[c]; 
        vetor[c] = vetor[f]; 
        vetor[f] = aux; 
        c++; 
        f--; 
    }

}

//Função para busca sequêncial (2) 
void buscaSequencial(int vetor[], int size, int numBuscado){
    int flag = 0;

    for(int i = 0; i < size; i++){
        if(vetor[i] == numBuscado){
            printf("SIM");
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        printf("NAO");
    }
}

//Função para busca binária interativa (3)
void buscaBinariaIterativa(int vetor[], int size, int numBuscado){
    int inicio = 0;
    int fim = size - 1;
    int flag = 0;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;
        if(numBuscado == vetor[meio]){
            printf("SIM");
            flag = 1;
            break;
        }else{
            if(numBuscado > vetor[meio]){
                inicio = meio + 1;
            }else{
                fim = meio - 1;
            }
        }
    }

    if(flag == 0){
        printf("NAO");
    }
}

void buscaBinariaRec(int c, int f, int *v, int n){
    //c: começo do vetor, f: final do vetor, v: vetor, n: numero buscado

    //se o índice do começo do vetor for maior que o índice do fim, o valor não foi encontrado
    if (c>f){
        printf("NAO\n");
        return;
    }
    
    //guarda índice do meio do vetor
    int index = (c+f)/2;

    if (v[index] == n){ //se o valor for encontrado
        printf("SIM\n");
        return;
    }

    if (v[index] < n){ //se o valor na posição do meio for menor que o valor desejado, a busca continua apartir desse valor
        buscaBinariaRec(index+1, f, v, n);
    } else{ //se o valor na posição do meio for maior que o valor desejado, a busca continua nos elementos que antecedem este valor
        buscaBinariaRec(c, index-1, v, n);
    }

}


int main(){
    int size, operacao, numBuscado;
    scanf("%d", &size);
    int vetor[size];

    for (int i = 0; i<size; i++){
        scanf("%d", &vetor[i]);
    }

    do{
        scanf("%d", &operacao);

        switch(operacao){
            case 1:
                //inverter ordem
                inversaoDoVetor(vetor, size);
                break;
            case 2:
                //busca sequencial
                scanf("%d", &numBuscado);
                buscaSequencial(vetor, size, numBuscado);
                break;
            case 3:
                // busca binária iterativa
                scanf("%d", &numBuscado);
                buscaBinariaIterativa(vetor, size, numBuscado);
                break;
            case 4:
                // busca binária recursiva
                scanf("%d", &numBuscado);
                buscaBinariaRec(0, size-1, vetor, numBuscado);
                break;
        }

    }while (operacao != 5);

}
