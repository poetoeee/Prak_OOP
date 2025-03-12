#include "Penganan.hpp"
#include <iostream>
using namespace std;

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

Penganan::Penganan() {
    this->keik = 0;
    this->panekuk = 0;
}

Penganan::Penganan(int keik, int panekuk){
    this->keik = keik;
    this->panekuk = panekuk;
}

int Penganan::GetKeik() const {
    return keik;
}

int Penganan::GetPanekuk() const {
    return panekuk;
}

void Penganan::SetKeik(int keik) {
    this->keik = keik;
}

void Penganan::SetPanekuk(int panekuk) {
    this->panekuk = panekuk;
}

Penganan operator+ (const Penganan& A, const Penganan& B){
    Penganan::n_rumah++;
    int keik = A.keik+B.keik;
    int panekuk = A.panekuk+B.panekuk;

    return Penganan(keik, panekuk);
}

Penganan operator- (const Penganan& A, const Penganan& B){
    int keik, panekuk;
    if (A.keik-B.keik < 0) {
        keik = 0;
        Penganan::uang += (A.keik*51);
    } else {
        keik = A.keik-B.keik;
        Penganan::uang += (B.keik*51);
    }
    if (A.panekuk-B.panekuk < 0) {
        panekuk = 0;
        Penganan::uang += (A.panekuk*51);
    } else {
        panekuk = A.panekuk-B.panekuk;
        Penganan::uang += (B.panekuk*51);
    }

    return Penganan(keik, panekuk);
}

Penganan operator^ (const Penganan& A, const int n){
    int keik = A.keik - n;
    int panekuk = A.panekuk - n;
    if (keik < 0) {
        Penganan::uang += (keik*51);
        keik = 0;
    }
    if (panekuk < 0) {
        Penganan::uang += (panekuk*37);
        panekuk = 0;
    }

    return Penganan(keik, panekuk);
}

Penganan operator^ (const int n, const Penganan& A){
    int keik = A.keik - n;
    int panekuk = A.panekuk - n;
    if (keik < 0) {
        Penganan::uang += (keik*51);
        keik = 0;
    }
    if (panekuk < 0) {
        Penganan::uang += (panekuk*37);
        panekuk = 0;
    }

    return Penganan(keik, panekuk);
}

int Penganan::JumlahUang(){
    return uang;
}

int Penganan::HitungNRumah(){
    return n_rumah;
}

void Penganan::Print(){
    cout << this->keik << "keik-" << this->panekuk << "panekuk" << endl; 
}