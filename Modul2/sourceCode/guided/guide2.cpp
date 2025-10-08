#include <iostream>
#define MAX 5

using namespace std;

int main() {
    int i, j;
    float nilai[MAX]; // ARRAY 1 DIMENSI
    static int nilai_tahun[MAX][MAX] = {
        {0,2,2,0,0},
        {0,1,1,1,0},
        {0,3,3,3,0},
        {0,4,0,0,4},
        {5,0,0,0,5}
    };

    //INPUT DATA ARRAY 1 DIMENSI
    cout << "\n=== Data Nilai Siswa ===\n";
    for ( i = 0; i < MAX; i++)
    {
        cout << "Masukkan nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    //MENAMPILKAN ISI ARRAY 1 DIMENSI
    cout << "\n=== Data Nilai Siswa ===\n";
    for ( i = 0; i < MAX; i++)
    {
        cout << "Nilai ke-" << i + 1 << " = " << nilai[i] << endl;
    }

    //MENAMPILKAN ISI ARRAY 2 DIMENSI
    cout << "\n=== Nilai Tahunan ===\n";
    for ( i = 0; i < MAX; i++){
        for (j = 0; j < MAX; j++){
            cout << nilai_tahun[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
