# Homework: Reuse past homework and

- `Students:` 
  - Mondalgo Tapia, Juan Carlos.
  - Pineda Silupu, Kevin Jair.
- `Course:` Parallel Programming
- `University:` UNMSM.


## Task reuse:
Obtain the same number of egetable_count



This C++ code implements a basic example of parallel programming using threads (std::thread). The program simulates two individuals, Olivia and Barron, chopping vegetables concurrently.

```c++
/**
 * Two threads chopping vegetables
 */
#include <thread>
#include <chrono>

bool chopping = true;

void vegetable_chopper(const char* name) {
    unsigned int vegetable_count = 0;
    while (chopping) {
        vegetable_count++;
    }
    printf("%s chopped %u vegetables.\n", name, vegetable_count);
}

int main() {
    std::thread olivia(vegetable_chopper, "Olivia");
    std::thread barron(vegetable_chopper, "Barron");
   
    printf("Barron and Olivia are chopping vegetables...\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    chopping = false;
    barron.join();
    olivia.join();
}
```

# Solution
The solution is [here](./Solution.cpp).
```c++
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

```
### Explanation of the code

Function `vegetable_chopper`:

- Takes a parameter `name` representing the name of the worker who is chopping vegetables.
- Utilizes a `while` loop that continuously increments the `vegetable_count` variable while the global variable `chopping` is true.
- When the loop ends (when `chopping` is set to false), it prints the worker's name and the quantity of vegetables chopped.
- Then, the thread sleeps for 10 seconds using `std::this_thread::sleep_for`.

Function `main`:

- Creates two threads (`olivia` and `barron`) that execute the `vegetable_chopper` function.
- Prints a message indicating that Barron and Olivia are chopping vegetables.
- Prints whether each thread is "joinable" before detaching.
- Detaches both threads using `detach()`, meaning the threads can continue running independently without needing to be explicitly joined in the future.
- Prints again whether the threads are "joinable," but now they should be false after detachment.
- Prints a message indicating that Barron and Olivia might still be chopping vegetables.
- The main program could terminate before the threads have finished executing, as there are no `join()` calls to wait for the threads to finish.

Observations:

- The global variable `chopping` controls the loop in the `vegetable_chopper` function.
- The use of `detach()` avoids the need to call `join()` but prevents the main program from waiting for the threads to finish.
- The program has no direct control over thread scheduling and does not guarantee that threads will finish executing before the main program terminates.

Possible Issue:

- There might be a race condition if the loop in `vegetable_chopper` continues running after the local variables of the main thread (`olivia` and `barron`) have been destroyed at the end of `main()`. This could lead to undefined behavior.

### Show schedule effects

txt

### show or add functions for:

### Join and joinable:

They are located at the end of the program within the `main` function.
After creating the threads `catThread` and `mouseThread`, there is a loop that waits for both threads to be joinable before calling join.
If a thread is not `joinable`, the loop breaks, and `join` is called to ensure the threads' completion before the main program terminates.

- join
  
  ```c++
    catThread.join();
    mouseThread.join();
  ```

- joinable

  ```c++
    if (!catThread.joinable() || !mouseThread.joinable())
      break;
  ```
- detach
   
  The `detach` function in C++ is used to release a thread from dependency on the main thread, allowing it to `continue execution` `independently`.
   

  ```c++
    // Detach the threads
    catThread.detach();
    mouseThread.detach();
  ```


