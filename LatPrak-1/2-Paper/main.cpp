#include "Paper.hpp"
#include <iostream>
using namespace std;

int main() {
    Paper *a= new Paper('A');
    Paper *b= new Paper('B');
    Paper *c= new Paper('C');
    Paper *d= new Paper(*c);

    (*a).fold();
    (*b).fold();
    (*c).fold();

    (*c).glue();

    (*a).~Paper();

    (*c).setName('X');

    (*d).fold();
    (*d).glue();

    (*d).~Paper();
    (*c).~Paper();
    (*b).~Paper();

    return 0;
}