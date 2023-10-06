# QuartDeSinge

## Projet BUT1 – SAE S1.02
### Comparaison d’approches algorithmiques – Le quart de singe –

Le but du projet est de développer un logiciel permettant à un ensemble de joueurs de disputer une partie de quart de singe. L’application doit veiller au respect des règles du jeu et gérer la totalité du déroulement de la partie jusqu’à l’annonce du perdant.

### 1. Règles du jeu
Les joueurs annoncent à tour de rôle une lettre qui vient compléter un mot. Un joueur donnant une lettre terminant un mot existant (de plus de deux lettres) perd la manche et est gratifié d’un quart de singe. Le joueur courant devant annoncer une lettre peut préférer demander au joueur précédant à quel mot il pense. Si ce dernier est incapable de donner un mot existant et qui soit cohérent avec les lettres déjà annoncées, il perd la manche. Dans le cas contraire, c’est le joueur qui a posé la question qui perd la manche. Le premier joueur ayant récolté quatre quarts de singe perd la partie.

Exemple :
- Lors des tours précédents d’une manche, les lettres ’A’, ’B’, ’A’ et ’C’ ont été annoncées.
- Si le joueur courant annonce ’A’, il perd la manche car le mot ”ABACA” est un mot existant.
- S’il joue ’U’ et que le joueur suivant lui demande à quel mot il pense, il pourra répondre ”ABACULE”, et ce joueur écopera d’un quart de singe.

### 2. Cahier des charges
L’application doit permettre à au moins deux joueurs de jouer une partie dans sa totalité. Pour permettre à un joueur seul de s’exercer, l'application doit implémenter des joueurs robots qui joueront automatiquement. Le nombre de joueurs, leur nature (humain ou robot), et l’ordre dans lequel les joueurs prendront leur tour sont spécifiés par une chaîne de caractères passée sur la ligne de commande. Par exemple, si votre fichier exécutable est nommé singe.exe, alors la commande `singe HRHR` lance une partie où 4 joueurs s’affrontent.

Dans les affichages, les joueurs sont désignés par leur numéro d’ordre (1, 2, etc.) et leur nature (H pour les humains et R pour les robots). À chaque tour de jeu, le numéro du joueur courant, sa nature, ainsi que les lettres déjà annoncées sont affichés.

### 3. Qui, quoi et quand?
- **Équipe n°12, Julia Leveque & Paulo Martins Leitao Coelho**
  - *Note générale (sur 20 pts) :* 17
  - *Note de test (sur 5 pts) :* 5
  - *Note de rapport (sur 5 points) :* 4
    - *La présentation est très courte même si l'essentiel est dit. Vous auriez pu parler du dictionnaire.*
    - *Le graphe est très clair et on y voit des composants. Les inclusions ne me semblent pas logiques mais c'est à partir d'a priori sur le nom des composants. La lecture du code me dira si je me trompe. Le code du test unitaire est très bien présenté mais le fond noir est un mauvais choix pour un rapport qui pourrait être imprimé. Les commentaires ne semblent pas à jour ("Initialisation de la pile" ???). Le test est basique mais c'est déjà cela. Les tests sont la partie la plus faible de votre rapport. C'est dommage. Les dictionnaires comme les robots se prêtent bien aux tests.*
    - *Le bilan est très bien.*
  - *Note de code (sur 10 pts) :* 8

*Exemple de session – en rouge, les données saisies par les joueurs humains, en bleu, les messages affichés par le programme.*

---

*Remarque : Ajoutez dans votre rapport les détails nécessaires concernant la gestion du dictionnaire, la mise en place des joueurs robots, et toute autre information pertinente pour la compréhension et l'évaluation de votre projet.*
