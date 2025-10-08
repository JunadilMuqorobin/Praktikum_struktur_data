#include <iostream>
using namespace std;

int main() {
    int N;

    cout << "Masukkan jumlah elemen array (maks 100): ";
    cin >> N;

    int arr[100];      
    int *ptr = arr;    

    cout << "\nMasukkan " << N << " bilangan bulat:\n";
    for (int i = 0; i < N; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> *(ptr + i);
    }

    int jumlah = 0;
    int maksimum = *ptr;
    int minimum = *ptr;

    for (int i = 0; i < N; i++) {
        int nilai = *(ptr + i);
        jumlah += nilai;
        if (nilai > maksimum) maksimum = nilai;
        if (nilai < minimum) minimum = nilai;
    }

    cout << "\n=== HASIL PERHITUNGAN ===\n";
    cout << "Jumlah seluruh bilangan : " << jumlah << endl;
    cout << "Nilai maksimum          : " << maksimum << endl;
    cout << "Nilai minimum           : " << minimum << endl;

    return 0;
}
