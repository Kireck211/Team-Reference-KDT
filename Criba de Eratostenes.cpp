#include <iostream>
#include <vector>

using namespace std;

vector<bool> primos(int n) {
	vector<bool> primos;
	int m = sqrt(n);

	for (int i = 1; i < n; i++) {
		primos.push_back(1);
	}

	primos[0] = 0;
	primos[1] = 0;

	for (int i = 2; i <= m; i++) {
		if (primos[i]) {
			for (int j = i * i; j <= n; j += i) {
				primos[j] = 0;
			}
		}
	}

	return primos;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<bool> primes;

	primes = primos(20);
	int j = 0;
	for (int i = 0; i < 20; i++) {
		if (primes[i]) {
			cout<<i<<" ";
			i++;
		}
	}

	return 0;
}

// Made by Rogelio Miguel Hernández Sandoval 