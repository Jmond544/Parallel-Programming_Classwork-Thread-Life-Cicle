#include <thread>
#include <chrono>
#include <cstdio>

// Global variable to control the chopping loop in vegetable_chopper function
bool chopping = true;

// Function representing the vegetable chopping task for each worker
void vegetable_chopper(const char* name) {
    unsigned int vegetable_count = 0;
    // Continue chopping vegetables until chopping is set to false
    while (chopping) {
        vegetable_count++;
    }
    // Print the number of vegetables chopped by the worker
    printf("%s chopped %u vegetables.\n", name, vegetable_count);
    // Sleep for 10 seconds to simulate additional work after chopping
    std::this_thread::sleep_for(std::chrono::seconds(10));
}

int main() {
    // Create two threads, Olivia and Barron, to perform vegetable chopping
    std::thread olivia(vegetable_chopper, "Olivia");
    std::thread barron(vegetable_chopper, "Barron");
   
    // Print a message indicating that Barron and Olivia are chopping vegetables
    printf("Barron and Olivia are chopping vegetables...\n");

    // Check if threads are joinable before calling join()
    printf("Is Barron joinable? %s\n", barron.joinable() ? "true" : "false");
    printf("Is Olivia joinable? %s\n", olivia.joinable() ? "true" : "false");

    // Detach threads, allowing them to continue execution independently
    barron.detach();
    olivia.detach();

    // Print whether threads are joinable after detachment
    printf("Is Barron joinable? %s\n", barron.joinable() ? "true" : "false");
    printf("Is Olivia joinable? %s\n", olivia.joinable() ? "true" : "false");

    // Allow threads to continue running in the background

    // To give detached threads time to execute the vegetable_chopper function
    printf("Barron and Olivia are possibly still chopping vegetables...\n");
    
    // Note: Threads are still running, but the main program may terminate

    return 0;
}
