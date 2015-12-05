/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo5
 Fichier     : labo5.cpp
 Auteur(s)   : Saez Sebastien, Jérémie Zanone
 Date        : 02.12.2015

 But         : 

 Remarque(s) : 

 Compilateur : g++ 5.2.0
 -----------------------------------------------------------------------------------
 */
#include <iomanip> 
#include <cstdlib>
#include <limits>
#include <iostream> 
#include <cmath>
#include <string>

using namespace std;

enum class Mois {
   JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE, 
   OCTOBRE, NOVEMBRE, DECEMBRE
};

void saisieUtilisateur(int&, int&, int&, int&);
int jourSemaineDebut(int mois, int annee);
void afficheCalendrier(int mois1, int mois2, int annee1, int annee2);
string intEnString(int mois);
bool estBissextile(int annee);
int joursDansMois(int mois, int annee);

const int LARGEUR_PREMIERE_COLONNE = 2,
          LARGEUR_COLONNE = 3,
          BORNE_ANNEE_MINIMALE = 1900,
          BORNE_ANNEE_MAXIMALE = 2100;

int main() {
   int mois1, mois2, annee1, annee2;

   // affichage accueil utilisateur
   cout << "+-----------------------------------------------------+" << endl
           << "|                Bonjour et bienvenue                 |" << endl
           << "+-----------------------------------------------------+" << endl
           << "| Ce programme permet d'afficher le calendrier entre 2|" << endl
           << "| dates ayant la forme mois/annee.                    |" << endl
           << "+-----------------------------------------------------+" << endl;

   saisieUtilisateur(mois1, mois2, annee1, annee2);
   afficheCalendrier(mois1, mois2, annee1, annee2);
   
   return EXIT_SUCCESS;
}

void afficheCalendrier(int mois1, int mois2, int annee1, int annee2) {
   int mois = mois1;
   int annee = annee1;

   while ((mois <= mois2 && annee<=annee2) || annee<annee2) {
      int index = 1;
      int compteur = 1;

      cout << intEnString(mois) + " " << annee << endl << endl;
      cout << setw(LARGEUR_COLONNE) << setfill(' ') << 'L'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'M'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'M'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'J'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'V'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'S'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'D' << endl;

      while (index < jourSemaineDebut(mois, annee)) {
         cout << setw(LARGEUR_COLONNE) << setfill(' ') << ' ';
         index++;
      }

      while (compteur <= joursDansMois(mois, annee)) {

         cout << ((index == 1) ? setw(LARGEUR_PREMIERE_COLONNE) : 
                  setw(LARGEUR_COLONNE)) << setfill(' ') << compteur;
         index++;
         compteur++;
         if (index == 8) {//début semaine
            cout << endl;
            index = 1;
         }
      }
      mois++;
      if (mois == 13) {//début mois
         mois = (int)Mois::JANVIER;
         annee++;
      }
      cout << endl << endl;
   }
}

string intEnString(int mois) {
   switch ((Mois) mois) {
      case Mois::JANVIER: return "Janvier";
         break;
      case Mois::FEVRIER: return "Fevrier";
         break;
      case Mois::MARS: return "Mars";
         break;
      case Mois::AVRIL: return "Avril";
         break;
      case Mois::MAI:return "Mai";
         break;
      case Mois::JUIN:return "Juin";
         break;
      case Mois::JUILLET:return "Juillet";
         break;
      case Mois::AOUT:return "Aout";
         break;
      case Mois::SEPTEMBRE:return "Septembre";
         break;
      case Mois::OCTOBRE:return "Octobre";
         break;
      case Mois::NOVEMBRE:return "Novembre";
         break;
      case Mois::DECEMBRE:return "Decembre";
         break;
   }
}

void saisieUtilisateur(int& mois1, int& mois2, int& annee1, int& annee2) {
   bool saisieOk = true;

   do {
      cout << "Entrez la date de debut: ";
      if (!(saisieOk = static_cast<bool>(cin >> mois1 >> annee1)) || mois1 > 12 
         || mois1 < 1 || annee1 < BORNE_ANNEE_MINIMALE || annee1 > BORNE_ANNEE_MAXIMALE) {
         cin.clear();
         cout << "Date non valide. Veuillez SVP recommencer." << endl;
         saisieOk = false;
         cout << endl;
      }
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while (!saisieOk);

   cout << endl;
   do {
      cout << "Entrez la date de fin : ";
      if (!(saisieOk = static_cast<bool>(cin >> mois2 >> annee2)) || !((annee1 
         < annee2) || ((annee1 == annee2) && (mois1 < mois2)))
         || mois2 > 12 || mois2 < 1 || annee2 < BORNE_ANNEE_MINIMALE || 
         annee2 > BORNE_ANNEE_MAXIMALE) {
         cin.clear();
         cout << "Date non valide. Veuillez SVP recommencer." << endl;
         saisieOk = false;
         cout << endl;
      }
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while (!saisieOk);
}

int jourSemaineDebut(int mois, int annee) {
   int premierJour;

   if (mois >= 3) {
      premierJour = (int) (floor((23 * mois) / 9) + 1 + 4 + annee + 
      floor(annee / 4) - floor(annee / 100) + floor(annee / 400) - 2) % 7;
   } else {
      premierJour = (int) (floor((23 * mois) / 9) + 1 + 4 + annee + 
      floor((annee - 1) / 4) - floor((annee - 1) / 100) + floor((annee - 1) / 400)) % 7;
   }

   if (premierJour == 0) {
      premierJour = 7;
   }
   return premierJour;
}

bool estBissextile(int annee) {
   return (annee % 400 == 0) || ((annee % 4 == 0) && ((annee % 100) != 0));
}

int joursDansMois(int mois, int annee) {
   int joursDansMois;

   if (estBissextile(annee) && mois == 2) {
      joursDansMois = 29;
   } else {
      switch ((Mois) mois) {
         case Mois::FEVRIER:
            joursDansMois = 28;
            break;
         case Mois::AVRIL:
         case Mois::JUIN:
         case Mois::SEPTEMBRE:
         case Mois::NOVEMBRE:
            joursDansMois = 30;
            break;
         default:
            joursDansMois = 31;
            break;
      }
   }
   return joursDansMois;
}