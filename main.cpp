#include <iostream>
#include <limits>
#include <typeinfo>

// Template function to add numbers with overflow detection
template <typename T>
bool add_numbers(T const& start, T const& increment, unsigned long int const& steps, T& result)
{
    result = start;

    for (unsigned long int i = 0; i < steps; ++i)
    {
        // Check for overflow
        if (result > std::numeric_limits<T>::max() - increment)
        {
            return false; // Overflow detected
        }
        result += increment;
    }

    return true; // No overflow detected
}

// Template function to subtract numbers with underflow detection
template <typename T>
bool subtract_numbers(T const& start, T const& decrement, unsigned long int const& steps, T& result)
{
    result = start;

    for (unsigned long int i = 0; i < steps; ++i)
    {
        // Check for underflow
        if (result < std::numeric_limits<T>::min() + decrement)
        {
            return false; // Underflow detected
        }
        result -= decrement;
    }

    return true; // No underflow detected
}

// Test function for overflow
template <typename T>
void test_overflow()
{
    const unsigned long int steps = 5;
    const T increment = std::numeric_limits<T>::max() / steps;
    const T start = 0;

    std::cout << "Overflow Test of Type = " << typeid(T).name() << std::endl;

    std::cout << "\tAdding Numbers Without Overflow (" << +start << ", " << +increment << ", " << steps << ") = ";
    T result;
    bool overflow = add_numbers<T>(start, increment, steps, result);
    std::cout << +result << " (Overflow: " << (overflow ? "false" : "true") << ")" << std::endl;

    std::cout << "\tAdding Numbers With Overflow (" << +start << ", " << +increment << ", " << (steps + 1) << ") = ";
    overflow = add_numbers<T>(start, increment, steps + 1, result);
    std::cout << +result << " (Overflow: " << (overflow ? "false" : "true") << ")" << std::endl;
}

// Test function for underflow
template <typename T>
void test_underflow()
{
    const unsigned long int steps = 5;
    const T decrement = std::numeric_limits<T>::max() / steps;
    const T start = std::numeric_limits<T>::max();

    std::cout << "Underflow Test of Type = " << typeid(T).name() << std::endl;

    std::cout << "\tSubtracting Numbers Without Underflow (" << +start << ", " << +decrement << ", " << steps << ") = ";
    T result;
    bool underflow = subtract_numbers<T>(start, decrement, steps, result);
    std::cout << +result << " (Underflow: " << (underflow ? "false" : "true") << ")" << std::endl;

    std::cout << "\tSubtracting Numbers With Underflow (" << +start << ", " << +decrement << ", " << (steps + 1) << ") = ";
    underflow = subtract_numbers<T>(start, decrement, steps + 1, result);
    std::cout << +result << " (Underflow: " << (underflow ? "false" : "true") << ")" << std::endl;
}

// Function to run overflow tests
void do_overflow_tests(const std::string& star_line)
{
    std::cout << std::endl << star_line << std::endl;
    std::cout << "*** Running Overflow Tests ***" << std::endl;
    std::cout << star_line << std::endl;

    test_overflow<char>();
    test_overflow<wchar_t>();
    test_overflow<short int>();
    test_overflow<int>();
    test_overflow<long>();
    test_overflow<long long>();
    test_overflow<unsigned char>();
    test_overflow<unsigned short int>();
    test_overflow<unsigned int>();
    test_overflow<unsigned long>();
    test_overflow<unsigned long long>();
    test_overflow<float>();
    test_overflow<double>();
    test_overflow<long double>();
}

// Function to run underflow tests
void do_underflow_tests(const std::string& star_line)
{
    std::cout << std::endl << star_line << std::endl;
    std::cout << "*** Running Underflow Tests ***" << std::endl;
    std::cout << star_line << std::endl;

    test_underflow<char>();
    test_underflow<wchar_t>();
    test_underflow<short int>();
    test_underflow<int>();
    test_underflow<long>();
    test_underflow<long long>();
    test_underflow<unsigned char>();
    test_underflow<unsigned short int>();
    test_underflow<unsigned int>();
    test_underflow<unsigned long>();
    test_underflow<unsigned long long>();
    test_underflow<float>();
    test_underflow<double>();
    test_underflow<long double>();
}

// Entry point into the application
int main()
{
    const std::string star_line = std::string(50, '*');

    std::cout << "Starting Numeric Underflow / Overflow Tests!" << std::endl;

    do_overflow_tests(star_line);
    do_underflow_tests(star_line);

    std::cout << std::endl << "All Numeric Underflow / Overflow Tests Complete!" << std::endl;

    return 0;
}
