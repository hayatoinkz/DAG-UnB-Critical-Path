#ifndef FILES_H
#define FILES_H

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

vector<Materia *> Read(string file);
void MakeDOT(vector<Materia *> materias);
void MakeDOT_Top(vector<Materia *> materias);
void MakeDOT_CPM(vector<Materia *> CPM, vector<Materia *> materias, string color);

#endif