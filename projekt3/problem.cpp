#include "problem.hpp"
#include <string.h>
#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;


void Problem::einlesen()
{
  // Eingabe, ggf. Abbruch mit return
  cout  <<  "\nWelche Datei soll eingelesen werden?  \n";
  cout  <<  "\nbitte geb den Dateinamen an 1 (dj38.txt) oder 2 (in6.txt)";
  cin >> d;

  if (d <1|| d >2) // Check Eingabe, wenn ungueltig: Fehler ausgeben
  {
    cout << "\nParameter ungueltig\n!";
  //_getch();
  exit(1);}

  char files[2][9]={"dj38.txt", "in6.txt"};   // Array bilden für die Dateinamen

  cout << "\noeffne Datei " << files[d-1] << "\n"; // Datei 1-3, Index 0-2

  ifstream datei_input;               // Inputstream definieren
  datei_input.open(files[d-1]);
  if (datei_input.bad())                          // Wenn Inputstream fehlerhaft, Fehlermeldung ausgeben
  {
    cout << "\nDatei konnten nicht gelesen werden \n!";
  }


string dummy; 							// ersten 11 Zeilen der Inputdatei überspringen
   for(int i=0; i < 11;++i)
   {
     getline(datei_input, dummy);
   }
   datei_input >> anzahl;
   cout << "\n Knotenanzahl:" << anzahl << "\n";

   // Knotenlisten initialisieren mit Knotendaten
   for(int i=0; i<anzahl; i++)
   {
     datei_input >> knotenliste[i].index;
     datei_input >> knotenliste[i].x_coord;
     datei_input >> knotenliste[i].y_coord;
   }

// Ausgabe zum Debuggen
  for(int i=0; i<anzahl; i++)
  {
    cout <<"\n" <<knotenliste[i].index << "\t" << knotenliste[i].x_coord << "\t" << knotenliste[i].y_coord;
  } cout <<"\n";
}


void Problem::calc_distances()
{
// Berechnen der Matrix
//Phytagoras
  for(int i = 0; i < anzahl;i++)
  {
    for(int j = 0; j < anzahl;j++)
    // Knoten ID initialisieren in der Struktur distance_matrix.index
    {
      if(i==j) // Diagonale befüllen
      {
        distance_matrix[i][j].weg = 0;                      // Distanz befüllen
        distance_matrix[i][j].index = knotenliste[j].index; // Index befüllen
      }
      else
      {
      double distance_x = (knotenliste[i].x_coord-knotenliste[j].x_coord);
      double distance_y = (knotenliste[i].y_coord-knotenliste[j].y_coord);
      distance_matrix[i][j].weg =  sqrt((distance_x*distance_x)+(distance_y*distance_y));
      distance_matrix[i][j].index = knotenliste[j].index;
    } // distance_matrix
    }
  }

// Ausgabe der Berechneten Entfernungen & zugehörigen Indexes
cout << "\n Entfernungsmatrix:" << "\n ";
  for(int i = 0; i < anzahl; i++)
    {
    for(int j = 0; j < anzahl; j++)
      {
        cout << distance_matrix[i][j].weg << "|" <<  distance_matrix[i][j].index << " ";
      }
    cout << "\n";
  }
}

int Problem::getanzahl()
{
  return anzahl;
}

/*
double ** Problem::getdistance_matrix()
{
  return distance_matrix;
}
*/
