//basic hack pack
//works on CF, CC not on hackerrank
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

g++ -O2 -std=c++17 -Wall -Wl,--stack=268435456 solution.cpp -o solution.exe

/*TAKE CARE:
1. GCD(__gcd) does not work for (x, 0)
2. Never use equal sign in compare function
3. IN MODULAR SUBTRACTION use ((a - b) + mod) % mod;
4. VECTOR ERASE takes O(n) time even if we delete first element so 
   for n elements time = O(n^2)
5. For doing Upper_bound on Sets/Multiset set.upper_bound(x) is faster than 
   upper_bound(set.begin(), set.end(), x);
6. String size's are always unsigned ints so if you subtract 2 string size's and
   get a negative value i.e let tmp = a.size() - b.size() and b.size() > a.size()
   then you will get garbage values
*/

//FUNCTIONS
//1.fast power function 
ll binX(ll a, ll b) {
    if(!a)
        return 0;

    ll res = 1;
    while(b) {

        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

//for mod_inverse
ll mod_inverse(ll num){
    return binX(num, mod - 2) % mod;
}

//for ceil function of a / b use (a + b - 1) / b
//for number of digits
dig = log10(n) + 1;//DOES NOT WORK FOR N = 0

//2. factorial
ll factorial(ll n)
{
   if(n == 0)
   {
      return 1;
   }

   return n * factorial(n - 1);
}


//choose
ll choose(ll n, ll r){
    if(r > n){
        return 0;
    }

    ll fact[n + 1];
    fact[0] = 1;
    for(ll i = 1; i <= n; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    return (fact[n] * mod_inverse((fact[r] * fact[n - r]) % mod)) % mod;
}

//XOR from 1 to n 
ll xor_till(ll n){
    ll tmp = n % 4;

    if(tmp == 0){
        return n;
    }
    else if(tmp == 1){
        return 1;
    }
    else if(tmp == 2){
        return n + 1;
    }
    else{
        return 0;
    }
}

ll gcd(ll a, ll b) {
    if(b > a) 
        swap(a, b);

    if(!b) 
        return a; 

    return gcd(b, a % b);
}

//Ordered Set
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
// find_by_order, order_of_key
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;