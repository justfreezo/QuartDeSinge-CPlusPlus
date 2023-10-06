#ifndef _GAME_
#define _GAME_

/**
 * @file game.h
 * @brief Fichier contenant les fonctions de gestion d'une partie.
 */


#include <assert.h>
#include <iostream>
#include <string.h>
#include "ConteneurTD.h"
#pragma warning(disable: 4996)

using namespace std;

enum {
    MIN_PLAYERS = 2,
    MIN_SCORE = 0,
    MAX_SCORE = 4,
    MAX_LETTER = 26,
    MIN_LETTER = 2,
    MIN_ASCII = 65,
    MAX_ASCII = 90,
};

struct Player {
    unsigned int score; // Score d'un joueur
    char type; // Type d'une joueur (humain ou robot)
};

struct Game {
    unsigned int nbPlayers; // Nombre de joueurs d'une partie
    unsigned int lastPlayer; // Dernier joueur ayant donn� une lettre
    Player* players; // Tableau des joueurs
};

/**
 * @brief Affiche le joueur qui joue actuellement et le mot actuellement forme.
 * @param[in] g La structure qui contient les informations sur la partie en cours.
 * @param[in] word Le mot actuellement forme.
 * @param[in] len La longueur du mot.
 * @pre g.nbPlayers > 0
 */
void showWord(const Game& g, const Item word, unsigned int len);

/**
 * @brief Cherche un mot dans un dictionnaire.
 * @param[in] dico Le dictionnaire dans lequel chercher.
 * @param[in] word Le mot a chercher dans le dictionnaire.
 * @pre dico.capacite > 0
 * @return true si le mot est trouve dans le dictionnaire 
 et a une longueur superieure a MIN_LETTER, false sinon.
 */
bool findWord(const ConteneurTD& dico, const Item word);

/**
 * @brief Ajoute une lettre a un mot.
 * @param[in, out] word Le mot auquel ajouter la lettre.
 * @param[in] ind L'index de la lettre a ajouter dans le mot.
 * @param[in] letter La lettre a ajouter au mot.
 * @return Le mot avec la lettre ajout�e.
 */
void addLetter(Item& word, unsigned int ind, const char letter);

/**
* @brief Détruit un mot et libère la mémoire allouée.
* @param[in, out] it l'Item a detruire.
*/
void destroyWord(Item& it);

#endif