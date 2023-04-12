#include <mutex>
#include <thread>
#include <iostream>

std::mutex global_mutex; // Declare a global mutex
int global_value = 0; // Declare a global variable to be protected by the mutex

void increment_global_value()
{
    for (int i = 0; i < 10000000; ++i)
    {
        global_mutex.lock(); // Acquire the mutex
        ++global_value; // Increment the global variable
        global_mutex.unlock(); // Release the mutex
    }
}

int main()
{
    std::thread t1(increment_global_value); // Create thread 1
    std::thread t2(increment_global_value); // Create thread 2

    t1.join(); // Wait for thread 1 to finish
    t2.join(); // Wait for thread 2 to finish

    std::cout << "Global value: " << global_value << std::endl; // Print the final value of global_value

    return 0;
}
