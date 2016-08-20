#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include "gamelib.h"
using namespace std;

int main() {
	int somma=0;
	int square[4][4];
	string command;
	cout << "╔═════════════════════════════════════════════════════════╗\n";
	cout << "║                            2048!                        ║\n";
	cout << "╠═════════════════════════════════════════════════════════╣\n";
	cout << "║  -- Usa i comandi WASD per muovere le caselle        -- ║\n";
	cout << "║  -- Unisci le caselle uguali per raggiungere il 2048 -- ║\n";
	cout << "╚═════════════════════════════════════════════════════════╝\n";
	azzera_tabella(4, square);
	while(end(4, square)==0) {
	inserisci_casella(4, square);
	stampa_tabella(4, square, somma);
	cout << "> ";
	cin.get(command);
	if(command=="w"){
	up(4, square);}
	else if(command=="a") {
	left(4, square);}
	else if(command=="s") {
	down(3, square);}
	else if(command=="d") {
	right(3, square);}
	sleep(0.5);
	}
	if (end(4, square)==1) {
		stampa_tabella(4, square, somma);
		cout << "\nHai vinto!";
		return 0;
	}
	else if(end(4, square)==-1) {
		stampa_tabella(4, square, somma);
		cout << "\nHai perso!";
		return 0;
	}

}