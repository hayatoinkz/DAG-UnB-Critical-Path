#include "files.h"
#include "graph.h"

map<int, Materia *> vertice;
vector<Materia *> verticesenumerados;

vector<Materia *> Read(string file)
{
  fstream FileReader;
  FileReader.open(file.c_str());
  string checkline;
  int num = 0;
  if (FileReader.is_open())
  {
    while (!FileReader.eof())
    {
      FileReader >> checkline;
      if (checkline == "node")
      {
        while (checkline != "id")
        {
          FileReader >> checkline;
        }
        int id;
        string nome;
        int peso;

        FileReader >> id;
        FileReader >> nome;
        FileReader >> peso;
        Materia *materia = new Materia(id, nome, peso);
        vertice.insert({id, materia});
        verticesenumerados.push_back(materia);

        num++;
      }
      else if (checkline == "edge")
      {
        while (checkline != "source")
        {
          FileReader >> checkline;
        }
        int source;
        int destiny;
        FileReader >> source;
        FileReader >> checkline;
        FileReader >> destiny;
        vertice[source]->InsertCon(vertice[destiny]);
        vertice[destiny]->InsertAnt(vertice[source]);
        vertice[destiny]->grau += 1;
      }
    }
  }
  else
  {
    cout << "Error reading File: " << file << endl;
  }
  FileReader.close();
  return verticesenumerados;
}

void MakeDOT(vector<Materia *> materias)
{
  ofstream myfile;
  myfile.open("grafo.dot");
  myfile << "digraph Ciencia_da_Computacao{\n";
  for (int i = 0; i < materias.size(); i++)
  {
    if (materias[i]->conexoes.size() == 0)
    {
      myfile << "\t" << materias[i]->id << "\n ";
    }
    else
    {
      for (int j = 0; j < materias[i]->conexoes.size(); j++)
      {
        myfile << "\t" << materias[i]->id << " -> " << materias[i]->conexoes[j]->id << " [label = " << materias[i]->peso << "];\n";
      }
    }
  }
  for (int i = 0; i < materias.size(); i++)
  {
    if (materias[i]->peso == 2)
    {
      myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=green]\n ";
    }
    else if (materias[i]->peso == 4)
    {
      myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=skyblue]\n ";
    }
    else if (materias[i]->peso == 6)
    {
      myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=yellow]\n ";
    }
  }
  myfile << "}\n";
  myfile.close();
  system("dot -Tpng grafo.dot -o grafo.png");
}

void MakeDOT_Top(vector<Materia *> materias)
{
  ofstream myfile;
  myfile.open("grafo_Ordenado.dot");

  myfile << "digraph Ciencia_da_Computacao{\n";
  myfile << "\tnode [shape=doublecircle];\n";
  myfile << "\tranksep = \"4\";\n";
  myfile << "\tsubgraph{\n ";
  myfile << "\trank = same; ";

  for (int i = 0; i < materias.size(); i++)
  {
    myfile << materias[i]->id << "; ";
  }
  myfile << "\n\t}\n";

  for (int i = 0; i < materias.size(); i++)
  {
    if (materias[i]->conexoes.size() == 0)
    {
      myfile << "\t" << materias[i]->id << "\n ";
    }
    else
    {
      for (int j = 0; j < materias[i]->conexoes.size(); j++)
      {
        myfile << "\t" << materias[i]->id << " -> " << materias[i]->conexoes[j]->id << " [label = " << materias[i]->peso << "];\n";
      }
    }
  }

  for (int i = 0; i < materias.size(); i++)
  {
    if (materias[i]->peso == 2)
    {
      myfile << "\t" << materias[i]->id << " [style=filled, fillcolor=green]\n ";
    }
    else if (materias[i]->peso == 4)
    {
      myfile << "\t" << materias[i]->id << " [style=filled, fillcolor=skyblue]\n ";
    }
    else if (materias[i]->peso == 6)
    {
      myfile << "\t" << materias[i]->id << " [style=filled, fillcolor=yellow]\n ";
    }
  }
  myfile << "}\n";
  myfile.close();
  system("dot -Tpng grafo_Ordenado.dot -o grafo_Ordenado.png");
}

void MakeDOT_CPM(vector<Materia *> CPM, vector<Materia *> materias, string color)
{
  {
    //a->b[color = red, penwidth = 3.0];
    ofstream myfile;
    myfile.open("grafoCPM.dot");
    myfile << "digraph Ciencia_da_Computacao{\n";
    for (int i = 0; i < materias.size(); i++)
    {
      if (materias[i]->conexoes.size() == 0)
      {
        myfile << "\t" << materias[i]->id << "\n ";
      }
      else
      {
        for (int j = 0; j < materias[i]->conexoes.size(); j++)
        {
          if ((SearchMateria(CPM, materias[i]) == true) && (SearchMateria(CPM, materias[i]->conexoes[j]) == true))
          {
            myfile << "\t" << materias[i]->id << " -> " << materias[i]->conexoes[j]->id << " [label = " << materias[i]->peso << ", color = " + color + ", penwidth = 3.0];\n";
          }
          else
          {
            myfile << "\t" << materias[i]->id << " -> " << materias[i]->conexoes[j]->id << " [label = " << materias[i]->peso << "];\n";
          }
        }
      }
    }
    for (int i = 0; i < materias.size(); i++)
    {
      if (materias[i]->peso == 2)
      {
        myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=green]\n ";
      }
      else if (materias[i]->peso == 4)
      {
        myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=skyblue]\n ";
      }
      else if (materias[i]->peso == 6)
      {
        myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=yellow]\n ";
      }
    }
    myfile << "}\n";
    myfile.close();
  }
}