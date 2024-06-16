/**
 * @file Main.cpp
 * @brief Main program to simulate a load balancer with web servers.
 */

#include "LoadBalancer.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Main function to run the load balancer simulation.
 * 
 * @return int 
 */
int main() {
    srand(time(0));

    int numServers, runtime;
    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter the runtime in clock cycles: ";
    std::cin >> runtime;

    std::ofstream logFile("logFile.txt"); // Create and open the log file
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file." << std::endl;
        return 1;
    }

    LoadBalancer lb(numServers);

    // Generate initial full queue
    int minTime = 100, maxTime = 0;
    for (int i = 0; i < numServers * 100; ++i) {
        std::string ipIn = "192.168.1." + std::to_string(rand() % 255);
        std::string ipOut = "10.0.0." + std::to_string(rand() % 255);
        int time = rand() % 100;
        lb.addNewRequest(Request(ipIn, ipOut, time));
        logFile << "Adding new request: " << ipIn << " time to process " << time << " sec" << std::endl;
        if (time < minTime) minTime = time;
        if (time > maxTime) maxTime = time;
    }

    // Log the starting queue size
    logFile << "Starting queue size: " << lb.getStartingQueueSize() << std::endl;

    // Run the load balancer for the specified runtime
    for (int t = 0; t < runtime; ++t) {
        logFile << "Elapsed time: " << t << " seconds" << std::endl;
        lb.distributeRequests(t, logFile);
        if (rand() % 10 == 0) { // Randomly add new requests
            std::string ipIn = "192.168.1." + std::to_string(rand() % 255);
            std::string ipOut = "10.0.0." + std::to_string(rand() % 255);
            int time = rand() % 100;
            lb.addNewRequest(Request(ipIn, ipOut, time));
            logFile << "Adding new request: " << ipIn << " time to process " << time << " sec" << std::endl;
            if (time < minTime) minTime = time;
            if (time > maxTime) maxTime = time;
        }
        lb.manageServers(logFile);
    }

    // Log the ending queue size
    logFile << "Ending queue size: " << lb.getEndingQueueSize() << std::endl;
    // Log the range of task times
    logFile << "Task times range from " << minTime << " to " << maxTime << " seconds" << std::endl;

    logFile << "Load balancer simulation complete." << std::endl;
    logFile.close(); // Close the log file

    return 0;
}



