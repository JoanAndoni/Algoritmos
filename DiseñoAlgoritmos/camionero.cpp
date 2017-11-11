// Complejidad = O(n) Solo compara una vez las distancias entre las gasolinerias del vector.

 
#include <iostream>
#include <vector>

using namespace std;

vector<int> calcularRecorrido(int MaxKM, vector<int> distancias) {
  
  vector<int> paradas;
  int kmRecorridos = 0;
  int pos = -1;
  int noDistancias = int(distancias.size()-1);
  
  while(pos != noDistancias) {

    if(kmRecorridos + distancias[pos+1] > MaxKM)
    {
      paradas.push_back(pos);
      kmRecorridos = 0;
      
      if (paradas[pos] != 0 && paradas[pos] == paradas[pos+1]) {
        pos = noDistancias;
        paradas[0] = -1;
      } 
    }

    else {
      pos++;
      kmRecorridos += distancias[pos];
    }  
  }
  return paradas; 

}

int main() 
{
	int MaxKM = 150;
	vector<int> GasDist = {79, 40, 60, 80, 120};
	vector<int> paradas = calcularRecorrido(MaxKM, GasDist);
	int numParadas = int(paradas.size());
 

  if (paradas.empty()) cout << "No hay paradas" << endl;
  else if (paradas[0] == -1) cout << "El camión no puede llegar a Acapulco ya que el numero de km permitidos se lo impide" << endl;
  else 
  {
    cout << "Numero de paradas: " << numParadas <<  endl;
    for(int i = 0; i < numParadas; i++) cout << "Se va a parar en la gasolineria: " << paradas[i+1] << endl;
  }
  return 0;

}