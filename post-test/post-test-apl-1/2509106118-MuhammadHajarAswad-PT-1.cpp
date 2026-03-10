#include <iostream>
using namespace std;

int main()
{
    int coba_login = 0;
    string username, password;

    while (coba_login < 3)
    {
        cout << "===== LOGIN PROGRAM =====" << endl;
        cout << "masukkan username : " << endl;
        cin >> username;
        cout << "masukkan password : " << endl;
        cin >> password;

        if (username == "aswad" && password == "118")
        {
            cout << "login berhasil" << endl;
            break;
        }
        else
        {
            cout << "login gagal" << endl;
            coba_login++;
        }
    }
    if (coba_login == 3)
    {
        cout << "anda telah mencoba login 3 kali, program berhenti" << endl;
        return 0;
    }

    int pilihan_konversi;
    double meter, kilometer, centimeter, nilai;

    do
    {
        cout << "===== KONVERSI PANJANG =====" << endl;
        cout << "1. Meter -> Kilometer dan Centimeter" << endl;
        cout << "2. Kilometer -> Meter dan Centimeter" << endl;
        cout << "3. Centimeter -> Meter dan Kilometer" << endl;
        cout << "4. Keluar Program" << endl;
        cout << "Pilih opsi konversi (1-4): ";
        cin >> pilihan_konversi;

        switch (pilihan_konversi)
        {
        case 1:
            cout << "Masukkan nilai dalam meter: ";
            cin >> nilai;
            kilometer = nilai / 1000;
            centimeter = nilai * 100;
            cout << "Hasil: " << kilometer << " km dan " << centimeter << " cm" << endl;
            break;

        case 2:
            cout << "Masukkan nilai dalam kilometer: ";
            cin >> nilai;
            meter = nilai * 1000;
            centimeter = nilai * 100000;
            cout << "Hasil: " << meter << " m dan " << centimeter << " cm" << endl;
            break;

        case 3:
            cout << "Masukkan nilai dalam centimeter: ";
            cin >> nilai;
            meter = nilai / 100;
            kilometer = nilai / 100000;
            cout << "Hasil: " << meter << " m dan " << kilometer << " km" << endl;
            break;

        case 4:
            cout << "Anda telah keluar dari program" << endl;
            break;
        }
    } while (pilihan_konversi != 4);
    return 0;
}