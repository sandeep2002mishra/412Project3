/**
 * @file LoadBalancer.h
 * @brief Defines the LoadBalancer class that manages web servers and request queues.
 */

#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "WebServer.h"
#include "RequestQueue.h"
#include <vector>
#include <fstream>

/**
 * @class LoadBalancer
 * @brief Manages the web servers and distributes the requests to them.
 */
class LoadBalancer {
public:
    /**
     * @brief Construct a new LoadBalancer object
     * 
     * @param numServers Number of web servers to manage
     */
    LoadBalancer(int numServers);

    /**
     * @brief Adds a new request to the request queue.
     * 
     * @param req The request to be added
     */
    void addNewRequest(const Request& req);

    /**
     * @brief Distributes the requests to the web servers.
     * 
     * @param currentTime The current time in clock cycles
     * @param logFile The log file to record events
     */
    void distributeRequests(int currentTime, std::ofstream& logFile);

    /**
     * @brief Manages the web servers, processing and completing requests.
     * 
     * @param logFile The log file to record events
     */
    void manageServers(std::ofstream& logFile);

    /**
     * @brief Gets the starting size of the request queue.
     * 
     * @return int The starting size of the request queue
     */
    int getStartingQueueSize() const;

    /**
     * @brief Gets the ending size of the request queue.
     * 
     * @return int The ending size of the request queue
     */
    int getEndingQueueSize() const;

private:
    std::vector<WebServer> servers; ///< Vector of web servers
    RequestQueue requestQueue; ///< Queue of requests
    int startingQueueSize; ///< Starting size of the request queue
    int endingQueueSize; ///< Ending size of the request queue
};

#endif // LOADBALANCER_H
