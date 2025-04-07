#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <new> //Substitui o malloc
#include <string>

using namespace std;

//Crio uma estrutura que tenha valor numero e um ponteiro para a proxima estrutura
struct estrutura{
    int valorNumerico;
    struct estrutura *proximo; //Ponteiro para a proxima estrutura(struct estrutura é um tipo, assim como int)


};

int main(){

    //Cria o inicio da lista
    estrutura *ponteiroEncadeada;

    //Cria um novo valor
    estrutura *novoPrimeiroValor = new estrutura; //(Criei um novo bloco)Em C eu teria que fazer malloc
    novoPrimeiroValor->valorNumerico = 13; //Utilizo a seta pra navegar na estrutura
    novoPrimeiroValor->proximo = NULL; 

    printf("%d",novoPrimeiroValor->valorNumerico);

    //Faz o ponteiro da encadeada apontar para o primeiro valor, ou seja ele vai receber a posição na memoria pra ele saber onde a lista começa
    ponteiroEncadeada = novoPrimeiroValor;

    //Cria um segundo valor
    estrutura *novoSegundoValor = new estrutura; //(Criei um novo bloco)Em C eu teria que fazer malloc
    novoSegundoValor->valorNumerico = 20; //Utilizo a seta pra navegar na estrutura
    novoSegundoValor->proximo = NULL;

    //Junta os valores com um encadeamento
    ponteiroEncadeada->proximo = novoSegundoValor; //Vai retorna a posicao na memoria do meu novoSegundoValor, vai ser armazenado no proximo do meu ponteiroEncadeada

//NULL representa o fim da minha lista
//Imprime a lista encadeada
    while(ponteiroEncadeada != NULL){
        //Imprime o valora tual
        printf("\nValor: %d", ponteiroEncadeada->valorNumerico);//Vai imprimir o primeiro membro da lista

        //Cursor recebe a posição de memória do próximo valor
        ponteiroEncadeada = ponteiroEncadeada->proximo; //ponteiroEncadeada vai receber o ponteiroEncadeada->proximo
    }


    return 0;
}

/*  
    Sempre que eu trabalhar com listas encadeada vou precisar de uma struct, que vai ter um valor numérico e uma estrutura
    Crio sempre um ponteiro pra trabalhar com a minha lista
    Pra criar um novo valor eu pego o nome da minha struct mais um ponteiro para esse novo valor recebendo new estrutura(Pra nao ter que usar malloc todas a svezes eu usso a biblioteca new)
    Depois de alocado na memória, coloco o valor 13 e o próximo como nulo, pois o primeiro valor tbm eh o ultimo
    Logo em seguida fiz o meu encadeamento(o ponteorio encadeada à proximo fosse o endereço de memória do novo segundo valor que foi alocado)

    E pra percorrer uso um while, enquanto ele conseguir encontrar um novo valor para o que está sendo apontado, ele vai percorrendo
*/