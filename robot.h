#ifndef _ROBOT_
#define _ROBOT_

#include "game.h"

/**
 * @file robot.h
 * @brief Fichier contenant les fonctions de gestion des joueurs robots.
 */

/**
 * @brief Compare une partie d'une chaine de caractère avec la totalité d'une autre
 * @param[in] dico, un Item dont on comparera une partie.
 * @param[in] word, un Item le mot recherché au début de l'Item dico.
 * @pre dico != NULL && word != NULL
 * @return true si word est égal au début de dico, flse sinon
 */
bool strcmpHalf(const Item dico, const Item word);

/**
 * @brief Cherche un mot dans un dictionnaire et renvoie la prochaine lettre du mot.
 * @param[in] dico Le dictionnaire dans lequel chercher.
 * @param[in] word Le mot à chercher dans le dictionnaire.
 * @pre dico.capacite > 0
 * @return La prochaine lettre du mot suivant si le mot est trouvé, '0' sinon.
 */
char closeWord(const ConteneurTD& dico, const Item word);

/**
 * @brief Permet à un robot de jouer en proposant une lettre.
 * @param[in] dico Le dictionnaire à utiliser pour trouver des mots.
 * @param[in] word Le mot actuellement formé par les adversaires.
 * @return La lettre proposée par le robot. '?' si aucun mot du dico ne commence par `word`.
 */
char robotPlay(const ConteneurTD& dico, const Item word);

/**
 * @brief Cherche le début d'un mot dans un dictionnaire et le renvoie en entier.
 * @param[in] dico Le dictionnaire dans lequel chercher.
 * @param[in] word Le mot à chercher dans le dictionnaire.
 * @pre dico.capacite > 0
 * @return Un mot commençant par `word` si trouvé, `word`sinon.
 */
Item getEnd(const ConteneurTD& dico, const Item word);

/**
 * @brief Demande au robot de donner le mot auquel il pense.
 * @param[in] g La structure qui contient les informations sur la partie en cours.
 * @param[in] dico Le dictionnaire à utiliser pour trouver des mots.
 * @param[in] word Le mot à complèter.
 * @return true si un mot du dico commence par `word`, false sinon.
 * @warning Si un mot est trouvé on l'affichera 
 ainsi qu'un message indiquant que le joueur précédent prend un quart de singe.
 */
bool askRobot(const Game& g, const ConteneurTD& dico, const Item word);

#endif