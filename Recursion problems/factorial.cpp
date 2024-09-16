#include <iostream>
using namespace std;

int factorial(int f) {
  if (f<=1) return 1;
return f * factorial(f-1);
}

int main () {
  int f ;
cout << " write a natural number --> " ;
cin >> f ;


int LoDekhLo = factorial(f);
cout << " The Factorial of "  << f << " is = " << LoDekhLo ;

return 0;
}
