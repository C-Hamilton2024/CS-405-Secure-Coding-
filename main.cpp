// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <stdexcept>

// Custom exception class derived from std::exception
class CustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Custom exception occurred";
    }
};

bool do_even_more_custom_application_logic()
{
    std::cout << "Running Even More Custom Application Logic." << std::endl;

    // Throwing a standard exception
    throw std::runtime_error("Standard exception thrown in do_even_more_custom_application_logic");

    return true; // This line will never be executed due to the throw above
}

void do_custom_application_logic()
{
    std::cout << "Running Custom Application Logic." << std::endl;

    try {
        // Wrapping the call to do_even_more_custom_application_logic with an exception handler
        if(do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    } catch (const std::exception& e) {
        // Catching std::exception and displaying a message and the exception.what()
        std::cerr << "Exception caught in do_custom_application_logic: " << e.what() << std::endl;
    }

    // Throwing a custom exception after handling the previous logic
    throw CustomException();

    // This line will never be executed due to the throw above
    // std::cout << "Leaving Custom Application Logic." << std::endl;
}

float divide(float num, float den)
{
    // Throwing an exception to deal with divide by zero errors
    if (den == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return (num / den);
}

void do_division() noexcept
{
    float numerator = 10.0f;
    float denominator = 0;

    try {
        // Capturing only the exception thrown by divide
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        // Handling the divide by zero error
        std::cerr << "Exception caught in do_division: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    try {
        do_division();
        do_custom_application_logic();
    } catch (const CustomException& e) {
        // Catching custom exception
        std::cerr << "CustomException caught in main: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Catching std::exception
        std::cerr << "std::exception caught in main: " << e.what() << std::endl;
    } catch (...) {
        // Catching any uncaught exceptions
        std::cerr << "An unknown exception caught in main" << std::endl;
    }

    return 0;
}
