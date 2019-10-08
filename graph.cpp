#include "graph.h"

Materia::Materia(int id, string nome, int peso)
{
  this->id = id;
  this->nome = nome;
  this->peso = peso;
  this->countapontada = 0;
}

void Materia::InsertCon(Materia *materia)
{
  conexoes.push_back(materia);
}

vector<Materia *> OrganizacaoTopologica(vector<Materia *> materias)
{
  //verifica vertices com 0 entradas
  queue<Materia *> fila;
  queue<Materia *> filafinal;
  int contadordevertices = 0;
  for (int i = 0; i < materias.size(); i++)
  {
    if (materias[i]->countapontada == 0)
    {
      fila.push(materias[i]);
    }
  }
  while (!fila.empty())
  {
    contadordevertices++;
    if (fila.front()->conexoes.size() != 0)
    {
      for (int i = 0; i < fila.front()->conexoes.size(); i++)
      {
        fila.front()->conexoes[i]->countapontada--;
        if (fila.front()->conexoes[i]->countapontada == 0)
        {
          fila.push(fila.front()->conexoes[i]);
        }
      }
    }
    filafinal.push(fila.front());
    fila.pop();
  }
  if (contadordevertices == materias.size())
  {
    cout << "O vertice pode ser Ordenado Topologicamente" << '\n';
  }
  vector<Materia *> vecordenado;
  for (int i = (filafinal.size() - 1); i > 0; i--)
  {
    vecordenado.push_back(filafinal.front());
    filafinal.pop();
  }
  return vecordenado;
}