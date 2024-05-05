#include <type_traits>
#include <iostream>

typedef unsigned long long ull;

template <ull P, ull N = P - 1>
struct is_prime : std::integral_constant<bool, std::conditional_t<((P % N) > 0), is_prime<P, N - 1>, std::false_type> {}> {};

template<ull P>
struct is_prime<P, 2> : std::integral_constant<bool, std::conditional_t<(P % 2 > 0), std::true_type, std::false_type> {}> {};

template<>
struct is_prime<1> : std::integral_constant<bool, false> {};

template<ull N, ull K = 1>
struct nth_prime : std::integral_constant<ull, std::conditional_t< (is_prime<K>::value),
                                                nth_prime<N - 1, K + 1>, nth_prime<N, K + 1> 
                                               >{}
                                         >{};

template<ull K>
struct nth_prime<0, K> : std::integral_constant<ull, K - 1> {};

template<>
struct nth_prime<0, 1> : std::integral_constant<ull, 2> {};

int main() {
    std::cout << 2 << "=" << nth_prime<0>{} << std::endl;
    std::cout << 3 << "=" << nth_prime<1>{} << std::endl;
    std::cout << 5 << "=" << nth_prime<2>{} << std::endl;
    std::cout << 7 << "=" << nth_prime<3>{} << std::endl;
    std::cout << 11 << "=" << nth_prime<4>{} << std::endl;
    std::cout << 13 << "=" << nth_prime<5>{} << std::endl;
    std::cout << 17 << "=" << nth_prime<6>{} << std::endl;
    std::cout << 19 << "=" << nth_prime<7>{} << std::endl;
    std::cout << 23 << "=" << nth_prime<8>{} << std::endl;
    std::cout << 29 << "=" << nth_prime<9>{} << std::endl;

    std::cout << 97 << "=" << nth_prime<24>{} << std::endl;

    std::cout << 137 << "=" << nth_prime<32>{} << std::endl;

    std::cout << 367 << "=" << nth_prime<72>{} << std::endl;


    return 0;
}
