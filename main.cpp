#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;
#define V -1
#define F -2
#define QTD_ESTADOS 14
#define B 0
#define QTD_SIMBOLOS 10

#define FLAG "flag"

int main() {
    cout << fixed;
    cout << setprecision(3);
    char alfabeto[QTD_SIMBOLOS] = {'\0', 'i', 'e', 'y', 'n', 't', 'g', 'r', 'x', 'p'};


    ///                            TABELA DE TRANSICAO
    ///                                                B  i  e  y  n  t   g  r  x  p
    int tabelaTransicao[QTD_ESTADOS][QTD_SIMBOLOS] = {{F, 1, F, F, F, 10, F, F, 9, F},
                                                       {V, F, F, F, 3, F, F, F, 2, F},
                                                       {V, F, F, F, F, F, F, F, F, F},
                                                       {F, F, F, F, F, 4, F, F, F, F},
                                                       {V, F, 5, F, F, F, F, F, F, F},
                                                       {F, F, F, F, F, F, 6, F, F, F},
                                                       {F, F, 7, F, F, F, F, F, F, F},
                                                       {F, F, F, F, F, F, F, 8, F, F},
                                                       {V, F, F, F, F, F, F, F, F, F},
                                                       {V, 2, F, F, F, F, F, F, F, F},
                                                       {F, F, F, 11, F, F, F, F, F, F},
                                                       {F, F, F, F, F, F, F, F, F, 12},
                                                       {F, F, 13, F, F, F, F, F, F, F},
                                                       {V, F, F, F, F, F, F, F, F, F}};
    string entrada;
    getline(cin, entrada);
    fflush(stdin);
    clock_t tStart = clock();
    vector<int> saidas;
    bool simboloExiste[entrada.size()];
    int simbolosEmInt[entrada.size() + 1];

/// ---------------VERIFICA SE OS SIMBOLOS EXISTEM NO E OS TRANSFORMA CADA UM EM INT------------------------------------
    int last = 0;
    for (int i = 0; i < entrada.size(); ++i) {
        simboloExiste[i] = false;
        for (int j = 0; j < QTD_SIMBOLOS ; ++j) {
            if(entrada[i] == alfabeto[j]){
                simboloExiste[i] = true;
//                cout << entrada[i] << FLAG << endl;
                simbolosEmInt[i] = j;
                last = i;
                break;
            }
        }
        for (int l = 0; l < entrada.size(); ++l) {
            if(!simboloExiste[i]){
                cout << "Simbolo nao existente no alfabeto." << endl;
                return 0;
            }
        }

    }
    /// --------------------------------------------------------------------------------------------

    simbolosEmInt[++last] = 0;
//    for(int x : simbolosEmInt)
//        cout << x << endl;

/// FAZ UMA BUSCA NA MATRIZ PELOS INTEIROS CORRESPONTENTES A CADA POSIÇÃO DOS SIMBOLOS LIDOS.
    int pi = 0;
    for (int s = 0; s < entrada.size() + 1 ; ++s) {
        int atual = simbolosEmInt[s];
//        cout << "Simb atual " << simbolosEmInt[s] << endl;
        for (int i = pi; i < QTD_ESTADOS ; ++i){
            if(tabelaTransicao[i][atual] != F){

                pi = tabelaTransicao[i][atual];
//                cout << "Proximo linha: " << pi << endl;
                saidas.push_back(pi);
                break;
            }
            if(tabelaTransicao[i][atual] == F){
                cout << "ERRO, NAO HA TRANSICAO PARA O SIMBOLO LIDO" << endl;
                return 0;
            }

        }

    }
    /// --------------------------------------------------------------------------------------------

/// SE A SAÍDA FOR VALIDA ELE MOSTRA A MENSAGEM ABAIXO COM OS VALORES ASSOCIOADOS, CASO CONTRARIO ELE CANCELA A EXECUÇÃO DO PROGRAMA.
//    cout << "ENTRADA ACEITA: " << saidas[0];
//    for (int j = 1; j < entrada.size(); ++j) {
//        cout << ", ";
//        cout << saidas[j];
//
//    }
//    cout << endl;
//    cout << "Tempo total para resolver a entrada: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;

    cout << "ENTRADA ACEITA: " << saidas[entrada.size() - 1];
    return 0;

}
