#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdexcept>
using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

struct Konser
{
    int id;
    string nama;
    string jenis;
    string tanggal;
    string tempat;
    int harga;
    int stok;
};

struct Tiket
{
    int idTiket;
    string pembeli;
    Konser konser;
    int jumlah;
    int totalHarga;
};

struct User
{
    string username;
    string nim;
    string role;
};

void header()
{
    setColor(11);
    cout << "========================================\n";
    cout << "     SISTEM TIKET KONSER ONLINE\n";
    cout << "========================================\n";
    setColor(7);
}

void tampilHarga(int harga)
{
    setColor(14);
    cout << "Harga: Rp " << harga << endl;
    setColor(7);
}

void tampilHarga(int harga, int jumlah)
{
    setColor(10);
    cout << "Total Harga: Rp " << harga * jumlah << endl;
    setColor(7);
}

void tampilKonser(Konser *konser, int jumlahKonser)
{
    setColor(14);
    cout << "\n=================================== DAFTAR KONSER ===================================\n";
    setColor(7);
    setColor(10);
    cout << left << setw(5) << "ID"
         << setw(20) << "Nama"
         << setw(15) << "Jenis"
         << setw(15) << "Tanggal"
         << setw(15) << "Tempat"
         << setw(12) << "Harga"
         << setw(8) << "Stok" << endl;
    cout << "-------------------------------------------------------------------------------------\n";

    for (int i = 0; i < jumlahKonser; i++)
    {
        setColor(10);
        cout << left << setw(5) << konser[i].id
             << setw(20) << konser[i].nama
             << setw(15) << konser[i].jenis
             << setw(15) << konser[i].tanggal
             << setw(15) << konser[i].tempat
             << setw(12) << konser[i].harga
             << setw(8) << konser[i].stok << endl;
        setColor(7);
    }
}

void tambahKonser(Konser *konser, int *jumlahKonser)
{
    try
    {

        cin.ignore();

        setColor(11);
        cout << "\n=== TAMBAH KONSER ===\n";
        setColor(7);

        konser[*jumlahKonser].id = *jumlahKonser + 1;

        cout << "Nama: ";
        getline(cin, konser[*jumlahKonser].nama);

        if (konser[*jumlahKonser].nama.empty())
            throw invalid_argument("Nama tidak boleh kosong");

        cout << "Jenis: ";
        getline(cin, konser[*jumlahKonser].jenis);

        cout << "Tanggal: ";
        getline(cin, konser[*jumlahKonser].tanggal);

        cout << "Tempat: ";
        getline(cin, konser[*jumlahKonser].tempat);

        cout << "Harga: ";
        cin >> konser[*jumlahKonser].harga;

        cout << "Stok: ";
        cin >> konser[*jumlahKonser].stok;

        (*jumlahKonser)++;

        setColor(10);
        cout << "Konser berhasil ditambahkan!\n";
        setColor(7);
    }
    catch (const exception &e)
    {
        setColor(12);
        cout << "Input tidak valid: " << e.what() << endl;
        setColor(7);
        cin.clear();
    }
}

void hapusKonser(Konser *konser, int *jumlahKonser)
{
    int id;
    tampilKonser(konser, *jumlahKonser);

    cout << "Masukkan ID: ";
    cin >> id;

    for (int i = 0; i < *jumlahKonser; i++)
    {
        if (konser[i].id == id)
        {
            for (int j = i; j < *jumlahKonser - 1; j++)
                konser[j] = konser[j + 1];

            (*jumlahKonser)--;

            setColor(10);
            cout << "Berhasil dihapus!\n";
            setColor(7);
            return;
        }
    }

    setColor(12);
    cout << "ID tidak ditemukan!\n";
    setColor(7);
}

void cariNamaKonser(Konser *konser, int jumlahKonser, string keyword)
{
    bool ditemukan = false;

    for (int i = 0; i < jumlahKonser; i++)
    {
        if (konser[i].nama == keyword)
        {
            setColor(10);
            cout << "\nDitemukan:\n";
            cout << "ID: " << konser[i].id << endl;
            cout << "Nama: " << konser[i].nama << endl;
            tampilHarga(konser[i].harga);
            setColor(7);
            ditemukan = true;
        }
    }

    if (!ditemukan)
    {
        setColor(12);
        cout << "Konser tidak ditemukan\n";
        setColor(7);
    }
}

int binarySearchID(Konser *konser, int jumlahKonser, int key)
{
    int left = 0, right = jumlahKonser - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (konser[mid].id == key)
            return mid;
        else if (konser[mid].id < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void ubahKonser(Konser *konser, int jumlahKonser)
{
    int id;

    tampilKonser(konser, jumlahKonser);
    cout << "Masukkan ID: ";
    cin >> id;

    int index = binarySearchID(konser, jumlahKonser, id);

    if (index != -1)
    {
        cin.ignore();

        cout << "Nama baru: ";
        getline(cin, konser[index].nama);

        cout << "Jenis baru: ";
        getline(cin, konser[index].jenis);

        cout << "Tanggal baru: ";
        getline(cin, konser[index].tanggal);

        cout << "Tempat baru: ";
        getline(cin, konser[index].tempat);

        cout << "Harga baru: ";
        cin >> konser[index].harga;

        cout << "Stok baru: ";
        cin >> konser[index].stok;

        setColor(10);
        cout << "Data berhasil diubah!\n";
    }
    else
    {
        setColor(12);
        cout << "ID tidak ditemukan!\n";
    }
    setColor(7);
}

void registerUser(User *users, int *jumlahUser)
{
    cout << "\n=== REGISTER ===\n";
    cout << "Username: ";
    cin >> users[*jumlahUser].username;

    cout << "Password: ";
    cin >> users[*jumlahUser].nim;

    users[*jumlahUser].role = "pelanggan";
    (*jumlahUser)++;
}

int loginUser(User *users, int jumlahUser)
{
    string username, nim;

    cout << "== LOGIN ==\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> nim;

    for (int i = 0; i < jumlahUser; i++)
    {
        if (users[i].username == username && users[i].nim == nim)
            return i;
    }

    throw invalid_argument("Login gagal: username atau password salah");
}

void beliTiket(User *users, Konser *konser, Tiket *tiket, int *jumlahTiket, int jumlahKonser, int indexUser)
{
    try
    {
        tampilKonser(konser, jumlahKonser);

        int id, jumlah;
        cout << "ID: ";
        cin >> id;
        cout << "Jumlah: ";
        cin >> jumlah;

        if (jumlah <= 0)
            throw invalid_argument("Jumlah harus lebih dari 0");

        int index = binarySearchID(konser, jumlahKonser, id);

        if (index == -1)
            throw invalid_argument("ID konser tidak valid");

        if (jumlah > konser[index].stok)
            throw invalid_argument("Stok tidak cukup!");

        tiket[*jumlahTiket].idTiket = *jumlahTiket + 1;
        tiket[*jumlahTiket].pembeli = users[indexUser].username;
        tiket[*jumlahTiket].konser = konser[index];
        tiket[*jumlahTiket].jumlah = jumlah;
        tiket[*jumlahTiket].totalHarga = jumlah * konser[index].harga;

        konser[index].stok -= jumlah;
        tampilHarga(konser[index].harga, jumlah);

        (*jumlahTiket)++;

        setColor(10);
        cout << "Tiket berhasil dibeli!\n";
        setColor(7);
    }
    catch (const exception &e)
    {
        setColor(12);
        cout << "Input tidak valid: " << e.what() << endl;
        setColor(7);
        cin.clear();
    }
}

void lihatPesanan(Tiket *tiket, int jumlahTiket, string username)
{
    cout << "\n===== PESANAN =====\n";

    for (int i = 0; i < jumlahTiket; i++)
    {
        if (tiket[i].pembeli == username)
        {
            cout << "Konser: " << tiket[i].konser.nama << endl;
            cout << "Jumlah: " << tiket[i].jumlah << endl;
            cout << "Total: " << tiket[i].totalHarga << endl;
            cout << "----------------\n";
        }
    }
}

void menuAdmin(Konser *konser, int *jumlahKonser)
{
    int menu;
    do
    {
        header();
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Tambah Konser\n2. Lihat Konser\n3. Ubah Konser\n4. Hapus Konser\n5. Keluar\nPilih: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tambahKonser(konser, jumlahKonser);
            break;
        case 2:
            tampilKonser(konser, *jumlahKonser);
            break;
        case 3:
            ubahKonser(konser, *jumlahKonser);
            break;
        case 4:
            hapusKonser(konser, jumlahKonser);
            break;
        }
    } while (menu != 5);
}

void menuPelanggan(User *users, Konser *konser, Tiket *tiket, int *jumlahTiket, int jumlahKonser, int indexUser)
{
    int menu;
    do
    {
        cout << "\n===== MENU PELANGGAN =====\n";
        cout << "1. Beli Tiket\n";
        cout << "2. Lihat Pesanan\n";
        cout << "3. Cari Nama Konser\n";
        cout << "4. Cari ID Konser\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            beliTiket(users, konser, tiket, jumlahTiket, jumlahKonser, indexUser);
            break;
        case 2:
            lihatPesanan(tiket, *jumlahTiket, users[indexUser].username);
            break;
        case 3:
        {
            string nama;
            cin.ignore();
            cout << "Nama: ";
            getline(cin, nama);
            cariNamaKonser(konser, jumlahKonser, nama);
            break;
        }
        case 4:
        {
            int id;
            cout << "ID: ";
            cin >> id;
            int i = binarySearchID(konser, jumlahKonser, id);
            if (i != -1)
                tampilHarga(konser[i].harga);
            else
                cout << "Tidak ditemukan\n";
        }
        }

    } while (menu != 5);
}

int main()
{
    User users[100];
    Konser konser[100];
    Tiket tiket[100];

    int jumlahUser = 1, jumlahKonser = 0, jumlahTiket = 0;

    users[0] = {"aswad", "118", "admin"};

    int menu;
    do
    {
        header();
        cout << "1. Register\n2. Login\n3. Keluar\nPilih: ";
        cin >> menu;

        if (menu == 1)

            registerUser(users, &jumlahUser);
        else if (menu == 2)
        {
            int idx = loginUser(users, jumlahUser);

            if (idx != -1)
            {
                if (users[idx].role == "admin")
                    menuAdmin(konser, &jumlahKonser);
                else
                    menuPelanggan(users, konser, tiket, &jumlahTiket, jumlahKonser, idx);
            }
            else
            {
                setColor(12);
                cout << "Login gagal\n";
                setColor(7);
            }
        }

    } while (menu != 3);

    return 0;
}