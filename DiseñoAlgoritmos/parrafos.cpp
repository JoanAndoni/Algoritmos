// Complejidad = O(n) ya que solo se ocupa un for.

#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

float costoRed(float red, float amplitudIdeal, int j, int i) {
  return ( fabs(red - amplitudIdeal) * (j - i) );
}

float costoAmp(float amp, float amplitudIdeal, int j, int i) {
  return ( fabs(amp - amplitudIdeal) * (j - i - 1) );
}

int main()
{
  vector<string> texto = {"Hola, ", "como ", "te ", "llamas? ", "Mucho ", "gusto, ","es un", "placer"};
  vector<int> tamPalabras;
  vector<string> linea = {" "};
  
  float tamLinea = 25;
  float tamPalComp = 0;
  float tamPalEsp = 0;
  
  float amplitudIdeal = 1;
  float sobrante;
  
  int i = 0;
  int j;
  
  float red;
  float amp;
  
  bool mostrado = true;
  
  for (int i = 0; i < texto.size(); i++) {
    tamPalabras.push_back( int(texto[i].length()) );
  }
  
  for (j = 0; j < texto.size(); j++) {
    
    if (mostrado) {
      i = j;
      mostrado = false;
      linea.clear();
      tamPalComp = 0;
    }
    
    tamPalComp += tamPalabras[j];
    tamPalEsp = tamPalComp + ((j - i) * amplitudIdeal);
    
    if (tamPalEsp > tamLinea) {
      sobrante = tamPalEsp - tamLinea;
      red = amplitudIdeal - (sobrante / (j - i));
      amp = amplitudIdeal + (tamLinea - ( (tamPalComp - tamPalabras[j]) + (amplitudIdeal * (j - i - 1) ) ) ) / (j - i - 1);
      
      if ( costoAmp(amp,amplitudIdeal,j,i) > costoRed(red, amplitudIdeal,j,i) && red > 0 ) {
        linea.push_back(texto[j]);
        
        for (int i = 0; i < linea.size(); i++) cout << linea[i] << " ";
        
        cout << " " <<  "-> reducción en la línea de: " << red << " mm.";
        cout << endl;
        mostrado = true;
      }
      else {
        for (int i = 0; i < linea.size(); i++) {
          cout << linea[i] << " ";
        }
        
        cout << " " << "-> ampliación en la línea de: " << amp << " mm.";
        cout << endl;
        j--;
        mostrado = true;
      }
      
    }
    
    linea.push_back(texto[j]);
    
  }
  
  
  for (int i = 0; i < linea.size(); i++) {
    cout << linea[i] << " ";
  }
  
  cout << endl;
  
}