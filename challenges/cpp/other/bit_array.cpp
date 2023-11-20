/*
# Bit Array

You are given four integers: N, S, P, Q. You will use them in order to create the sequence a
with the following pseudo-code.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31)

Your task is to calculate the number of distinct integers in the sequence a.

## Input Format

Four space separated integers on a single line, N, S, P, and Q respectively.

## Output Format

A single integer that denotes the number of distinct integers in the sequence a.

## Constraints

1 <= N <= 10^8
0 <= S, P, Q < 2^31

## Sample Input

3 1 1 1

## Sample Output

3

## Explanation

a = [1, 2, 3]
Hence, there are 3 different integers in the sequence.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

constexpr long long valmax = 1LL<<31;
constexpr long long modmax = valmax - 1;

int main() {
    long long n = 0;
    long long s = 0;
    long long p = 0;
    long long q = 0;
    cin >> n;
    cin >> s;
    cin >> p;
    cin >> q;

    bitset<valmax> *bs;
    bs = (bitset<valmax> *)malloc(sizeof(bitset<valmax>));

    bs->set(s % valmax);
    for (int i=1; i<n; ++i) {
        s = (s*p+q) & modmax;
        bs->set(s);
    }

    cout << bs->count() << "\n";

    free(bs);

    return 0;
}
