/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "saisies.h"

using namespace std;

void saisieDate(const string& messageEntree, int& moisSaisi, int& anneeSaisie)
{
   bool saisieOk = true;
   do
   {
      cout << messageEntree;
      if(!(saisieOk = static_cast<bool> (cin >> moisSaisi >> anneeSaisie)
         && moisSaisi <= (int)Mois::DECEMBRE && moisSaisi >= (int)Mois::JANVIER 
         && anneeSaisie >= BORNE_ANNEE_MINIMALE && moisSaisi <= BORNE_ANNEE_MAXIMALE))
      {
         cin.clear();
         cout << SAISIE_INCORRECTE << endl << endl;
      }
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   while(!saisieOk);   
   cout << endl;
}


void saisieEtCheckDate(int& moisDebut, int& moisFin, int& anneeDebut, int& anneeFin)
{
   saisieDate(DATE_DEBUT, moisDebut, anneeDebut);
   do
   {
      saisieDate(DATE_FIN, moisFin, anneeFin);
   }
   while(!(anneeDebut < anneeFin) || ((anneeDebut == anneeFin) && (moisDebut <= moisFin))
         && moisFin <= (int) Mois::DECEMBRE && moisFin >= (int) Mois::JANVIER
         && anneeFin >= BORNE_ANNEE_MINIMALE && anneeFin <= BORNE_ANNEE_MAXIMALE);
 
}

char saisieContinuerProgramme(char& saisieUtilisateur)
{
   cout << "Voulez-vous quitter le programme ? [o/n] : ";
   cin >> saisieUtilisateur;
   if (cin.fail())
   {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   if ((saisieUtilisateur != OUI && saisieUtilisateur != NON)
          and cin.fail() == false)
   {
         cout << "La valeur que vous avez entree n'est pas correcte."
                 " Veuillez recommencer." << endl << endl;
   }
   cout << endl << endl;
   
   return saisieUtilisateur;
}