#include "ListaDup.h"
#include "geradorDatabase.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ano(cNo* nozim) {
  string aux = "";
  for (int i = 6; i <= 9;i++) {
    aux+=nozim->getDataDeAdicao()[i];
  }
  return aux;
}

string mes(cNo* nozim) {
  string aux = "";
  for (int i = 3; i <= 4;i++) {
    aux+=nozim->getDataDeAdicao()[i];
  }
  return aux;
}

string dia(cNo* nozim) {
  string aux = "";
  for (int i = 0; i <= 1;i++) {
    aux+=nozim->getDataDeAdicao()[i];
  }
  return aux;
}

void counting(cListaDupEnc* Lista, int tamanhoEntrada, int palavraInicio, int palavraFim) {
  cNo* baldes[10]; //1
  for (int digito = palavraFim - 1; digito >= palavraInicio - 1; digito--) {
    cNo* aux1 = Lista->getInicio();
    Lista->setInicio(NULL); 
    Lista->setFim(NULL);
    Lista->setTamanho(0);


    
    //Zerando os baldes.
    for (int i = 0;i < 10;i++) {
      baldes[i] = NULL;
    }
    //Preenchendo os baldes.
    for (int i = 0; i < tamanhoEntrada;i++) {
      if(baldes[aux1->getDataDeAdicao()[digito] - '0'] == NULL) {
        baldes[aux1->getDataDeAdicao()[digito] - '0'] = aux1;
        cNo* aux2 = aux1->getProx();
        aux1->setAnte(NULL);
        aux1->setProx(NULL);
        aux1 = aux2;
      }
      else if(baldes[aux1->getDataDeAdicao()[digito] - '0'] != NULL) {
        cNo* aux3 = baldes[aux1->getDataDeAdicao()[digito] - '0'];
        cNo* aux2 = aux1->getProx();
        aux1->setProx(NULL);
        aux1->setAnte(NULL);
        while(aux3->getProx() != NULL) {
          aux3 = aux3->getProx();
        }
        aux3->setProx(aux1);
        aux1 = aux2;
      }
    }

    //Tira dos Baldes e Recria a Lista.
    for(int i = 0; i < 10;i++) {
      cNo* aux4;
      cNo* aux5;
      if(baldes[i] != NULL) {
        aux4 = baldes[i];
        aux5 = aux4->getProx();
        Lista->InsereElemFim(aux4);
        while(aux5 != NULL) {
          aux4 = aux5;
          aux5 = aux5->getProx();
          Lista->InsereElemFim(aux4);
        }
      }
    }
  }
}



void split(cListaDupEnc* Lista, int tamanhoEntrada) {
  cNo* aux = Lista->getInicio();
  vector <cNo*> vetor;
  vetor.push_back(aux);
  aux = aux->getProx();

  while(aux != NULL) {
    if(ano(vetor[vetor.size() - 1]) != ano(aux)) {
      vetor.push_back(aux);
    }
    aux = aux->getProx();
  }

  for (int i = 0; i < vetor.size();i++) {
    cout <<vetor[i]->getDataDeAdicao()<<endl;
  }

}




int main() {
  cListaDupEnc MinhaLista;
  for (int i = 0; i < 10;i++) {
    MinhaLista.InsereElemFim(gerarNomeArtista(i), gerarNomeAlbum(i), gerarGenero(), gerarAno(), gerarNomeMusica(i), gerarDuracao(), gerarClassificacao(), gerarReproducoes(), gerarDataAdicao(), gerarUltimaReproducao());
  }
  counting(&MinhaLista, 10, 7,10);
  cNo* aux = MinhaLista.getInicio();
  while(aux != NULL) {
    cout << aux->getDataDeAdicao() <<endl;
    aux = aux->getProx();
  }
  cout <<"=============================="<<endl;
  split(&MinhaLista, 10);
}