#include <iostream>
using namespace std;

class bit
{
public:
    void swap(int &a, int &b);        // 1
    int occurs_once(int *arr, int n); // 2
    int XOR_1toN(int N);              // 3
    int XOR_LtoR(int l, int r);       // 4
    int countSetBits(int n)
    {
        int count = 0;
        while (n)
        {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
    string XOR(string a, string b, int n)
    {
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            // If the Character matches
            if (a[i] == b[i])
                ans += "0";
            else
                ans += "1";
        }
        return ans;
    }
    bool check_odd(int n)
    {
        if (n & 1)
        {
            return true;
        }
        else
            return false;
    }
    bool check_ith_bit_set_or_not(int n, int i)
    {
        int mask = 1 << i;
        return n & mask ? true : false;
    }
    int extract_ith_bit(int n, int i)
    {
        int mask = 1 << i;
        return ((n & 1) >> i);
    }
    void set_ith_bit(int &n, int i)
    {
        n = n | (1 << i);
    }
    void clear_ith_bit(int &n, int i)
    {
        int mask = ~(1 << i);
        n = n & mask;
    }
    void remove_last_set_bit(int &n)
    {
        n = n & (n - 1);
    }
    bool isPowerOf2(int n)
    {
        return n & (n - 1) == 0 ? true : false;
    }
    int count_1s(int n)
    {
        // this can also be stated as count the number of set bits (set bit = 1)
        // method 1: TC: O(no.of set bits)
        int cnt = 0;
        while (n != 0)
        {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
        // method 2: TC: O(total no.of bits in n)
        //  while(n!=0){
        //      if(n&1){
        //          cnt++;
        //      }
        //      n = n>>1;
        //  }
        //  return cnt;
    }
};

// Function(1): swap two numbers without using 3rd variable
void bit ::swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

/* Function(2): In an array, one element occurs once, rest occurs twice, find that one element
   Eg: arr[n] = {3,5,3,5,2,7,1,2,7,8} then ans will be 8 */
int bit ::occurs_once(int *arr, int n)
{
    int ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int bit::XOR_1toN(int N)
{
    if (N % 4 == 0)
    {
        return N;
    }
    else if (N % 4 == 1)
    {
        return 1;
    }
    else if (N % 4 == 2)
    {
        return N + 1;
    }
    else if (N % 4 == 3)
    {
        return 0;
    }
}

int bit::XOR_LtoR(int L, int R)
{
    return (XOR_1toN(L - 1) ^ XOR_1toN(R));
}

class test : public bit
{
public:
    void Test()
    {
        int arr[5] = {1, 1, 2, 2, 3};
        int a = 5;
        int b = 7;
        swap(a, b);
        cout << a << " " << b << endl;
        int ans = occurs_once(arr, 5);
        cout << ans << endl;
        int rs = XOR_1toN(13);
        cout << rs << "\n";
    }
};

int main()
{
    test t;
    t.Test();
    return 0;
}
