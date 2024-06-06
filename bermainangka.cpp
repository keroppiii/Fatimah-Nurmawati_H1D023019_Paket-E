#include <iostream>
#include <algorithm>
using namespace std;

// Fungsi untuk memeriksa apakah bilangan adalah prima
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true; 
}
// Fungsi untuk mencari nilai di array menggunakan linear search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i; // kalau ada x di array, maka indeksnya dikembalikan
    }
    return -1; 
}

int main() {
    int n, m;
    cin >> n >> m;

    int array_A[n];
    int array_B[m];

    // Input array A
    for (int i = 0; i < n; i++) {
        cin >> array_A[i];
    }

    // Input array B
    for (int i = 0; i < m; i++) {
        cin >> array_B[i]; 
    }

    int results[n + m]; // Array untuk menyimpan hasil
    int result_count = 0; // Counter untuk jumlah hasil

    // Cari nilai yang memenuhi syarat
    for (int i = 0; i < n; i++) {
        if (isPrime(array_A[i]) && linearSearch(array_B, m, array_A[i]) != -1) {
            results[result_count++] = array_A[i]; //elemen yang memenuhi syarat akan disimpan ke results
        }
    }

    // Urutkan hasil pencarian
    sort(results, results + result_count); 

    // Cetak hasil pencarian
    if (result_count == 0) {
        cout << "TIDAK ADA" << endl; //cetak "TIDAK ADA" kalau hasil tidak sesuai
    } else {
        for (int i = 0; i < result_count; i++) {
            cout << results[i] << " "; // Cetak setiap elemen yang memenuhi syarat
        }
        cout << endl;
    }
    return 0;
}