#include<bits/stdc++.h>
using namespace std;

struct U {
    char c;
    string codeword;
    int n;
    double p;

    U() {}
    U(char c, double p) : c(c), p(p) {
        n = ceil(-log2(p));
    }

    bool operator<(const U &other) const {
        return p < other.p;
    } 
    bool operator>(const U &other) const {
        return p > other.p;
    }
};

string converter(double dec, int n, string str  = "") {
    if(n == 0) {
        return str;
    }
    else {
        dec *= 2;
        if(dec >= 1) return converter(dec - 1, n - 1, str += "1");
        else return converter(dec, n - 1, str += "0");
    }
}

int main() {
    vector<U> u;
    vector<double> f;
    unordered_map<string, char> key;
    string source;
    getline(cin, source);

    int l = source.length();
    unordered_map<char, int> freq;
    for(char c : source) {
        freq[c]++;
    }

    int n = freq.size();
    cout << n << endl;
    f.reserve(n);
    u.reserve(n);
    for(pair<char, int> wf : freq) {
        u.push_back(U(wf.first, (double) wf.second / l));
    }
    sort(u.begin(), u.end(), greater<U>());

    f[0] = 0;
    u[0].codeword = u[0].p < 1 ? converter(f[0], u[0].n) : "0";
    for(int i = 1; i < n; i++) {
        f[i] = f[i - 1] + u[i - 1].p;
        u[i].codeword = converter(f[i], u[i].n);
    }

    cout << setw(8) << "U" << setw(12) << "P" << setw(12) << "F" << setw(5) << "n" << setw(12) << "Ma\n";
    for (unsigned int i = 0; i < n; i++)
        { 
            if(u[i].c == L' ') cout << setw(8) << "<space>" << setw(12) << u[i].p << setw(12) << f[i] << setw(5) << u[i].n << setw(12) << u[i].codeword << endl;
            else cout << setw(8) << u[i].c << setw(12) << u[i].p << setw(12) << f[i] << setw(5) << u[i].n << setw(12) << u[i].codeword << endl;
            key[u[i].codeword] = u[i].c;
        }

    string encrypted = "";
    for(char c : source) {
        for(U x : u) {
            if(x.c == c) {
                encrypted += x.codeword;
                break;
            }
        }
    }
    cout << encrypted << endl;

    string decrypted = "";
    string word = "";
    for(char bit : encrypted) {
        word += bit;
        if(key[word]) {
            decrypted += key[word];
            word = "";
        }
    }
    cout << decrypted << endl;
}