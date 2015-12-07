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
               - La saisie est de la forme: moisDebut(mm) anneeDebut(yyyy) moisFin anneeFin
                 située entre BORNE_ANNEE_MINIMALE, BORNE_ANNEE_MAXIMAL.
               - Les valeurs du programme peuvent facilement être modifiées 
                 (constantes prévues à cet effet).
               - Le programme est structuré en fonctions
               - Le programme tient compte des années bissextiles.
               - A la fin de la première exécution l'utilisateur a la possibilité
                 d'afficher un nouveau calendrier ou de quitter l'application.
   
 Compilateur : g++ 5.2.0
 -----------------------------------------------------------------------------------
 */
#include <iomanip> 
#include <cstdlib>
#include <limits>
#include <iostream> 
#include <cmath>

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
void saisieDate(const string& messageEntree, int& moisTemp, int& anneeTemp);
void checkSaisieDate(int& mois1, int& mois2, int& annee1, int& annee2);

const int LARGEUR_PREMIERE_COLONNE = 2,
        LARGEUR_COLONNE = 3,
        BORNE_ANNEE_MINIMALE = 1900,
        BORNE_ANNEE_MAXIMALE = 2100,
        DIMANCHE = 7,
        LUNDI = 1;

const string DATE_DEBUT = "Entrez la date de debut: ",
        DATE_FIN = "Entrez la date de fin: ",
        SAISIE_INCORRECTE = "Date non valide. Veuillez SVP recommencer.";

int main() {
   int mois1, mois2, annee1, annee2;
   //int mois1 = 10, mois2 = 1, annee1 = 2014, annee2 = 2015;

   // affichage accueil utilisateur
   cout << "+-----------------------------------------------------+" << endl
           << "|                Bonjour et bienvenue                 |" << endl
           << "+-----------------------------------------------------+" << endl
           << "| Ce programme permet d'afficher le calendrier entre 2|" << endl
           << "| dates ayant la forme mois annee.                    |" << endl
           << "+-----------------------------------------------------+" << endl
           << endl; 
   /*saisieUtilisateur(mois1, mois2, annee1, annee2);*/
   
   
   //void checkSaisieDate(); CONNARD DE MERDE
   checkSaisieDate(mois1, mois2, annee1, annee2);
   
   afficheCalendrier(mois1, mois2, annee1, annee2);

   
   return EXIT_SUCCESS;
}

void afficheCalendrier(int mois1, int mois2, int annee1, int annee2) {
   int mois = mois1;
   int annee = annee1;

   while ((mois <= mois2 && annee == annee2) || annee < annee2) {
      int index = LUNDI;
      int compteur = 1;

      cout << intEnString(mois) + " " << annee << endl << endl;
      cout << setw(LARGEUR_PREMIERE_COLONNE) << setfill(' ') << 'L'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'M'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'M'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'J'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'V'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'S'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'D' << endl;

      while (index < jourSemaineDebut(mois, annee)) {
         cout << ((index == LUNDI) ? setw(LARGEUR_PREMIERE_COLONNE) :
                 setw(LARGEUR_COLONNE)) << setfill(' ') << ' ';
         index++;
      }

      while (compteur <= joursDansMois(mois, annee)) {

         cout << ((index == LUNDI) ? setw(LARGEUR_PREMIERE_COLONNE) :
                 setw(LARGEUR_COLONNE)) << setfill(' ') << compteur;
         index++;
         compteur++;
         if (index > DIMANCHE) {//début semaine           
            index = LUNDI;
            cout << endl;
         }
      }
      mois++;
      if (mois > (int) Mois::DECEMBRE) {//début mois
         mois = (int) Mois::JANVIER;
         annee++;
      }
      cout << endl << endl;
   }
}

string intEnString(int mois) {
   string moisConverti;
   switch ((Mois) mois) {
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
      case Mois::AOUT:moisConverti = "Aout";
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



void saisieDate(const string& messageEntree, int& moisTemp, int& anneeTemp)
{
   bool saisieOk = true;
   do
   {
      cout << messageEntree;
      if(!(saisieOk = static_cast<bool> (cin >> moisTemp >> anneeTemp)
         && moisTemp <= (int)Mois::DECEMBRE && moisTemp >= (int)Mois::JANVIER 
         && anneeTemp >= BORNE_ANNEE_MINIMALE && moisTemp <= BORNE_ANNEE_MAXIMALE))
      {
         cin.clear();
         cout << SAISIE_INCORRECTE << endl << endl;
      }
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   while(!saisieOk);
     
}
void checkSaisieDate(int& mois1, int& mois2, int& annee1, int& annee2)
{
   saisieDate(DATE_DEBUT, mois1, annee1);
   do
   {
      saisieDate(DATE_FIN, mois2, annee2);
   }
   while(!((annee1 < annee2) || ((annee1 == annee2) && (mois1 <= mois2)))
         && mois2 <= (int) Mois::DECEMBRE && mois2 >= (int) Mois::JANVIER
         && annee2 >= BORNE_ANNEE_MINIMALE && annee2 <= BORNE_ANNEE_MAXIMALE);
 
}



void saisieUtilisateur(int& mois1, int& mois2, int& annee1, int& annee2) {
   bool saisieOk = true;

   do {
      cout << DATE_DEBUT;
      if (!(saisieOk = static_cast<bool> (cin >> mois1 >> annee1)
              && mois1 <= (int) Mois::DECEMBRE && mois1 >= (int) Mois::JANVIER
              && annee1 >= BORNE_ANNEE_MINIMALE && annee1 <= BORNE_ANNEE_MAXIMALE)) {
         cin.clear();
         cout << SAISIE_INCORRECTE << endl << endl;
      }
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while (!saisieOk);
   
   cout << endl;
   
   do {
      cout << DATE_FIN;
      if (!(saisieOk = static_cast<bool> (cin >> mois2 >> annee2)
              && ((annee1 < annee2) || ((annee1 == annee2) && (mois1 <= mois2)))
              && mois2 <= (int) Mois::DECEMBRE && mois2 >= (int) Mois::JANVIER
              && annee2 >= BORNE_ANNEE_MINIMALE && annee2 <= BORNE_ANNEE_MAXIMALE)) {
         cin.clear();
         cout << SAISIE_INCORRECTE << endl << endl;
      }
      cin.ignore(numeric_limits<streamsize>::max(), '\n');   
   } while (!saisieOk);
   
   cout << endl;
}

int jourSemaineDebut(int mois, int annee) {
   int premierJour;

   if (mois >= (int) Mois::MARS) {
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

   if (estBissextile(annee) && mois == (int) Mois::FEVRIER) {
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
