/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 5
 Fichier     : labo05_saez_zanone.cpp
 Auteur(s)   : Sébastien Saez & Jérémie Zanone
 Date        : 2 décembre 2015

 But         :        

 Remarque(s) : 

 Compilateur : g++ 5.2.0
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

void saisieUtilisateur();
bool estBissextile(int annee);
void afficheCalendrier(int debut, int fin);
int jourSemaineDebut(int mois, int annee);

enum class JOURS_DANS_MOIS_NON_BISS {JANVIER = 31, FEVRIER = 28, MARS = 31,
                                     AVRIL = 30, MAI = 31, JUIN = 30,
                                     JUILLET = 31, AOUT = 31, SEPTEMBRE = 30,
                                     OCTOBRE = 31, NOVEMBRE = 30, DECEMBRE = 31};


enum class JOURS_DANS_MOIS_BISS {JANVIER = 31, FEVRIER = 29, MARS = 31,
                                 AVRIL = 30, MAI = 31, JUIN = 30,
                                 JUILLET = 31, AOUT = 31, SEPTEMBRE = 30,
                                 OCTOBRE = 31, NOVEMBRE = 30, DECEMBRE = 31};
                                 
const int MOIS_MAXIMUM = 12;
const int MOIS_MINIMUM = 11;
const int BORNE_ANNEE_MINIMALE = 1900;
const int BORNE_ANNEE_MAXIMALE = 2100;
const char OUI = 'o';

int main() {
    char saisieContinuerProgramme;
   
   /* Boucle principale*/
   do
   {
      
      
      
      cout << "Pressez sur la lettre \'o\' pour refaire un calendrier, "
              "autrement pressez sur n'importe quelle autre touche pour quitter"
              << endl;
      cin >> saisieContinuerProgramme;
   }
   while (saisieContinuerProgramme == OUI);
   
   
 
   
   return EXIT_SUCCESS;
}


void saisieUtilisateur()
{
   int moisDebut, anneeDebut, moisFin, anneeFin;
   cout << "Entrez la date de debut : ";
   cin >> moisDebut >> anneeDebut;
   if (cin.fail())
   {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   if ((moisDebut < MOIS_MINIMUM  or moisDebut < MOIS_MAXIMUM) and (anneeDebut 
        < BORNE_ANNEE_MINIMALE or anneeDebut > BORNE_ANNEE_MAXIMALE) 
        and cin.fail() == false)
   {
         cout << "La valeur que vous avez entree n'est pas correcte."
                 " Veuillez recommencer." << endl << endl;
   }
   
   cout << "Entrez la date de fin : ";
   cin >> moisFin >> anneeFin;
   if (cin.fail())
   {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   if ((moisFin < MOIS_MINIMUM  or moisFin < MOIS_MAXIMUM) and (anneeFin 
        < BORNE_ANNEE_MINIMALE or anneeFin > BORNE_ANNEE_MAXIMALE) 
        and cin.fail() == false and (anneeFin >= anneeDebut and moisFin > moisDebut))
   {
         cout << "La valeur que vous avez entree n'est pas correcte."
                 " Veuillez recommencer." << endl << endl;
   }
   
}

bool estBissextile(int annee)
{
   return (((annee % 400) == 0) || ((annee % 4 == 0) && (annee % 100 != 0))); 
}


/*
Jour de semaine : si m >= 3, D = { [(23m)/9] + d + 4 + y + [y/4] - [y/100] + [y/400] - 2 } mod 7
si m < 3, D = { [(23m)/9] + d + 4 + y + [z/4] - [z/100] + [z/400] } mod 7*/
int jourSemaineDebut(int mois, int annee)
{
   
}