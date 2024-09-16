#include <iostream>
using namespace std;

int fibo(int x) {
  if (x <= 0) return 0;
  if (x == 1) return 1;
  return fibo(x-1) + fibo(x-2);
}

void printFibo (int n){
  for (int i = 0 ; i < n ; i++) {
    cout << fibo(i) << "  ";
  }
}

int main() {
  int n;
  cout << " Write the no. of terms : " ;
  cin >> n;
  cout << "\n The Required Fibbonaci series is \n \n" ;
  printFibo(n);
}

