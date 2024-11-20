
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;

void sieveOfEratosthenes(int limit) {
    // Step 1: Create a boolean array to represent primality of numbers
    vector<bool> isPrime(limit + 1, true);

    // Step 2: Mark 0 and 1 as non-prime
    isPrime[0] = isPrime[1] = false;

    // Step 3: Sieve algorithm
    int upperLimit = sqrt(limit);
    for (int i = 2; i <= upperLimit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Step 4: Count primes (optional: display some if needed)
    int primeCount = 0;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            ++primeCount;
        }
    }

    // Output results
    cout << "Number of primes up to " << limit << ": " << primeCount << endl;
}

int main() {
    const int LIMIT = 1000000; // Find all primes up to 1,000,000

    // Measure runtime
    chrono::time_point<chrono::system_clock> start, end;
    chrono::duration<float> elapsed;

    start = chrono::system_clock::now(); // Start timing
    sieveOfEratosthenes(LIMIT);
    end = chrono::system_clock::now(); // End timing

    elapsed = end - start;

    cout << "Time to find all prime numbers up to " << LIMIT << ": "
        << elapsed.count() << " seconds" << endl;

    return 0;
}

