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

//Pas de classe en c, utilisation d'une struct pour stocker les codes et des fonctions annexes pour intéragir avec la struct

/**
 * @brief A representation of a digit-code lock.
 */
struct CodeLock {
    uint8_t secretCode, visibleCode;
};

/**
 * Créer une nouvelle structure avec secretCode et visibleCode initialisés à la valeur code
 * @param code code à utiliser pour le CodeLock
 * @return nouveau CodeLock
 */
struct CodeLock newCodeLock(uint8_t code);

/**
 * Incrémente le code visible du CodeLock de 1
 * @param this CodeLock à incrémenter
 * @return le nouveau code visible
 */
uint8_t incrementer(struct CodeLock* this);

/**
 * Retourne le code visible
 * @param this CodeLock à utiliser
 * @return code visible
 */
uint8_t getVisibleCode(struct CodeLock* this);

/**
 * @brief Try to open the lock using the given \p code
 * @param this CodeLock to open
 * @param code the valid code
 * @return `true` if successfully opened, `false` otherwise
 */
bool open(struct CodeLock* this, uint8_t code);