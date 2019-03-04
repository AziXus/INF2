/*
 -----------------------------------------------------------------------------------
 Labo       : 02
 File       : main.cpp
 Author(s)  : Robin Müller
 Date       : 05.03.19

 Purpose    : Test the class Message and Mailbox and their different functions.

 Comment(s) : -

 Compiler   : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include "Message.h"
#include "Mailbox.h"

using namespace std;

void printMailboxSize(const Mailbox& mailbox);

int main() {
    Mailbox mailbox;

    Message m1("Pierre Burki", "Alfred Strohmeier");
    m1.addLine("RDV demain a 9h.");
    m1.addLine("Pierre");

    Message m2("Alfred Strohmeier", "Pierre Burki");
    m2.addLine("OK.");
    m2.addLine("Alfred");

    cout << "Message 1 :\n";
    m1.print();
    cout << "Message 2 :\n";
    m2.print();

    cout << "Adding m1 to mailbox...\n";
    mailbox.addMessage(m1);
    printMailboxSize(mailbox);

    cout << "\nAdding m1 to mailbox again...\n";
    mailbox.addMessage(m1);
    printMailboxSize(mailbox);

    cout << "\nAdding m2 to mailbox...\n";
    mailbox.addMessage(m2);
    printMailboxSize(mailbox);

    cout << "\nRemoving message in position 9...\n";
    mailbox.removeMessage(9);
    printMailboxSize(mailbox);

    cout << "\nRemoving message in position 0...\n";
    mailbox.removeMessage(0);
    printMailboxSize(mailbox);

    cout << "\nMessage in position 0 :\n";
    mailbox.getMessage(0).print();

    cout << "Adding new line to message in position 0 :\n";
    mailbox.getMessage(0).addLine("new line");
    mailbox.getMessage(0).print();

    return EXIT_SUCCESS;
}

void printMailboxSize(const Mailbox& mailbox) {
    cout << "Mailbox size : " << mailbox.getMessagesCount() << endl;
}