#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>

void menu();
void randomkey();
void manualkey();
void xor();
char messaggio[129];
char key[129];
char m_output[129];

int main (){
    int s;

      printf("Inserisci una stringa NON piu lunga di 128 caratteri:\n");  //richiesta stringa
      fgets(messaggio, 129, stdin);    // memorizzazo solamente i primi 128 caratteri
      while(getchar()!='\n');   // pulisco il buffer
      printf("Messaggio iniziale: %s\n", messaggio);  //ristampo il messaggio iniziale
    do{

          menu();  // invoco il metodo menu dove si potra scegleire
          printf("\033[0;31m1- Menu\n!1- Esci\n"); //output con colore...
          scanf("%d", &s);
    }while(s==1);  // ripete la richiesta per le chiavi

return 0;
}

void menu(){
  printf("\033[0;31m"); // colore rosso per output
    int s;
    printf("**********************************************\n");
    printf("* 1- Inserire chiave per cifrare manualmente *\n");    // chiedo in che modo vuole riempire le variabili
    printf("* 2- Chiave randomica                        *\n");
    printf("**********************************************\n");
    scanf("%d", &s);
    switch(s){
      case 1:
        memset(key, 0, sizeof(key)); // svuoto la key
        manualkey();  // invoco il metodo manuale
        xor(); // parte il metodo xor che lavora sulle variabili ormai riempite
        break;
      case 2:
        memset(key, 0, sizeof(key)); // svuoto la key
        randomkey();  // (altrimenti) invoco il metodo randomico
        xor(); // parte il metodo xor che lavora sulle variabili ormai riempite
        break;
    }
}

void manualkey(){

  do{
      while(getchar()!='\n');   // pulisco il buffer
      printf("\033[0;34mInserisci una chiave di Max 128 caratteri e NON piu corta del Messaggio:\n");
      fgets(key, 129, stdin);
  }while(strlen(key)<strlen(messaggio));  // ripeto l'input fino a che la key sara maggiore o uguale al messaggio
  printf("Chiave manuale: %s\n", key);
  while(getchar()!='\n');   // pulisco il buffer
}

void randomkey(){
  while(getchar()!='\n');   // pulisco il buffer
  int l= strlen(messaggio);
  time_t t;
  srand((unsigned) time(&t));
  for(int i =0; i< l; i++){        // faccio un ciclo lungo quanto il messaggio
    key[i]= rand()%128 ;   // assegno un valore casuale per ogni cella...
  }
  printf("\033[1;32mChiave randomica: %s\n", key);

}

void xor(){

int l = strlen(messaggio);
printf("Messaggio cifrato: ");
for (int i=0; i<l; i++){              // ciclo lungo quanto il Messaggio
  m_output[i]=key[i]^messaggio[i];   // faccio la combinazione messaggio key
  printf("%X", m_output[i]);
}printf("\n");

  char m;
  for (int i=0; i<l; i++){       // ciclo lungo quanto il Messaggio
    m=m_output[i]^key[i];        // metto su una variabile d'appoggio la combinazione cifrato e chiave
    m_output[i]=m;              // metto il risultato sulla sua cella...
  }
  printf("Messaggio decifrato: %s\n", m_output);
}

//@author andim
