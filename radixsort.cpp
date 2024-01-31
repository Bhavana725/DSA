#include <iostream>
#include <algorithm>


using namespace std;


int main() {
    const int base = 10;
    int a[50], n;
    
    cout << "Enter array size: " << endl;
    cin >> n;


    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }


    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[50];
        int count[base] = {0};


        for (int i = 0; i < n; i++) {
            count[(a[i] / exp) % base]++;
        }


        for (int i = 1; i < base; i++) {
            count[i] += count[i - 1];
        }


        for (int i = n - 1; i >= 0; i--) {
            output[count[(a[i] / exp) % base] - 1] = a[i];
            count[(a[i] / exp) % base]--;
        }


        for (int i = 0; i < n; i++) {
            a[i] = output[i];
        }
    }


    cout << "Sorted array using Radix Sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }


    return 0;
}