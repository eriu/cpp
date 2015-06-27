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
  statusliste[i].index = i+1;   // Status.k inistalisieren mit Nr des Knotens
}


void Heuristik::set_problem(Problem problem)
{
  this->problem = problem;
}

void Heuristik::find_nachbar()
{     cout << "\n sortiere Entfernungsmatrix:" << "\n ";

  for (int i = 0; i < problem.getanzahl(); i++) {
    std::sort(problem.distance_matrix[i], problem.distance_matrix[i]+problem.getanzahl(), [](Distance1 const &a, Distance1 const &b) { return a.weg < b.weg; });
  for (int j = 0; j<problem.getanzahl(); j++)
  {
    cout << "\t" << problem.distance_matrix[i][j].weg << "|" <<  problem.distance_matrix[i][j].index << " ";
  }
    cout << "\n";

  // find nächsten nachbarn der noch nicht besichtigt wurde  



}



/*
 // problem.distance_matrix[i][j]
 for(int i=0; i<problem.getanzahl(); i++)
 {
   double dis_min=99999998;   //initialisieren
   for (int j=0; j< problem.getanzahl(); j++)
   {
     if (statusliste[i].angefahren == 0)
        {
        if (dis_min > problem.distance_matrix[i][j].weg)
          {
            problem.distance_matrix[i][j].weg;
          }
        }
     else
        {
       // Überspringe Komponente
        }
   }
 }*/
}
