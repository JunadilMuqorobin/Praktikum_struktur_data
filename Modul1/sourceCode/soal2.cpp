#include <iostream>
#include <string>
using namespace std;

string satuan(int n) {
    switch(n) {
        case 0: return "nol";
        case 1: return "satu";
        case 2: return "dua";
        case 3: return "tiga";
        case 4: return "empat";
        case 5: return "lima";
        case 6: return "enam";
        case 7: return "tujuh";
        case 8: return "delapan";
        case 9: return "sembilan";
    }
    return "";
}

string konversi(int n) {
    if (n < 0 || n > 100) return "Input di luar 0-100";
    if (n == 100) return "seratus";
    if (n < 10) return satuan(n);
    if (n == 10) return "sepuluh";
    if (n == 11) return "sebelas";
    if (n < 20) {
        return satuan(n % 10) + " belas";
    }
    int puluhan = n / 10;
    int sisa = n % 10;
    string hasil = satuan(puluhan) + " puluh";
    if (sisa != 0) hasil += " " + satuan(sisa);
    return hasil;
}

int main() {
    int x;
    cout << "Input bilangan bulat 0-100 : ";
    if (!(cin >> x)) {
        cout << "Input tidak valid\n";
        return 1;
    }
    cout << x << " : " << konversi(x) << '\n';
    return 0;
}
