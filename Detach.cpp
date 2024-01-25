#include <thread>
#include <chrono>
#include <iostream>

void chef_olivia() {
    std::cout << "Olivia started & waiting for sausage to thaw..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Olivia is done cutting sausage." << std::endl;
}

int main() {
    std::cout << "Barron requests Olivia's help." << std::endl;
    std::thread olivia(chef_olivia);

    std::cout << "Barron continues cooking soup." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Verificar si el hilo es joinable antes de llamar a join()
    if (olivia.joinable()) {
        std::cout << "Barron patiently waits for Olivia to finish and join..." << std::endl;
        olivia.join();  // Esperar a que Olivia termine
    }

    std::cout << "Barron and Olivia are both done!" << std::endl;

    // Agregar funcionalidad para demostrar detach
    std::cout << "Creating a new thread for background task..." << std::endl;
    std::thread background_thread([]() {
        std::cout << "Background thread is doing some work..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Background thread has finished its work." << std::endl;
    });

    // Verificar si el hilo es joinable antes de llamar a detach()
    if (background_thread.joinable()) {
        std::cout << "Detaching the background thread..." << std::endl;
        background_thread.detach();  // El hilo ahora se ejecutará en segundo plano
    }

    // No podemos llamar a join() después de detach()

    std::cout << "Main thread continues without waiting for the background thread." << std::endl;

    return 0;
}
