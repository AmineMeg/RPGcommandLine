//
// Created by kreek on 13/01/2022.
//

#include <chrono>
#include "Chateau.hpp"

bool check, check2 = false;

__uint128_t g_lehmer64_state = 1337;

uint64_t lehmer64() {
    g_lehmer64_state *= 0xda942042e4dd58b5;
    return g_lehmer64_state >> 64;
}

// Constructeur
Chateau:: Chateau(int nbSalles): compteur (0) {
    for(int i = 0; i < nbSalles; i++){

        creerNoeud();
    }
    creerConnexions();
}

// Destructeur
Chateau :: ~Chateau ()
{
    Salle* del;
    int i = 0;
    while (i < compteur){
        del = listeSalle[i];
        delete del;
        i++;
    }
}

Salle* Chateau :: creerNoeud (){
    Salle* temp = new Salle;
    temp -> nom = to_string(compteur);
    temp -> haut = NULL;
    temp -> bas = NULL;
    temp -> gauche = NULL;
    temp -> droite = NULL;
    listeSalle.push_back(temp);
    compteur++;
    return temp;
}



void Chateau :: supprimer (){
    for(int i = 0; i<compteur; i++){
        Salle* temp = listeSalle[i];
        temp -> haut = NULL;
        temp -> bas = NULL;
        temp -> gauche = NULL;
        temp -> droite = NULL;
        delete temp;
    }
}

void afficherVect(vector<Salle*> liste){
    cout << "[ ";
    for (int i = 0; i < liste.size(); i ++){
        cout << liste[i] -> nom << " , ";
    }
    cout << "]" << endl;
}

void Chateau :: creerConnexions (){
    vector<Salle *> listeSalleAModifier (listeSalle.size());
    listeSalleAModifier.assign(listeSalle.begin(), listeSalle.end());
    cout << "Sous liste bien crée" << endl;
    for (int i = compteur -1; i > 0; i--){// Pour chaque porte

        Salle * selected = listeSalleAModifier[listeSalleAModifier.size()-1];
        cout << "\n\n\n\nPorte = " << selected -> nom << endl;
        cout << "Selected passed" <<  endl;
        if(selected -> nbPorteLibres > 0) {
            int nbPortes = lehmer64() % selected->nbPorteLibres + 1; // Choisir un nombre de portes entre 0 et 4
            cout << "nbPortesLibres passed" << endl;
            cout << "\n \n Size before :" << listeSalleAModifier.size() << endl;
            afficherVect(listeSalleAModifier);
            listeSalleAModifier.pop_back();
            cout << "\n \n Size after :" << listeSalleAModifier.size() << endl;
            if (listeSalleAModifier.size() > 0) {
                afficherVect(listeSalleAModifier);
                mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
                std::shuffle(std::begin(listeSalleAModifier),
                             std::end(listeSalleAModifier), rng);
                cout << "Random crée" << endl;
                int j = 0;
                cout << "\nNB portes DITES LIBRES :\n" << selected->nbPorteLibres << endl;
                cout << "NB portesLibres num : " << nbPortes << endl;
                while (j < nbPortes && listeSalleAModifier.size() - 1 - j > 0 && selected->nbPorteLibres != 0) {
                    cout << " Porte j = " << j << endl;
                    while (listeSalleAModifier[listeSalleAModifier.size() - 1 - j]->nbPorteLibres == 0) {
                        listeSalleAModifier.pop_back();
                        cout << "check if it's free " << endl;
                        if (listeSalleAModifier.size() - 1 - j <= 0) {
                            return;
                        }
                    }
                    if (listeSalleAModifier.size() - 1 - j > 0) {
                        cout << "go selectPorte" << endl;
                        cout << "SALLE 1 : " << selected->nom << endl;
                        cout << "SALLE 2 :" << listeSalleAModifier[listeSalleAModifier.size() - 1 - j]->nom
                             << " position dans la liste "
                             << listeSalleAModifier.size() - j << endl;
                        afficherVect(listeSalleAModifier);
                        selectPorte(selected, listeSalleAModifier[listeSalleAModifier.size() - 1 - j]);
                        check = false;
                        check2 = false;
                        cout << "selectPorteDone \n check :" << listeSalleAModifier.size() - 1 - j << endl;
                        j++;
                    } else {
                        return;
                    }
                }
            }
            else {
                return;
            }
        }
    }
}

void Chateau :: selectPorte(Salle * salle, Salle * nextSalle){
    int choix = lehmer64() %4 + 1;
    switch (choix) {
        case 1:
            if (check == false){
                if (salle->haut != NULL) {
                    selectPorte(salle, nextSalle);
                    break;
                } else {
                    cout << "Affectation 1 haut" << endl;
                    salle->haut = nextSalle;
                    cout <<"fait"<< endl;
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
                    cout << "Affectation 1 bas" << endl;
                    salle->bas = nextSalle;
                    cout <<"fait"<< endl;
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
                    cout << "Affectation 1 gauche" << endl;
                    salle->gauche = nextSalle;
                    cout <<"fait"<< endl;
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
                    cout << "Affectation 1 droite" << endl;
                    salle->droite = nextSalle;
                    cout <<"fait"<< endl;
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
void Chateau :: selectPorte2(Salle * salle, Salle * nextSalle){
    int choix = lehmer64() %4 + 1;
    cout<<"tentative affect2"<< endl;
    switch (choix) {
        case 1:
            if (check2 == false) {
                if (salle->haut != NULL) {
                    selectPorte2(salle, nextSalle);
                    break;
                } else {
                    cout << "Affectation 2 haut" << endl;
                    salle->haut = nextSalle;
                    cout << "ICCI " << salle -> haut -> nom << endl;
                    cout << nextSalle -> nom << "\n"<< endl;
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
                    cout << "Affectation 2 bas" << endl;
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
                    cout << "Affectation 2 gauche" << endl;
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
                    cout << "Affectation 2 droite" << endl;
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

void Chateau :: afficher () {
    if (compteur == 0) {
        cout << "La liste est vide!" << endl;
        return;
    }
    for (int i = 0; i < compteur; i++) {
        if (listeSalle[i]->haut != NULL) {
            cout << "               haut " << listeSalle[i]->haut->nom << endl;
        } else {
            cout << "               haut MUR " << endl;
        }


        if (listeSalle[i]->droite != NULL && listeSalle[i]->gauche != NULL) {
            cout << "cas 1" << endl;
            cout << "gauche " << listeSalle[i]->gauche->nom
                 << "  | Salle " << listeSalle[i]->nom << " |   droite "
                 << listeSalle[i]->droite->nom << endl;


        } else if (listeSalle[i]->droite != NULL && listeSalle[i]->gauche == NULL) {
            cout << "cas 2 "<< endl;
            cout << "gauche MUR"
                 << "  | Salle " << listeSalle[i]->nom << " |   droite "
                 << listeSalle[i]->droite->nom << endl;

        } else if (listeSalle[i]->droite == NULL && listeSalle[i]->gauche != NULL) {
            cout << "cas 3" << endl;
            cout << "gauche " << listeSalle[i]->gauche->nom <<
                  "  | Salle " << listeSalle[i]->nom << " |   droite MUR"<< endl;

        }
        else if(listeSalle[i] -> droite == NULL && listeSalle[i] -> gauche == NULL) {
            cout << "cas 4" << endl;
            cout << "gauche MUR  | Salle " << listeSalle[i] -> nom << " |   droite MUR"
                 << endl;
        } else {
            cout << "cas 5" << endl;
            cout << " BUUUUUUUUUUGGGGG " << endl;
        }
        if (listeSalle[i] -> bas != NULL){
            cout << "               bas " << listeSalle[i] -> bas  -> nom<< "\n" <<endl;
        } else {
            cout << "               bas MUR \n" << endl;
        }
    }
}

int Chateau :: taille () const{
    return compteur;
}
