#include <iostream>
#include <string>
using namespace std;
#include "Livre.h"

std::ostream& operator<<(std::ostream& os, Etat e) {
    switch (e) {
        case LIBRE:    os << "LIBRE";    break;
        case EMPRUNTE: os << "EMPRUNTE"; break;
        case PRETE:    os << "PRETE";    break;
        default:       os << "INCONNU";  break;
    }
    return os;
}

Livre::Livre(string c, string t, string a, string e, string i, Public p)
        : code(c), titre(t), auteur(a), editeur(e), isbn(i), publicVise(p) {
    etat = Etat::LIBRE;
    proprietaire = "";
}

Livre::~Livre(){}

string Livre::getCode() const { return code; }
string Livre::getISBN() const { return isbn; }
Etat Livre::getEtat() const { return etat; }
string Livre::getProprio() const { return proprietaire;}
string Livre::getTitre() const { return titre;}

void Livre::setEtat(Etat e) { etat = e; }
void Livre::setProprio(string proprio) { proprietaire = proprio;}
bool Livre::estLibre(string codeBiblio) const { return etat == LIBRE or (etat == PRETE and proprietaire != codeBiblio); } //2eme cas du (or) : livre prete par une autre bibliotheque



//Livre de type Roman
Roman::Roman(string c, string t, string a, string e, string i, Public p, string g)
        : Livre(c, t, a, e, i, p), genre(g) {}

void Roman::afficher(ostream& os) const{
        os << "("<< code <<", "<< isbn<<") " << titre << " de " << auteur << " (" << genre << ") - Etat: " << etat;
    }

string Roman::getCategorie() const{
    return "Roman";
}

//Livre de type BandeDessinee
BandeDessinee::BandeDessinee(string c, string t, string a, string e, string i, Public p, string d)
        : Livre(c, t, a, e, i, p), dessinateur(d) {}

void BandeDessinee::afficher(ostream& os) const{
        os << "("<< code <<", "<< isbn<<") " << titre << " de " << auteur << " (" << dessinateur << ") - Etat: " << etat;
    }

string BandeDessinee::getCategorie() const{
    return "BandeDessinee";
}

//Livre de type RecueilPoesie
RecueilPoesie::RecueilPoesie(string c, string t, string a, string e, string i, Public p, string indicateur)
        : Livre(c, t, a, e, i, p), indicateur(indicateur) {}

void RecueilPoesie::afficher(ostream& os) const{
        os << "("<< code <<", "<< isbn<<") " << titre << " de " << auteur << " (" << indicateur << ") - Etat: " << etat;
    }

string RecueilPoesie::getCategorie() const{
    return "RecueilPoesie";
}

//Livre de type PieceTheatre
PieceTheatre::PieceTheatre(string c, string t, string a, string e, string i, Public p, int s)
        : Livre(c, t, a, e, i, p), siecle(s) {}

void PieceTheatre::afficher(ostream& os) const{
        os << "("<< code <<", "<< isbn<<") " << titre << " de " << auteur << " (" << siecle << "e) - Etat: " << etat;
    }

string PieceTheatre::getCategorie() const{
    return "PieceTheatre";
}

//Livre de type Album
Album::Album(string c, string t, string a, string e, string i, Public p, string illustrations)
        : Livre(c, t, a, e, i, p), illustrations(illustrations) {}

void Album::afficher(ostream& os) const{
        os << "("<< code <<", "<< isbn<<") " << titre << " de " << auteur << " (" << illustrations << ") - Etat: " << etat;
    }

string Album::getCategorie() const{
    return "Album";
}

