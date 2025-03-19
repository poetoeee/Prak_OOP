#include "Authenticator.hpp"

Authenticator::Authenticator() {
    this->secretResource = "Ini adalah data rahasia!";
    this->currentUser = nullptr;
    this->userCount = 0;
}

void Authenticator::registerUser(const string &username, const string &password, bool isAdmin){
    if (userCount >= MAX_USERS) {
        cout << "Gagal: Kapasitas user penuh!" << endl;
    }else{
        for (int i=0; i<userCount; i++){
            if(users[i]->getUsername() == username){
                cout << "Gagal: Username sudah digunakan!" << endl;
                return;
            }
        }
        if (isAdmin){
            users[userCount] = new AdminUser(username, password);
        }else{
            users[userCount] = new User(username, password);
        }
        userCount++;
        cout << "Sukses: User " << username << " berhasil terdaftar!" << endl;
    }
}

void Authenticator::login(const string &username, const string &password){
    for (int i=0; i<userCount; i++){
        if(users[i]->getUsername() == username && users[i]->checkPassword(password)){
            currentUser = users[i];
            cout << "Sukses: Login berhasil! Selamat datang, " << username << "." << endl;
            return;
        }
    } cout << "Gagal: Username atau password salah!" << endl;
}

void Authenticator::logout(){
    if(currentUser != nullptr){
        string username = currentUser->getUsername();
        currentUser = nullptr;
        cout << "Sukses: User " << username << " telah logout." << endl;
    }else{
        cout << "Gagal: Tidak ada user yang sedang login!" << endl;
    }
}

void Authenticator::accessResource() const{
    if(currentUser != nullptr){
        cout << "Resource: " << secretResource << endl;
    }else{
        cout << "Akses ditolak! Silakan login terlebih dahulu." << endl;
    }
}

void Authenticator::setResource(const string &newResource){
    if(currentUser != nullptr){
        if(currentUser->isAdmin()){
            secretResource = newResource;
            cout << "Sukses: Resource telah diperbarui oleh " << currentUser->getUsername() << "." << endl;
        }else{
            cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << endl;
        }
    }else{
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." << endl;
    }
}

Authenticator::~Authenticator(){
    for (int i=0; i<userCount; i++){
        delete users[i];
    }
}