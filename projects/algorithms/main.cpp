#include <iostream>
#include <limits>
#include <string>

using namespace std;

double factorial(int n) {
  double sum = 1;
  while (n > 0) {
    sum *= n--;
  }
  return sum;
}

int factorial_rec(int n) {
  if (n <= 0) {
    return 1;
  } else {
    return n * factorial_rec(n-1);
  }
}

int fib(int n) {
  int previous = 1;
  int current = 1;
  int i = 2;
  while (i < n) {
    int tmp = current;
    current = current + previous;
    previous = tmp;
    i++;
  }

  return current;
}

int fib_rec(int n ) {
  if (n <= 2) {
    return 1;
  } else {
    return fib_rec(n-1) + fib_rec(n-2);
  }
}

int print(const char* list, int size) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    cout << list[i] << endl;
    count += 1;
  }
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      cout << list[i] << list[j] << endl;
      count += 1;
    }
  }
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      for (int k = 0; k < size; ++k) {
        cout << list[i] << list[j] << list[k] << endl;
        count += 1;
      }
    }
  }
  return count;
}

int bubblesort(int* items, int n) {
  int count = 0;
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < n-1; ++j) {
      #ifdef DEBUG
      count += 1;
      #endif
      if (items[j] > items[j+1]) {
        int tmp = items[j];
        items[j] = items[j+1];
        items[j+1] = tmp;
        #ifdef DEBUG
        count += 3;
        #endif
      }
    }
  }
  return count;
}

void printarray(int* items, int n) {
  for (int i = 0; i < n; ++i) {
    cout << items[i] << " ";
  }
  cout << endl;
}

int main() {

  cout << "Total: " << factorial(8) << endl;
  cout << "Total: " << factorial_rec(8) << endl;

  cout << "Fib (5): " << fib(10) << endl;

  cout << "Fib (5): " << fib_rec(10) << endl;

  cout << "Print: " << print(string("abcdefghijklmnopqrstuvwxyz").c_str(), 26) << endl;

  int items[] = {3, 4, 12, 0, 8, 39, 23, 14};
  printarray(items, 8);
  cout << bubblesort(items, 8) << endl;
  printarray(items, 8);
  cout << bubblesort(items, 8) << endl;

  return 0;
}
