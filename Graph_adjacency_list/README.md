# Graph representation using adjacency list

Powyższy kod przedstawia przykładową implementację grafu w C++, używając do tego listy sąsiedztwa.

Graf w tej reprezentacji to lista list. Dla każdego wierzchołka trzymamy listę jego sąsiadów (czyli wierzchołków, z którymi jest on połączony krawędzią). Listy dla kolejnych wierzchołków trzymamy w liście zewnętrznej.
alety:
Mała złożoność pamięciowa O(V+E) gdzie E to liczba krawędzi a V liczba wierzchołków. 
Wady:
Sprawdzenie, czy istnieje krawędź między dwoma wierzchołkami ma złożoność -w najgorszym razie O(E)
