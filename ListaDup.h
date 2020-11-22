#include <iostream>
#include <string>
#include "No.h"

class cListaDupEnc {
	private:
		int numElem;
		cNo* inicio;
		cNo* fim;
		
	public:
		cListaDupEnc();
		cListaDupEnc(const cListaDupEnc &l);
		~cListaDupEnc();
    
		bool 	InsereElemInicio(std::string nomeArtista, std::string nomeAlbum, std::string generoAlbum, std::string anoAlbum, std::string nomeMusica, std::string duracaoMusica, std::string classificacaoMusica, std::string reproducoesMusica, std::string dataDeAdicao, std::string ultimaReproducao);		
		bool 	InsereElemFim(std::string nomeArtista, std::string nomeAlbum, std::string generoAlbum, std::string anoAlbum, std::string nomeMusica, std::string duracaoMusica, std::string classificacaoMusica, std::string reproducoesMusica, std::string dataDeAdicao, std::string ultimaReproducao);
		bool 	BuscaElem(std::string nomeMusica, cNo** no, cNo** noProx, cNo** noAnte); //busca pelo nome da música
		bool 	RemoveElem(std::string nomeMusica); //remove pelo nome da música
		bool 	RemoveElemInicio();
		bool 	RemoveElemFim();
		void 	ImprimirLista();
		int 	getTamanho();
		cNo* 	getInicio();
		cNo* 	getFim();

    //Metodos Ayran.
    void setInicio(cNo* novo);
    void setFim(cNo* novo);
    void setTamanho(int novo);
    bool InsereElemFim(cNo* novo);
};

