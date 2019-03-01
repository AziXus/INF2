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
#ifndef MAILBOX_H
#define MAILBOX_H

#include <vector>
#include "Message.h"

using Messages = std::vector<Message>;

class Mailbox {
public:
    Mailbox();
    Message getMessage(size_t index) const;
    unsigned getMessagesCount() const;
    void addMessage(const Message& m);
    void removeMessage(size_t index);
private:
    Messages messages;
};


#endif //MAILBOX_H
