/**
 * @file LoadBalancer.cpp
 * @brief Implementation of the LoadBalancer class.
 */

#include "LoadBalancer.h"
#include <iostream>

LoadBalancer::LoadBalancer(int numServers) {
    for (int i = 0; i < numServers; ++i) {
        servers.emplace_back(i);
    }
    startingQueueSize = 0;
    endingQueueSize = 0;
}

void LoadBalancer::addNewRequest(const Request& req) {
    requestQueue.addRequest(req);
    if (requestQueue.size() > startingQueueSize) {
        startingQueueSize = requestQueue.size();
    }
}

void LoadBalancer::distributeRequests(int currentTime, std::ofstream& logFile) {
    for (auto& server : servers) {
        if (!server.isBusy() && !requestQueue.isEmpty()) {
            Request req = requestQueue.getNextRequest();
            server.processRequest(req, logFile);
        }
    }
}

void LoadBalancer::manageServers(std::ofstream& logFile) {
    for (auto& server : servers) {
        if (server.isBusy()) {
            server.decrementTimeRemaining();
            if (server.getTimeRemaining() == 0) {
                server.requestComplete(logFile);
            }
        }
    }
    endingQueueSize = requestQueue.size();
}

int LoadBalancer::getStartingQueueSize() const {
    return startingQueueSize;
}

int LoadBalancer::getEndingQueueSize() const {
    return endingQueueSize;
}
