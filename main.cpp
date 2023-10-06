/**
 * @file main.cpp
 * @brief Fichier principal d'un jeu de quart de singe
 * @author Julia Leveque (108) et Paulo Martins (108)
 * @version 06/01/2023
 */

#include <fstream>
#include <iomanip>
#include <limits.h>
#include "human.h"
#include "robot.h"

using namespace std;

/**
 * @brief Joue une manche de quart de singe.
 * @param[in, out] g La structure qui contient les informations sur la partie.
 * @param[in] dico Le dictionnaire contenant les mots.
 * @pre g.nbPlayers >= MIN_PLAYERS : au moins deux joueurs
 * @return L'index du joueur qui a pris un quart de singe.
 */
unsigned int play(Game& g, const ConteneurTD& dico) {
    assert(g.nbPlayers >= MIN_PLAYERS);
    unsigned int ind = 0, before = (g.lastPlayer - 1) % g.nbPlayers;
    bool perdu = false;
    char letter = { 0 };
    Item word = { 0 };
    word = new char[MIN_LETTER];
    word[0] = '\0';
    do {
        // Affichage du joueur, son type et le mot d�j� form�
        showWord(g, word, ind);

        if (g.players[g.lastPlayer].type == 'H') {
            // Verifie que la lettre est valide (lettre ou '!' ou '?')
            do {
                cin >> letter;
                cin.ignore(INT_MAX, '\n');
            } while (letter != '!' && letter != '?' 
                && not isalpha((unsigned char)letter)
                || (letter == '?' && ind == 0)); // Pas de '?' au premier tour
        }
        else {
            // Permet a un joueur robot de donner une lettre
            letter = robotPlay(dico, word);
            cout << letter << endl;
        }

        if (letter == '!') {
            cout << "le joueur " << g.lastPlayer + 1 
                << g.players[g.lastPlayer].type
                << " abandonne la manche et prend un quart de singe" << endl;
            perdu = true;
            break;
        }
        else if (letter == '?') {

            if (g.players[before].type == 'H') {
                // On demande au joueur humain d'entrer son mot
                g.lastPlayer = askWord(g, dico, word, before);
            }
            else {
                // On demande au joueur robot d'entrer son mot
                cout << before + 1 << g.players[before].type 
                    << ", saisir le mot > ";
                if (not askRobot(g, dico, word)) {
                    cout << "le mot " << word << " n'existe pas, le joueur "
                        << before + 1 << g.players[before].type
                        << " prend un quart de singe" << endl;
                    g.lastPlayer = before;
                    perdu = true;
                    break;
                }
            }
            perdu = true;
            break;
        }

        addLetter(word, ind, letter);

        // Si le mot est complet
        if (findWord(dico, word)) {
            cout << "le mot " << word << " existe, le joueur " 
                << g.lastPlayer + 1 << g.players[g.lastPlayer].type 
                << " prend un quart de singe" << endl;
            perdu = true;
            break;
        }
        
        // On determine le prochain joueur a jouer
        g.lastPlayer = (g.lastPlayer + 1) % g.nbPlayers;
        before = g.lastPlayer == 0 ? g.nbPlayers - 1 
            : (g.lastPlayer - 1) % g.nbPlayers;
        ++ind;

    } while (not perdu);

    destroyWord(word);
    return g.lastPlayer;
}

/**
 * @brief Recupere le nombre de lignes dans un fichier `file`.
 * @param[in] file le nom du fichier
 * @pre Le fichier doit exister et etre accessible en lecture.
 * @return Le nombre de lignes dans le fichier.
 */
int getLenght(const char* file) {
    ifstream in(file);
    assert(in);

    unsigned int len = 1;
    char line[MAX_LETTER];

    in >> setw(MAX_LETTER) >> line;
    while (in) {
        ++len;
        in >> setw(MAX_LETTER) >> line;
    }

    in.close();
    return len;
}

/**
 * @brief Initialise le dictionnaire avec les mots contenus dans un fichier.
 * @param[in, out] dico Le dictionnaire a initialiser.
 * @pre Le fichier doit exister et etre accessible en lecture.
 * @pre Le dictionnaire doit etre initialise (alloue et vide).
 */
void initDico(ConteneurTD& dico) {
    ifstream in("ods6.txt");
    assert(in);

    int ind = 0;
    char line[MAX_LETTER];

    in >> setw(MAX_LETTER) >> line;
    while (in) {
        ecrire(dico, ind, line);
        ++ind;
        in >> setw(MAX_LETTER) >> line;
    }

    in.close();
}

/**
 * @brief Fonction principale du programme
 * @param[in] argc Nombre d'arguments passes au programme.
 * @param[in, out] argv Tableau de chaines de caracteres contenant les arguments.
 * @return 0 si la partie s'est deroulee avec succes, 2 sinon.
 */
int main(int argc, char* argv[]) {
    if (argc >= 2) {
        Game g;
        ConteneurTD dico;
        unsigned int countPlayer = 0, dicoLenght = getLenght("ods6.txt");

        // Verification des types de joueurs
        for (unsigned int i = 0; i < strlen(argv[1]); ++i) {
            argv[1][i] = toupper(argv[1][i]);
            if (argv[1][i] == 'H' || argv[1][i] == 'R') {
                countPlayer += 1;
            }
        }

        if (countPlayer < MIN_PLAYERS) {
            cout << "Il faut au moins 2 joueurs pour lancer une partie." 
                << endl;
            return 2;
        }

        init(g, countPlayer);
        initialiser(dico, dicoLenght);
        initDico(dico);
        //Ajout des joueurs dans la partie
        for (unsigned int j = 0; j < strlen(argv[1]); ++j) {
            if (argv[1][j] == 'H' || argv[1][j] == 'R') {
                addPlayer(g, j, argv[1][j]);
            }
        }
        // Lancement d'une manche
        int loser = g.lastPlayer;
        do {
            loser = play(g, dico);
            g.players[loser].score += 1;
            showScore(g);
        } while (g.players[loser].score < MAX_SCORE);

        detruire(dico);
        destroyGame(g);
        cout << "La partie est finie" << endl;
        return 0;
    }
    else{
        cout << "Il faut au moins 2 joueurs pour lancer une partie." << endl;
        return 2;
    }
}
