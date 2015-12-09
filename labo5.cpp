/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo5
 Fichier     : labo5.cpp
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
#include "saisies.h"
#include "traitementEtAffichage.h"
#include "saisies.cpp"
#include "traitementEtAffichage.cpp"
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
          BORNE_ANNEE_MINIMALE = 1900,
          BORNE_ANNEE_MAXIMALE = 2100,
          DIMANCHE = 7,
          LUNDI = 1;

const string DATE_DEBUT = "Entrez la date de debut: ",
             DATE_FIN = "Entrez la date de fin: ",
             SAISIE_INCORRECTE = "Date non valide. Veuillez SVP recommencer.";

const char OUI = 'o',
           NON = 'n';


int main() 
{
   int moisDebut, moisFin, anneeDebut, anneeFin;
   char saisieUtilisateur;
   
   affichageBienvenue();
   
   do
   {
   saisieEtCheckDate(moisDebut, moisFin, anneeDebut, anneeFin);
   afficheCalendrier(moisDebut, moisFin, anneeDebut, anneeFin);
   saisieContinuerProgramme(saisieUtilisateur);
   }
   while(saisieUtilisateur != OUI);
   

   return EXIT_SUCCESS;
}