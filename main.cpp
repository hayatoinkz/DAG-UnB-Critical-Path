#include "graph.h"
#include "files.h"

int main()
{
  string file;
  cout << "Digite o nome do arquivo GML" << endl;
  cin >> file;
  vector<Materia *> Vertices = Read(file + ".gml");
  MakeDOT(Vertices);
  vector<Materia *> Grafo_Ordenado = OrganizacaoTopologica(Vertices);
  MakeDOT_Top(Grafo_Ordenado);
  vector<vector<Materia *>> Caminho_Critico = CPM(Grafo_Ordenado);
  MakeDOT_CPM(Caminho_Critico[0], Grafo_Ordenado, "red");
  system("dot -Tpng grafoCPM.dot -o grafo_CPM1.png");
  MakeDOT_CPM(Caminho_Critico[1], Grafo_Ordenado, "blue");
  system("dot -Tpng grafoCPM.dot -o grafo_CPM2.png");
  return 0;
}