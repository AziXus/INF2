/**
 * @brief CodeLock
 *
 * @author romain
 * @date 14.04.2016
 * @file codelock.h
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief A representation of a digit-code lock.
 */
struct CodeLock {
    uint8_t secretCode, visibleCode;
};

void setCodes(struct CodeLock *this, uint8_t code);
void incrementer(struct CodeLock *this);
uint8_t getVisibleCode(struct CodeLock *this);
bool open(struct CodeLock *this, uint8_t code);

//class CodeLock
//        {
//                public:
//                /**
//                 * @brief Create a digit-code lock using given \p secretCode
//                 */
//                CodeLock(uint8_t secretCode);
//
//                int operator++();
//
//                int getVisibleCode() const;
//
//                /**
//                 * @brief Try to open the lock using the given \p code
//                 * @param the valid code
//                 * @return `true`if successfully opened, `false` otherwise
//                 */
//                bool open(uint8_t code = 0);
//
//                private:
//                uint8_t secretCode, visibleCode;
//        };
