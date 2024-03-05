// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  uint16_t res = value;
  while (n != 1) {
	  res *= value;
	  n -= 1;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n <= 1) {
	  return 1;
	}
	return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double res = 1;
  for (uint16_t i = 1; i <= count; i++) {
	  res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = 0;
  for (uint16_t i = 1; i <= count; i++) {
    res += pown(-1, i - 1) * calcItem(x, 2 * i - 1);
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 0;
  for (uint16_t i = 1; i <= count; i++) {
	  res += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
  }
  return res;
}
