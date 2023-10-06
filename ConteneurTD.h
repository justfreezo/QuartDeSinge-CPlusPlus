#ifndef _CONTENEURTD_
#define _CONTENEURTD_

/**
 * @file ConteneurTD.h
 * @brief Composant de conteneur d'items en m�moire dynamique � capacit� fixe.
 */

// Sp�cialisation d'Item en pointeur de char
typedef char* Item;

/** @brief Type des conteneurs d'itemes allou�s en m�moire dynamique
 *  et de capacit� fixe. */ 
struct ConteneurTD {
	/// Capacit� du conteneur.
	unsigned int capacite; 	
	/// Tableau d'items allou� en m�moire dynamique.
	Item* tab;				
};

/**
 * @brief Initialise un conteneur d'items vide (allocation dynamique de m�moire - @see detruire pour sa 
 * d�sallocation en fin d'utilisation). 
 * @param[out] c Conteneur d'items.
 * @param [in] capa Capacit� du conteneur.
 * @pre capa > 0
 */
void initialiser(ConteneurTD& c, unsigned int capa);

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique.
 * @param[out] c Conteneur d'items.
 */
void detruire(ConteneurTD& c);

/**
 * @brief Lecture d'un item d'un conteneur.
 * @param[in] c Conteneur d'items.
 * @param[in] i Indice de l'item � lire.
 * @return L'item se trouvant � la position i dans le conteneur c.
 * @pre i < c.capacite.
 */
 Item lire(const ConteneurTD& c, unsigned int i); 

/**
 * @brief Ecrire un item dans un conteneur d'items.
 * @param[out] c Conteneur d'items.
 * @param[in] i Position o� ajouter/modifier l'item.
 * @param[in] item Item � �crire.
 * @pre i < c.capacite.
 */
void ecrire(ConteneurTD& t, unsigned int i, const Item& it);

#endif