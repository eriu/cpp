// Headerdatei problem.h

// Dateien einfügen
#ifndef _INC_problem_
#define _INC_problem_
#define strcpy_s strcpy

class Problem
{
public:
	// Elementfunktionen
    int test(int a1, int b1);
    void einlesen(int Anzahl, int d, double **Matrix);
    void calc_distances(int Anzahl, double **Matrix, double **Entfernungen);
    void ausgabe();

// Datenelemente
  int Anzahl;									// Anzahl der Knoten
  int d;                      // Eingabe welche Datei eingelesen werden soll
  double Matrix[39][2];
  double Entfernungen[39][39]; // Entferungsmatrix
  int a1;
  int b1;
  int c1;

  private:


};

#endif // #define _INC_problem_
