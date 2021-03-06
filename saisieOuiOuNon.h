/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo5
 Fichier     : saisieOuiOuNon.h
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

#ifndef SAISIEOUIOUNON_H
#define SAISIEOUIOUNON_H
#include <iomanip> 
#include <cstdlib>
#include <limits>
#include <iostream> 
#include <cmath>

using namespace std;

const char OUI = 'o',
           NON = 'n';
/*
 Fonction qui permet à l'utilisateur de faire continuer le programme en fonction
 de deux saisies différents('o' ou 'n').
 */
char saisieContinuerProgramme(char& saisieUtilisateur);

#endif /* SAISIEOUIOUNON_H */
