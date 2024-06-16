/**
 * @file RequestQueue.cpp
 * @brief Implementation of the RequestQueue class.
 */

#include "RequestQueue.h"

void RequestQueue::addRequest(const Request& req) {
    queue.push(req);
}

Request RequestQueue::getNextRequest() {
    Request req = queue.front();
    queue.pop();
    return req;
}

bool RequestQueue::isEmpty() const {
    return queue.empty();
}

int RequestQueue::size() const {
    return queue.size();
}

