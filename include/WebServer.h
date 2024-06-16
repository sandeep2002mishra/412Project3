/**
 * @file WebServer.h
 * @brief Defines the WebServer class that processes web requests.
 */

#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"
#include <fstream>

/**
 * @class WebServer
 * @brief Represents a web server that processes requests.
 */
class WebServer {
public:
    /**
     * @brief Construct a new WebServer object
     * 
     * @param id The ID of the web server
     */
    WebServer(int id);

    /**
     * @brief Processes a request.
     * 
     * @param req The request to be processed
     * @param logFile The log file to record events
     */
    void processRequest(const Request& req, std::ofstream& logFile);

    /**
     * @brief Checks if the server is busy.
     * 
     * @return true If the server is busy
     * @return false If the server is not busy
     */
    bool isBusy() const;

    /**
     * @brief Gets the ID of the server.
     * 
     * @return int The ID of the server
     */
    int getId() const;

    /**
     * @brief Completes the current request.
     * 
     * @param logFile The log file to record events
     */
    void requestComplete(std::ofstream& logFile);

    /**
     * @brief Gets the remaining time for the current request.
     * 
     * @return int The remaining time
     */
    int getTimeRemaining() const;

    /**
     * @brief Decrements the remaining time for the current request.
     */
    void decrementTimeRemaining();

private:
    int serverId; ///< The ID of the server
    bool busy; ///< Flag to indicate if the server is busy
    int timeRemaining; ///< Time remaining for the current request
    Request currentRequest; ///< The current request being processed
};

#endif // WEBSERVER_H
