#include <bitset>
ll _sieve_size;
bitset<10000010> bs;
vi primes;
// compact STL for Sieve, better than vector<bool>!
// ll is defined as: typedef long long ll;
// 10^7 should be enough for most cases
// compact list of primes in form of vector<int>
void sieve(ll upperbound) {
// create list of primes in [0..upperbound]
_sieve_size
sieve size = upperbound + 1;
// add 1 to include upperbound
bs.set();
// set all bits to 1
bs[0] = bs[1] = 0;
// except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
primes.push_back((int)i);
// add this prime to the list of primes
} }
// call this method in main method
bool isPrime(ll N) {
// a good enough deterministic prime tester
_sieve_size)
_
return bs[N];
// O(1) for small primes
if (N <= _
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true;
// it takes longer time if N is a large prime!
}
// note:
t
only
l work
k f
for N <=
< (last
(l t prime
i
i
in vi
i "primes")^2