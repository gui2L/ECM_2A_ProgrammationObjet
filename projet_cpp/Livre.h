#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include "Erreur.h"

enum Public { ADULTE, ADO, JEUNESSE, TOUT_PUBLIC };
enum Etat { LIBRE, EMPRUNTE, PRETE};

// On annonce que l'opérateur << existe pour le type 'Etat'
std::ostream& operator<<(std::ostream& os, Etat e);

class Livre {
protected: // Protected pour que les classes filles (types de livre) y accèdent
    string code;
    string titre;
    string auteur;
    string editeur;
    string isbn;
    Public publicVise;
    Etat etat;
    string proprietaire; // Nom de la bibliothèque propriétaire (qui a acheté le livre)

public:
    Livre(string c, string t, string a, string e, string i, Public p);

    virtual ~Livre(); 

    // Méthode virtuelle pour rendre la classe abstraite
    virtual void afficher(ostream& os) const = 0; //oblige codage afficher dans chaque classe fille
    virtual string getCategorie() const = 0;

    string getCode() const;
    string getISBN() const;
    string getTitre() const;
    Etat getEtat() const;
    void setEtat(Etat e);
    bool estLibre(string codeBiblio) const;
    void setProprio(string proprio);
    string getProprio() const;

    // Surcharge opérateur << (Fonction amie)
    friend ostream& operator<<(ostream& os, const Livre& l) {
        l.afficher(os); // Délègue à la méthode virtuelle (polymorphisme)
        return os;
    }
    
};

// Classes dérivées/filles de la classe mère Livre

class Roman : public Livre {
    string genre;
public:
    Roman(string c, string t, string a, string e, string i, Public p, string g);
    void afficher(ostream& os) const override;
    string getCategorie() const override;
};


class BandeDessinee : public Livre {
    string dessinateur;
public:
    BandeDessinee(string c, string t, string a, string e, string i, Public p, string d);
    void afficher(ostream& os) const override;
    string getCategorie() const override;
};

class RecueilPoesie : public Livre {
    string indicateur;
public:
    RecueilPoesie(string c, string t, string a, string e, string i, Public p, string indicateur);
    void afficher(ostream& os) const override;
    string getCategorie() const override;
};

class PieceTheatre : public Livre {
    int siecle;
public:
    PieceTheatre(string c, string t, string a, string e, string i, Public p, int siecle);
    void afficher(ostream& os) const override;
    string getCategorie() const override;
};

class Album : public Livre {
    string illustrations;
public:
    Album(string c, string t, string a, string e, string i, Public p, string illustrations);
    void afficher(ostream& os) const override;
    string getCategorie() const override;
};

#endif
