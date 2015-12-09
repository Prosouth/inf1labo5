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
#include <iomanip> 
#include <cstdlib>
#include <limits>
#include <iostream> 
#include <cmath>

using namespace std;

enum class Mois 
{
   JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE,
   OCTOBRE, NOVEMBRE, DECEMBRE
};

const int LARGEUR_PREMIERE_COLONNE = 2,
          LARGEUR_COLONNE = 3,
          DIMANCHE = 7,
          LUNDI = 1;
          
const int BORNE_ANNEE_MINIMALE = 1900,
          BORNE_ANNEE_MAXIMALE = 2100;

const string DATE_DEBUT = "Entrez la date de debut   : ",
             DATE_FIN = "Entrez la date de fin     : ",
             SAISIE_INCORRECTE = "Date non valide. Veuillez SVP recommencer.";

/*
 Fonction qui détermine le jour de la semaine du premier jour du mois.
 Elle prend en paramètres le mois désiré ainsi que l'année.
 Elle retourne le jour de la semaine (1 = LUNDI => 7 = DIMANCHE)
 Remarque: La formule mathématique a été trouvée sur ce lien:
 https://goo.gl/hRHD6V
 */
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

/*
 * Fonction qui permet d'afficher un message de bienvenue à l'utilisateur.
 */
void affichageBienvenue();

/*
 Fonction qui permet de saisie une date sous la forme mm yyyy et qui vérifie 
 que les bornes (supérieures et inférieures) soient respectées. 
 Elle prend en paramètres le message d'invitation à la saisie, un mois ainsi
 qu'une année.
 */
void saisieDate(const string& messageEntree, int& moisSaisi, int& anneeSaisie);

/*
 Fonction qui fait appel à saisieDate en interne et qui permet de saisir deux
 dates ainsi de vérifier que la deuxième date soit supérieure ou égale à la
 première.
 Elle prend en entrée le mois de début, le mois de fin, l'année de début ainsi
 que l'année de fin.
 */
void saisieEtCheckDate(int& moisDebut, int& moisFin, int& anneeDebut, int& anneeFin);

#endif /* TRAITEMENTETAFFICHAGE_H */