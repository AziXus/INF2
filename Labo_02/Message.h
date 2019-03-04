/*
 -----------------------------------------------------------------------------------
 Labo        : 02
 File        : Message.h
 Author(s)   : Robin Müller
 Date        : 05.03.2019

 Purpose     : This class implement various function to create and manipulate a message (email).
               A message is composed of a sender, a recipient, a date (fixed) and a body.
               The body of the message is a vector of strings and can only be added line per line.

 Comment(s)  : The date of the message is constant and is set to the current time at the initialization.
               The assignment and equality operators are overloaded.

 Compiler    : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctime>
#include <iostream>
#include <vector>

//using Line to be able to change type easily
using Line = std::string;
using Body = std::vector<Line>;

class Message {
public:
    /**
     * Constructor of class Message with the sender and the recipient specified, the date is
     * automatically generated with the current time.
     * @param from sender
     * @param to recipient
     */
    Message(const std::string& from, const std::string& to);

    /**
     * Add a new line to the body of the message.
     * @param line to add to the body
     */
    void addLine(const Line& line);

    /**
     * Get the message and all its information and format it as string in an email like format.
     * @return message as string
     */
    std::string toString() const;

    /**<à compléter>
     * Print the message with cout.
     */
    void print() const;

    /**
     * Overload of == operator to compare if two messages are equal.
     * @param msg message to compare with the current message
     * @return true if both messages are equal, false otherwise
     */
    bool operator==(const Message& msg) const;

    /**
     * Overload of = to assign a message
     * @param msg message to assign to the current message
     * @return modified message as a reference
     */
    Message& operator=(const Message& msg);

private:
    //DATE assigned to current time at initialization
    const time_t DATE = time(nullptr);
    std::string from;
    std::string to;
    Body body;

    /**
     * Get the date formatted with the format jj.mm.yyyy HH:MM (e.g.: 24.11.2019 23:54).
     * @return date as string
     */
    std::string getFormattedDate() const;
};

#endif //MESSAGE_H