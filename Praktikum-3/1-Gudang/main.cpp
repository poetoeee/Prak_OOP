// main.cpp
#include <iostream>
#include "Gudang.hpp"
#include "BarangElektronik.hpp"
#include "BarangMakanan.hpp"
#include "Exception.hpp" // Untuk menangkap exception kustom

using namespace std;

// Fungsi helper untuk mencetak pemisah agar output lebih rapi
void printSeparator() {
    cout << "\n========================================\n" << endl;
}

int main() {
    cout << "Membuat Gudang g1 (Default)..." << endl;
    Gudang g1;
    g1.statusGudang();
    printSeparator();

    // cout << "Membuat Gudang g2 (Kapasitas/Sumber Daya Terbatas)..." << endl;
    // Gudang g2(50, 50, 1); // Kapasitas 50kg, Uang 50, Tenaga Kerja 1
    // g2.statusGudang();
    // printSeparator();

    // cout << "Menambah sumber daya ke Gudang g1..." << endl;
    g1.tambahKapasitas(50); // Kapasitas jadi 150
    g1.tambahUang(1000);   // Uang jadi 2000
    g1.tambahTenagaKerja(5); // Tenaga kerja jadi 10
    // cout << "Status Gudang g1 setelah penambahan sumber daya:" << endl;
    g1.statusGudang();
    printSeparator();

    // cout << "Menguji simpanBarang di Gudang g1..." << endl;

    // // 1. Mencoba simpan Barang Elektronik (Sukses)
    // cout << "-> Mencoba simpan Laptop (Elektronik, 3kg)..." << endl;
    // try {
    //     // Penting: Alokasikan barang dengan 'new'
        g1.simpanBarang(new BarangElektronik("Laptop", 3, 220));
    // } catch (const exception& e) {
    //     cout << "Exception tertangkap: " << e.what() << endl;
    // }
    g1.statusGudang();
    // cout << "----\n";

    // // 2. Mencoba simpan Barang Makanan (Sukses)
    // cout << "-> Mencoba simpan Roti Tawar (Makanan, 1kg, 7 hari)..." << endl;
    try {
        g1.simpanBarang(new BarangMakanan("Roti Tawar", 1, 7));
    } catch (const exception& e) {
        cout << "Exception tertangkap: " << e.what() << endl;
    }
    g1.statusGudang();
    // cout << "----\n";

    // // 3. Mencoba simpan Barang Makanan Kedaluwarsa (Gagal)
    // cout << "-> Mencoba simpan Susu Basi (Makanan, 1kg, 0 hari)..." << endl;
    // try {
    //     // Barang ini seharusnya di-delete di dalam simpanBarang jika gagal
        g1.simpanBarang(new BarangMakanan("Susu Basi", 1, 0));
    // } catch (const BarangKedaluwarsaException& e) {
    //     cout << "Exception tertangkap (sesuai harapan): " << e.what() << endl;
    // } catch (const exception& e) {
    //     cout << "Exception lain tertangkap: " << e.what() << endl;
    // }
    // cout << "Status Gudang g1 setelah gagal simpan barang kedaluwarsa (seharusnya tidak berubah):" << endl;
    g1.statusGudang();
    // cout << "----\n";

    // // 4. Mengisi gudang sampai hampir penuh kapasitasnya
    // cout << "-> Mencoba simpan Kulkas (Elektronik, 60kg)..." << endl;
    //  try {
    //     g1.simpanBarang(new BarangElektronik("Kulkas", 60, 220));
    // } catch (const exception& e) {
    //     cout << "Exception tertangkap: " << e.what() << endl;
    // }
    // cout << "-> Mencoba simpan TV (Elektronik, 15kg)..." << endl;
    //  try {
    //     g1.simpanBarang(new BarangElektronik("TV", 15, 110));
    // } catch (const exception& e) {
    //     cout << "Exception tertangkap: " << e.what() << endl;
    // }
    //  // Kapasitas terpakai: 3 + 1 + 60 + 15 = 79 kg. Sisa kapasitas: 150 - 79 = 71 kg
    // g1.statusGudang();
    // cout << "----\n";

    // // 5. Mencoba simpan barang melebihi kapasitas (Gagal)
    // cout << "-> Mencoba simpan Mesin Cuci (Elektronik, 80kg)... Harusnya gagal kapasitas." << endl;
    //  try {
    //     g1.simpanBarang(new BarangElektronik("Mesin Cuci", 80, 220));
    // } catch (const KapasitasPenuhException& e) {
    //      cout << "Exception tertangkap (sesuai harapan): " << e.what() << endl;
    // } catch (const exception& e) {
    //     cout << "Exception lain tertangkap: " << e.what() << endl;
    // }
    // cout << "Status Gudang g1 setelah gagal simpan karena kapasitas (seharusnya tidak berubah):" << endl;
    // g1.statusGudang(); // Status tidak boleh berubah
    // cout << "----\n";


    // // 6. Menghabiskan tenaga kerja
    // cout << "-> Menghabiskan tenaga kerja..." << endl;
    // // Tenaga kerja awal 10, terpakai 4 (Laptop, Roti, Kulkas, TV) -> sisa 6
    // int sisaTenagaKerja = 6;
    // for(int i=0; i<sisaTenagaKerja; ++i) {
    //     cout << "   Simpan Beras Karung ke-" << (i+1) << " (Makanan, 10kg, 30 hari)" << endl;
    //     try {
    //         // Kapasitas cukup (10kg), Uang cukup (100), Tenaga kerja 1
    //         g1.simpanBarang(new BarangMakanan("Beras Karung", 10, 30));
    //     } catch (const exception& e) {
    //          cout << "   Exception saat simpan Beras Karung ke-" << (i+1) << ": " << e.what() << endl;
    //          break; // Berhenti jika ada error tak terduga
    //     }
    // }
    // // Sekarang tenaga kerja = 0
    // // Kapasitas terpakai = 79 + 6*10 = 139 kg. Sisa kapasitas = 150 - 139 = 11 kg
    // // Uang terpakai = 4*100 + 6*100 = 1000. Sisa uang = 2000 - 1000 = 1000
    // g1.statusGudang();
    // cout << "----\n";

    // // 7. Mencoba simpan saat tenaga kerja habis (Gagal)
    // cout << "-> Mencoba simpan Gula (Makanan, 1kg, 100 hari)... Harusnya gagal tenaga kerja." << endl;
    //  try {
    //     g1.simpanBarang(new BarangMakanan("Gula", 1, 100));
    // } catch (const TenagaKerjaTidakCukupException& e) {
    //      cout << "Exception tertangkap (sesuai harapan): " << e.what() << endl;
    // } catch (const exception& e) {
    //     cout << "Exception lain tertangkap: " << e.what() << endl;
    // }
    //  cout << "Status Gudang g1 setelah gagal simpan karena tenaga kerja (seharusnya tidak berubah):" << endl;
    //  g1.statusGudang(); // Status tidak boleh berubah
    // cout << "----\n";

    // // 8. Menghabiskan uang (sisa 1000, butuh 100 per barang)
    // cout << "-> Menghabiskan uang..." << endl;
    // g1.tambahTenagaKerja(10); // Tambah tenaga kerja lagi agar tidak jadi limit
    // int sisaUang = 1000;
    // int barangBisaDibeli = sisaUang / 100; // = 10 barang
    // for(int i=0; i<barangBisaDibeli; ++i) {
    //     cout << "   Simpan Air Mineral ke-" << (i+1) << " (Makanan, 1kg, 365 hari)" << endl;
    //     try {
    //         // Kapasitas cukup (1kg), Uang cukup (100), Tenaga kerja cukup
    //         g1.simpanBarang(new BarangMakanan("Air Mineral", 1, 365));
    //     } catch (const exception& e) {
    //          cout << "   Exception saat simpan Air Mineral ke-" << (i+1) << ": " << e.what() << endl;
    //          break; // Berhenti jika ada error tak terduga
    //     }
    // }
    //  // Uang sekarang 0
    // g1.statusGudang();
    // cout << "----\n";

    // // 9. Mencoba simpan saat uang habis (Gagal)
    // cout << "-> Mencoba simpan Garam (Makanan, 1kg, 1000 hari)... Harusnya gagal uang." << endl;
    //  try {
    //     g1.simpanBarang(new BarangMakanan("Garam", 1, 1000));
    // } catch (const UangTidakCukupException& e) {
    //      cout << "Exception tertangkap (sesuai harapan): " << e.what() << endl;
    // } catch (const exception& e) {
    //     cout << "Exception lain tertangkap: " << e.what() << endl;
    // }
    //  cout << "Status Gudang g1 setelah gagal simpan karena uang (seharusnya tidak berubah):" << endl;
    //  g1.statusGudang(); // Status tidak boleh berubah
    // printSeparator();


    // cout << "Menguji sebutBarang di Gudang g1..." << endl;
    // cout << "-> Sebut barang index 0 (Laptop):" << endl;
    // g1.sebutBarang(0);
    // cout << "-> Sebut barang index 1 (Roti Tawar):" << endl;
    // g1.sebutBarang(1);
    //  cout << "-> Sebut barang index terakhir (" << (g1.numberOfSongs() - 1) << "):" << endl; // numberOfSongs() tidak ada, harusnya pake getter lain kalau mau atau hitung manual
    //  // Mari kita cek index terakhir dari item yang berhasil ditambahkan
    //  // Laptop(0), Roti(1), Kulkas(2), TV(3), Beras x6 (4-9), Air x10 (10-19) -> Total 20 barang, index 0-19
    //  cout << "-> Sebut barang index 19 (Air Mineral terakhir):" << endl;
    // g1.sebutBarang(19);
    // cout << "-> Sebut barang index 20 (Invalid):" << endl;
    // g1.sebutBarang(20); // Akan melempar out_of_range yang ditangkap di dalam sebutBarang
    // printSeparator();

    // cout << "Menguji Gudang g2 (Sumber Daya Terbatas)..." << endl;
    // cout << "-> Mencoba simpan Monitor (Elektronik, 5kg)..." << endl;
    //  try {
    //      // Butuh 100 uang, g2 hanya punya 50. Butuh 1 tenaga kerja, g2 punya 1.
    //     g2.simpanBarang(new BarangElektronik("Monitor", 5, 110));
    // } catch (const UangTidakCukupException& e) {
    //     cout << "Exception tertangkap (sesuai harapan): " << e.what() << endl;
    // } catch (const exception& e) {
    //     cout << "Exception lain tertangkap: " << e.what() << endl;
    // }
    // cout << "Status Gudang g2 (seharusnya tidak berubah):" << endl;
    // g2.statusGudang();
    // printSeparator();


    // cout << "Pengujian Selesai. Gudang g1 dan g2 akan dihancurkan saat keluar scope." << endl;
    // // Destruktor ~Gudang() akan dipanggil di sini untuk g1 dan g2,
    // // yang seharusnya menghapus semua Barang* yang tersimpan di dalamnya.
    // // (Periksa output memory checker seperti Valgrind jika perlu)

    return 0;
}