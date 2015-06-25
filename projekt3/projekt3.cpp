#include "problem.hpp"
#include "heuristik.hpp"
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
using namespace std;

int main ()
{
 Problem problem;
 problem.einlesen();
 problem.calc_distances();

 Heuristik heuristik;
 heuristik.set_problem(problem); // Zugriff auf die Instanz problem der Klasse Problem
 heuristik.find_nachbar();
  return 0;
}
