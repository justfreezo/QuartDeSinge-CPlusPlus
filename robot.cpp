/**
 * @file robot.h
 * @brief Fichier contenant les fonctions de gestion des joueurs robots.
 */

#include "robot.h"

bool strcmpHalf(const Item dico, const Item word) {
    assert(dico != NULL && word != NULL);
    unsigned int lenDico = strlen(dico), lenWord = strlen(word);
    if (lenDico <= MIN_LETTER || lenDico <= lenWord) {
        return false;
    }
    for (unsigned int i = 0; i < strlen(word); ++i) {
        if (dico[i] != word[i]) {
            return false;
        }
    }
    return true;
}

char closeWord(const ConteneurTD& dico, const Item word) {
    assert(dico.capacite > 0);
    unsigned int start = 0, end = dico.capacite, mid = ((start + end) / 2);
    while (start <= end) {
        if (strcmpHalf(dico.tab[mid], word)) {
            return dico.tab[mid][strlen(word)];
        }
        else {
            if (strcmp(dico.tab[mid], word) <= 0) {
                start = mid + 1;
            }
            else if (strcmp(dico.tab[mid], word) > 0) {
                end = mid - 1;
            }
        }
        mid = ((start + end) / 2);
    }
    return '0';
}

char robotPlay(const ConteneurTD& dico, const Item word) {
    char letter = { 0 };

    // Si mot vide, lettre au hasard
    if (word == 0) {
        srand(time(NULL));
        letter = char(rand() % (MAX_ASCII - MIN_ASCII + 1) + MIN_ASCII);
    }
    else {
        letter = closeWord(dico, word);
        // Si il n'y a pas de mot commencant par cette lettre
        if (letter == '0') {
            letter = '?';
        }
    }
    return letter;
}

Item getEnd(const ConteneurTD& dico, const Item word) {
    assert(dico.capacite > 0);
    unsigned int start = 0, end = dico.capacite, mid = ((start + end) / 2);
    while (start <= end) {
        if (strcmpHalf(dico.tab[mid], word)) {
            return dico.tab[mid];
        }
        else {
            if (strcmp(dico.tab[mid], word) <= 0) {
                start = mid + 1;
            }
            else if (strcmp(dico.tab[mid], word) > 0) {
                end = mid - 1;
            }
        }
        mid = ((start + end) / 2);
    }
    return word;
}

bool askRobot(const Game& g, const ConteneurTD& dico, const Item word) {
    Item answer = getEnd(dico, word);
    cout << answer << endl;
    if (answer == word) {
        return false;
    }
    cout << "le mot " << answer << " existe, le joueur "
        << g.lastPlayer + 1 << g.players[g.lastPlayer].type
        << " prend un quart de singe" << endl;
    return true;
}