#include <iostream>
#include <iomanip>
using namespace std;

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

int main()
{

    User users[100];
    Konser konser[100];
    Tiket tiket[100];

    int jumlahUser = 1;
    int jumlahKonser = 0;
    int jumlahTiket = 0;

    int menuAwal;

    users[0].username = "aswad";
    users[0].nim = "118";
    users[0].role = "admin";

    do
    {

        cout << "\n===== APLIKASI PENJUALAN TIKET KONSER =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menuAwal;

        if (menuAwal < 1 || menuAwal > 3)
        {
            cout << "Pilihan tidak valid!\n";
            continue;
        }

        switch (menuAwal)
        {

        case 1:

            cout << "\n=== REGISTER PELANGGAN ===\n";
            cout << "Username : ";
            cin >> users[jumlahUser].username;

            cout << "NIM (Password) : ";
            cin >> users[jumlahUser].nim;

            users[jumlahUser].role = "pelanggan";

            jumlahUser++;

            cout << "Registrasi berhasil!\n";
            break;

        case 2:
        {

            string username, nim;
            int percobaanLogin = 0;
            int indexUser = -1;

            while (percobaanLogin < 3)
            {

                cout << "\n=== LOGIN ===\n";
                cout << "Username : ";
                cin >> username;

                cout << "NIM : ";
                cin >> nim;

                for (int i = 0; i < jumlahUser; i++)
                {
                    if (users[i].username == username && users[i].nim == nim)
                    {
                        indexUser = i;
                        break;
                    }
                }

                if (indexUser != -1)
                {
                    cout << "Login berhasil!\n";
                    break;
                }
                else
                {
                    cout << "Login gagal!\n";
                    percobaanLogin++;
                }
            }

            if (percobaanLogin == 3)
            {
                cout << "Login gagal 3 kali. Program berhenti.\n";
                return 0;
            }

            if (users[indexUser].role == "admin")
            {

                int menuAdmin;

                do
                {

                    cout << "\n===== MENU ADMIN =====\n";
                    cout << "1. Tambah Konser\n";
                    cout << "2. Lihat Konser\n";
                    cout << "3. Ubah Konser\n";
                    cout << "4. Hapus Konser\n";
                    cout << "5. Keluar\n";
                    cout << "Pilih menu: ";
                    cin >> menuAdmin;

                    if (menuAdmin < 1 || menuAdmin > 5)
                    {
                        cout << "Pilihan tidak valid!\n";
                        continue;
                    }

                    switch (menuAdmin)
                    {

                    case 1:

                        konser[jumlahKonser].id = jumlahKonser + 1;

                        cout << "Nama konser : ";
                        cin.ignore();
                        getline(cin, konser[jumlahKonser].nama);

                        cout << "Jenis konser : ";
                        getline(cin, konser[jumlahKonser].jenis);

                        cout << "Tanggal konser : ";
                        getline(cin, konser[jumlahKonser].tanggal);

                        cout << "Tempat konser : ";
                        getline(cin, konser[jumlahKonser].tempat);

                        cout << "Harga tiket : ";
                        cin >> konser[jumlahKonser].harga;

                        cout << "Stok tiket : ";
                        cin >> konser[jumlahKonser].stok;

                        jumlahKonser++;

                        cout << "Konser berhasil ditambahkan!\n";
                        break;

                    case 2:

                        cout << "\n==================== DAFTAR KONSER ====================\n";
                        cout << left
                             << setw(5) << "ID"
                             << setw(20) << "Nama"
                             << setw(15) << "Jenis"
                             << setw(15) << "Tanggal"
                             << setw(15) << "Tempat"
                             << setw(15) << "Harga"
                             << setw(10) << "Stok" << endl;

                        for (int i = 0; i < jumlahKonser; i++)
                        {

                            int ribu = konser[i].harga / 1000;
                            int sisa = konser[i].harga % 1000;

                            cout << left
                                 << setw(5) << konser[i].id
                                 << setw(20) << konser[i].nama
                                 << setw(15) << konser[i].jenis
                                 << setw(15) << konser[i].tanggal
                                 << setw(15) << konser[i].tempat;

                            cout << "Rp " << ribu << ".";
                            if (sisa < 100)
                                cout << "0";
                            if (sisa < 10)
                                cout << "0";
                            cout << sisa;

                            cout << setw(8) << " ";
                            cout << konser[i].stok << endl;
                        }

                        break;

                    case 3:
                    {

                        cout << "\n==================== DAFTAR KONSER ====================\n";
                        cout << left
                             << setw(5) << "ID"
                             << setw(20) << "Nama"
                             << setw(15) << "Jenis"
                             << setw(15) << "Tanggal"
                             << setw(15) << "Tempat"
                             << setw(15) << "Harga"
                             << setw(10) << "Stok" << endl;

                        for (int i = 0; i < jumlahKonser; i++)
                        {

                            int ribu = konser[i].harga / 1000;
                            int sisa = konser[i].harga % 1000;

                            cout << left
                                 << setw(5) << konser[i].id
                                 << setw(20) << konser[i].nama
                                 << setw(15) << konser[i].jenis
                                 << setw(15) << konser[i].tanggal
                                 << setw(15) << konser[i].tempat;

                            cout << "Rp " << ribu << ".";
                            if (sisa < 100)
                                cout << "0";
                            if (sisa < 10)
                                cout << "0";
                            cout << sisa;

                            cout << setw(8) << " ";
                            cout << konser[i].stok << endl;
                        }

                        int id;
                        cout << "\nMasukkan ID konser yang ingin diubah : ";
                        cin >> id;

                        for (int i = 0; i < jumlahKonser; i++)
                        {

                            if (konser[i].id == id)
                            {

                                cout << "Nama baru : ";
                                cin.ignore();
                                getline(cin, konser[i].nama);

                                cout << "Jenis baru : ";
                                getline(cin, konser[i].jenis);

                                cout << "Tanggal baru : ";
                                getline(cin, konser[i].tanggal);

                                cout << "Tempat baru : ";
                                getline(cin, konser[i].tempat);

                                cout << "Harga baru : ";
                                cin >> konser[i].harga;

                                cout << "Stok baru : ";
                                cin >> konser[i].stok;

                                cout << "Data berhasil diupdate!\n";
                            }
                        }

                        break;
                    }

                    case 4:
                    {

                        cout << "\n==================== DAFTAR KONSER ====================\n";
                        cout << left
                             << setw(5) << "ID"
                             << setw(20) << "Nama"
                             << setw(15) << "Jenis"
                             << setw(15) << "Tanggal"
                             << setw(15) << "Tempat"
                             << setw(15) << "Harga"
                             << setw(10) << "Stok" << endl;

                        for (int i = 0; i < jumlahKonser; i++)
                        {

                            int ribu = konser[i].harga / 1000;
                            int sisa = konser[i].harga % 1000;

                            cout << left
                                 << setw(5) << konser[i].id
                                 << setw(20) << konser[i].nama
                                 << setw(15) << konser[i].jenis
                                 << setw(15) << konser[i].tanggal
                                 << setw(15) << konser[i].tempat;

                            cout << "Rp " << ribu << ".";
                            if (sisa < 100)
                                cout << "0";
                            if (sisa < 10)
                                cout << "0";
                            cout << sisa;

                            cout << setw(8) << " ";
                            cout << konser[i].stok << endl;
                        }

                        int idHapus;

                        cout << "\nMasukkan ID konser yang ingin dihapus : ";
                        cin >> idHapus;

                        for (int i = 0; i < jumlahKonser; i++)
                        {

                            if (konser[i].id == idHapus)
                            {

                                for (int j = i; j < jumlahKonser - 1; j++)
                                {
                                    konser[j] = konser[j + 1];
                                }

                                jumlahKonser--;

                                cout << "Data berhasil dihapus!\n";
                                break;
                            }
                        }

                        break;
                    }
                    }

                } while (menuAdmin != 5);
            }

            else if (users[indexUser].role == "pelanggan")
            {

                int menuPelanggan;

                do
                {

                    cout << "\n===== MENU PELANGGAN =====\n";
                    cout << "1. Beli Tiket dan Lihat Daftar Konser\n";
                    cout << "2. Lihat Pesanan\n";
                    cout << "3. Keluar\n";
                    cout << "Pilih menu: ";
                    cin >> menuPelanggan;

                    if (menuPelanggan < 1 || menuPelanggan > 3)
                    {
                        cout << "Pilihan tidak valid!\n";
                        continue;
                    }

                    switch (menuPelanggan)
                    {

                    case 1:
                    {

                        cout << "\n==================== DAFTAR KONSER ====================\n";
                        cout << left
                             << setw(5) << "ID"
                             << setw(20) << "Nama"
                             << setw(15) << "Jenis"
                             << setw(15) << "Tanggal"
                             << setw(15) << "Tempat"
                             << setw(15) << "Harga"
                             << setw(10) << "Stok" << endl;

                        for (int i = 0; i < jumlahKonser; i++)
                        {

                            int ribu = konser[i].harga / 1000;
                            int sisa = konser[i].harga % 1000;

                            cout << left
                                 << setw(5) << konser[i].id
                                 << setw(20) << konser[i].nama
                                 << setw(15) << konser[i].jenis
                                 << setw(15) << konser[i].tanggal
                                 << setw(15) << konser[i].tempat;

                            cout << "Rp " << ribu << ".";
                            if (sisa < 100)
                                cout << "0";
                            if (sisa < 10)
                                cout << "0";
                            cout << sisa;

                            cout << setw(8) << " ";
                            cout << konser[i].stok << endl;
                        }

                        int idBeli, jumlahBeli;

                        cout << "\nMasukkan ID konser : ";
                        cin >> idBeli;

                        for (int i = 0; i < jumlahKonser; i++)
                        {

                            if (konser[i].id == idBeli)
                            {

                                cout << "Jumlah tiket : ";
                                cin >> jumlahBeli;

                                if (jumlahBeli > konser[i].stok)
                                {
                                    cout << "Stok tidak cukup!\n";
                                }
                                else
                                {

                                    tiket[jumlahTiket].idTiket = jumlahTiket + 1;
                                    tiket[jumlahTiket].pembeli = users[indexUser].username;
                                    tiket[jumlahTiket].konser = konser[i];
                                    tiket[jumlahTiket].jumlah = jumlahBeli;
                                    tiket[jumlahTiket].totalHarga = jumlahBeli * konser[i].harga;

                                    jumlahTiket++;

                                    konser[i].stok -= jumlahBeli;

                                    cout << "Pembelian berhasil!\n";
                                }
                            }
                        }

                        break;
                    }

                    case 2:

                        cout << "\n===== PESANAN SAYA =====\n";

                        for (int i = 0; i < jumlahTiket; i++)
                        {

                            if (tiket[i].pembeli == users[indexUser].username)
                            {

                                int ribu = tiket[i].totalHarga / 1000;
                                int sisa = tiket[i].totalHarga % 1000;

                                cout << "ID Tiket : " << tiket[i].idTiket << endl;
                                cout << "Konser : " << tiket[i].konser.nama << endl;
                                cout << "Jumlah : " << tiket[i].jumlah << endl;

                                cout << "Total Harga : Rp " << ribu << ".";
                                if (sisa < 100)
                                    cout << "0";
                                if (sisa < 10)
                                    cout << "0";
                                cout << sisa << endl;

                                cout << "----------------------\n";
                            }
                        }

                        break;
                    }

                } while (menuPelanggan != 3);
            }

            break;
        }
        }

    } while (menuAwal != 3);

    return 0;
}