#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "csvParser.h"
#include "writerCSV.h"

using namespace std;

#define ASPAS 34
#define VIRGULA 44

// Muda um boolean de estado
bool mudaEstado(bool estado){
    if(estado) return false;
    else return true;
};

// Separa as linhas em célula
vector<string> split(vector<string>& linhas){
    bool controleDeAspas = false;
    vector<string> splits;
    int tamanho = linhas.size();

    for(int i = 0; i < tamanho; i++){
        string linhaLida = linhas[i];
        string celula;
        for(int j = 0; j < linhaLida.size(); j++){
            if(linhaLida[j] == ASPAS)
                controleDeAspas = mudaEstado(controleDeAspas);
            if((linhaLida[j] == VIRGULA && !controleDeAspas)){
                splits.push_back(celula);
                celula.clear();
            } 
            else
                if(linhaLida[j] != ASPAS)
                    celula.push_back(linhaLida[j]);
        }
        splits.push_back(celula);
    }
    return splits;
};

// Lê o arquivo, separa-o em linhas e adiciona-as num vetor
void separaEmLinhas(){
    ifstream file("MusicDataBase-G3.csv");
    string extrator;
    vector<string> linhas;

    while(getline(file, extrator, '\n')){
        linhas.push_back(extrator);
    }

    vector<string> aux = split(linhas);

    for(int i = 0; i < aux.size(); i++){
        cout << aux[i] << endl;
    }
    criarArquivoCSV(aux);
};
