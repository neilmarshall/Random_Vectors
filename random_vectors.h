#include <algorithm>
#include <chrono>
#include <random>
#include <type_traits>
#include <vector>

template<typename T>
std::vector<T> get_random_numbers(const T& lower_bound,
    const T& upper_bound, const std::size_t& count) {

    static_assert(std::is_integral<T>::value,
        "Function must be called with an integral data type");

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine engine = std::default_random_engine(seed);
    std::uniform_int_distribution<T> distribution = std::uniform_int_distribution<T>(lower_bound, upper_bound);

    auto RNG = [&](){return lower_bound + distribution(engine) % (upper_bound - lower_bound);};

    std::vector<T> random_numbers(count);
    std::generate(std::begin(random_numbers), std::end(random_numbers), RNG);

    return random_numbers;
};

template<typename T>
std::vector<T> get_random_numbers(const T& upper_bound, const std::size_t& count) {
    return get_random_numbers(static_cast<T>(0), upper_bound, count);
};

template<typename T = int>
std::vector<T> get_random_numbers(const std::size_t& count) {
    return get_random_numbers(static_cast<T>(0), std::numeric_limits<T>::max(), count);
};
