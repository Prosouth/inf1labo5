/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "traitementEtAffichage.h"


bool estBissextile(int annee) 
{
   return (annee % 400 == 0) || ((annee % 4 == 0) && ((annee % 100) != 0));
}



int nbreDeJoursDansMois(int mois, int annee) 
{
   int nbreDeJoursDansMois;

   if (estBissextile(annee) && mois == (int) Mois::FEVRIER) 
   {
      nbreDeJoursDansMois = 29;
   } 
   else 
   {
      switch ((Mois) mois) 
      {
         case Mois::FEVRIER:
            nbreDeJoursDansMois = 28;
            break;
         case Mois::AVRIL:
         case Mois::JUIN:
         case Mois::SEPTEMBRE:
         case Mois::NOVEMBRE:
            nbreDeJoursDansMois = 30;
            break;
         default:
            nbreDeJoursDansMois = 31;
            break;
      }
   }
   
   return nbreDeJoursDansMois;
}


int premierJourSemaineDuMois(int mois, int annee) 
{
   int premierJour;

   if (mois >= (int) Mois::MARS) 
   {
      premierJour = (int) (floor((23 * mois) / 9) + 1 + 4 + annee +
                    floor(annee / 4) - floor(annee / 100) + floor(annee / 400) 
                    - 2) % 7;
   } 
   else 
   {
      premierJour = (int) (floor((23 * mois) / 9) + 1 + 4 + annee +
                    floor((annee - 1) / 4) - floor((annee - 1) / 100) 
                    + floor((annee - 1) / 400)) % 7;
   }

   if (premierJour == 0) 
   {
      premierJour = 7;
   }
   
   return premierJour;
}

string conversionNombreEnMois(int mois) 
{
   string moisConverti;
   switch((Mois)mois) 
   {
      case Mois::JANVIER: moisConverti = "Janvier";
         break;
      case Mois::FEVRIER: moisConverti = "Fevrier";
         break;
      case Mois::MARS: moisConverti = "Mars";
         break;
      case Mois::AVRIL: moisConverti = "Avril";
         break;
      case Mois::MAI: moisConverti = "Mai";
         break;
      case Mois::JUIN: moisConverti = "Juin";
         break;
      case Mois::JUILLET: moisConverti = "Juillet";
         break;
      case Mois::AOUT: moisConverti = "Aout";
         break;
      case Mois::SEPTEMBRE: moisConverti = "Septembre";
         break;
      case Mois::OCTOBRE: moisConverti = "Octobre";
         break;
      case Mois::NOVEMBRE: moisConverti = "Novembre";
         break;
      case Mois::DECEMBRE: moisConverti = "Decembre";
         break;
   }
   
   return moisConverti;
}


void afficheCalendrier(int moisDebut, int mois2, int annee1, int annee2) 
{
   int moisAffiche = moisDebut;
   int annee = annee1;
   
   while((moisAffiche <= mois2 && annee == annee2) || annee < annee2) 
   {
      int index = LUNDI;
      int premierJourDuMois = premierJourSemaineDuMois(moisAffiche, annee);
      int nbreJoursDansMois = nbreDeJoursDansMois(moisAffiche, annee);
     
     
      cout << conversionNombreEnMois(moisAffiche) + " " << annee << endl << endl;
      cout << setw(LARGEUR_PREMIERE_COLONNE) << setfill(' ') << 'L'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'M'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'M'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'J'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'V'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'S'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'D' << endl;
 
      while(index < premierJourDuMois) 
      {
         cout << ((index == LUNDI) ? setw(LARGEUR_PREMIERE_COLONNE) :
                  setw(LARGEUR_COLONNE)) << setfill(' ') << ' ';
         index++;
      }
 
      for(int compteur = 1; compteur <= nbreJoursDansMois; compteur++) {
         cout << ((index == LUNDI) ? setw(LARGEUR_PREMIERE_COLONNE) :
                 setw(LARGEUR_COLONNE)) << setfill(' ') << compteur;
         index++;
 
         if(index > DIMANCHE) 
         {//début semaine          
            index = LUNDI;
            cout << endl;
         }
      }
      moisAffiche++;
      if(moisAffiche > (int) Mois::DECEMBRE) 
      {//début mois
         moisAffiche = (int) Mois::JANVIER;
         annee++;
      }
      cout << endl << endl;
   }
}


void affichageBienvenue()
{
      
   // Affichage accueil utilisateur
   cout << "+-----------------------------------------------------+" << endl
        << "|                Bonjour et bienvenue                 |" << endl
        << "+-----------------------------------------------------+" << endl
        << "| Ce programme permet d'afficher le calendrier entre 2|" << endl
        << "| dates.                                              |" << endl
        << "| Veuillez rentrer les dates sous la forme (mm yyyy)  |" << endl
        << "+-----------------------------------------------------+" << endl
        << endl; 
   
}