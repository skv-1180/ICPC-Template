vector<bool> isPrime;

void sieve(int sz){
    isPrime.assign(sz+1,true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= sz; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= sz; j += i)
                isPrime[j] = false;
        }
    }
}