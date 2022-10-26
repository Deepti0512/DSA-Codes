// Program to find highest power of 2 smaller than or equal to n.
#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
int highestPowerof2(unsigned int n)
{
	// Invalid input
	if (n < 1)
		return 0;
	int res = 1;
	// Try all powers starting from 2^1
	for (int i = 0; i < 8 * sizeof(unsigned int); i++) {
		int curr = 1 << i;
		// If current power is more than n, break
		if (curr > n)
			break;
		res = curr;
	}
	return res;
}

// TC: O(logn)
int highestPowerof2(int n)
{
   int p = (int)log2(n);
   return (int)pow(2, p);
}

//TC:O(1)
unsigned HighestPowerof2(unsigned x)
{
    // check for the set bits
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
 
    // Then we remove all but the top bit by xor'ing the
    // string of 1's with that string of 1's shifted one to
    // the left, and we end up with just the one top bit
    // followed by 0's.
    return x ^ (x >> 1);
}

//TC: O(1)
long long highestPowerof2(long long N)
{
    // if N is a power of two simply return it
    if (!(N & (N - 1)))
        return N;
    // else set only the most significant bit
    return 0x8000000000000000 >> (__builtin_clzll(N));
}

int main()
{
	int n = 1052;
	cout << highestPowerof2(n);
	return 0;
}
