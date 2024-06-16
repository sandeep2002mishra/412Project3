/**
 * @file WebServer.cpp
 * @brief Implementation of the WebServer class.
 */

#include "WebServer.h"
#include <iostream>
#include <sstream>

WebServer::WebServer(int id) : serverId(id), busy(false), timeRemaining(0) {}

void WebServer::processRequest(const Request& req, std::ofstream& logFile) {
    currentRequest = req;
    busy = true;
    timeRemaining = req.time;

    logFile << "Server " << serverId << " is processing request from " << req.ipIn << " to " << req.ipOut << " for " << req.time << " seconds." << std::endl;
}

bool WebServer::isBusy() const {
    return busy;
}

int WebServer::getId() const {
    return serverId;
}

void WebServer::requestComplete(std::ofstream& logFile) {
    busy = false;
    logFile << "Server " << serverId << " has completed the request." << std::endl;
}

int WebServer::getTimeRemaining() const {
    return timeRemaining;
}

void WebServer::decrementTimeRemaining() {
    if (timeRemaining > 0) {
        --timeRemaining;
    }
}
