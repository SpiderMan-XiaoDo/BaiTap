#include <iostream>
using namespace std;


void nhap_mang(int n, int A[]){
    for (int i =0; i<n; i++){
        cin>>A[i];
    }
}

int thaydoi(int start, int end, int A[], int condition){
    int count = 0;
    for (int i=start; i<=end; i++){
        if (A[i]== condition){
            count ++;
        }
    }
    return count;
}

int max_den_xanh(int start, int end, int n, int A[]){
    int count1 = thaydoi(0, start-1, A, 1);
    int count2 = 0;
    if (end < n-1){
        count2 = thaydoi(end+1, n, A,1);
    }
    return count1 + count2;
}

int dan_den(int n, int k, int A[]){
    int l =0;
    int r = k-1;

    int max_l = 0;
    int max_r = k-1;

    int max_thaydoi = thaydoi(l, r, A, 0);
    for (int i = 0; i< n-k; i++){
        int gt_thaydoi = thaydoi(l, r, A, 0);
        if (max_thaydoi < gt_thaydoi){
            max_l = l;
            max_r = r;
            max_thaydoi = gt_thaydoi;
        }
        if (max_thaydoi == k){
            break;
        }
        l++;
        r++;
    }
    return max_thaydoi + max_den_xanh(max_l, max_r, n, A);
}


int main(){
    int n, k;
    cin>>n >> k;
    int a[n];
    nhap_mang(n, a);

    cout<< dan_den(n, k, a);


    return 0;
}