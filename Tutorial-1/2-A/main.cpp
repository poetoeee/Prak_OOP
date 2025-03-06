#include "A.hpp"

int main () {
  A* a = new A('1');
  A* b = new A('2');
  A* c = new A(*a);
  *a=*b;
  a->show();
  a->~A();
  b->~A();
  c->~A();

  return 0;
}