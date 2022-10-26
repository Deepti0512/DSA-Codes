// Program to findsmallest power of 2 greater than or equal to n
#include <bits/stdc++.h>
using namespace std;

// TC : O(logn)
unsigned int _nextPowerOf2(unsigned int n)
{
	unsigned count = 0;
	
	// First n in the below condition is for the case where n is 0
	if (n && !(n & (n - 1)))
		return n;
	
	while( n != 0)
	{
		n >>= 1;
		count += 1;
	}
	
	return 1 << count;
}

// TC: O(logn)
unsigned int nextPowerOf2_(unsigned int n)
{
    unsigned int p = 1;
    if (n && !(n & (n - 1)))
        return n;
 
    while (p < n)
        p <<= 1;
     
    return p;
}
// TC: O(logn)
unsigned int NextPowerOf2(unsigned int n) 
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}
// TC: O(1)
long long nextPowerOf_2(long long N)
{
    // if N is a power of two simply return it
    if (!(N & (N - 1)))
        return N;
    // else set only the left bit of most significant bit
    return 0x8000000000000000 >> (__builtin_clzll(N) - 1);
}


int main()
{
	unsigned int n = 0;
    long long ans = nextPowerOf_2(1052);
	cout << ans;
	return 0;
}

