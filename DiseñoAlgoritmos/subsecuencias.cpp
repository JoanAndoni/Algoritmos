/* Complejidad = O(T*p) ya que se revisan los dos strings


Input:    Text with n characters and Pattern with m characters
Output: Index of the first substring of T matching P */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


std::string boyerymoore(std::string T, int n, std::string p, int m ){
  int i = m-1;
  int j = m-1;
  while( i < n-1 ){
    if(p[j] == T[i]){
      if(j==0){
        return i;
      }else{
        i--;
        j--;
      }
    }else{
      i = i + m - min(j, 1 + last[T[i]]);
      j = m - 1;
    }
  }
  return "no match";
}