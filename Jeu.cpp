#include "Chateau.hpp"
#include "Sorcieres.hpp"
#include "Jeu.hpp"
#include "Amazones.hpp"
#include "Guerriers.hpp"
#include "Moines.hpp"
Jeu::Jeu(){
}

void Jeu::creationJoueur(){
    cout << "---------------- CHOIX DU PERSONNAGE --------------" << endl;
    cout<<"Vous avec le choix entre 4 classes :\n 1- Le Guerrier, fort et un idiot \n"
          " 2- Le Moine pas fort, mais gentil \n "
          "3- La Sorciere, vil et intellieng\n "
          "4- L'Amazone, farouche et determinée "<<endl;
    int rep;
    cin>>rep;

    while(rep<1 || rep>4){
        cout<<"choisissez un personnage valable !"<<endl;
        cin>>rep;
    }
    if(rep==4){
         string nomJoueur;
         cout<<"Entrez le nom de votre champion ;)" <<endl;
         cin>> nomJoueur;
         Amazones * am = new Amazones(nomJoueur);
         joueur=am;
         listePerso.push_back(am);
         Guerriers * gu = new Guerriers("bot1");
         Moines * mo = new Moines("bot2");
         Sorcieres * so = new Sorcieres("bot3");
         cout <<"Vous avez choisit d'etre une AMAZONE !" << endl;
         listePerso.push_back(gu);
         listePerso.push_back(mo);
         listePerso.push_back(so);
    }else if(rep == 3){
        string nomJoueur;
        cout<<"Entrez le nom de votre champion ;)" <<endl;
        cin>> nomJoueur;
        Sorcieres * so = new Sorcieres(nomJoueur);
        joueur=so;
        listePerso.push_back(so);
        Guerriers * gu = new Guerriers("bot1");
        Moines * mo = new Moines("bot2");
        Amazones * am = new Amazones("bot3");
        cout <<"Vous avez choisit d'etre une SORCIERE !" << endl;
        listePerso.push_back(gu);
        listePerso.push_back(mo);
        listePerso.push_back(am);
    }else if(rep==2){
        string nomJoueur;
        cout<<"Entrez le nom de votre champion ;)" <<endl;
        cin>> nomJoueur;
        Moines * mo = new Moines(nomJoueur);
        joueur=mo;
        listePerso.push_back(mo);
        Guerriers * gu = new Guerriers("bot1");
        Sorcieres * so = new Sorcieres("bot2");
        Amazones * am = new Amazones("bot3");
        cout <<"Vous avez choisit d'etre un MOINES....serieux ?!" << endl;
        listePerso.push_back(gu);
        listePerso.push_back(so);
        listePerso.push_back(am);
    }else{
        string nomJoueur;
        cout<<"Entrez le nom de votre champion ;)" <<endl;
        cin>> nomJoueur;
        Guerriers * gu = new Guerriers(nomJoueur);
        joueur=gu;
        listePerso.push_back(gu);
        Moines * mo = new Moines("bot1");
        Sorcieres * so = new Sorcieres("bot2");
        Amazones * am = new Amazones("bot3");
        cout <<"Vous avez choisit d'etre un GUERRIER!" << endl;
        listePerso.push_back(mo);
        listePerso.push_back(so);
        listePerso.push_back(am);
    }

}

int Jeu::introduction(){
    cout <<"   /\\                                                        /\\" << endl;
    cout <<"  |  |                                                      |  |" << endl;
    cout <<" /----\\                                                    /----\\" << endl;
    cout <<"[______]                                                  [______]" << endl;
    cout <<" |    |         _____                        _____         |    |" << endl;
    cout <<" |[]  |        [     ]                      [     ]        |  []|" << endl;
    cout <<" |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |" << endl;
    cout <<" |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |" << endl;
    cout <<" |             |     |/'    ____..____    '\\|     |             |" << endl;
    cout <<" \\  []        |     |    /'    ||    '\\    |     |        []  /" << endl;
    cout <<"   |      []   |     |   |o     ||     o|   |     |  []       |" << endl;
    cout <<"   |           |  _  |   |     _||_     |   |  _  |           |" << endl;
    cout <<"   |   []      | (_) |   |    (_||_)    |   | (_) |       []  |" << endl;
    cout <<"   |           |     |   |     (||)     |   |     |           |" << endl;
    cout <<"   |           |     |   |      ||      |   |     |           |" << endl;
    cout <<" /''           |     |   |o     ||     o|   |     |           ''\\" << endl;
    cout <<"[_____________[_______]--'------''------'--[_______]_____________]" << endl;
    cout <<"" << endl;

    cout <<"--------------------------------------------------------------------------" << endl;
    cout <<"|                 BIENVENUE DANS LE CHATEAU DU MAGE SDF                  |" << endl;
    cout <<"--------------------------------------------------------------------------\n\n\n" << endl;

    cout<<"-----------------------------PARAMETRAGE---------------------------------\n" << endl;
    cout << "Nombre de salles voulus dans le chateau ? (entre 10 et 100)" << endl;
    int choixNbSalle = 0;
    cin >> choixNbSalle;
    cout << "" <<endl;

    while (choixNbSalle <= 9 || choixNbSalle>101){
        cout << "/!\\ on a dit entre 10 et 100 /!\\" << endl;
        cin >> choixNbSalle;
        cout << "" <<endl;
    }
    return choixNbSalle;
}

int menuAction(){
    cout <<"________________________________________\n"
           "|*****************MENU*****************|\n"
           "|Vous pouvez :(1 action = 1 tour)      |\n"
           "| 1-changer de piece                   |\n"
           "| 2-rammasser un objet                 |\n"
           "| 3-utiliser un objet                  |\n"
           "| 4-deposer Objet                      |\n"
           "| 5-Rien                               |\n"
           "|______________________________________|" << endl;
    int action;
    cin >> action;
    return action;
}

void Jeu::partie () {
    int choixNbSalle = introduction();
    creationJoueur();
    Chateau *chateau = new Chateau(choixNbSalle, listePerso);
    while (chateau->securiteVerif() != true) {
        chateau = new Chateau(choixNbSalle, listePerso);
    }
    while (enCours) {
        for (int i = 0; i < listePerso.size(); i++) {
            if (listePerso.at(i) == joueur) {
                if (joueur->getClasse().compare("Amazones") == 0) {
                    printAmazone();
                }
                if (joueur->getClasse().compare("Guerriers") == 0) {
                    printGuerrier();
                }
                if (joueur->getClasse().compare("Moines") == 0) {
                    printMoine();
                }
                if (joueur->getClasse().compare("Sorcieres") == 0) {
                    printSorciere();
                }
                printSalle(chateau);
                int action = menuAction();
                if (action == 1)
                    changerDeSalleJoueur(chateau);
                else if (action == 3) {
                    utiliserObjet();
                } else if (action == 2) {
                    ramasserObjet(chateau);
                } else if (action == 4) {
                    deposerObjet(chateau);
                } else
                    changerSalleBot(chateau, listePerso.at(i));
                checkCombat(chateau);
            }
        }
    }
}

void Jeu::deposerObjet(Chateau * cha){
    cout<<"--------------->Quel objet voulez vous deposer?"<<endl;
    for(int i=0;i<joueur->getSac().size();i++){
        cout<< "             "<<i+1<<"- "<<joueur->getSac().at(i)->getNom();
    }
    cout << "           0- Rien" << endl;
    int rep;
    cin >>rep;
    while(rep<0 || rep>joueur->getSac().size()){
        cout<<"/!\\Choississez un objet valable/!\\"<<endl;
        cin>>rep;
    }
    if (rep == 0) {
        cout <<"Non pas interessé"<<endl;
    } else {
        cha->getListeSalle()[joueur->getPosition()]->objetsPresent.push_back(joueur->getSac().at(rep-1));
        joueur->retirerObjet(joueur->getSac().at(rep-1));
    }

}
void Jeu::utiliserObjet() {
    cout << "--------------->Quel Objet Utiliser ?" << endl;
    for (int i = 0; i < joueur->getSac().size(); i++) {
        cout << "             " << i + 1 << "- " << joueur->getSac().at(i)->getNom();
    }
    cout << "           0- Rien" << endl;
    int rep;
    cin >> rep;
    while (rep < 0 || rep > joueur->getSac().size()) {
        cout<<"/!\\Choississez un objet valable/!\\"<<endl;
        cin >> rep;
    }
    if (rep == 0) {
        cout <<"Non pas interessé"<<endl;
    } else {
        joueur->getSac().at(rep - 1)->utiliser();
    }
}

void Jeu::ramasserObjet(Chateau * cha){
    cout<<"--------------->Quel objet voulez vous prendre"<<endl;
    for(int i =0;i<cha->getListeSalle()[joueur->getPosition()]->objetsPresent.size();i++){
        cout<< "           " <<i+1<<"- "<<cha->getListeSalle()[joueur->getPosition()]->objetsPresent.at(i)->getNom();
    }    
    cout<<"           0- Rien"<<endl;
    int rep;
    cin>>rep;
    while(rep<0 || rep>cha->getListeSalle()[joueur->getPosition()]->objetsPresent.size()){
        cout<<"/!\\Choississez un objet valable/!\\"<<endl;
        cin>>rep;
    }
    if(rep == 0){
        cout <<"Non pas interessé"<<endl;
    }else if(rep>0 && rep<=cha->getListeSalle()[joueur->getPosition()]->objetsPresent.size()){
        if(joueur->getSac().size()<4){
            cha->getListeSalle()[joueur->getPosition()]->objetsPresent.at(rep-1)->ajouter(joueur);
            cha->getListeSalle()[joueur->getPosition()]->objetsPresent.erase(
                    cha->getListeSalle()[joueur->getPosition()]->objetsPresent.begin()+rep-1);
        }else{
            cout <<"Sac plein"<<endl;
        }
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
    int choixAleat = rand()%choix.size();
    for (int i = 0;i < chateau->getListeSalle()[bot->getPosition()]->personnagesPresent.size();i++){
        if (bot == chateau->getListeSalle()[bot->getPosition()]->personnagesPresent[i] && salleDuChoix[choix.at(choixAleat)-1]!=-1){
            cout<<salleDuChoix[choix.at(choixAleat)-1]<<endl;
            chateau->getListeSalle()[bot->getPosition()]->personnagesPresent.erase(
                    chateau->getListeSalle()[bot->getPosition()]->personnagesPresent.begin()+i);
            bot->setPosition(salleDuChoix[choix.at(choixAleat)-1]);
            chateau->getListeSalle()[bot->getPosition()]->personnagesPresent.push_back(bot);
        }
    }

}

void Jeu::checkCombat(Chateau * cha){

    for(int i=0;i<cha->getListeSalle().size();i++){
        if(cha->getListeSalle().at(i)->personnagesPresent.size()>1){
            cout <<"________________________________________\n"
                   "|****************COMBAT****************|\n"
                   "|______________________________________|"<<endl;
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
        cout << "résultat attendu : "<<resAttendu<<" jet de dés :"<<jetDes<<endl;
        if(jetDes>=resAttendu){
            perso2->setSante(perso2->getSante()-1);
            cout<<pers1->getNom()<<" inflige des dégats à "<<perso2->getNom()<<endl;
        }else{
            cout<<perso2->getNom()<<" esquive l'attaque de "<<pers1->getNom()<<endl;
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


void Jeu::printAmazone(){
    cout <<"      _ _" << endl;
    cout <<"     /.-.`." << endl;
    cout <<"    //o;o\\ \\                     |Nom : "<< joueur->getNom()<< endl;
    cout <<"    \\\\_-_/)/                     |Sante :" << joueur->getSante()<< " Attaque :"<< joueur->getAttaque()<< endl;
    cout <<"    _`) ( _\\\\                    |Force :" << joueur->getForce()<< " Resistance :" << joueur->getResistance()<< endl;
    cout <<" .`) '-.-' ( `.                  |Habilité : " << joueur->getHabilite() << endl;
    cout <<"/ `/   .   \\`. \\                 " << endl;
    cout <<"\\ \\\\___A___/_` /" << endl;
    cout <<" '-)|)=@=(|(-'`\\" << endl;
    cout <<"   |/\\   /\\|  )/" << endl;
    cout <<"   /__\\_/__\\" << endl;
    cout <<"  '---' '---'" << endl;
    cout <<"   \\ /   \\ /" << endl;
    cout <<"   ( )   ( )" << endl;
    cout <<"   /_\\   /_\\" << endl;
    cout <<"  '---' '---'" << endl;
    cout <<"   \\ /   \\ /" << endl;
    cout <<"   /_\\   /_\\" << endl;
}
void Jeu::printGuerrier(){
    cout <<"  ,   A           {}" << endl;
    cout <<" / \\, | ,        .--." << endl;
    cout <<"|    =|= >      /.--.\\                           |Nom : "<< joueur->getNom()<< endl;
    cout <<" \\ /` | `       |====|                           |Sante :" << joueur->getSante()<< " Attaque :"<< joueur->getAttaque()<< endl;
    cout <<"  `   |         |`::`|                           |Force :" << joueur->getForce()<< " Resistance :" << joueur->getResistance()<< endl;
    cout <<"      |     .-;`\\..../`;_.-^-._                  |Habilité : " << joueur->getHabilite() << endl;
    cout <<"     /\\\\/  /  |...::..|`   :   `|               " << endl;
    cout <<"     |:'\\ |   /'''::''|   .:.   |" << endl;
    cout <<"      \\ /\\;-,/\\   ::  |..:::::..|" << endl;
    cout <<"      |\\ <` >  >._::_.| ':::::' |" << endl;
    cout <<"      | `\"\"`  /   ^^  |   ':'   |" << endl;
    cout <<"      |       |       \\    :    /" << endl;
    cout <<"      |       |        \\   :   / " << endl;
    cout <<"      |       |___/\\___|`-.:.-`" << endl;
    cout <<"      |        \\_ || _/    `" << endl;
    cout <<"      |        <_ >< _>" << endl;
    cout <<"      |        |  ||  |" << endl;
    cout <<"      |        |  ||  |" << endl;
    cout <<"      |       _\\.:||:./_" << endl;
    cout <<"      |      /____/\\____\\" << endl;
}

void Jeu::printSorciere(){
    cout <<"                       ." << endl;
    cout <<"                        ." << endl;
    cout <<"              /^\\     .                     |Nom : "<< joueur->getNom()<< endl;
    cout <<"         /\\   \"V\"                           |Sante :" << joueur->getSante()<< " Attaque :"<< joueur->getAttaque()<< endl;
    cout <<"        /__\\   I      O  o                  |Force :" << joueur->getForce()<< " Resistance :" << joueur->getResistance()<< endl;
    cout <<"       //..\\\\  I     .                      |Habilité : " << joueur->getHabilite() << endl;
    cout <<"       \\].`[/  I               " << endl;
    cout <<"       /l\\/j\\  (]    .  O" << endl;
    cout <<"      /. ~~ ,\\/I          ." << endl;
    cout <<"      \\\\L__j^\\/I       o" << endl;
    cout <<"       \\/--v}  I     o   ." << endl;
    cout <<"       |    |  I   _________" << endl;
    cout <<"       |    |  I c(`       ')o" << endl;
    cout <<"       |    l  I   \\.     ,/" << endl;
    cout <<"     _/j  L l\\_!  _//^---^\\\\_" << endl;
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}
void Jeu::printMoine(){
    cout <<"              _,._      \n"
           "  .||,       /_ _\\\\     \n"
           " \\.`',/      |'L'| |    \n"
           " = ,. =      | -,| L                   |Nom : "<< joueur->getNom()<<"\n"
           " / || \\    ,-'\\\"/,'`.                  |Sante : " << joueur->getSante()<<" Attaque :"<< joueur->getAttaque()<< "\n"
           "   ||     ,'   `,,. `.                 |Force : " << joueur->getForce()<<" Resistance :" << joueur->getResistance()<<"\n"
           "   ,|____,' , ,;' \\| |                 |Habilité : " << joueur->getHabilite() <<"\n"
           "  (3|\\    _/|/'   _| |  \n"
           "   ||/,-''  | >-'' _,\\\\ \n"
           "   ||'      ==\\ ,-'  ,' \n"
           "   ||       |  V \\ ,|   \n"
           "   ||       |    |` |   \n"
           "   ||       |    |   \\  \n"
           "   ||       |    \\    \\ \n"
           "   ||       |     |    \\\n"
           "   ||       |      \\_,-'\n"
           "   ||       |___,,--\")_\\\n"
           "   ||         |_|   ccc/\n"
           "   ||        ccc/       \n" << endl;
}

void Jeu::printSalle(Chateau * cha){
    Salle * salleDuJoueur = cha->getListeSalle()[joueur->getPosition()];
    if (salleDuJoueur->haut != NULL) {
        cout << "                             HAUT : " << salleDuJoueur->haut->nom<<  endl;
        cout << "________________________|               |________________________" <<  endl;
    } else {
        cout << "_________________________________________________________________" << endl;
    }
        cout<< "|[]                                                             []|\n"
               "|[]                                                             []|\n"
               "|[]                                                             []|"
        << endl;

    if (salleDuJoueur->droite != NULL && salleDuJoueur->gauche != NULL) {
        cout << "___                                                             ___" << endl;
        cout << "GAUCHE : " << salleDuJoueur->gauche->nom
             << "                 SALLE  "<< salleDuJoueur->nom <<"                         DROITE : "
             << salleDuJoueur->droite->nom << endl;
        cout << "___                                                             ___"<< endl;


    } else if (salleDuJoueur->droite != NULL && salleDuJoueur->gauche == NULL) {
        cout << "|[]                                                             ___" << endl;
        cout << "|[]                     SALLE  "<< salleDuJoueur->nom <<"                              DROITE : "
        << salleDuJoueur->droite->nom << endl;
        cout << "|[]                                                             ___" << endl;

    } else if (salleDuJoueur->droite == NULL && salleDuJoueur->gauche != NULL) {
        cout << "___                                                             []|" << endl;
        cout << "GAUCHE : " << salleDuJoueur->gauche->nom
             << "                      SALLE "<< salleDuJoueur->nom <<"                        []| "
             << endl;
        cout << "___                                                             []|" << endl;
    } else if (salleDuJoueur->droite == NULL && salleDuJoueur->gauche == NULL) {
        cout << "|[]                           SALLE " << salleDuJoueur->nom << "                           []|" << endl;
    }
    cout << "|[]                         Objet present :                     []|" << endl;
    for (int j = 0; j < salleDuJoueur->objetsPresent.size(); j++) {
        cout <<"|[]                      "<<salleDuJoueur->objetsPresent[j]->getNom() << "              []| " << endl;
    }
    cout<< "|[]                                                             []|\n"
           "|[]                                                             []|\n"
           "|[]                                                             []|"
        << endl;
    if (salleDuJoueur->bas != NULL) {
        cout << "|[]_____________________|   BAS : " << salleDuJoueur->bas->nom<<"    |________________________[]|" <<  endl;
    } else {
        cout << "|[]_____________________________________________________________[]|" << endl;
    }

    cout << "\n" << endl;
}
