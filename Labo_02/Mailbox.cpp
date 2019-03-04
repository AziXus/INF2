/*
 -----------------------------------------------------------------------------------
 Labo       : 02
 File       : Mailbox.cpp
 Author(s)  : Robin Müller
 Date       : 05.03.19

 Compiler   : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "Mailbox.h"
#include <algorithm>

Mailbox::Mailbox() : messages() {
}

Message& Mailbox::getMessage(size_t index) {
    //vector.at() returns an out_of_range exception if index is invalid
    return messages.at(index);
}

unsigned Mailbox::getMessagesCount() const {
    return (unsigned)messages.size();
}

void Mailbox::addMessage(const Message &m) {
    //If vector does not contain the new message, add it to the end
    if (find(messages.begin(), messages.end(), m) == messages.end()) {
        messages.push_back(m);
    }
}

void Mailbox::removeMessage(size_t index) {
    if (index < messages.size())
        messages.erase(messages.begin() + index);
}
