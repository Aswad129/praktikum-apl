// #include <iostream>
// using namespace std;
// // Fungsi ditaruh sebelum main
// int kuadrat(int x) {
// return x * x;
// }

// // Prosedur ditulis sebelum main
// void sapa(string nama) {
// cout < "Halo, " < nama < "!" < endl;
// }

// int main() {
// sapa("Budi");
// cout << "Hasil 5 kuadrat: " << kuadrat(5) << endl;
// return 0;
// }

// #include <iostream>
// using namespace std;

// // prosedur ini menerima nilai dari variable gajiSaya
// void cobaUbahGaji(int gajiSaya) {
// gajiSaya = 1000000000; // gaji di dalam prosedur
// cout << "Gaji pas di dalam fungsi: " << gajiSaya << endl;
// }

// int main() {
// int gajiSaya = 5000000; // gaji di dalam main

// cout << "Gaji awal: " << gajiSaya << endl;

// cobaUbahGaji(gajiSaya); // kirim ke fungsi

// cout << "Gaji setelah fungsi dipanggil: " << gajiSaya << endl;

// return 0;
// }

// #include <iostream>
// using namespace std;

// / perhatikan tanda '&' di sebelah parameter
// void tukarsenjata(string &senjata) {
// senjata = "Sarung Wadimor"; / langsung ganti isi variabel
// aslinya
// }

// int main() {
// string senjatahero = "Kayu Busuk";

// cout < "Senjata awal: " < senjatahero < endl;

// tukarsenjata(senjatahero); / panggil prosedur

// / variable dalam main akan ikut terubah
// cout < "Senjata sekarang: " < senjatahero < endl;

// return 0;
// }