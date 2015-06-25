// Headerdatei heuristik.h

// Dateien einfügen
#ifndef _INC_heuristik_
#define _INC_heuristik_

typedef struct {
  int k;              //Nr des Knotens
  bool angefahren;    // 0 nicht angefahren, 1 angefahren
  double full_distance;
}Status ;

class Heuristik
{
  public:
    Heuristik(); // Konstruktor für Heuristiklasse
    // Elementarfunktionen
    // schreibende Zugriffsfunktionen
    void set_problem(Problem problem); // Übergebe Problem

    // lesende Zugriffsfunktionen

    // weitere Elementfunktionen
    void find_nachbar();

  private:
    Problem problem;  // Zugriff auf bishere Instanz
    Status statusliste[MAX_KNOTEN];

    // Variablen
};

#endif // #define _INC_heuristik_
