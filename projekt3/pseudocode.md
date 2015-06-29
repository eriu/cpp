## Heuristik
* gegeben: Distanz der Entfernungen in einer Matrix i/j

**Schleife für jeden Standort i:**

* Sortiere die Entfernungen für i zum Standort j aufsteigend
* wähle den Standort für das nächste Ziel, welcher die geringste Entferung zu i besitzt, und noch nicht angefahren wurde
* addiere nun die Distanz des angefahrenen Standortes auf den Gesamtweg
* speichere den gewählten Weg in Array für die Reihenfolge (int path[MAX_KNOTEN])
* setze den Status des angefahrenen Standortes auf angefahren (bool visited[MAX_KNOTEN])
* Zähle die Anzahl der angefahrenen Codes um 1 nach oben

**Abbruch:**

* Anzahl der angefahrenen Städte = Anzahl der geg. Städte aus der Importdatei
* Anschließend Rückfahrt zum Ausgangsstandort (entspreched Addieren des zugehörigen Weges)

**Ausgabe:**

* Ausgabe der Reihenfolge der Knoten (aufsteigend) -> Route
* Ausgabe der Gesamtdistanz

verwenden von:
* Distanzmatrix mit Sturktur die die  jeweiligen Entfernungen und Indexes
* einen Array für besuchten Standorte
* einen Array für die Reihenfolge der angefahrenden Städte
* counter für die Anzahl der bereits angefahrenen Städte
* double für die Addition der angefahrenen Wege
