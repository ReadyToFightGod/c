#include<iostream>
#include<vector>
#include <array>

template <size_t N>
constexpr int nth_prime(){
	int skolko = 0;
	std::array<int, N> primes{};
	for (int i = 2; skolko != N; i++){
			bool is_prime = true;
			for (int j = 0; j < skolko; j++){
				if(i%primes[j] == 0){
					is_prime = false;
					break;
				}
			}
			if (is_prime){
				primes[skolko++] = i;
			}
	}
	return primes[N-1];
}

int main(){
	constexpr auto x = nth_prime<5>();
	std::cout << x << std::endl;
	return 0;
}