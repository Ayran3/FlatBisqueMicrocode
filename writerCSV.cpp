#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "writerCSV.h"

using namespace std;

#define ASPAS 34
#define VIRGULA 44

// Se uma celula contém pelo menos uma virgula ela deve receber aspas no inicio e no final
// Assim como o padrão do arquivo csv prevê para essa situação
string verificaSeDeveTerAspas(string celula){
    for(int i = 0; i < celula.size(); i++){
        if(celula[i] == VIRGULA){
            string celulaAlterada;
            celulaAlterada += ASPAS;
            celulaAlterada += celula;
            celulaAlterada += ASPAS;
            return celulaAlterada;
        }
    }
    return celula;
};

// Tem finalidade de estruturar e retornar como saída um arquivo .csv
void criarArquivoCSV(vector<string>& split){
    ofstream out("tester.csv");
    string varredura;
    for(int i = 0; i < split.size(); i++){
        varredura = verificaSeDeveTerAspas(split[i]);
        out << varredura;
        if((i+1)%10 != 0) 
            out << ",";
        else 
            if(i != (split.size() - 1)) out << endl;
    }
};
