/*
# Running Time and Complexity

## Task
A prime is a natural number greater than 1 that has no positive divisors other than 1 and itself. Given a number, n, determine and print whether it is Prime or Not prime.

Note: If possible, try to come up with a O(sqrt(n)) primality algorithm, or see what sort of optimizations you come up with for an O(n) algorithm.

## Input Format

The first line contains an integer, T, the number of test cases.
Each of the T subsequent lines contains an integer, n, to be tested for primality.

## Constraints

1 <= T <= 30
1 <= n <= 2x10^9

## Output Format

For each test case, print whether n is Prime or Not prime on a new line.

## Sample Input

3
12
5
7

## Sample Output

Not prime
Prime
Prime

Explanation

Test Case 0: n = 12.
12 is divisible by numbers other than 1 and itself (i.e.: 2, 3, 4, 6), so we print Not prime on a new line.

Test Case 1: n = 5.
5 is only divisible by 1 and itself, so we print Prime on a new line.

Test Case 2: n = 7.
7 is only divisible by 1 and itself, so we print Prime on a new line.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    
    for (int i=0; i<T; ++i) {
        int n;
        cin >> n;
        
        if (n<=1) { cout << "Not prime\n"; continue; }
        if (n==2) { cout << "Prime\n"; continue; }
        
        int maxdiv = sqrt(n);
        bool fail = false;
        for (int j=2; j<=maxdiv; ++j) {
            if (n%j == 0) {
                cout << "Not prime\n";
                fail = true;
                break;
            }
        }
        if (!fail) { cout << "Prime\n"; }
    }
    return 0;
}
