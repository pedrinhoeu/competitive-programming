#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

template<typename T, int N> struct matrix {
    array<array<T, N>, N> a{};

    matrix operator * (const matrix &o) const {
        matrix ans;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) {
            ans.a[i][j] += a[i][k] * o.a[k][j];
        }
        return ans;
    }

    matrix operator ^ (ll e) const {
        matrix ans, self(*this);
        for (int i = 0; i < N; i++) ans.a[i][i] = 1;
        while (e > 0) {
            if (e & 1) ans = ans * self;
            self = self * self;
            e >>= 1;
        }
        return ans;
    }

    vector<T> operator * (const vector<T> &o) const {
        vector<T> ans(N);
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            ans[i] += a[i][j] * o[j];
        }
        return ans;
    }
};

int main() {
    matrix<int, 2> fib;
    fib.a = {{ {{1, 1}}, {{1, 0}} }};
    vector<int> aux = { 1, 1 };
    
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << "-th term of fibonacci is ";
        cout << ((fib ^ i) * aux)[0] << endl;
    }
}

