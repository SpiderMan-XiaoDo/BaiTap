#include <iostream>
using namespace std;

const int MAXT = 105;
const int MAXB = 10005;
const int MOD = 1000000;

int T, A, S, B;
int C[MAXT];
int dp[MAXB], new_dp[MAXB], prefix[MAXB];

int main() {
    cin >> T >> A >> S >> B;

    // Đếm số lượng mỗi loại
    for (int i = 1; i <= A; i++) {
        int x;
        cin >> x;
        C[x]++;
    }

    // Khởi tạo
    dp[0] = 1;
    for (int j = 1; j <= B; j++) dp[j] = 0;
    // DP
    for (int i = 1; i <= T; i++) {
        // prefix sum
        prefix[0] = dp[0];
        for (int j = 1; j <= B; j++) {
            prefix[j] = (prefix[j-1] + dp[j]) % MOD;
        }

        // tính dp mới
        for (int j = 0; j <= B; j++) {
            if (j - C[i] - 1 >= 0) {
                new_dp[j] = prefix[j] - prefix[j - C[i] - 1];
            } else {
                new_dp[j] = prefix[j];
            }

            // xử lý mod
            new_dp[j] %= MOD;
            if (new_dp[j] < 0) new_dp[j] += MOD;
        }

        // copy lại
        for (int j = 0; j <= B; j++) {
            dp[j] = new_dp[j];
        }
    }

    // tính kết quả
    int result = 0;
    for (int j = S; j <= B; j++) {
        result = (result + dp[j]) % MOD;
    }

    cout << result;

    return 0;
}