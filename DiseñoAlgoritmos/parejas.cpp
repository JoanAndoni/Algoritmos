// Complejidad: O(n^2) Se comparan la matriz, la cual es bidimencional.

#include <iostream>
#include <vector>

 using namespace std;

bool BestMan(vector<vector <int> > mejor, int hombre, int mujer, int anotherMan, int columnas) 
{
  for (int i = 0; i < columnas; i++)
  {
    if (mejor[mujer][i] == anotherMan) return true;
    if (mejor[mujer][i] == hombre) return false;
  }
}

void asignar(vector<vector<int>> pref, int columnas) {
  
  vector<int> matchMujeres;
  vector<bool> HombresAsig;
  
  for (int i = 0; i < columnas; i++)
  {  
    matchMujeres.push_back(-1);
    HombresAsig.push_back(false); 
  }
  
  int solteros = columnas;
  
  while (solteros > 0) {
    
    int hombre;
    
    for (int i = 0; i < columnas; i++) 
    {      
      if (HombresAsig[i] == false)
      {
        hombre = i;
        i = columnas;
      }
    }
    
    for (int i = 0; (i < columnas) && (HombresAsig[hombre] == false); i++) 
    {  
		int mujer = pref[hombre][i];

      if (matchMujeres[mujer - columnas] == -1) 
      {
        matchMujeres[mujer - columnas] = hombre;
        HombresAsig[hombre] = true;
        solteros--;
      }
      
      else
      {  
        int otroHombre = matchMujeres[mujer - columnas];
        
        if (BestMan(pref, hombre, mujer, otroHombre, columnas) == false) 
        {
          matchMujeres[mujer - columnas] = hombre;
          HombresAsig[hombre] = true;
          HombresAsig[otroHombre] = false;
        } 
      }
    }
  }
  for (int i = 0; i < columnas; i++) cout << "Esta mujer" << i + columnas << " hizo match con este hombre" << matchMujeres[i] << endl; 
}


void asignar(vector<vector<int>> pref, int columnas);

int main() 
{
  int columnas = 4;

  vector<vector<int>> pref(2 * columnas, vector<int>(columnas));

  pref =
  {
    { 4, 5, 6, 7 }, 
    { 5, 6, 7, 4 }, 
    { 6, 7, 4, 5 }, 
    { 7, 4, 5, 6 }, 
    
    { 0, 1, 2, 3 }, 
    { 1, 2, 3, 0 }, 
    { 2, 3, 0, 1 }, 
    { 3, 0, 1, 2 }, 
    
  };

  asignar(pref, columnas);  
}