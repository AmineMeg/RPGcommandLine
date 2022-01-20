#include <chrono>
#include <algorithm>
#include "Chateau.hpp"
#include "Arme.hpp"
#include "Armure.h"
#include "PotionSoin.hpp"

bool check, check2 = false;

__uint128_t g_lehmer64_state = 1337;

uint64_t lehmer64() {
    g_lehmer64_state *= 0xda942042e4dd58b5;
    return g_lehmer64_state >> 64;
}

// Constructeur
Chateau::Chateau(int nbSalles, vector<Personnage *> listePersonnage) : compteur(0) {
    vector < Personnage * > listePersonnageAModifier{};
    listePersonnageAModifier.assign(listePersonnage.begin(), listePersonnage.end());
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    std::shuffle(std::begin(listePersonnageAModifier),
                 std::end(listePersonnageAModifier), rng);
    for (int i = 0; i < nbSalles; i++) {
        if ((i == nbSalles / 4) || (i == ((nbSalles * 2) / 4)) || (i == ((nbSalles * 3) / 4)) ||
            (i == (nbSalles) - 1)) {
            creerNoeud(listePersonnageAModifier, 1);
            listePersonnageAModifier.pop_back();
        } else {
            creerNoeud(listePersonnageAModifier, 0);
        }
    }
    creerConnexions();
    ajouterObjet();
}

void Chateau::ajouterObjet() {
    Arme *arme1 = new Arme("arme 1", 5, -2, 1);
    Arme *arme2 = new Arme("arme 2", 5, -2, 1);
    Arme *arme3 = new Arme("arme 3", 5, -2, 1);
    Armure *armure1 = new Armure("Armure 1", 1, 1, 1);
    Armure *armure2 = new Armure("Armure 2", 1, 1, 1);
    Armure *armure3 = new Armure("Armure 3", 1, 1, 1);
    PotionSoin *potion = new PotionSoin();

    vector < Objet * > listeObjet;
    listeObjet.push_back(arme1);
    listeObjet.push_back(arme2);
    listeObjet.push_back(arme3);
    listeObjet.push_back(armure1);
    listeObjet.push_back(armure2);
    listeObjet.push_back(armure3);
    listeObjet.push_back(potion);
    srand((unsigned int) time(0));
    for (int i = 0; i < listeObjet.size(); i++) {
        int pieceAleat = rand() % listeSalle.size();
        listeSalle.at(pieceAleat)->objetsPresent.push_back(listeObjet.at(i));
    }
}

// Destructeur
Chateau::~Chateau() {
    Salle *del;
    int i = 0;
    while (i < compteur) {
        del = listeSalle[i];
        delete del;
        i++;
    }
}

Salle *Chateau::creerNoeud(vector<Personnage *> listePerso, int check) {
    Salle *temp = new Salle;
    temp->nom = to_string(compteur);
    temp->haut = NULL;
    temp->bas = NULL;
    temp->gauche = NULL;
    temp->droite = NULL;
    if (check == 1) {
        temp->personnagesPresent.push_back(listePerso[listePerso.size() - 1]);
        listePerso[listePerso.size() - 1]->setPosition(compteur);
    }
    listeSalle.push_back(temp);
    compteur++;
    return temp;
}


void Chateau::supprimer() {
    for (int i = 0; i < compteur; i++) {
        Salle *temp = listeSalle[i];
        temp->haut = NULL;
        temp->bas = NULL;
        temp->gauche = NULL;
        temp->droite = NULL;
        delete temp;
    }
}

void afficherVect(vector<Salle *> liste) {
    cout << "[ ";
    for (int i = 0; i < liste.size(); i++) {
        cout << liste[i]->nom << " , ";
    }
    cout << "]" << endl;
}

void Chateau::creerConnexions() {
    vector < Salle * > listeSalleAModifier(listeSalle.size());
    listeSalleAModifier.assign(listeSalle.begin(), listeSalle.end());
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    std::shuffle(std::begin(listeSalleAModifier),
                 std::end(listeSalleAModifier), rng);
    for (int i = listeSalle.size() - 1; i > 1; i--) {// Pour chaque salle
        Salle *selected = listeSalleAModifier[listeSalleAModifier.size() - 1];
        listeSalleAModifier.pop_back();
        if (selected->nbPorteLibres > 0) { //sinon ? et on sort selected quand ?
            int nbPortes = lehmer64() % std::min(selected->nbPorteLibres, (int) listeSalleAModifier.size()) +
                           1; // Choisir un nombre de portes entre 0 et 4
            mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
            std::shuffle(std::begin(listeSalleAModifier),
                         std::end(listeSalleAModifier), rng);
            int j = 0;
            while (j < nbPortes &&
                   listeSalleAModifier.size() > 0 &&
                   selected->nbPorteLibres != 0) {
                while (listeSalleAModifier[listeSalleAModifier.size() - 1 - j]->nbPorteLibres == 0) {
                    listeSalleAModifier.pop_back();
                    j++;
                }
                if (listeSalleAModifier.size() - 1 - j >= 0) {
                    selectPorte(selected, listeSalleAModifier[listeSalleAModifier.size() - 1 - j]);
                    check = false;
                    check2 = false;
                }
                j++;
            }
        }
    }
}

bool Chateau::securiteVerif(){
    for (int i = 0; i < compteur; i++) {
        if (listeSalle[i]->haut == NULL &&
            listeSalle[i]->bas == NULL &&
            listeSalle[i]->gauche == NULL &&
            listeSalle[i]->droite == NULL) {
            return false;
        }
    }
    return true;
}

void Chateau::selectPorte(Salle *salle, Salle *nextSalle) {
    int choix = lehmer64() % 4 + 1;
    switch (choix) {
        case 1:
            if (check == false) {
                if (salle->haut != NULL) {
                    selectPorte(salle, nextSalle);
                    break;
                } else {
                    salle->haut = nextSalle;
                    selectPorte2(nextSalle, salle);
                    salle->nbPorteLibres--;
                    check = true;
                    break;
                }
            }
            break;
        case 2:
            if (check == false) {
                if (salle->bas != NULL) {
                    selectPorte(salle, nextSalle);
                    break;
                } else {
                    salle->bas = nextSalle;
                    selectPorte2(nextSalle, salle);
                    salle->nbPorteLibres--;
                    check = true;
                    break;
                }
            }
            break;
        case 3:
            if (check == false) {
                if (salle->gauche != NULL) {
                    selectPorte(salle, nextSalle);
                    break;
                } else {
                    salle->gauche = nextSalle;
                    salle->nbPorteLibres--;
                    selectPorte2(nextSalle, salle);
                    check = true;
                    break;
                }
            }
            break;
        case 4:
            if (check == false) {
                if (salle->droite != NULL) {
                    selectPorte(salle, nextSalle);
                    break;
                } else {
                    salle->droite = nextSalle;
                    selectPorte2(nextSalle, salle);
                    salle->nbPorteLibres--;
                    check = true;
                    break;
                }
            }
            break;
        default:
            break;
    }
}

void Chateau::selectPorte2(Salle *salle, Salle *nextSalle) {
    int choix = lehmer64() % 4 + 1;
    switch (choix) {
        case 1:
            if (check2 == false) {
                if (salle->haut != NULL) {
                    selectPorte2(salle, nextSalle);
                    break;
                } else {
                    salle->haut = nextSalle;
                    salle->nbPorteLibres--;
                    check2 = true;
                    break;
                }
            }
            break;
        case 2:
            if (check2 == false) {
                if (salle->bas != NULL) {
                    selectPorte2(salle, nextSalle);
                    break;
                } else {
                    salle->bas = nextSalle;
                    salle->nbPorteLibres--;
                    check2 = true;
                    break;
                }
            }
            break;
        case 3:
            if (check2 == false) {
                if (salle->gauche != NULL) {
                    selectPorte2(salle, nextSalle);
                    break;
                } else {
                    salle->gauche = nextSalle;
                    salle->nbPorteLibres--;
                    check2 = true;
                    break;
                }
            }
            break;
        case 4:
            if (check2 == false) {
                if (salle->droite != NULL) {
                    selectPorte2(salle, nextSalle);
                    break;
                } else {
                    salle->droite = nextSalle;
                    salle->nbPorteLibres--;
                    check2 = true;
                    break;
                }
            }
            break;
        default:
            break;
    }
}

void Chateau::afficher() {
    if (compteur == 0) {
        cout << "La liste est vide!" << endl;
        return;
    }
    for (int i = 0; i < compteur; i++) {
            if (listeSalle[i]->haut == NULL &&
            listeSalle[i]->bas == NULL &&
            listeSalle[i]->gauche == NULL &&
            listeSalle[i]->droite == NULL)
            {
                cout << "BUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG" << endl;
            } else

            if (listeSalle[i]->haut != NULL) {
                cout << "               haut " << listeSalle[i]->haut->nom << endl;
            } else {
                cout << "               haut MUR " << endl;
            }


            if (listeSalle[i]->droite != NULL && listeSalle[i]->gauche != NULL) {
                cout << "gauche " << listeSalle[i]->gauche->nom
                     << "  | Salle " << listeSalle[i]->nom << " |   droite "
                     << listeSalle[i]->droite->nom << endl;


            } else if (listeSalle[i]->droite != NULL && listeSalle[i]->gauche == NULL) {
                cout << "gauche MUR"
                     << "  | Salle " << listeSalle[i]->nom << " |   droite "
                     << listeSalle[i]->droite->nom << endl;

            } else if (listeSalle[i]->droite == NULL && listeSalle[i]->gauche != NULL) {
                cout << "gauche " << listeSalle[i]->gauche->nom <<
                     "  | Salle " << listeSalle[i]->nom << " |   droite MUR" << endl;

            } else if (listeSalle[i]->droite == NULL && listeSalle[i]->gauche == NULL) {
                cout << "gauche MUR  | Salle " << listeSalle[i]->nom << " |   droite MUR"
                     << endl;
            } else {
            }
            cout << "Personnage present :";
            for (int j = 0; j < listeSalle[i]->personnagesPresent.size(); j++) {
                cout << listeSalle[i]->personnagesPresent[j]->getNom() << " | " << endl;
            }
            cout << "Objet present :";
            for (int j = 0; j < listeSalle[i]->objetsPresent.size(); j++) {
                cout << listeSalle[i]->objetsPresent[j]->getNom() << " | " << endl;
            }
            if (listeSalle[i]->bas != NULL) {
                cout << "               bas " << listeSalle[i]->bas->nom << "\n" << endl;
            } else {
                cout << "               bas MUR \n" << endl;
            }

    }
}

int Chateau::taille() const {
    return compteur;
}


vector<Salle *> Chateau::getListeSalle() {
    return listeSalle;
}

