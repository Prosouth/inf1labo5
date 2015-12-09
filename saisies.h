/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo5
 Fichier     : saisies.h
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

#ifndef SAISIES_H
#define SAISIES_H
#include <iomanip> 
#include <cstdlib>
#include <limits>
#include <iostream> 
#include <cmath>



const int BORNE_ANNEE_MINIMALE = 1900,
          BORNE_ANNEE_MAXIMALE = 2100;

const string DATE_DEBUT = "Entrez la date de debut: ",
             DATE_FIN = "Entrez la date de fin: ",
             SAISIE_INCORRECTE = "Date non valide. Veuillez SVP recommencer.";

const char OUI = 'o',
           NON = 'n';

using namespace std;

void saisieDate(const string& messageEntree, int& moisSaisi, int& anneeSaisie);
void saisieEtCheckDate(int& moisDebut, int& moisFin, int& anneeDebut, int& anneeFin);
char saisieContinuerProgramme(char& saisieUtilisateur);

#endif /* SAISIES_H */

