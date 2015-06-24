// Dateien einf�gen
#include <iostream>
#include <string>
#ifndef __GNUC__
#include <conio.h>
#else
#define _getch()
#endif
#include <iomanip>
#include <math.h>
#include <fstream>
#include "problem.h"
using namespace std;

// main-Funktion


int main()
{
	Problem tsp;
	// tsp.test(Problem::a,Problem::b)
	cout <<"\n c1=" << Problem::c1 << "\n";

/*
	tsp.einlesen(Problem::Anzahl, Problem::d, **Matrix);
	tsp.calc_distances(Problem::Anzahl, **Matrix,  **Entfernungen);
	// tsp.ausgabe( 1, 2, 3 );
*/
/*





	int d;                      // Eingabe welche Datei eingelesen werden soll

  // Eingabe, ggf. Abbruch mit return
  cout  <<  "\nWelche Datei soll eingelesen werden?  \n";
  cout  <<  "\nbitte geb den Dateinamen an (1 oder 2)";
  cin >> d;

  if (d <1|| d >2) // Check Eingabe, wenn ungueltig: Fehler ausgeben
  {
	  cout << "\nParameter ungueltig\n!";
  _getch();
  exit(1);}

  char files[2][9]={"dj38.txt", "in6.txt"};   // Array bilden f�r die Dateinamen

  cout << "\noeffne Datei " << files[d-1] << "\n"; // Datei 1-3, Index 0-2

  ifstream datei_input;               // Inputstream definieren
  datei_input.open(files[d-1]);
  if (datei_input.bad())                          // Wenn Inputstream fehlerhaft, Fehlermeldung ausgeben
  {
	  cout << "\nDatei konnten nicht gelesen werden \n!";
  }

int Anzahl;										// Anzahl der Knoten
double Matrix[39][2]; 				// Matrix Kooridinaten der Standorte
double Entfernungen[39][39]; // Entferungsmatrix

char trash;

string dummy; 							// ersten 11 Zeilen der Inputdatei überspringen
	 for(int i=0; i < 11;++i)
	 {
		 getline(datei_input, dummy);
	 }
	 datei_input >> Anzahl;
	 cout << Anzahl << "\n";
	 for(int i=0; i<Anzahl; i++)
	 {
		 datei_input >> trash; 				// Todo: in Struktur i mit datenfeld Knotennummer legen/initialisieren
		 datei_input.ignore();

		 for(int j = 0; j<2; j++)
		 {
			 datei_input >> Matrix[i][j];
			// Übertragung der Standortdaten in Standortmatrix
		 }
	 }
// Ausgabe zum Debuggen
	for(int i=0; i<Anzahl; i++)
	 {

		 for(int j = 0; j<2; j++)
		 {

			 cout << Matrix[i][j] << " ";
		 }
		 cout << "\n";
	 }
*/


/*
	 //Phytagoras
	 for(int i = 0; i < Anzahl;i++)
	 {
		 for(int j = 0; j < Anzahl;j++)
		 {
			 if(i==j)
			 {
			 Entfernungen[i][j] = 99999999;
			 }
			 else
			 {
			 Entfernungen[i][j] =  sqrt(((Matrix[j][0] - Matrix[i][0])*(Matrix[j][0] - Matrix[i][0])) +((Matrix[j][1] - Matrix[i][1])*(Matrix[j][1] - Matrix[i][1])));
			 }
		 }
	 }

// Ausgabe der Berechneten Entfernungen
	 for(int i = 0; i < Anzahl; i++)
	 {
		 for(int j = 0; j < Anzahl; j++)
		 {
			 cout << Entfernungen[i][j] << " ";
		 }
		 cout << "\n";
	 }
	*/
	// _getch();
}
