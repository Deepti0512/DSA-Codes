// problem link : https://www.codechef.com/problems/XORPROD?tab=solution
/* Given an array A, in one move you can choose x,y ∈ A, delete them, and add x⊕y to A.
   Maximize the product of A.
   Hints and explaination:
   A little analysis of how the operation affects the product of all the elements should tell you that it’s almost never optimal to replace two elements.
   In fact, it’s optimal to replace x and y with x xor y if and only if x = 1 and y is even
   reason: This can be seen somewhat intuitively by looking at just two elements.
   Let x≤y, and we want to decide whether to operate on x and y or not.
   First, note that we have x⊕y<2y, which should both be obvious to see by looking at the bits independently.
    Now,
    If we don’t operate on x and y, we contribute xy to the product.
    If we do operate on them, we contribute x⊕y<2y to the product.
In particular, if xy≥2y, i.e, x≥2, then it’s always better to not perform the operation.
This forces x=1.
Now we have to decide which y give us 1⊕y > 1⋅y = y. Note that:

If y is even, 1⊕y=y+1
If y is odd, 1⊕y=y−1
This tells us that x=1 and y being even is the only optimal case to perform an operation on two elements.

It’s somewhat reasonable to expect this to hold when we need to perform more than one move, but a lot less obvious why: after all, 
the order of moves matters, and maybe we want to perform one ‘bad’ move to be able to get to a ‘good’ one later.
It so happens that this is never the case. A slightly more detailed proof is attached below if you’re interested.
Let B = [B1,B2,...,Bk] be the final array, after we have performed some operations. 
Note that Bi = Ai1 xor Ai2 xor Ai3 ... Air for some indices i1,i2,..ir.
Let's call each Aij a component of Bi. 
Suppose there exists a Bi such that it has at least two components that are >= 2 .w.l.o.g. let Ai1 >= 2.
Then, we can instead perform operations so that we end up with Bi xor Ai1 and Ai1 instead of just Bi;
and this gives us a strictly higher product.
So, an optimal solution will never have such a Bi.
Now suppose some Bi has >= 2 components (which doesn't change its xor) and keep 
those ones as two more separate components: this doesn’t affect the product.
So, there exists an optimal solution in which each Bi has at most one 1, and at most one value >= 2.
Now consider Bi = 1 xor y where y >= 2.
As we noted above, if y is odd it's better to have y and 1 seperately.
So, an optimal solution can only have Bi that are either single elements, or 1 xor y for even y.
This completes the proof.
With this information in hand, let’s now get to actually solving the problem.

We can simply simulate the process: as long as we have at least one 11 and one even number remaining, perform an operation on them.
All that remains is to decide which even number to operate on at each step. This is simple: choose the smallest remaining even number.
Why? --> Note that choosing x = 1 and even y, which means we're removing 
1*y from the product and multiplying it by y+1 instead. So, our product is multiplied by (y+1)/y.
(y+1)/y is larger the smaller y is, so it's optimal to choose the smallest y we can (while ensuing it's even)
 
Implementing this is fairly straightforward: count the number of 11's in the sequence, then sort the even numbers and keep choosing the smallest
one of them to operate on while there are remaining 11's.
Note that operating on an even number turns it into an odd number so the list doesn’t need to be updated.
Time complexity: O(NlogN)
*/
#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

int main() {
    //freopen("inp4.in", "r", stdin);
    //freopen("out4.out", "w", stdout);
    int t;
    cin >> t;
    assert(t > 0 && t < 50000);
    while(t--) {
        int n;
        cin >> n;
        assert(n > 0 && n <= 100000);
        long long int a[n];
        int ones = 0;
        priority_queue<long long int> pq;
        long long int ans = 1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            assert(a[i] > 0 && a[i] <= 1000000000);
            if(a[i]&1) {
                if(a[i] == 1) ones++;
                ans *= a[i];
                ans %= mod;
            } else pq.push(-a[i]);
        }
        while(ones && !pq.empty()) {
            int top = -pq.top();
            pq.pop();
            ones--;
            ans *= (top + 1);
            ans %= mod;
        }
        while(!pq.empty()) {
            ans *= (-pq.top());
            pq.pop();
            ans %= mod;
        }
        cout << ans << "\n";
    }
}