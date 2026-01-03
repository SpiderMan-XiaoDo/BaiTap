#include <iostream>
#include <math.h>

using namespace std;
bool isPrime(int n) {
    if (n < 2){
        return false;
    }
    else if (n == 2){
        return true;
    }
    else{
        for (int i = 2; i <= (sqrt(n)); i++){
            if (n % i == 0){
                return false;
            }
        }
    }
    return true;
}

int tim_tat_ca_snt_nho_hon_n(int n, int snt[]){
    int index_snt = 0;
    for (int i =2; i<=n/2; i++){
        if (isPrime(i) == true){
            snt[index_snt] = i;
            index_snt++;
        }
    }
    return index_snt;
}

void xuat_snt(int length, int snt[] ){
    for (int i =0; i< length; i++){
        cout << snt[i]<<endl;
    }
}

int dem_snt(int length, int snt[], int n){
    int count =0;
    for (int i = 0; i < length-1; i++){
        for (int j = i+1; j< length; j++){
            if (snt[i] * snt[j] <= n){
                count++;
            }
            else{
                break;
            }
        }
        if (snt[i] * snt[i+1] > n){
            break;
        }
    }
    return count;
}

int main(){

    int n;
    cout << "Nhap N: ";
    cin>> n;
    // Số lượng số nguyên tố p * q <= n sẽ có lớn nhất: n/2
    int snt[n/2] = {0};

    int length_snt = tim_tat_ca_snt_nho_hon_n(n, snt);
    cout<< "\n-----------------------------------------\n";
    cout<< "So luong cac so nguyen to: " <<endl;
    // xuat_snt(length_snt, snt);
    cout<< "-----------------------------------------\n";

    cout<<"So luong dem duoc: "<< dem_snt(length_snt, snt, n);
    return 0;
}