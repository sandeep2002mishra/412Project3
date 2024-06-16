/**
 * @file Request.h
 * @brief Defines the Request struct that holds the details of a web request.
 */

#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @struct Request
 * @brief Holds details of a web request.
 */
struct Request {
    std::string ipIn; ///< Incoming IP address
    std::string ipOut; ///< Outgoing IP address
    int time; ///< Time required to process the request

    /**
     * @brief Default constructor
     */
    Request() : ipIn(""), ipOut(""), time(0) {}

    /**
     * @brief Parameterized constructor
     * 
     * @param in Incoming IP address
     * @param out Outgoing IP address
     * @param t Time required to process the request
     */
    Request(const std::string& in, const std::string& out, int t)
        : ipIn(in), ipOut(out), time(t) {}
};

#endif // REQUEST_H
