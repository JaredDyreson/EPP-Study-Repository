#include "HashBrowns.hpp"
#include <iostream>

int main() {
  Dog a("Howard");
  Dog b("Jared");
  Dog c("Kyle");
  hash_brown h;
  h.hash(a);
  h.insert(a.name(), a);
  h.print();
  return 0;
}
