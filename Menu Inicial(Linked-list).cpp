#include <stdio.h>
#include <iostream> //Libera o uso de cout e cin ao invés de printf("%d"...)
#include <stdlib.h>
#include <new> //Substitui o malloc
#include <string> //Strings sendo vetores de caracteres e alocando memorias para eles toda hora

using namespace std;

void limpaTela(){
    system("CLS");
}

//Crio uma estrutura que tenha valor numero e um ponteiro para a proxima estrutura
struct Pessoa{
    string nome;//Sem o C++ teria que criar um vetor de caracter
    int rg;
    struct Pessoa *proximo; //Ponteiro para a proxima estrutura(struct estrutura é um tipo, assim como int)
};

int retornaTamanho(Pessoa *ponteiroEncadeado){

    //Antes de sair percorrendo a lista, verifico se o ponteiroEncadeada(primeiro membro) esta vazio
    //Se a lista estiver vazia, retorna 0
    if(ponteiroEncadeado->nome == ""){
        return 0;
    }

    //Tamanho da lista
    int tamanho = 0;

    //ponteiro(cursos) auxiliar
    Pessoa *p = ponteiroEncadeado; //Joguei o cursor la no primeiro membro da lista


    while(p != NULL){

        p = p->proximo;//Faz com que o cursos atual seja igual ao proximo na memoria(o cursor vai para o proximo mebro) e toda vez q eu fizer isso quero aumentar meu tamanho

        //Contador de tamanho aumenta
        tamanho++;

    }

    return tamanho;
}


void imprimeEncadeada(Pessoa *ponteiroEncadeada){
    //Ponteiro auxiliar
    Pessoa *p = ponteiroEncadeada;

    while(p != NULL){

        //Imprime a lista
        cout << p->nome << "," << p->rg << "\n";

        //Atualiza o cursos
        p = p->proximo;
    }
}

//Quando eu quero alterar um ponteiro no meu escopo global, preciso utilizar: *&
void adcComecoEncadeada(Pessoa *&ponteiroEncadeada, string nome, int rg){
    //Cria uma nova estrutura
    Pessoa *novoValor = new Pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = ponteiroEncadeada;

    //Verifica se a lista está vazia
    if(ponteiroEncadeada->nome == ""){
        novoValor->proximo = NULL;
    }else{
        novoValor->proximo = ponteiroEncadeada;
    }

    //Redireciona o ponteiro
    ponteiroEncadeada = novoValor;
}

void adcFimEncadeada(Pessoa *&ponteiroEncadeada, string nome, int rg){

    //Cria uma nova estrutura
    Pessoa *novoValor = new Pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    //Ponteiro auxiliar
    Pessoa *p = ponteiroEncadeada;

    //Quando chega no ultimo elemento, faz ele apontar para o novo valor
    while(p == NULL){
        //Quando chega no último elemento, faz ele apontar para o novo valor
        if(p->proximo == NULL){

            p->proximo = novoValor;
            return; //Para sair do laço de repetição e nao fazer a atualização da posição do cursor 

        }

        //Atualiza o cursor
        p = p->proximo; 
    }
}
void adcPosicaoEncadeada(Pessoa *&ponteiroEncadeada, string nome, int rg, int posicao){
    //Cria uma nova estrutura
    Pessoa *novoValor = new Pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    //Ponteiro auxiliar
    Pessoa *p = ponteiroEncadeada;

    //Contador de posições
    int cont = 0;
    //tem que ser ate uma posição antes da desejada
    while(cont <= posicao){
        if(cont == posicao - 1){
            //Auxiliar do valor(vai ter que gravar quem vai vir como proximo do novo elemento)
            Pessoa *aux = new Pessoa;
            //Armazena o proximo valor
            aux->proximo = p->proximo;
            //Coloca o novo valor como proximo dele
            p->proximo = novoValor;
             //Faz com que o novo valor aponte para o proximo
            novoValor->proximo = aux->proximo;

            free(aux);
        }




        p = p->proximo;
        cont++;

    }
}

void removeInicioEncadeada(Pessoa *&ponteiroEncadeada){
     
    if(ponteiroEncadeada->proximo == NULL){
        //Cria uma nova estrutura
        Pessoa *novoValor = new Pessoa;
        novoValor->nome = "";
        novoValor->rg = 0;
        novoValor->proximo = NULL;

        ponteiroEncadeada = novoValor;

    }else{
        //Faz o ponteiro principal apontar para o próximo valor
        ponteiroEncadeada = ponteiroEncadeada->proximo;
    }
}

void removeFimEncadeada(Pessoa *&ponteiroEncadeada){
    //Auxiliares
    Pessoa *p = new Pessoa;
    Pessoa*aux = new Pessoa;

    //Ponteiro auxiliar
    p = ponteiroEncadeada;

    while(p->proximo != NULL){
        //O aux sempre vai ficar um index atras do p
        aux = p; 
        //Passa o cursor para o proximo elemento
        p = p->proximo;
    }
    //Muda o final da lista para o penultimo elemento
    aux->proximo = NULL;
}

void removePosicaoEncadeada(Pessoa *&ponteiroEncadeada, int posicao){

    //Ponteiro auxiliar
    Pessoa *p = ponteiroEncadeada;
    //Contador de posições
    int cont = 0;
    while(cont <= posicao){
        if(cont == posicao - 1){
            //Cria um auxiliar
            Pessoa *aux = new Pessoa;
            //Auxiliar recebe elemento que sera eliminado
            aux = p->proximo;

            //Faz com que o proximo pule um elemento
            p->proximo = aux->proximo;

            free(aux);
        }
        //Passa o cursos para o proximo elemento
        p = p->proximo;

        //Regitra uma movimentação
        cont++;
    }
}

string retornaNomeEncadeada(Pessoa *&ponteiroEncadeada, int rg){
    //Nome a ser retornada
    string nome = "Não encontrado";

    //Ponteiro auxiliar
    Pessoa *p = ponteiroEncadeada;

    while(p != NULL){
        //Quando encontra o rg
        if(p->rg == rg){
            nome = p->nome;
            return nome;
        }


        //Passa o cursos para o próximo elemento
        p = p->proximo;
    }

    return nome;
}

int main(){
    //Variáveis
    int funcaoDesejada = 1;

    //Cria o inicio da lista encadeada
    Pessoa *ponteiroEncadeado = new Pessoa;
    ponteiroEncadeado->nome = "";
    ponteiroEncadeado->rg = 0;
    ponteiroEncadeado->proximo = NULL;


    while(funcaoDesejada < 9 && funcaoDesejada > 0){

        //mostrando Menu
        cout << "Operacoes \n";
        printf("1 - Insercao de um node no inicio da lista \n");
        printf("2 - Insercao de um node no fim da lista \n");
        printf("3 - Insercao de um node na posicao N \n");
        printf("4 - Retirar um node do inicio da lista \n");
        printf("5 - Retirar um node no fim da lista \n");
        printf("6 - Retirar um node na posicao N \n");
        printf("7 - Procurar um node com o campo RG \n");
        printf("8 - Imprimir a lista \n");
        printf("9 - Sair do sistema \n");
        printf("\nEscolha um numero e pressione ENTER: \n");

        cout << "\n\nTamanho atual:" << retornaTamanho(ponteiroEncadeado) << "\n";

        //Imprime lista encadeada
        if(retornaTamanho(ponteiroEncadeado) == 0){
            cout << "Lista vazia\n";
        }else{
            imprimeEncadeada(ponteiroEncadeado);
        }
    
        cin >> funcaoDesejada;

        limpaTela();

        //Variaveis temporarias
        string nome;
        int rg;
        int posicao;

        switch(funcaoDesejada){
            case 1:
                printf("Funcao escolhida: 1 - Insercao de um node no inicio da lista \n");
                //lendo valores do usuário
                cout << "Digite um nome:\n";
                cin  >> nome;
                cout << "Digite um rg:";
                cin  >> rg;

                adcComecoEncadeada(ponteiroEncadeado, nome, rg);
                break;
            case 2:
                printf("Funcao escolhida: 2 - Insercao de um node no fim da lista \n");
                //lendo valores do usuário
                cout << "Digite um nome:\n";
                cin  >> nome;
                cout << "Digite um rg:";
                cin  >> rg;

                //Dessa forma mesmo que nao haja nenhum item na lista, ele vai adicionar de qualquer forma
                if(retornaTamanho(ponteiroEncadeado) == 0){
                    adcComecoEncadeada(ponteiroEncadeado, nome, rg);
                }else{
                    adcFimEncadeada(ponteiroEncadeado, nome, rg);
                }

                break;
            case 3:
                printf("Funcao escolhida: 3 - Insercao de um node na posicao N \n");
                //Lendo valores do usuário
                cout << "Digite a posicao:\n";
                cin  >> posicao;
                cout << "Digite um nome:\n";
                cin  >> nome;
                cout << "Digite um rg:";
                cin  >> rg;

                if(posicao == 0){
                    adcComecoEncadeada(ponteiroEncadeado, nome, rg);
                }else if(posicao == retornaTamanho(ponteiroEncadeado) - 1){ //O index da lista eh sempre o tamanho - 1
                    adcFimEncadeada(ponteiroEncadeado, nome, rg);
                }else{
                    adcPosicaoEncadeada(ponteiroEncadeado, nome, rg, posicao);
                }

                break;
            case 4:
                printf("Funcao escolhida: 4 - Retirar um node do inicio da lista \n");
                
                removeInicioEncadeada(ponteiroEncadeado);

                break;
            case 5:
                printf("Funcao escolhida: 5 - Retirar um node no fim da lista \n");
                //Se houver apenas um valor na lista, remove no inicio
                if(retornaTamanho(ponteiroEncadeado) == 1){
                    removeInicioEncadeada(ponteiroEncadeado);
                }else{
                    removeFimEncadeada(ponteiroEncadeado);
                }
                
                break;
            case 6:
                printf("Funcao escolhida: 6 - Retirar um node na posicao N \n");
                cout << "Digite a posicao:\n";
                cin  >> posicao;

                if(posicao == 0){
                    removeInicioEncadeada(ponteiroEncadeado);
                }else if(posicao == retornaTamanho(ponteiroEncadeado) - 1){
                    removeFimEncadeada(ponteiroEncadeado);
                }else{
                    removePosicaoEncadeada(ponteiroEncadeado, posicao);
                }
                break;
            case 7:
                printf("Funcao escolhida: 7 - Procurar um node com o campo RG \n");
                //RG buscado pelo usuário
                cout << "Digite o RG:\n";
                cin  >> rg;

                cout << "\nO nome que possui o rg " << rg << " eh: " << retornaNomeEncadeada(ponteiroEncadeado, rg) << "\n";
                break;
            case 8:
                imprimeEncadeada(ponteiroEncadeado);
                break;
            
            default:
                break;
            }

    }

    return 0;
}

/*  
    
*/