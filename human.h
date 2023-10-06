#ifndef _HUMAN_
#define _HUMAN_

#include "game.h"

/**
 * @file human.h
 * @brief Fichier contenant les fonctions de gestion des joueurs humains.
 */

/**
 * @brief Initialise une partie de pendu, les joueurs sont alloués dynamiquement.
 * @param[in, out] g La structure à initialiser.
 * @param[in] players Le nombre de joueurs dans la partie.
 * @pre players >= MIN_PLAYERS
 */
void init(Game& g, unsigned int players);

/**
 * @brief Détruit une partie et libère la mémoire allouée pour les joueurs.
 * @param[in, out] g La partie à détruire.
 */
void destroyGame(Game& g);

/**
 * @brief Lit les informations d'un joueur dans une partie.
 * @param[in] g La structure qui contient les informations sur la partie en cours.
 * @param[in] i L'index du joueur à lire.
 * @pre i < g.nbPlayers
 * @return Les informations du joueur à l'index `i`.
 */
Player read(const Game& g, unsigned int i);

/**
 * @brief Ajoute un joueur à une partie. Allocation dynamique si on dépasse le tableau.
 * @param[in, out] g La structure qui contient les informations sur la partie.
 * @param[in] i L'index du joueur à ajouter.
 * @param[in] type Le type de joueur (humain ou robot).
 */
void addPlayer(Game& g, unsigned int i, const char type);

/**
 * @brief Affiche les scores des joueurs d'une partie.
 * @param[in] g La structure qui contient les informations sur la partie en cours.
 */
void showScore(const Game& g);

/**
 * @brief Demande le mot auquel pense un joueur d'une partie de quart de singe.
 * @param[in] g La structure qui contient les informations sur la partie en cours.
 * @param[in] dico Le dictionnaire contenant les mots.
 * @param[in] word Le mot en construction.
 * @param[in] before L'index du joueur (précédent) qui a demandé le mot.
 * @pre before >= 0 && before < g.nbPlayers
 * @return L'index du joueur qui a pris un quart de singe 
 (`before` si le mot n'est pas valide, sinon l'index du joueur qui a donné le mot).
 */
int askWord(const Game& g, const ConteneurTD& dico, Item word, unsigned int before);

#endif