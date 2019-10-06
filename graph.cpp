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