// Headerdatei heuristik.h

// Dateien einfügen
#ifndef _INC_heuristik_
#define _INC_heuristik_
#define MAX_KNOTEN 100

typedef struct {
  int index;              //Nr des Knotens
  bool angefahren;    // 0 nicht angefahren, 1 angefahren
  double full_distance;
} Status;

struct City {
    double x;
    double y;
};

struct Distance {
    int index;
    double distance;
};

class Heuristik
{
  public:
    Heuristik(); // Konstruktor für Heuristiklasse
    // Elementarfunktionen
    // schreibende Zugriffsfunktionen
    void set_problem(Problem problem); // Übergebe Problem

    // lesende Zugriffsfunktionen

    // weitere Elementfunktionen
    void sort_matrix();
    void find_nachbar();
    void ergebnis();

  private:
    Problem problem;  // Zugriff auf bishere Instanz
    Status statusliste[MAX_KNOTEN];
    // Distance1 distance;

    // Variablen
};
#endif // #define _INC_heuristik_
