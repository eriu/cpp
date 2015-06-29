// Headerdatei heuristik.h

// Dateien einfügen
#ifndef _INC_heuristik_
#define _INC_heuristik_
#define MAX_KNOTEN 100

typedef struct {
  int index;          //Nr des Knotens
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
    void set_problem(Problem problem); // Übergebe Problem
    void orig_matrix();
    void sort_matrix();
    void find_nachbar();

  private:
    Problem problem;  // Zugriff auf bishere Instanz
    Status statusliste[MAX_KNOTEN];
    double oldmatrix[MAX_KNOTEN][MAX_KNOTEN];

};
#endif // #define _INC_heuristik_
