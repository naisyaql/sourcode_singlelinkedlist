#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama_menu;
    int harga;
    Node* next;
};

Node* head = NULL;

void tambah_menu(string nama, int harga) {
    Node* node_baru = new Node();
    node_baru->nama_menu = nama;
    node_baru->harga = harga;
    node_baru->next = NULL;
    
    if (head == NULL) {
        head = node_baru;
    } else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node_baru;
    }
    cout << nama << " sudah ditambahkan ke keranjang"       << endl;
    cout <<"----------------------------------------------" <<endl;
}

void tampilkan_pesanan() {
    int nomor = 1;
    Node* curr = head;
    while (curr != NULL) {
        cout << nomor << ". " << curr->nama_menu << " " << curr->harga << " rupiah" << endl;
        nomor++;
        curr = curr->next;
    }
}

void bayar_pesanan() {
    int total = 0;
    Node* curr = head;
    while (curr != NULL) {
        total += curr->harga;
        curr = curr->next;
    }
     cout   <<"**************" <<endl;
    cout    <<"Total biaya yang harus dibayarkan adalah " << total << " rupiah, terimakasih sudah memesan" << endl;
    head = NULL;
}

int main() {
    cout <<"----------------------------------------------" << endl;
    cout <<"        Selamat Datang Di Kedai D4 MIXUE      " << endl;
    cout <<"----------------------------------------------" << endl;
    cout <<"    Silahkan baca menunya terlebih dahulu     " << endl;
    cout <<"=================MENU MIXUE===================" << endl;
    cout <<"----------------------------------------------" << endl;
    cout <<"|       MENU            |     HARGA           |" << endl;
    cout <<"|1. Mixue Ice Cream     |    Rp.  5. 000      |" << endl;
    cout <<"|2. Boba Shake          |    Rp. 16. 000      |" << endl;
    cout <<"|3. Mi Sundae           |    Rp. 14. 000      |" << endl;
    cout <<"|4. Mi Ganas            |    Rp. 11. 000      |" << endl;
    cout <<"|5. Creamy Mango Boba   |    Rp. 22. 000      |" << endl;
    cout <<"----------------------------------------------"  << endl;
    
    while (true) {
        cout << "Silakan pilih menu (1-5) atau selesai (0): ";
        int pilihan;
        cin >> pilihan;
        
        if (pilihan == 0) {
            break;
        }
        
        string nama;
        int harga;
        if (pilihan == 1) {
            nama = "Mixue Ice Cream";
            harga = 5000;
        } else if (pilihan == 2) {
            nama = "Boba Shake";
            harga = 16000;
        } else if (pilihan == 3) {
            nama = "Mi Sundae";
            harga = 14000;
        } else if (pilihan == 4) {
            nama = "Mi Ganas";
            harga = 11000;
        } else if (pilihan == 5) {
            nama = "Creamy Mango Boba";
            harga = 22000;
        } else {
            cout << "Input tidak valid" << endl;
            continue;
        }
        
        tambah_menu(nama, harga);
    }
    
    cout << "Pesanan Anda:" << endl;
    tampilkan_pesanan();
    
    bayar_pesanan();
    
    return 0;
}
    
