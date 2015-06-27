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
  for (int i=0; i<problem.getanzahl(); i++)
  {
  statusliste[i].index = i+1;   // Status.k inistalisieren mit Nr des Knotens
  statusliste[i].angefahren = 0;
  statusliste[i].full_distance = 0;
  }
}


void Heuristik::set_problem(Problem problem)
{
  this->problem = problem;
}

void Heuristik::sort_matrix()
{
  cout << "\n sortiere Entfernungsmatrix:" << "\n ";
  for (int i = 0; i < problem.getanzahl(); i++) {
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
  bool finished=false;
  double ges_weg;
  double reihenfolge[1][problem.getanzahl()];
  double visited[1][problem.getanzahl()];

  while (finished == false)
  {
    finished = true;
    for(int i=1; i<problem.getanzahl(); i++)  // Zeilenweise
    {
      // weg möglich

      finished = false;



    }
  } */
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
  
}

double Heuristik::berechne_weg()
{
  double weg=0;
  for(int i=0; i<problem.getanzahl(); i++)
  {
    if (statusliste[i].full_distance > weg)
    {
      weg = statusliste[i].full_distance;
    }
  }
  return weg;
}

void Heuristik::ergebnis()
{
  cout << "\n" << "Der Gesamtweg beträgt: " << berechne_weg() << " Einheiten\n ";
}
