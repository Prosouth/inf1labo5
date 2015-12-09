/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo5
 Fichier     : traitementEtAffichage.h
 Auteur(s)   : Saez Sebastien, Jérémie Zanone
 Date        : 09.12.2015
 But         : Ce programme affiche l'ensemble des mois du calendrier grégorien
               correspondant à l'intervalle (date début, date fin) bornes incluses
               choisie par l'utilisateur lui-même.
 
 Remarque(s) : - Le programme gère les exceptions de la saisie utilisateur.
               - La saisie est de la forme: moisDebut(mm), anneeDebut(yyyy),
                 moisFin, anneeFin située entre BORNE_ANNEE_MINIMALE, BORNE_ANNEE_MAXIMALE.
               - Les valeurs du programme peuvent facilement être modifiées 
                 (constantes prévues à cet effet).
               - Le programme est structuré en fonctions
               - Le programme tient compte des années bissextiles.
               - A la fin de la première exécution l'utilisateur a la possibilité
                 d'afficher un nouveau calendrier ou de quitter l'application.
               - On suppose les paramètres en entrée aux fonctions corrects.
   
 Compilateur : g++ 5.2.0
 -----------------------------------------------------------------------------------
 */

#ifndef TRAITEMENTETAFFICHAGE_H
#define TRAITEMENTETAFFICHAGE_H

using namespace std;

int premierJourSemaineDuMois(int mois, int annee);

/*
Converti l'entier correspondant au mois de l'année en texte clair  
prenant en paramètre le mois définie sur un entier.
Elle retourne le mois en français (texte clair).
*/
string conversionNombreEnMois(int mois);

/*
Détermine si l'année est bissextile ou non
prenant en paramètre l'entier de l'année à tester.
Elle retroune le booléen 1 si bissextile et 0 sinon.
*/
bool estBissextile(int annee);

/*
Calcule le nombre de jour dans un mois sachant son année
prenant en paramètre le mois et l'année tout 2 des entiers.
Elle retourne la valeur correspondant au nombre de jours dans le mois.
*/
int nbreDeJoursDansMois(int mois, int annee);

/*
Fonction principale pour mettre en oeuvre l'affichage du calendrier
prenant en paramètre le mois du début le mois de fin, l'année du début, l'année de fin
tous des entiers. 
*/
void afficheCalendrier(int moisDebut, int moisFin, int anneeDebut, int anneeFin);

void affichageBienvenue();

#endif /* TRAITEMENTETAFFICHAGE_H */

