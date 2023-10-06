## Projet SAE S1.02 - Quart de Singe en C++

### Description du Projet

Le projet SAE S1.02, intitulé "Comparaison d’approches algorithmiques – Le quart de singe", vise à développer un logiciel permettant à un ensemble de joueurs de participer à une partie de quart de singe. L'application doit garantir le respect des règles du jeu et gérer l'ensemble du déroulement de la partie jusqu'à l'annonce du perdant.

### Règles du Jeu

Les joueurs annoncent tour à tour une lettre qui vient compléter un mot. Un joueur donnant une lettre terminant un mot existant (de plus de deux lettres) perd la manche et est gratifié d'un quart de singe. Le joueur courant peut préférer demander au joueur précédent à quel mot il pense. Si ce dernier est incapable de donner un mot existant et cohérent avec les lettres déjà annoncées, il perd la manche. Dans le cas contraire, c'est le joueur qui a posé la question qui perd la manche. Le premier joueur ayant récolté quatre quarts de singe perd la partie.

Par exemple, si les lettres 'A', 'B', 'A', et 'C' ont été annoncées dans cet ordre lors des tours précédents d'une manche, et si le joueur courant annonce 'A', il perd la manche car le mot "ABACA" est un mot existant.

Les mots retenus sont ceux acceptés au Scrabble, les accents sont ignorés, et les verbes peuvent être conjugués.

### Cahier des Charges

L'application doit permettre à au moins deux joueurs de jouer une partie dans sa totalité. Pour permettre à un joueur seul de s'exercer, l'application doit implémenter des joueurs robots qui joueront automatiquement. Le nombre de joueurs, leur nature (humain ou robot), et l'ordre dans lequel les joueurs prendront leur tour sont spécifiés par une chaîne de caractères passée sur la ligne de commande.

Par exemple, si votre fichier exécutable est nommé "singe.exe", alors la commande "singe HRHR" lance une partie où 4 joueurs s'affrontent. Le premier et le troisième sont des humains, alors que le deuxième et le quatrième sont des robots.

Dans les affichages, les joueurs sont désignés par leur numéro d'ordre (1, 2, etc.) et leur nature (H pour les humains et R pour les robots). À chaque tour de jeu, le numéro du joueur courant, sa nature, ainsi que les lettres déjà annoncées sont affichés (par exemple, "1H (ABAC) >").

Le joueur saisit soit une lettre de l'alphabet (non accentuée et en majuscule ou en minuscule) s'il veut compléter la chaîne de lettres, soit le caractère '?' s'il veut demander au joueur précédent à quel mot il pense, soit le caractère '!' s'il veut abandonner la manche (et prendre un quart de singe).

Si la lettre jouée vient finir un mot existant du dictionnaire, l'application affiche "le mot XXX existe, le joueur X prend un quart de singe" (où XXX est remplacée par le mot ainsi formé et X par le numéro du joueur courant). Si le caractère '?' a été saisi, le joueur précédent est invité à saisir le mot auquel il pense. Si les premières lettres de ce mot ne correspondent pas à celles déjà jouées, l'application affiche "le mot XXX ne commence pas par les lettres attendues, le joueur X prend un quart de singe" (où XXX est remplacée par le mot saisi).

Si le mot saisi n'appartient pas au dictionnaire, l'application affiche "le mot XXX n'existe pas, le joueur X prend un quart de singe". Dans le cas contraire, l'application affiche "le mot XXX existe, le joueur X prend un quart de singe". Dans le cas où le caractère '!' est saisi, l'application affiche "le joueur X abandonne la manche et prend un quart de singe".

À la fin de chaque manche, le nombre de quarts de singe de chaque joueur est affiché (par exemple, "1H : 0.25; 2R : 0; 3H : 0.75; 4R : 0"). Si aucun joueur n'a reçu quatre quarts de singe, le joueur ayant perdu la dernière manche débute la suivante. Dans le cas contraire, l'application affiche "La partie est finie".

### Qui, Quoi et Quand?

Le projet doit être réalisé en binôme. Les groupes de 3 ne seront pas acceptés. Évitez de faire le projet tout seul (soit vous êtes très fort et des personnes ont besoin de votre aide, soit vous avez des difficultés et il faut vous faire aider).

Vous pouvez employer les structures de données vues en cours ou développer les vôtres. Cependant, l'usage des chaînes de caractères du C++ (le type string) ainsi que les conteneurs de la bibliothèque standard (vector, list, map, stack, etc.) est strictement interdit. En cas de doute, contactez-moi.

Vous devez porter une attention particulière à la rédaction de votre dossier. Sa qualité est déterminante pour l'évaluation de votre travail. Votre dossier doit être un document PDF unique comprenant les éléments suivants :

- Une page de garde indiquant le nom et le groupe des membres du binôme, l'objet du dossier.
- Une table des matières de l'ensemble du dossier.
- Une brève introduction du projet.
- Le graphe de dépendance des fichiers sources de vos applications. Tous les composants (qu'ils soient réutilisés ou développés) de vos applications doivent figurer sur le graphe (cf. Cours 4).
- Le code source des tests unitaires que vous aurez écrits (précisez quels tests passent et lesquels échouent).
- Un bilan du projet (les difficultés rencontrées, ce qui est réussi, ce qui peut être amélioré).
- En annexe, le code complet de vos sources (triez les fichiers selon un ordre logique).

Nous vous rappelons que le critère principal de notation est la structuration de votre code. Votre rapport doit mettre en avant la qualité de celle-ci.

Tous les éléments (constantes, types, et fonctions) déclarés au sein d'un fichier .h doivent être documentés.

Vous devez déposer une archive ZIP contenant votre rapport ainsi que l'ensemble des fichiers sources de vos applications le 3 janvier 2023.

---

## Résultats de l'évaluation

Le projet a été évalué et a obtenu la note suivante :

- **Note générale (sur 20 pts)** : 17
- **Note de test (sur 5 pts)** : 5
- **Note de rapport (sur 5 points)** : 4

La présentation est très courte même si l'essentiel est dit. Vous auriez pu parler du dictionnaire. Le graphe est très clair, et on y voit des composants. Les inclusions ne me semblent pas logiques, mais c'est à partir d'a priori sur le nom des composants. La lecture du code me dira si je me trompe. Le code du test unitaire est très bien présenté, mais le fond noir est un mauvais choix pour un rapport qui pourrait être imprimé. Les commentaires ne semblent pas à jour ("Initialisation de la pile" ???). Le test est basique, mais c'est déjà cela. Les tests sont la partie la plus faible de votre rapport. C'est dommage. Les dictionnaires comme les robots se prêtent bien aux tests. Le bilan est très bien.

- **Note de code (sur 10 pts)** : 8
