/*
 -----------------------------------------------------------------------------------
 Labo       : 02
 File       : Mailbox.h
 Author(s)  : Robin Müller
 Date       : 05.03.19

 Purpose    : This class provides a mailbox that is able to store messages.
              It is possible to add, get and remove messages from the mailbox.

 Comment(s) : The get message function return the message as a reference so that
              it can be modified.

 Compiler   : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef MAILBOX_H
#define MAILBOX_H

#include <vector>
#include "Message.h"

using Messages = std::vector<Message>;

class Mailbox {
public:
    /**
     * Constructor with no parameters of Mailbox to initialize the object.
     */
    Mailbox();

    /**
     * Return a reference to the message at the specified index.
     * If the index is invalid, an out_of_range exception is thrown.
     * @param index of the message to get
     * @return message in reference found on the specified index
     */
    Message& getMessage(size_t index);

    /**
     * Return the number of messages currently in the mailbox.
     * @return number of messages in mailbox
     */
    unsigned getMessagesCount() const;

    /**
     * Add a message at the end of the mailbox if not already in it.
     * @param m message to add
     */
    void addMessage(const Message& m);

    /**
     * Remove the message on the specified index. If index is invalid, the function does nothing.
     * @param index of the message to remove
     */
    void removeMessage(size_t index);

private:
    Messages messages;
};


#endif //MAILBOX_H
