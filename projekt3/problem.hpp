// Headerdatei problem.h

// Dateien einfügen
#ifndef _INC_problem_
#define _INC_problem_
#define strcpy_s strcpy
#define MAX_KNOTEN 100

typedef struct
{
  int index;
  double x_coord;
  double y_coord;
} Knoten;


class Problem
{
  public:
    void einlesen();
    void calc_distances();
    double ** getdistance_matrix();
    int getanzahl();
    // Elementarfunktionen
    // schreibende Zugriffsfunktionen

    // lesende Zugriffsfunktionen

    // weitere Elementfunktionen
    // public Variablen
    double distance_matrix[MAX_KNOTEN][MAX_KNOTEN]; // Matrix definieren


  private:
    int d; // welche Datei soll eingelesen werden
    int anzahl;
    Knoten knotenliste[MAX_KNOTEN]; // Pointer auf knotenliste



};

#endif // #define _INC_problem_
