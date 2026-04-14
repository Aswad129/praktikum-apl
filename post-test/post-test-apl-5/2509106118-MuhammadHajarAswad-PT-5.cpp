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

void sortNamaDescending(Konser *konser, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (konser[j].nama < konser[j + 1].nama)
                swap(konser[j], konser[j + 1]);
}

void sortHargaAscending(Konser *konser, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (konser[j].harga < konser[min].harga)
                min = j;

        swap(konser[i], konser[min]);
    }
}

int partition(Konser *konser, int low, int high)
{
    int pivot = konser[high].stok;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (konser[j].stok > pivot)
        {
            i++;
            swap(konser[i], konser[j]);
        }
    }
    swap(konser[i + 1], konser[high]);
    return i + 1;
}

void quickSort(Konser *konser, int low, int high)
{
    if (low < high)
    {
        int pi = partition(konser, low, high);
        quickSort(konser, low, pi - 1);
        quickSort(konser, pi + 1, high);
    }
}

void tampilHarga(int harga)
{
    cout << "Harga: Rp " << harga << endl;
}

void tampilHarga(int harga, int jumlah)
{
    cout << "Total Harga: Rp " << harga * jumlah << endl;
}

void registerUser(User *users, int *jumlahUser)
{
    cout << "\n=== REGISTER ===\n";
    cout << "Username: ";
    cin >> users[*jumlahUser].username;

    cout << "NIM (Password): ";
    cin >> users[*jumlahUser].nim;

    users[*jumlahUser].role = "pelanggan";
    (*jumlahUser)++;

    cout << "Registrasi berhasil!\n";
}

int loginUser(User *users, int jumlahUser)
{
    string username, nim;

    cout << "\n=== LOGIN ===\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> nim;

    for (int i = 0; i < jumlahUser; i++)
    {
        if (users[i].username == username && users[i].nim == nim)
            return i;
    }

    return -1;
}

void lihatKonser(Konser *konser, int jumlahKonser)
{
    int pilih;

    cout << "\n1. Tanpa Sorting\n";
    cout << "2. Nama Descending\n";
    cout << "3. Harga Ascending\n";
    cout << "4. Stok Descending\n";
    cout << "Pilih: ";
    cin >> pilih;

    if (pilih == 2)
        sortNamaDescending(konser, jumlahKonser);
    else if (pilih == 3)
        sortHargaAscending(konser, jumlahKonser);
    else if (pilih == 4)
        quickSort(konser, 0, jumlahKonser - 1);

    cout << "\n=================================== DAFTAR KONSER ===================================\n";

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
        cout << left << setw(5) << konser[i].id
             << setw(20) << konser[i].nama
             << setw(15) << konser[i].jenis
             << setw(15) << konser[i].tanggal
             << setw(15) << konser[i].tempat
             << setw(12) << konser[i].harga
             << setw(8) << konser[i].stok
             << endl;
    }
}

void tambahKonser(Konser *konser, int *jumlahKonser)
{
    konser[*jumlahKonser].id = *jumlahKonser + 1;

    cout << "Nama konser: ";
    cin.ignore();
    getline(cin, konser[*jumlahKonser].nama);

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
    cout << "Konser berhasil ditambahkan\n";
}

void ubahKonser(Konser *konser, int jumlahKonser)
{
    int id;
    lihatKonser(konser, jumlahKonser);

    cout << "Masukkan ID konser: ";
    cin >> id;

    for (int i = 0; i < jumlahKonser; i++)
    {
        if (konser[i].id == id)
        {
            cout << "Nama baru: ";
            cin.ignore();
            getline(cin, konser[i].nama);

            cout << "Jenis baru: ";
            getline(cin, konser[i].jenis);

            cout << "Tanggal baru: ";
            getline(cin, konser[i].tanggal);

            cout << "Tempat baru: ";
            getline(cin, konser[i].tempat);

            cout << "Harga baru: ";
            cin >> konser[i].harga;

            cout << "Stok baru: ";
            cin >> konser[i].stok;

            cout << "Data berhasil diubah\n";
        }
    }
}

void hapusKonser(Konser *konser, int *jumlahKonser)
{
    int id;
    lihatKonser(konser, *jumlahKonser);

    cout << "Masukkan ID konser: ";
    cin >> id;

    for (int i = 0; i < *jumlahKonser; i++)
    {
        if (konser[i].id == id)
        {
            for (int j = i; j < *jumlahKonser - 1; j++)
                konser[j] = konser[j + 1];

            (*jumlahKonser)--;

            cout << "Konser berhasil dihapus\n";
            break;
        }
    }
}

void menuAdmin(Konser *konser, int *jumlahKonser)
{
    int menu = 0;

    do
    {
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Tambah Konser\n";
        cout << "2. Lihat Konser\n";
        cout << "3. Ubah Konser\n";
        cout << "4. Hapus Konser\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tambahKonser(konser, jumlahKonser);
            break;
        case 2:
            lihatKonser(konser, *jumlahKonser);
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

void beliTiket(User *users, Konser *konser, Tiket *tiket, int *jumlahTiket, int jumlahKonser, int indexUser)
{
    lihatKonser(konser, jumlahKonser);

    int id, jumlah;

    cout << "ID konser: ";
    cin >> id;

    cout << "Jumlah tiket: ";
    cin >> jumlah;

    for (int i = 0; i < jumlahKonser; i++)
    {
        if (konser[i].id == id)
        {
            if (jumlah > konser[i].stok)
                cout << "Stok tidak cukup\n";
            else
            {
                tiket[*jumlahTiket].idTiket = *jumlahTiket + 1;
                tiket[*jumlahTiket].pembeli = users[indexUser].username;
                tiket[*jumlahTiket].konser = konser[i];
                tiket[*jumlahTiket].jumlah = jumlah;
                tiket[*jumlahTiket].totalHarga = jumlah * konser[i].harga;

                konser[i].stok -= jumlah;

                tampilHarga(konser[i].harga, jumlah);

                (*jumlahTiket)++;

                cout << "Pembelian berhasil\n";
            }
        }
    }
}

void menuPelanggan(User *users, Konser *konser, Tiket *tiket, int *jumlahTiket, int jumlahKonser, int indexUser)
{
    int menu = 0;

    do
    {
        cout << "\n===== MENU PELANGGAN =====\n";
        cout << "1. Beli Tiket\n";
        cout << "2. Lihat Pesanan\n";
        cout << "3. Keluar\n";
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
        }

    } while (menu != 3);
}

int main()
{
    User users[100];
    Konser konser[100];
    Tiket tiket[100];

    int jumlahUser = 1;
    int jumlahKonser = 0;
    int jumlahTiket = 0;

    int percobaanLogin = 0;

    users[0].username = "aswad";
    users[0].nim = "118";
    users[0].role = "admin";

    int menu = 0;

    do
    {
        cout << "\n===== APLIKASI PENJUALAN TIKET KONSER =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            registerUser(users, &jumlahUser);
            break;

        case 2:
        {
            int indexUser = loginUser(users, jumlahUser);

            if (indexUser != -1)
            {
                percobaanLogin = 0;

                if (users[indexUser].role == "admin")
                    menuAdmin(konser, &jumlahKonser);
                else
                    menuPelanggan(users, konser, tiket, &jumlahTiket, jumlahKonser, indexUser);
            }
            else
            {
                percobaanLogin++;
                cout << "Login gagal!" << endl;

                if (percobaanLogin == 3)
                {
                    cout << "Program berhenti.\n";
                    return 0;
                }
            }

            break;
        }
        }

    } while (menu != 3);

    return 0;
}