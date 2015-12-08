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

int premierJourSemaineDuMois(int mois, int annee);
void afficheCalendrier(int moisDebut, int moisFin, int anneeDebut, int anneeFin);
string conversionNombreEnMois(int mois);
bool estBissextile(int annee);
int nbreDeJoursDansMois(int mois, int annee);
void saisieDate(const string& messageEntree, int& moisSaisi, int& anneeSaisie);
void saisieEtCheckDate(int& moisDebut, int& moisFin, int& anneeDebut, int& anneeFin);

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
   int moisDebut, moisFin, anneeDebut, anneeFin;
   
   // affichage accueil utilisateur
   cout << "+-----------------------------------------------------+" << endl
           << "|                Bonjour et bienvenue                 |" << endl
           << "+-----------------------------------------------------+" << endl
           << "| Ce programme permet d'afficher le calendrier entre 2|" << endl
           << "| dates ayant la forme mois annee.                    |" << endl
           << "+-----------------------------------------------------+" << endl
           << endl; 
   
  
   saisieEtCheckDate(moisDebut, moisFin, anneeDebut, anneeFin);
   
   afficheCalendrier(moisDebut, moisFin, anneeDebut, anneeFin);

   
   return EXIT_SUCCESS;
}

void afficheCalendrier(int moisDebut, int moisFin, int anneeDebut, int anneeFin) {
   int mois = moisDebut;
   int annee = anneeDebut;

   while ((mois <= moisFin && annee == anneeFin) || annee < anneeFin) {
      int index = LUNDI;
      int compteur = 1;

      cout << conversionNombreEnMois(mois) + " " << annee << endl << endl;
      cout << setw(LARGEUR_PREMIERE_COLONNE) << setfill(' ') << 'L'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'M'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'M'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'J'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'V'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'S'
           << setw(LARGEUR_COLONNE) << setfill(' ') << 'D' << endl;

      while (index < premierJourSemaineDuMois(mois, annee)) {
         cout << ((index == LUNDI) ? setw(LARGEUR_PREMIERE_COLONNE) :
                 setw(LARGEUR_COLONNE)) << setfill(' ') << ' ';
         index++;
      }

      while (compteur <= nbreDeJoursDansMois(mois, annee)) {

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

string conversionNombreEnMois(int mois) {
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
   while(!((anneeDebut < anneeFin) || ((anneeDebut == anneeFin) && (moisDebut <= moisFin)))
         && moisFin <= (int) Mois::DECEMBRE && moisFin >= (int) Mois::JANVIER
         && anneeFin >= BORNE_ANNEE_MINIMALE && anneeFin <= BORNE_ANNEE_MAXIMALE);
 
}

int premierJourSemaineDuMois(int mois, int annee) {
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

int nbreDeJoursDansMois(int mois, int annee) {
   int nbreDeJoursDansMois;

   if (estBissextile(annee) && mois == (int) Mois::FEVRIER) {
      nbreDeJoursDansMois = 29;
   } else {
      switch ((Mois) mois) {
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