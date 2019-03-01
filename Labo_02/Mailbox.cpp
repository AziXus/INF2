
/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : Mailbox.cpp
 Auteur(s)   : Robin Müller
 Date        : 25.02.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "Mailbox.h"
#include <algorithm>

Mailbox::Mailbox() : messages() {
}

Message Mailbox::getMessage(size_t index) const {
    //vector.at() manages the out of range error
    return messages.at(index);
}

unsigned Mailbox::getMessagesCount() const {
    return (unsigned)messages.size();
}

void Mailbox::addMessage(const Message &m) {
    //If vector does not contain m, add it to the end
    if (find(messages.begin(), messages.end(), m) == messages.end()) {
        messages.push_back(m);
    }
}

void Mailbox::removeMessage(size_t index) {
    if (index < messages.size())
        messages.erase(messages.begin() + index);
}
