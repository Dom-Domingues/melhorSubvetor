#include<stdio.h>
#include<stdlib.h>




int* calcularMelhorSubvetor(int* vetor, int tamanhoVet);


int main()
{
    //int vetorInicial[8] = {1, -5, 4, 3, -2, 3, 20, -10};
    //int vetorInicial[8] = {20, -30, 15, -10, 30, -20, -30, 30};
    //int vetorInicial[5] = {4, 4, -1, 4, 4};
    //int vetorInicial[9] = {1, -5, 4, 3, -2, 3, 20, -10, 100};
    int vetorInicial[4] = {-1, -2, 20, 45, -10};




    printf("AAAA: %d", sizeof(vetorInicial));


    int tamanhoVet = sizeof(vetorInicial)/sizeof(int);

    int* melhorSubvetor = calcularMelhorSubvetor(vetorInicial, tamanhoVet);


    //printf("\n\n%d", melhorSubvetor[2]);


    printf("\n\nMelhor subvetor: ");


    for(int i = 0; i < sizeof(vetorInicial)/sizeof(int); i++){
        printf("%d, ", melhorSubvetor[i]);
    }

    return 0;

}


int* calcularMelhorSubvetor(int* vetor, int tamanhoVet)
{

    int ini = 0;

    printf("\n\nTAMANHO VET RECEBIDO: %d", tamanhoVet);
    int fim = tamanhoVet - 1;
    printf("\n\nFIM CALCULADO: %d", fim);


    int menorValor = 0;

    int menorValorIndex = -1;

    int somaTotal = 0;

    printf("\n\nVETOR RECEBIDO: ");


    for(int i = 0; i <= fim; i++)
    {
        printf("%d, ", vetor[i]);

        somaTotal += vetor[i];

        if(vetor[i] < menorValor)
        {
            menorValor = vetor[i];

            menorValorIndex = i;
        }
    }

    printf("\n\nMENOR VALOR INDEX: %d", menorValorIndex);
    printf("\n\nSOMA TOTAL: %d", somaTotal);

    if(menorValor >= 0)
    {
        return vetor;
    }

    //int* subVetorEsquerdo = (int*)calloc(menorValorIndex, sizeof(int));
    //int* subVetorDireito = (int*)calloc(fim - menorValorIndex, sizeof(int));

    //int* subVetorEsquerdo = (int*)calloc(menorValorIndex, sizeof(int));
    //int* subVetorDireito = (int*)calloc(fim - menorValorIndex, sizeof(int));


    int* subVetorEsquerdo = (int*)calloc(tamanhoVet, sizeof(int));
    int* subVetorDireito = (int*)calloc(tamanhoVet, sizeof(int));




    int totalSubVetorEsquerdo = 0;



    int totalSubVetorDireito = 0;





    int contadorEsquerdo = 0;

    printf("\nSub vetor esquerdo: ");
    for(int i = 0; i < menorValorIndex; i++){
        subVetorEsquerdo[contadorEsquerdo++] = vetor[i];

        printf("%d, ", vetor[i]);
    }

    printf("\n\nTamanho vetor esquerdo: %d", contadorEsquerdo);
    int* subVetorEsquerdoNovo = calcularMelhorSubvetor(subVetorEsquerdo, tamanhoVet);



   int contadorDireito = 0;
    printf("\nSub vetor direito: ");

    for(int i = menorValorIndex + 1; i <= fim; i++){
        subVetorDireito[contadorDireito++] = vetor[i];

        printf("%d, ", vetor[i]);

    }


    printf("\n\nTamanho vetor direito: %d", contadorDireito);
    int* subVetorDireitoNovo = calcularMelhorSubvetor(subVetorDireito, tamanhoVet);


    //int tamanhoSubVetorEsquerdo = sizeof(subVetorEsquerdo) / sizeof(int);
    //int tamanhoSubVetorDireito = sizeof(subVetorDireito) / sizeof(int);

    int tamanhoSubVetorEsquerdo = tamanhoVet;
    int tamanhoSubVetorDireito = tamanhoVet;


    printf("\n\nSubvetor esquerdo final: ");
    for(int i = 0; i < tamanhoSubVetorEsquerdo; i++){
        if(subVetorEsquerdo[i]){
            totalSubVetorEsquerdo += subVetorEsquerdoNovo[i];

        }

        printf("%d, ", subVetorEsquerdoNovo[i]);

    }


    printf("\n\nSubvetor direito final: ");

    for(int i = 0; i < tamanhoSubVetorDireito; i++){
        if(subVetorDireito[i]){
            totalSubVetorDireito += subVetorDireitoNovo[i];





        }


        printf("%d, ", subVetorDireitoNovo[i]);

    }





    if(totalSubVetorEsquerdo <= somaTotal && totalSubVetorDireito <= somaTotal){
        printf("\n\nRetorno array: ");


        int* subVetorConcatenado = (int*)calloc(tamanhoVet, sizeof(int));


        int contAux = 0;

        for(int i = 0; i < menorValorIndex; i++){

            if(subVetorEsquerdoNovo[i]){
                subVetorConcatenado[contAux] = subVetorEsquerdoNovo[i];

                contAux++;
            }


        }

        subVetorConcatenado[contAux++] = menorValor;


        for(int i = 0; i < contadorDireito; i++){

            if(subVetorDireitoNovo[i]){
                subVetorConcatenado[contAux] = subVetorDireitoNovo[i];

                contAux++;
            }


        }

        printf("\n\n");

        int totalsubVetorConcatenado = 0;

        for(int i = 0; i < tamanhoVet; i++){
            totalsubVetorConcatenado += subVetorConcatenado[i];
        }


        //return vetor;

        return totalsubVetorConcatenado > somaTotal ? subVetorConcatenado : vetor;
    }

    printf("\n\ntotal vetor: %d", somaTotal);
    printf("\n\ntotal sub vetor direito: %d", totalSubVetorDireito);
    printf("\n\ntotal sub vetor esquerdo: %d", totalSubVetorEsquerdo);



        if(totalSubVetorEsquerdo > totalSubVetorDireito || totalSubVetorEsquerdo == totalSubVetorDireito){


            return subVetorEsquerdoNovo;
        }
        else{



            return subVetorDireitoNovo;
        }




}
