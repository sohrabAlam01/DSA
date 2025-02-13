

/////Find the sum of n fibonacci numbers///



#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Edge cases
    if (n == 1) {
        cout << 0;
        return 0;
    }
    else if (n == 2) {
        cout << 1; // Sum of first 2 Fibonacci numbers: 0 + 1 = 1
        return 0;
    }

    int first = 0;
    int second = 1;
    long long sum = first + second; // Sum initialized to 0 + 1 = 1

    int i = 3; // Since 2 numbers (0 and 1) are already summed up, we are on the third one

    while (i <= n) {
        int next = first + second;
        sum += next;
        first = second;
        second = next;
        i++;
    }

    cout << sum;
    return 0;
}