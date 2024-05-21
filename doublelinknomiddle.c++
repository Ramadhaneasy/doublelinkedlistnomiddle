#include <iostream>
#include <string>

using namespace std;

struct Antrian {
    int nomorAntrian;
    string namaPemilik;
    string waktuKedatangan;
    Antrian* next;
    Antrian* prev;
};

Antrian* kepala = nullptr;
Antrian* ekor = nullptr;

// Fungsi untuk menambahkan antrian ke akhir linked list
void tambahAntrian(int nomorAntrian, string namaPemilik, string waktuKedatangan) {
    Antrian* newNode = new Antrian;
    newNode->nomorAntrian = nomorAntrian;
    newNode->namaPemilik = namaPemilik;
    newNode->waktuKedatangan = waktuKedatangan;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (kepala == nullptr) {
        kepala = ekor = newNode;
    } else {
        ekor->next = newNode;
        newNode->prev = ekor;
        ekor = newNode;
    }
}

// Fungsi untuk mencetak semua antrian dari kepala ke ekor
void cetakAntrian() {
    Antrian* current = kepala;
    while (current != nullptr) {
        cout << "Nomor Antrian: " << current->nomorAntrian << endl;
        cout << "Nama Pemilik: " << current->namaPemilik << endl;
        cout << "Waktu Kedatangan: " << current->waktuKedatangan << endl << endl;
        current = current->next;
    }
}

// Fungsi untuk mencetak semua antrian dari ekor ke kepala
void cetakAntrianTerbalik() {
    Antrian* current = ekor;
    while (current != nullptr) {
        cout << "Nomor Antrian: " << current->nomorAntrian << endl;
        cout << "Nama Pemilik: " << current->namaPemilik << endl;
        cout << "Waktu Kedatangan: " << current->waktuKedatangan << endl << endl;
        current = current->prev;
    }
}

// Fungsi utama
int main() {
    tambahAntrian(1, "John Doe", "08:00");
    tambahAntrian(2, "Jane Doe", "08:15");
    tambahAntrian(3, "Alice", "08:30");

    // Menampilkan daftar antrian dari kepala ke ekor
    cout << "Daftar Antrian (dari kepala ke ekor):" << endl;
    cetakAntrian();
    cout << "\n";

    // Menampilkan daftar antrian dari ekor ke kepala
    cout << "Daftar Antrian (dari ekor ke kepala):" << endl;
    cetakAntrianTerbalik();
    cout << "\n";

    return 0;
}
