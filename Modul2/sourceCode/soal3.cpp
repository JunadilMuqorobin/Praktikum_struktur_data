#include <iostream>
using namespace std;


float hitungRataRata(int nilai[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += nilai[i];
    }
    return (float) total / n;
}

void cariNilaiTertinggiTerendah(int nilai[], int n, int &maks, int &min) {
    maks = nilai[0];
    min = nilai[0];
    for (int i = 1; i < n; i++) {
        if (nilai[i] > maks) maks = nilai[i];
        if (nilai[i] < min) min = nilai[i];
    }
}

int main() {
    int N;
    cout << "Masukkan jumlah siswa: ";
    cin >> N;

    int nilai[N]; 

    cout << "\nMasukkan nilai ujian untuk " << N << " siswa:\n";
    for (int i = 0; i < N; i++) {
        cout << "Nilai siswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    float rataRata = hitungRataRata(nilai, N);
    int maks, min;
    cariNilaiTertinggiTerendah(nilai, N, maks, min);

    cout << "\n===== HASIL PERHITUNGAN =====\n";
    cout << "Rata-rata kelas : " << rataRata << endl;
    cout << "Nilai tertinggi : " << maks << endl;
    cout << "Nilai terendah  : " << min << endl;

    return 0;
}
