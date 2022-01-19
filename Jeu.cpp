#include "Chateau.hpp"
#include "Sorcieres.hpp"
#include "Jeu.hpp"
#include "Amazones.hpp"
#include "Guerriers.hpp"
#include "Moines.hpp"
Jeu::Jeu(){

}

void Jeu::creationJoueur(){
    cout<<"Vous avec le choix entre 4 classes :\n 1- Le Guerrier \n 2- Le Mage \n 3- La Sorciere\n 4- L'Amazone"<<endl;
    int rep;
    cin>>rep;
    string nomJoueur;
    cout<<"Entrez le nom de votre champion ;)" <<endl;
    cin>> nomJoueur;

    while(rep<1 || rep>4){
        cout<<"choisissez un personnage valable !"<<endl;
        cin>>rep;
    }
    if(rep==4){
         Amazones * am = new Amazones(nomJoueur);
         cout<<"sante "<<am->getSante();
         joueur=am;
         listePerso.push_back(am);
         Guerriers * gu = new Guerriers("bot1");
         Moines * mo = new Moines("bot2");
         Sorcieres * so = new Sorcieres("bot3");
         listePerso.push_back(gu);
         listePerso.push_back(mo);
         listePerso.push_back(so);
    }else if(rep == 3){
        Sorcieres * so = new Sorcieres(nomJoueur);
        joueur=so;
        listePerso.push_back(so);
        Guerriers * gu = new Guerriers("bot1");
        Moines * mo = new Moines("bot2");
        Amazones * am = new Amazones("bot3");
        listePerso.push_back(gu);
        listePerso.push_back(mo);
        listePerso.push_back(am);
    }else if(rep==2){
        Moines * mo = new Moines(nomJoueur);
        joueur=mo;
        listePerso.push_back(mo);
        Guerriers * gu = new Guerriers("bot1");
        Sorcieres * so = new Sorcieres("bot2");
        Amazones * am = new Amazones("bot3");
        listePerso.push_back(gu);
        listePerso.push_back(so);
        listePerso.push_back(am);
    }else{
        Guerriers * gu = new Guerriers(nomJoueur);
        joueur=gu;
        listePerso.push_back(gu);
        Moines * mo = new Moines("bot1");
        Sorcieres * so = new Sorcieres("bot2");
        Amazones * am = new Amazones("bot3");
        listePerso.push_back(mo);
        listePerso.push_back(so);
        listePerso.push_back(am);
    }

}

void Jeu::partie (){
    creationJoueur();

    cout << "veuillez choisir le nombre de salles voulus (entre 10 et 100)" << endl;
    int choixNbSalle = 0;
    cin >> choixNbSalle;
    while (choixNbSalle <= 10 && choixNbSalle>101){
        cout << "Op op op non non non monsieur, on a dit entre 10 et 100" << endl;
        cin >> choixNbSalle;
    }
    if (choixNbSalle % 2 == 0){
        choixNbSalle++;
    }
    Chateau * chateau = new Chateau (choixNbSalle, listePerso);
    while (enCours){
        //chateau->afficher();
        for (int i=0;i<listePerso.size();i++){
            cout <<listePerso.at(i)<<endl<<endl;
        }
        for(int i=0;i<listePerso.size();i++){
            if(listePerso.at(i)==joueur){
                int action;
                cout<<"Vous pouvez :(1 action = 1 tour) \n 1-changer de piece \n 2-rammasser un objet \n 3-utiliser une Potion \n 4-Rien "<<endl;
                cin >>action;
                if(action==1)
                    changerDeSalleJoueur(chateau);
                else if(action ==3){
                    for(int i =0;i<joueur->getSac().size();i++){
                        if(joueur->getSac().at(i)->getNom()=="Potion de soin"){
                            cout << "Vous avez une potion de soin, vous l'utilisez !"<<endl;
                            joueur->getSac().at(i)->utiliser();
                        }else{
                            cout<<"Vous n'avez pas de potions !"<<endl;
                        }
                    }
                }
            }
            /*else
                changerSalleBot(chateau,listePerso.at(i));*/
        }
        checkCombat(chateau);
    
       }
}

void Jeu::changerSalleBot(Chateau * chateau, Personnage * bot){
    vector<int> choix;
    vector<int> salleDuChoix = {-1, -1, -1, -1};
    srand((unsigned int)time(0));
    if (chateau->getListeSalle()[bot->getPosition()]-> haut != NULL){
        choix.push_back(1);
         salleDuChoix.at(0)=std::stoi(
                chateau->getListeSalle()[bot->getPosition()]->haut->nom);
    }
    if (chateau->getListeSalle()[bot->getPosition()]-> bas != NULL){
        choix.push_back(2);
        salleDuChoix.at(1)=std::stoi(
                chateau->getListeSalle()[bot->getPosition()]->bas->nom);
    }
    if (chateau->getListeSalle()[bot->getPosition()]-> gauche != NULL){
        choix.push_back(3);
        salleDuChoix.at(2)=std::stoi(
                chateau->getListeSalle()[bot->getPosition()]->gauche->nom);
    }
    if (chateau->getListeSalle()[bot->getPosition()]-> droite != NULL){
        choix.push_back(4);
        salleDuChoix.at(3)=std::stoi(
                chateau->getListeSalle()[bot->getPosition()]->droite->nom);
    }
    
    for (int i = 0;i < chateau->getListeSalle()[bot->getPosition()]->personnagesPresent.size();i++){
        if (bot == chateau->getListeSalle()[bot->getPosition()]->personnagesPresent[i] && salleDuChoix[choix.at(0)-1]!=-1){
            cout<<salleDuChoix[choix.at(0)-1]<<endl;
            chateau->getListeSalle()[bot->getPosition()]->personnagesPresent.erase(
                    chateau->getListeSalle()[bot->getPosition()]->personnagesPresent.begin()+i);
            bot->setPosition(salleDuChoix[choix.at(0)-1]);
            chateau->getListeSalle()[bot->getPosition()]->personnagesPresent.push_back(bot);
        }
    }

}

void Jeu::checkCombat(Chateau * cha){

    for(int i=0;i<cha->getListeSalle().size();i++){
        if(cha->getListeSalle().at(i)->personnagesPresent.size()>1){
            cout<<"il y a combat "<<endl;
            vector<Personnage*> combattants = cha->getListeSalle().at(i)->personnagesPresent;
            for(int j=0;j<combattants.size();j++){
                for(int l=j+1;l<combattants.size();l++){
                    if(combattants.at(j)->getHabilite()<combattants.at(l)->getHabilite()){
                        combat(combattants.at(l),combattants.at(j));
                        if(combattants.at(j)->getSante()>0)
                            combat(combattants.at(j),combattants.at(l));
                    }
                    else{
                    combat(combattants.at(j),combattants.at(l));
                    if(combattants.at(l)->getSante()>0)
                            combat(combattants.at(l),combattants.at(j));
                    }
                    checkMort(cha);
                    combattants = cha->getListeSalle().at(i)->personnagesPresent;
                }
            }
            
        }
    }

}

void Jeu::checkMort(Chateau * cha){
    for(int i=0;i<listePerso.size();i++){
        if(listePerso.at(i)->getSante()<=0)
            mortPersonnage(listePerso.at(i),cha);
    }
}

void Jeu::changerDeSalleJoueur(Chateau * chateau){
    cout << "Votre personnage est dans la salle " << joueur->getPosition() << endl;
    cout << "Vous pouvez aller en salle :" << endl;
    vector<int> choix;
    vector<int> salleDuChoix = {-1, -1, -1, -1};
    if (chateau->getListeSalle()[joueur->getPosition()]-> haut != NULL){
        cout <<"   1-haut vers la salle "<<
        chateau->getListeSalle()[joueur->getPosition()]->haut->nom<<  endl;
        choix.push_back(1);
        salleDuChoix.at(0)=std::stoi(
                chateau->getListeSalle()[joueur->getPosition()]->haut->nom);
    }
    if (chateau->getListeSalle()[joueur->getPosition()]-> bas != NULL){
        cout <<"   2-bas vers la salle "<<
        chateau->getListeSalle()[joueur->getPosition()]->bas->nom<<  endl;
        choix.push_back(2);
        salleDuChoix.at(1)=std::stoi(
                chateau->getListeSalle()[joueur->getPosition()]->bas->nom);
    }
    if (chateau->getListeSalle()[joueur->getPosition()]-> gauche != NULL){
        cout <<"   3-gauche vers la salle "<<
        chateau->getListeSalle()[joueur->getPosition()]->gauche->nom<<  endl;
        choix.push_back(3);
        salleDuChoix.at(2)=std::stoi(
                chateau->getListeSalle()[joueur->getPosition()]->gauche->nom);
    }
    if (chateau->getListeSalle()[joueur->getPosition()]-> droite != NULL){
        cout <<"   4-droite vers la salle "<<
        chateau->getListeSalle()[joueur->getPosition()]->droite->nom<<  endl;
        choix.push_back(4);
        salleDuChoix.at(3)=std::stoi(
                chateau->getListeSalle()[joueur->getPosition()]->droite->nom);
    }
    cout << "Ou voulez vous aller ?" << endl;
    int choixDuJoueur;
    cin >> choixDuJoueur;
    while (std::find(choix.begin(), choix.end(), choixDuJoueur) == choix.end()){
        cout << "Foncer dans le mur n'est jamais une bonne idee," <<endl;
        cout << "Vous pouvez aller en salle :" << endl;
        if (chateau->getListeSalle()[joueur->getPosition()]-> haut != NULL){
            cout <<"   1-haut vers la salle "<<
                 chateau->getListeSalle()[joueur->getPosition()]->haut->nom<<  endl;
            choix.push_back(1);
        }
        if (chateau->getListeSalle()[joueur->getPosition()]-> bas != NULL){
            cout <<"   2-bas vers la salle "<<
                 chateau->getListeSalle()[joueur->getPosition()]->bas->nom<<  endl;
            choix.push_back(2);
        }
        if (chateau->getListeSalle()[joueur->getPosition()]-> gauche != NULL){
            cout <<"   3-gauche vers la salle "<<
                 chateau->getListeSalle()[joueur->getPosition()]->gauche->nom<<  endl;
            choix.push_back(3);
        }
        if (chateau->getListeSalle()[joueur->getPosition()]-> droite != NULL){
            cout <<"   4-droite vers la salle "<<
                 chateau->getListeSalle()[joueur->getPosition()]->droite->nom<<  endl;
            choix.push_back(4);
        }
        cout << "Ou voulez vous aller ?" << endl;
        cin >> choixDuJoueur;
    }
    for (int i = 0;
    i < chateau->getListeSalle()[joueur->getPosition()]->personnagesPresent.size();
    i++){
        if (joueur == chateau->getListeSalle()[joueur->getPosition()]->personnagesPresent[i] && salleDuChoix[choixDuJoueur-1]!=-1){
            chateau->getListeSalle()[joueur->getPosition()]->personnagesPresent.erase(
                    chateau->getListeSalle()[joueur->getPosition()]->personnagesPresent.begin()+i);
            joueur ->setPosition(salleDuChoix[choixDuJoueur-1]);
            chateau->getListeSalle()[joueur->getPosition()]->personnagesPresent.push_back(joueur);
        }
    }
}

void Jeu::combat(Personnage * pers1, Personnage * perso2){

    srand((unsigned int)time(0));
    for (int i=0;i<pers1->getAttaque();i++){
        int resAttendu;
        if(pers1->getForce()<perso2->getResistance()){
            resAttendu = 5;
        }else if(pers1->getForce()==perso2->getResistance()){
            resAttendu = 4;
        }else{
            resAttendu=3;
        }

        int jetDes = (rand() % 6 + 1);
        cout<<"resattendu "<<resAttendu<<endl;
        cout<<"jet des "<<jetDes<<endl;
        if(jetDes>=resAttendu){
            perso2->setSante(perso2->getSante()-1);
            cout<<pers1->getNom()<<" inflige des dégats à "<<perso2->getNom()<<endl;
        }else{
            cout<<"esquive"<<endl;
        }

    }


}



Personnage * Jeu::getJoueur(){
    return joueur;
}

vector<Personnage*> Jeu::getListePerso(){
    return listePerso;
}

void Jeu::mortPersonnage(Personnage * pe,Chateau * chateau){

    cout<<"mort"<<endl;
    for(int i=0;i<listePerso.size();i++){
        if(pe == listePerso.at(i)){
            delete listePerso.at(i);
            listePerso.erase(listePerso.begin()+i);
            if(pe==joueur){
                joueur=nullptr;
                enCours=false;
                cout<<"VOUS ETES MORT !!!!!"<<endl;
            }else if(listePerso.size()==1){
                enCours=false;
                cout<<"VOUS AVEZ GAGNE !!!!!"<<endl;
            }
        }
    }

    for (int i = 0;i < chateau->getListeSalle()[pe->getPosition()]->personnagesPresent.size();i++){
        if (pe == chateau->getListeSalle()[pe->getPosition()]->personnagesPresent[i]){
            chateau->getListeSalle()[pe->getPosition()]->personnagesPresent.erase(
                    chateau->getListeSalle()[pe->getPosition()]->personnagesPresent.begin()+i);
        }
    }
}

