#include "problem.hpp"
#include "heuristik.hpp"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
//using namespace std;

// Konstruktor für Heuristikklasse
Heuristik::Heuristik()
{
  for (int i=0; i<problem.getanzahl(); i++)
  statusliste[i].k = i+1;   // Status.k inistalisieren mit Nr des Knotens
}


void Heuristik::set_problem(Problem problem)
{
  this->problem = problem;
}

void Heuristik::find_nachbar()
{
 // problem.distance_matrix[i][j]
 for(int i=0; i<problem.getanzahl(); i++)
 {
   double dis_min=99999998;   //initialisieren
   for (int j=0; j< problem.getanzahl(); j++)
   {
     if (statusliste[i].angefahren == 0)
     {
       if (dis_min > problem.distance_matrix[i][j])
       {
         problem.distance_matrix[i][j];
       }
     }
     else
     {
       // Überspringe Komponente
     }
   }
  }  
}
