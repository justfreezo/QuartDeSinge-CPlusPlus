/**
 * @file human.h
 * @brief Fichier contenant les fonctions de gestion des joueurs humains.
 */

#include <iomanip>
#include <limits.h>
#include "human.h"

void init(Game& g, unsigned int players) {
    assert(players >= MIN_PLAYERS);
    g.nbPlayers = players;
    g.players = new Player[players];
    g.lastPlayer = 0;
}

void destroyGame(Game& g) {
    delete[] g.players;
    g.players = NULL;
    g.nbPlayers = 0;
    g.lastPlayer = 0;
}

Player read(const Game& g, unsigned int i) {
    assert(i < g.nbPlayers);
    return g.players[i];
}

void addPlayer(Game& g, unsigned int i, const char type) {
    Player pl;
    pl.type = type;
    pl.score = MIN_SCORE;
    if (i >= g.nbPlayers) {
        unsigned int newTaille = i + 1;
        Player* newT = new(nothrow) Player[newTaille];
        for (unsigned int j = 0; j < g.nbPlayers; ++j) {
            newT[i] = read(g, j);
        }
        delete[] g.players;
        g.players = newT;
        g.nbPlayers = newTaille;
    }
    g.players[i] = pl;
}

void showScore(const Game& g) {
    float res = 0.;
    for (int i = 0; i < g.nbPlayers; ++i) {
        res = float(g.players[i].score) / float(MAX_SCORE);
        cout << i + 1 << g.players[i].type << " : "
            << res;
        if (i != g.nbPlayers - 1) {
            cout << "; ";
        }
    }
    cout << endl;
}

int askWord(const Game& g, const ConteneurTD& dico, Item word, unsigned int before) {
    assert(before >= 0 && before < g.nbPlayers);
    char answer[MAX_LETTER];
    cout << before + 1 << g.players[before].type << ", saisir le mot > ";
    cin >> setw(MAX_LETTER) >> answer;
    cin.ignore(INT_MAX, '\n');

    for (unsigned int i = 0; i < strlen(answer); ++i) {
        answer[i] = toupper(answer[i]);
    }

    for (unsigned int j = 0; j < strlen(word); ++j) {
        if (answer[j] != word[j]) {
            cout << "le mot " << answer
                << " ne commence pas par les lettres attendues, le joueur "
                << before + 1 << g.players[before].type
                << " prend un quart de singe" << endl;
            return before;
        }
    }

    if (findWord(dico, answer)) {
        cout << "le mot " << answer << " existe, le joueur "
            << g.lastPlayer + 1 << g.players[g.lastPlayer].type
            << " prend un quart de singe" << endl;
        return g.lastPlayer;
    }

    cout << "le mot " << answer << " n'existe pas, le joueur " << before + 1
        << g.players[before].type << " prend un quart de singe" << endl;
    return before;
}