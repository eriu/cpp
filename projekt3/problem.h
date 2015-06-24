// Headerdatei problem.h

// Dateien einfügen
#ifndef _INC_problem_
#define _INC_problem_
#define strcpy_s strcpy

class Problem
{
public:
	// Elementfunktionen
    void einlesen (int Anzahl, int d, double **Matrix);
    void entfernungsmatrix(int Anzahl, double **Matrix, double **Entfernungen);
    void ausgabe();

// Datenelemente
  int Anzahl;									// Anzahl der Knoten
  int d;                      // Eingabe welche Datei eingelesen werden soll
  double Matrix[39][2];
  double Entfernungen[39][39]; // Entferungsmatrix

  private:


};

#endif // #define _INC_problem_
