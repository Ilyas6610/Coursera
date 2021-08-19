#include <iostream>
#include "student.h"

using namespace std;

bool Compare(const Student& first, const Student& second) {
  return first.rating > second.rating;
}
