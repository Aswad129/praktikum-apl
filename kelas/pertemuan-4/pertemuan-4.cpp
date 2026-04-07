// // #include<iostream>
// // using namespace std;

// // int main(){
// //     string var = "Aku Variabel";
// //     string* varPtr = &var;

// //     cout << "Hasil dari varPtr (Alamat): " << varPtr << endl;
// //     cout << "Hasil dari *varPtr (Nilai): " << *varPtr << endl;
// //     cout << endl << "Kesimpulannya varPtr isi nya alamatnya var" << endl;
// //     cout << "*varPtr hasilnya value dari var" << endl;
// //     cout << endl;
// //     cout << "Hasil/value dari var: " << var << endl;
// //     cout << "Hasil/value dari alamat var (&var): " << &var << endl;
// //     cout << "Hasil/value dari varPtr: " << varPtr << endl;
// //     cout << "Hasil/value dari *varPtr: " << *varPtr << endl;
// //     return 0;
// // }

// #include<iostream>
// using namespace std;

// int main(){
//     cout << "Pointer yang menunjuk ke suatu array" << endl;
//     int a[5] = {1, 2, 3, 4, 5};
//     int (*aPtr)[5] = &a;
//     for(int i = 0; i < 5; i++){
//         cout << *aPtr << endl;
//     }

//     cout << "\nPointer yang menunjuk ke arah elemen array" << endl;
//     int b[5] = {1, 2, 3, 4, 5};
//     int *bPtr = b;
//     for(int i = 0; i < 5; i++){
//         cout << "Alamat: " << bPtr << " | Nilai: " << *bPtr << endl;
//         bPtr++;
//     }

// }