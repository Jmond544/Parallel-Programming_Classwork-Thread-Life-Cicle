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
The solution is **here**



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
   
  Next, we will present the possible implementation in our cat and mouse code; However, we consider that these lines of code are `unnecessary` in the `program code`.
  ```c++
    // Detach the threads
    catThread.detach();
    mouseThread.detach();
  ```


