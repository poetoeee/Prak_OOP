#include "Barang.hpp"
#include <string>

using namespace std;

Barang::Barang(string nama, int berat) : nama(nama), berat(berat) {}

Barang::~Barang() {}

string Barang::getNama() const {
    return nama;
}

int Barang::getBerat() const {
    return berat;
}