/**
 * @file ConteneurTD.cpp
 * @brief Composant de conteneur d'items en memoire dynamique a capacite fixe.
 */

#include <iostream>
#include <assert.h>
#include <string.h>

#include "ConteneurTD.h"
#pragma warning(disable : 4996);

using namespace std;

void initialiser(ConteneurTD& c, unsigned int capa) {
	assert(capa>0);
	c.capacite = capa;
	c.tab = new Item[capa];	
}

void detruire(ConteneurTD& c) {
	for(unsigned int i = 0; i < c.capacite - 1; ++i){
		delete [] c.tab[i];
		c.tab[i] = NULL;
	}
	delete [] c.tab;
	c.tab = NULL;
}

 Item lire(const ConteneurTD& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

 void ecrire(ConteneurTD& c, unsigned int i, const Item& it) {
	 assert(i < c.capacite);
	 Item chaine = new char[26];
	 strcpy(chaine, it);
	 c.tab[i] = chaine;
 }