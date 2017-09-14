#include <iostream>
#include <chrono>

long long pow1(int n, int k) {
    long long result = 1;
    long long last = n;
    for(int i = (k & 1); k != 0; k >>= 1, i = (k & 1)) {
        if (i) {
            result *= last;
        }
        last *= last;
    }
    return result;
}

long long pow2(int n, int k) {
    long long result = 1;
    for (int i = 0; i < k; ++i) {
        result *= n;
    }
    return result;
}

int main() {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
    long long r1 = 0, r2 = 0;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        r1 = pow1(2, 300);
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<
        std::chrono::microseconds>(stop - start).count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        r2 = pow2(2, 300);
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<
        std::chrono::microseconds>(stop - start).count() << std::endl;

    if (r1 == r2) {
        std::cout << "success" << std::endl;
    }
}
