#include "graph.h"
#include "files.h"

int main()
{
  string file;
  cout << "Digite o nome do arquivo GML" << endl;
  cin >> file;
  vector<Materia *> Vertices = Read(file + ".gml");
  MakePNG(Vertices);
  system("dot -Tpng grafo.dot -o grafo.png");
  return 0;
}