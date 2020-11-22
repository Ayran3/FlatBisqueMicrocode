#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "writerCSV.h"
#include "geradorDatabase.h"

#define NUMEROS_DE_MUSICAS 140

using namespace std;

string gerarNomeArtista(int ind){
	string strind= to_string(ind);	
	string nome = strind+"Artista"+strind;
	return nome;
}

string gerarNomeAlbum(int ind){
	string strind = to_string(ind);
	string nome = strind+"Album"+strind;
	return nome;
}

string gerarGenero(){
	string genero = "";
	int val = rand() % 7;
	switch(val){
		case 0:
			genero = "Rock";
			break;
		case 1:
			genero = "MPB";
			break;
		case 2:
			genero = "Rap";
			break;
		case 3:
			genero = "Kpop";
			break;
		case 4:
			genero = "Jazz";
			break;
		case 5:
			genero = "Indie";
			break;
		case 6:
			genero = "";
			break;
	}
	return genero;
}

string gerarAno(){
	int a = rand() % 100 + 1920;
	string ano = to_string(a);
	return ano;
}

string gerarNomeMusica(int ind){
	string strind= to_string(ind);
	string nome = strind+"Musica"+strind;
	return nome;
}

string gerarDuracao(){
	int dura1 = rand() % 7;
	int dura2 = rand() % 6;
	int dura3 = rand() % 10;
	string strind1 = to_string(dura1);
	string strind2 = to_string(dura2);
	string strind3 = to_string(dura3);
	string duracao = strind1 + ":" + strind2 + strind3;
	return duracao;
}

string gerarClassificacao(){
	int c = rand() % 7;
	string classi;
	if(c == 6)
		classi = "";
	else{
		c *= 20;
		classi = to_string(c);
	}
	return classi;
}

string gerarReproducoes(){
	int r = rand() % 10 + 1;
	string repr = to_string(r);
	return repr;
}

string gerarDataAdicao(){
	int dura1 = rand() % 31 + 1;
	int dura2 = rand() % 12 + 1;
	int dura3 = rand() % 2 + 2017;
	int dura4 = rand() % 24;
	int dura5 = rand() % 6;
	int dura6 = rand() % 10;
	string strind1 = to_string(dura1);
  if(strind1.length() == 1) {
    strind1 = "0" + strind1;
  }
	string strind2 = to_string(dura2);
  if(strind2.length() == 1) {
    strind2 = "0" + strind2;
  }
	string strind3 = to_string(dura3);
	string strind4 = to_string(dura4);
	string strind5 = to_string(dura5);
	string strind6 = to_string(dura6);
	string data = strind1 + "/" + strind2 + "/" + strind3;
	return data;
}

string gerarUltimaReproducao(){
	string data;
	int c = rand() % 4;
	if(c == 3)
		data = "";
	else{
		int dura1 = rand() % 31 + 1;
		int dura2 = rand() % 12 + 1;
		int dura3 = rand() % 2 + 2018;
		int dura4 = rand() % 24;
		int dura5 = rand() % 6;
		int dura6 = rand() % 10;
		string strind1 = to_string(dura1);
		string strind2 = to_string(dura2);
		string strind3 = to_string(dura3);
		string strind4 = to_string(dura4);
		string strind5 = to_string(dura5);
		string strind6 = to_string(dura6);
		data = strind1 + "/" + strind2 + "/" + strind3 + " " + strind4 + ":" + strind5 + strind6;
	}
	return data;
}

void primeiraLinha(vector<string>& valores){
	string c1 = "Artista";
	valores.push_back(c1);
	string c2 = "Album";
	valores.push_back(c2);
	string c3 = "Genero";
	valores.push_back(c3);
	string c4 = "Ano";
	valores.push_back(c4);
	string c5 = "Nome";
	valores.push_back(c5);
	string c6 = "Duracao";
	valores.push_back(c6);
	string c7 = "Classificação";
	valores.push_back(c7);
	string c8 = "Reproducoes";
	valores.push_back(c8);
	string c9 = "DataAdicao";
	valores.push_back(c9);
	string c10 = "UltimaReproducao";
	valores.push_back(c10);
}

void geradorDatabase(vector<string>& valores){
	primeiraLinha(valores);
	srand(time(NULL));
	for(int i=0;i<NUMEROS_DE_MUSICAS;i++){
		for(int u=0;u<10;u++){
			int ind = u;
			string valor;
			switch(ind){
				case 0:
					valor = gerarNomeArtista(i+1);
					break;
				case 1:
					valor = gerarNomeAlbum(i+1);
					break;
				case 2:
					valor = gerarGenero();
					break;
				case 3:
					valor = gerarAno();
					break;
				case 4:
					valor = gerarNomeMusica(i+1);
					break;
				case 5:
					valor = gerarDuracao();
					break;
				case 6:
					valor = gerarClassificacao();
					break;
				case 7:
					valor = gerarReproducoes();
					break;
				case 8:
					valor = gerarDataAdicao();
					break;
				case 9:
					valor = gerarUltimaReproducao();
					break;
			}			
			valores.push_back(valor);
		}
	}
	criarArquivoCSV(valores);	
}
	
	
	
