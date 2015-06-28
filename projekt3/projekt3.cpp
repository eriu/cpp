#include "problem.hpp"
#include "heuristik.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <fstream>
#ifndef __GNUC__
#include <conio.h>
#else
#define _getch()
#endif
using namespace std;

int main ()
{
 Problem problem;
 problem.einlesen();
 problem.calc_distances();

 Heuristik heuristik;
 heuristik.set_problem(problem);
 heuristik.sort_matrix();
 heuristik.find_nachbar();
 heuristik.ergebnis();
 return 0;
}
