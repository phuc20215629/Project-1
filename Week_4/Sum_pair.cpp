/*
Description
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu
Dòng 1: ghi n và M (1 <= n, M <= 1000000)
Dòng 2: ghi a1, a2, ..., an
Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, M;
    cin >> n >> M;

    unordered_map<int, int> freqMap;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        freqMap[num]++;
    }

    for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
        int x = it->first;
        int y = M - x;
        if (freqMap.find(y) != freqMap.end() && x != y) {
            count++;
        }
    }

    cout << count / 2 << endl;

    return 0;
}