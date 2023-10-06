/**
 * @file game.h
 * @brief Fichier contenant les fonctions de gestion d'une partie.
 */

#include "game.h"

void showWord(const Game& g, const Item word, unsigned int len) {
    assert(g.nbPlayers > 0);
    cout << g.lastPlayer + 1 << g.players[g.lastPlayer].type << ", (";
    for (unsigned int i = 0; i < len; ++i) {
        cout << word[i];
    }
    cout << ") > ";
}


bool findWord(const ConteneurTD& dico, const Item word) {
    assert(dico.capacite > 0);
    unsigned int start = 0, end = dico.capacite, mid = ((start + end) / 2);
    bool found = false;
    while (not found and start <= end) {
        if (strcmp(dico.tab[mid], word) == 0
            && strlen(dico.tab[mid]) > MIN_LETTER) {
            found = true;
            return found;
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
        if (mid == 0) {
            return (strcmp(dico.tab[mid], word) == 0
                && strlen(dico.tab[mid]) > MIN_LETTER);
        }
    }
    return found;
}

void addLetter(Item& word, unsigned int ind, const char letter) {    
    if (ind >= strlen(word)) {
        unsigned int newTaille = strlen(word) + 2;
        Item newWord = new char[newTaille];
        for (unsigned int j = 0; j < strlen(word); ++j) {
            newWord[j] = word[j];
        }
        delete[] word;
        word = newWord;
    }
    
    word[ind] = toupper(letter);
    word[ind + 1] = '\0';
}

void destroyWord(Item& it) {
    delete[] it;
    it = NULL;
}
