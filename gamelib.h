#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
using namespace std;
int score=0;
int azzera_tabella (int dim, int square [4] [4] ) {
	int i; //variabii di ciclo
	int j; //variabili di ciclo

	for (j = 0; j < dim; j++)
		{
		for (i = 0; i < dim; i++)
			{
			square [j][i] = 0;
			}
		}
	}
int stampa_tabella(int dim,int square[4][4],int somma) {
	system("clear");
	int i;
	int j;
	cout << "╔════╦════╦════╦════╗       Score: " << score << "\n";
	for (j = 0; j < dim; j++)
		{
		for (i = 0; i < dim; i++)
			{
			cout << "║";
			if (square [j][i] >0){
			if (square[j][i]<10)
			 cout << "  " << square[j][i] << " ";
		    else if( square[j][i] <100 && square[j][i]>9)
				cout <<" " << square[j][i] << " ";
			else if(square[j][i]<1000 && square[j][i]>99)
				cout << " " << square[j][i];
			else if(square[j][i]<10000 && square[j][i]>999)
				cout << square[j][i];
		 }
			else if (square[j][i]==0){
			cout << "    ";}
			}
		cout << "║\n";
		
		if ( j != dim - 1)
			{	
			cout << "╠════╬════╬════╬════╣\n";
			}

		else 
			{
			cout << "╚════╩════╩════╩════╝\n";
			
		}
}
}
int cercavuota (int dim, int square [4] [4], int usr){
	int i;
	int j;
	int k=0;
	int ro;	
	int co;	//coloumn
	srand (time(NULL)); 
    while (k<10000) //dovrebbe trovarne almeno la [j][i]
					{
					// cerco righe e colonne casuali un bel po' di volte
					//se proprio non ne trovo, ne prendo una sicutamente vuota ([j][i])
					ro = rand () % dim;
					co = rand () % dim;
					if (square [ro][co] == 0)
						{
						//a questo punto la prenoto
						square [ro][co] = 2;
						return 2; //e basta
						}
                      k++;
					}
	for(j=0;j<dim;j++) {
		for(i=0;i<dim;i++) {
			if(square[j][i]==0)
				square[j][i]=2;
			return 2;
		}
	}
return 0; //nessuna cella libera, in pratica il gioco è finito
}
			
int end(int dim, int square[4][4]) {
    int i; 
	int j; 
    int x=0;
	for (j = 0; j < dim; j++)
		{
		for (i = 0; i < dim; i++)
			{
			if(square[j][i]==2048) {
				return 1;
			}
			if(square[j][i]==0)
				x=1;
			}
		}
	if (x==0) {
		return -1;
	}
	return 0;
}
int inserisci_casella(int dim, int square[4][4]) {
	int pcresult=cercavuota(dim, square, 2);
	return pcresult;
}
int up(int dim, int square[4][4]) {
	int i,j;
		for (j=0;j<dim;j++) {
	     for (i=0;i<dim;i++) {
			 int g=j;
			 while(g>=1 && g<=3 && square[g][i]>0 && square[g-1][i]==0) { //si muove in su finchè quello sopra=0
				 square[g-1][i]=square[g][i];
				 square[g][i]=0;
				 if(g>0){
				 g=g-1;}
			 }
			 //due casi: si può sommare o no
			 if(square[g-1][i]==square[g][i] && square[g][i]>0) {//si 
				 square[g-1][i]=square[g-1][i]+square[g][i];
				 score=score+square[g-1][i]+square[g][i];
			     square[g][i]=0;
			 }//se no rimane fermo
		 }
		}
}
int left(int dim, int square[4][4]) {
	int i,j;
	for (j=0;j<dim;j++) {
		for(i=0;i<dim;i++) {
			int y=i;
			while(y>=1 &&y<=3&& square[j][y]>0 && square[j][y-1]==0) {
				square[j][y-1]=square[j][y];
				square[j][y]=0;
				if (y>0){
				y=y-1;}
			}
			if(square[j][y-1]==square[j][y] && square[j][y]>0) {
				square[j][y-1]=square[j][y]*2;
				score=score+square[j][y]*2;
				square[j][y]=0;
			}
		}
	}
}
int down(int dim, int square[4][4]) {
	int i,j;
		for (j=dim;j>=0;j--) {
	     for (i=dim;i>=0;i--) {
			 int g=j;
			 while(g<3 && g>=0 && square[g][i]>0 && square[g+1][i]==0) { 
			     if(g<3){
				 square[g+1][i]=square[g][i];
				 square[g][i]=0;
				 g++;}
			 }
			 if(square[g+1][i]==square[g][i] && square[g][i]>0) {
				 square[g+1][i]=square[g+1][i]+square[g][i];
				 score=score+square[g+1][i]+square[g][i];
			     square[g][i]=0;
			 }
		 }
		}
}
int right(int dim, int square[4][4]) {
	int i,j;
	for (j=dim;j>=0;j--) {
		for(i=dim;i>=0;i--) {
			int y=i;
			while(y<3 && y>=0 && square[j][y]>0 && square[j][y+1]==0) {
				if(y<3){
				square[j][y+1]=square[j][y];
				square[j][y]=0;
				y++;}
			}
			if(square[j][y+1]==square[j][y] && square[j][y]>0) {
				square[j][y+1]=square[j][y]+square[j][y+1];
				score=score+square[j][y]+square[j][y+1];
				square[j][y]=0;
			}
		}
	}
}