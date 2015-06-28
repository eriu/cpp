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

void Heuristik::sort_matrix()
{
  cout << "\n sortiere Entfernungsmatrix:" << "\n ";
  for (int i = 0; i < problem.getanzahl(); i++)
  {
    std::sort(problem.distance_matrix[i], problem.distance_matrix[i]+problem.getanzahl(), [](Distance1 const &a, Distance1 const &b) { return a.weg < b.weg; });
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
/*
// alte variante
  double oldweg=0;
  int newline=0;

  for(int i=0; i<problem.getanzahl(); i++)  // Zeilenweise
  {
    int j=1;
    bool knoten_gefunden = false;
    while ( j< problem.getanzahl() && knoten_gefunden == false)  // Spaltenweise ab Spalte 2 (erste Spalte wäre i->i)
    {
      if (statusliste[j].angefahren == 0 )
          {// Addiere Weg des nächsten möglichen Knotens auf die bisherige Gesamtdistance
          statusliste[j].full_distance = oldweg + problem.distance_matrix[newline][j].weg;

          // Status ändern
          knoten_gefunden = true;
          statusliste[j].angefahren = 1;
          // Berechenn des neuen Weges und der Zielzeile
          oldweg = oldweg + problem.distance_matrix[newline][j].weg;
          newline=problem.distance_matrix[newline][j].index-1;

          cout << "\t"<< oldweg;
          cout << "\t newline: "<< newline << "\n";
          // Abbruch nach der ersten Addition
          }
      else
          {
            // Überspringe Komponente
          j++;
          }
    }
  }
*/
// neuer Versuch
int city_count = problem.getanzahl();
double weg_laenge = 0;
bool visited[MAX_KNOTEN];          // Array mit Status (angefahrenen oder nicht)
fill_n(visited, city_count, false);
int path[MAX_KNOTEN]; // Array mit Reihenfolge der angefahrenen Städte

// Zufällig eine Stadt aussuchen
// int city = rand() % 10;
// Starten bei Stadt 1
int city = 1;

// suche nach dem nächsten Nachbarn (der noch nicht besucht wurde)
bool finished = false;
int weg_index = 0;
  while (!finished)
  {
    finished = true;
    for (int i = 1; i < city_count; i++)
      {
        if (!visited[problem.distance_matrix[city][i].index])
        {
            finished = false;
            weg_laenge += problem.distance_matrix[city][i].weg;
            path[weg_index++] = city;
            visited[city] = true;
            city = problem.distance_matrix[city][i].index;
            break;
        }
      }
  }

  // Ergebnis ausgeben
  // als Datei & im Terminal
  ofstream datei_output("output.txt");     // Outputstream definieren
  if (datei_output.bad())                  // Wenn Outputstream fehlerhaft, Fehlermeldung ausgeben
    {
      cout << "\nDatei konnten nicht geschrieben werden \n!";
    }

  cout << "Weglänge: " << weg_laenge << "\n" << endl;
  datei_output << "Weglänge: " << weg_laenge << "\n" << endl;

  cout << "Weg: ";
  datei_output << "Weg: ";
  for (int i = 0; i < city_count; i++)
      {
      cout << path[i];
      datei_output << path[i];
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


void Heuristik::ergebnis()
{
  // cout << "\n" << "Der Gesamtweg beträgt: " << berechne_weg() << " Einheiten\n ";
  // ausgeben des Gesamtweges und der Reihenfolge in eine Datei
}
