#include "problem.hpp"
#include "heuristik.hpp"
#include <string.h>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
//using namespace std;

// Konstruktor für Heuristikklasse
Heuristik::Heuristik()
{
  for (int i=0; i<problem.getanzahl(); i++){
  statusliste[i].index = i+1;   // Status.k inistalisieren mit Nr des Knotens
  statusliste[i].angefahren = 0;
  statusliste[i].full_distance = 0;
  }
}

void Heuristik::set_problem(Problem problem){
  this->problem = problem;
}

void Heuristik::orig_matrix()
{
  for (int i = 0; i < problem.getanzahl(); i++)
  for (int j = 0; j<problem.getanzahl(); j++)
  oldmatrix[i][j] = problem.distance_matrix[i][j].weg;
  }

void Heuristik::sort_matrix()
{
  cout << "\n sortiere Entfernungsmatrix:" << "\n ";
  for (int i = 0; i < problem.getanzahl(); i++)
  {
    sort(problem.distance_matrix[i], problem.distance_matrix[i]+problem.getanzahl(), [](Distance1 const &a, Distance1 const &b) { return a.weg < b.weg; });
    for (int j = 0; j<problem.getanzahl(); j++)
    {
      cout << "\t" << problem.distance_matrix[i][j].weg << "|" <<  problem.distance_matrix[i][j].index << " ";
    }
    cout << "\n";
  // find nächsten nachbarn der noch nicht besichtigt wurde
  }
}
void Heuristik::find_nachbar()
{
int city_count = problem.getanzahl();
double weg_laenge = 0;
bool visited[MAX_KNOTEN];          // Array mit Status (angefahrenen oder nicht)
fill_n(visited, city_count, false);
int path[MAX_KNOTEN]; // Array mit Reihenfolge der angefahrenen Städte

// Starten bei Stadt 1
int city = 1;

// suche nach dem nächsten Nachbarn (der noch nicht besucht wurde)
bool finished = false;
int weg_index = 0;
path[weg_index]=city;
  while (!finished)
  {
    finished = true;
    for (int i = 1; i < city_count; i++) // überspringe sortierte erste Spalte, da dies die Hauptdiagonalen Elemente schreibende
      {
        if (!visited[problem.distance_matrix[city-1][i].index])
        {
            finished = false;
            weg_laenge += problem.distance_matrix[city-1][i].weg;
            visited[city] = true;
            city = problem.distance_matrix[city-1][i].index;
            weg_index++;              // gewählter Knotenanzahl hochzählen
            path[weg_index] = city;   
            break;
        }
      }
  }
  // Rückfahrt zu 1
  weg_laenge += oldmatrix[city-1][0];
  weg_index++;              // gewählter Knotenanzahl hochzählen

  // Ergebnis ausgeben
  // als Datei & im Terminal
  ofstream datei_output("output.txt");     // Outputstream definieren
  if (datei_output.bad())                  // Wenn Outputstream fehlerhaft, Fehlermeldung ausgeben
    {
      cout << "\nDatei konnten nicht geschrieben werden \n!";
    }

  cout << "\n Weglänge: " << weg_laenge << "\n" << endl;
  datei_output << "\n Weglänge: " << weg_laenge << "\n" << endl;

  cout << "\n Weg:\n ";
  datei_output << "\n Weg: \n ";
  int h=0;
  for (int i = 0; i < city_count; i++)
      {
      cout << path[i];
      datei_output << path[i];

      h = h+1;
      if(h==9)
      {
        cout << "\n";
        datei_output <<  "\n";
        h=0;
      }
      if (i != city_count -1)
      {
          cout << " -> ";
          datei_output << " -> ";
      } else
      {
          cout << " -> 1" << endl;
          datei_output << " -> 1 \n" << endl;
      }
    }
}
