#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Materia;

class Materia
{
public:
  int id;
  string nome;
  int peso;
  int countapontada;

  Materia(int id, string nome, int peso);
  vector<Materia *> conexoes;

  void InsertCon(Materia *materia);
};

#endif