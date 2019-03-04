/*
 -----------------------------------------------------------------------------------
 Labo        : 02
 File        : Message.cpp
 Author(s)   : Robin Müller
 Date        : 05.03.2019

 Compiler    : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "Message.h"

using namespace std;

Message::Message(const string& from, const string& to) : from(from), to(to) {
}

void Message::addLine(const Line& line) {
    body.push_back(line);
}

string Message::toString() const {
    string strBody;

    strBody = "From : " + from               + "\n"
            + "To   : " + to                 + "\n"
            + "Date : " + getFormattedDate() + "\n\n";

    //Concatenate the lines with a \n
    for (const Line& line : body) {
        strBody += line + "\n";
    }

    return strBody;
}

void Message::print() const {
    cout << toString() << endl;
}

bool Message::operator==(const Message& msg) const {
    return from == msg.from and
           to   == msg.to   and
           DATE == msg.DATE and
           body == msg.body;
}

Message& Message::operator=(const Message& msg) {
    from = msg.from;
    to   = msg.to;
    body = msg.body;

    //Convert to ref in order to be able to write const
    (time_t&)DATE = msg.DATE;

    return *this;
}

string Message::getFormattedDate() const {
    //Buffer for the time conversion
    char buffer[20];

    //Convert time to the format jj.mm.yyyy HH:MM (e.g.: 24.11.2019 23:54)
    strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M", localtime(&DATE));

    return string(buffer);
}

