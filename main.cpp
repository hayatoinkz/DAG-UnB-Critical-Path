#include "graph.h"
#include "files.h"

int main()
{
  string file;
  cout << "Digite o nome do arquivo GML" << endl;
  cin >> file;
  vector<Materia *> Vertices = Read(file + ".gml");
  MakeDOT(Vertices);
  system("dot -Tpng grafo.dot -o grafo.png");
  vector<Materia *> Grafo_Ordenado = OrganizacaoTopologica(Vertices);
  MakeDOT(Grafo_Ordenado);
  system("dot -Tpng grafo.dot -o grafo_Ordenado.png");
  return 0;
}