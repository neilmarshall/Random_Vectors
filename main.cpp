/*
    Example program demonstrating use of functions from the 'random_vectors' library
*/

#include "random_vectors.h"

#include <iostream>
#include <vector>

int main() {

    std::size_t count = 15;

    std::cout << "Random integers of type 'unsigned short' between 0 and 20:\n";
    std::vector<unsigned short> vec1 = get_random_numbers(static_cast<unsigned short>(20), count);
    for (auto n : vec1) std::cout << n << " ";
    std::cout << '\n' << std::endl;

    std::cout << "Random integers of type 'long' between 10 and 20:\n";
    std::vector<long> vec2 = get_random_numbers(10L, 20L, count);
    for (auto n : vec2) std::cout << n << " ";
    std::cout << '\n' << std::endl;

    std::cout << "Random integers of type 'unsigned long long' between 0 and maximum value:\n";
    std::vector<unsigned long long> vec3 = get_random_numbers<unsigned long long>(count);
    for (auto n : vec3) std::cout << n << " ";
    std::cout << std::endl;
}
