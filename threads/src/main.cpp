#include <iostream>
#include <thread>

// Initialise variable to determine if thread is finished
bool finished = false;

// Define function for thread to execute
void DoWork() {
	// Define using namespace to allow for 1s in thread sleep
	using namespace std::literals::chrono_literals;

	// Print to terminal every 1 second
	while (!finished) {
		std::cout << "Working..." << std::endl;
		std::this_thread::sleep_for(1s);
	}
}

int main() {
	// Start thread
	std::thread worker(DoWork);

	// Set Finished variable to true when user provides input
	std::cin.get();
	finished = true;

	// Wait for worker node process to finish
	worker.join();
	std::cout << "Finished." << std::endl;

	// Wait for user input to stop debug window closing immediately
	std::cin.get();
}