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
  for (int i = 0; i < Vertices.size(); i++)
  {
    cout << i + 1 << " " + Vertices[i]->nome + " " << Vertices[i]->id << endl;
  }
  cout << "-----------------------------------------------------------------------------------" << endl;
  vector<Materia *> Grafo_Ordenado = OrganizacaoTopologica(Vertices);
  MakeDOT(Grafo_Ordenado);
  for (int i = 0; i < Grafo_Ordenado.size(); i++)
  {
    cout << i + 1 << " " + Grafo_Ordenado[i]->nome + " " << Grafo_Ordenado[i]->id << endl;
  }
  system("dot -Tpng grafo.dot -o grafo_Ordenado.png");
  return 0;
}