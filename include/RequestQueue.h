/**
 * @file RequestQueue.h
 * @brief Defines the RequestQueue class that manages a queue of requests.
 */

#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "Request.h"
#include <queue>

/**
 * @class RequestQueue
 * @brief Manages a queue of requests.
 */
class RequestQueue {
public:
    /**
     * @brief Adds a request to the queue.
     * 
     * @param req The request to be added
     */
    void addRequest(const Request& req);

    /**
     * @brief Retrieves and removes the next request from the queue.
     * 
     * @return Request The next request in the queue
     */
    Request getNextRequest();

    /**
     * @brief Checks if the queue is empty.
     * 
     * @return true If the queue is empty
     * @return false If the queue is not empty
     */
    bool isEmpty() const;

    /**
     * @brief Gets the size of the queue.
     * 
     * @return int The size of the queue
     */
    int size() const;

private:
    std::queue<Request> queue; ///< The queue of requests
};

#endif // REQUESTQUEUE_H
