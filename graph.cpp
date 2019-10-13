#include "graph.h"

Materia::Materia(int id, string nome, int peso)
{
  this->id = id;
  this->nome = nome;
  this->peso = peso;
  this->grau = 0;
}

void Materia::InsertCon(Materia *materia)
{
  conexoes.push_back(materia);
}

void Materia::InsertAnt(Materia *materia)
{
  antecessor.push_back(materia);
}

int SearchMateriaInt(vector<Materia *> materias, Materia *materia)
{
  int i = 0;
  while (materias[i]->id != materia->id)
  {
    i++;
  }

  return i;
}
bool SearchMateria(vector<Materia *> materias, Materia *materia)
{
  for (int i = 0; i < materias.size(); i++)
  {
    if (materias[i]->id == materia->id)
    {
      return true;
    }
  }
  return false;
}

vector<Materia *> OrganizacaoTopologica(vector<Materia *> materias)
{
  queue<Materia *> fila;
  queue<Materia *> filafinal;
  int contadordevertices = 0;
  for (int i = 0; i < materias.size(); i++)
  {
    if (materias[i]->grau == 0)
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
        fila.front()->conexoes[i]->grau--;
        if (fila.front()->conexoes[i]->grau == 0)
        {
          fila.push(fila.front()->conexoes[i]);
        }
      }
    }
    filafinal.push(fila.front());
    fila.pop();
  }
  //if (contadordevertices == materias.size())
  //{
  //  cout << "O vertice pode ser Ordenado Topologicamente" << '\n';
  //}
  vector<Materia *> vecordenado;
  for (int i = (filafinal.size() - 1); i >= 0; i--)
  {
    vecordenado.push_back(filafinal.front());
    filafinal.pop();
  }
  return vecordenado;
}

vector<vector<Materia *>> CPM(vector<Materia *> materias)
{
  queue<Materia *> fila;
  int distancia[materias.size()];
  int Distancia = 0;
  int Max1 = 0;
  int Max2 = 0;
  int index1 = 0;
  int index2 = 0;

  for (int i = 0; i < materias.size(); i++)
  {
    distancia[i] = 0;
    if (materias[i]->grau == 0)
    {
      fila.push(materias[i]);
    }
  }
  while (!fila.empty())
  {
    Materia *materia = fila.front();
    fila.pop();
    for (int i = 0; i < materia->conexoes.size(); i++)
    {
      distancia[SearchMateriaInt(materias, materia->conexoes[i])] = max(distancia[SearchMateriaInt(materias, materia->conexoes[i])], distancia[SearchMateriaInt(materias, materia)] + materia->peso);
      materia->conexoes[i]->grau--;
      if (materia->conexoes[i]->grau == 0)
      {
        fila.push(materia->conexoes[i]);
      }
    }
  }

  for (int i = 0; i < materias.size(); i++)
  {
    if (distancia[i] > Max1)
    {
      Max2 = Max1;
      Max1 = distancia[i];
      index2 = index1;
      index1 = i;
    }
  }
  vector<vector<Materia *>> CPM;
  vector<Materia *> temp;
  stack<Materia *> pilha;
  Materia *percorre1 = materias[index1];
  Materia *percorre2 = materias[index2];

  pilha.push(percorre1);

  while (Distancia != Max1)
  {
    for (int i = 0; i < materias.size(); i++)
    {
      for (int j = 0; j < materias[i]->conexoes.size(); j++)
      {
        if ((materias[i]->conexoes[j] == percorre1) && (distancia[SearchMateriaInt(materias, percorre1)] == distancia[SearchMateriaInt(materias, materias[i])] + materias[i]->peso))
        {
          pilha.push(materias[i]);
          Distancia += materias[i]->peso;
          percorre1 = materias[i];
        }
      }
    }
  }
  while (!pilha.empty())
  {
    temp.push_back(pilha.top());
    pilha.pop();
  }
  CPM.push_back(temp);
  temp.clear();

  Distancia = 0;

  pilha.push(percorre2);
  while (Distancia != Max2)
  {
    for (int i = 0; i < materias.size(); i++)
    {
      for (int j = 0; j < materias[i]->conexoes.size(); j++)
      {
        if ((materias[i]->conexoes[j] == percorre2) && (distancia[SearchMateriaInt(materias, percorre2)] == distancia[SearchMateriaInt(materias, materias[i])] + materias[i]->peso))
        {
          pilha.push(materias[i]);
          Distancia += materias[i]->peso;
          percorre2 = materias[i];
        }
      }
    }
  }

  while (!pilha.empty())
  {
    temp.push_back(pilha.top());
    pilha.pop();
  }
  CPM.push_back(temp);
  temp.clear();
  return CPM;
}