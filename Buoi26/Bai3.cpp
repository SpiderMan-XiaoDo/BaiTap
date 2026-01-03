#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Hàm nhập mảng
void nhap_mang(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
}

// Hàm đếm tần suất xuất hiện của các khối lượng sản phẩm
void dem_tan_suat(int n, int A[], int counts[]) {
    for (int i = 0; i < n; i++) {
        counts[A[i]]++;
    }
}

// Hàm giải quyết trường hợp k = 1
int giai_quyet_k1(int counts[]) {
    int max_kients = 0;
    for (int i = 1; i <= 1000; i++) {
        max_kients = max(max_kients, counts[i]);
    }
    return max_kients;
}

// Hàm giải quyết trường hợp k = 2
int giai_quyet_k2(int counts[]) {
    int max_kients = 0;
    // Tổng khối lượng S có thể từ 2 đến 2000
    for (int S = 2; S <= 2000; S++) {
        int current_kients = 0;
        for (int i = 1; i <= S / 2; i++) {
            int j = S - i;
            if (j > 1000 || j < 1) continue;
            if (i == j) {
                current_kients += counts[i] / 2;
            } else {
                current_kients += min(counts[i], counts[j]);
            }
        }
        max_kients = max(max_kients, current_kients);
    }
    return max_kients;
}


int main() {
    int n, k;
    cin >> n >> k;

    int A[100005];
    int counts[1001] = {0};

    nhap_mang(n, A);
    dem_tan_suat(n, A, counts);

    for (int i =0; i<=10; i++){
        cout<< counts[i];

    }
    if (k == 1) {
        cout << giai_quyet_k1(counts) << endl;
    } else if (k == 2) {
        cout << giai_quyet_k2(counts) << endl;
    } else if (k == 3) {
    }

    return 0;
}