#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  int count = 0;
  for (int i = 0; i < 100; i++) {
      if (fmod(sqrt(i), 1) == 0.0) count++;
  }
  cout << count << endl;
}