/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "saisies.h"

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
