#include <iostream>
#include <string>
using namespace std;
#include "Bibliotheque.h"


Bibliotheque::Bibliotheque(string n, string a, string c) : nom(n), adresse(a), code(c) {}

Bibliotheque::~Bibliotheque(){
    // Supprimer les livres (car la bibliotheque les "possède")
    Element<Livre*>* courantLivre = stock.getTete();
    while (courantLivre != nullptr) {
        delete courantLivre->donnee; // On supprime le livre réel en mémoire
        courantLivre = courantLivre->suivant;
    }

    // Supprimer les adhérents
    Element<Adherent*>* courantAdh = inscrits.getTete();
    while (courantAdh != nullptr) {
        delete courantAdh->donnee; // On supprime l'adherent réel
        courantAdh = courantAdh->suivant;
    }
}

void Bibliotheque::acheterLivre(Livre* l) {
    cout << "\nREQUEST -> Achat livre: " << l->getTitre() << " par: " << nom << endl;
    if (l->getProprio() == ""){ 
        stock.ajouter(l);
        l->setProprio(code); // le livre est attaché à la bibliotheque qui achete le livre
        cout << "ACCEPTED : Livre achete" << endl;
    }else{ //si le livre a deja un proprietaire
        throw Erreur("Livre non disponible en vente");
    }
}

void Bibliotheque::afficherStock() const {
    cout << "\n--- Stock " << nom << endl;
    Element<Livre*>* courant = stock.getTete();
    while (courant != nullptr) {
        // courant->donnee est un Livre*
        cout << *(courant->donnee) << endl; // utilise opérateur << pour afficher
        courant = courant->suivant;
    }
    cout << "---"<< endl;
}

void Bibliotheque::afficherParCategorie(string categorieDemandee) const {
    cout << "\n--- Stock "<< nom << " (categorie : " << categorieDemandee << ")" << endl;
    
    bool trouve = false;
    
    Element<Livre*>* courant = stock.getTete();

    while (courant != nullptr) {
        // courant->donnee est un Livre*
       
        if (courant->donnee->getCategorie() == categorieDemandee) { // méthode polymorphique getCategorie()
            cout << *(courant->donnee) << endl; 
            trouve = true;
        }
        courant = courant->suivant;
    }

    if (!trouve) {
        cout << "Aucun livre trouve pour cette categorie" << endl;
    }else{
        cout << "---"<< endl;
    }
    
}

// Pour prêter un livre à un adhérent 
void Bibliotheque::preterLivre(Adherent& adherent, string codeLivre) {
    cout << "\nREQUEST -> Livre (" << codeLivre << ") demande par " << adherent.getNom()<< endl;
    Livre* livreTrouve = nullptr;

    Element<Livre*>* courant = stock.getTete();
    while (courant != nullptr) {
        if (courant->donnee->getCode() == codeLivre) {
            livreTrouve = courant->donnee;
            break;
        }
        courant = courant->suivant;
    }

    if (!livreTrouve) throw Erreur("Livre introuvable.");
    
    if (livreTrouve->estLibre()) {
            adherent.ajouterEmprunt(livreTrouve);
            livreTrouve->setEtat(EMPRUNTE);
            cout << "ACCEPTED : Livre " << codeLivre << " prete a " << adherent.getNom() << endl;
    }else{
        throw Erreur("Livre deja emprunte/prete.");
    }
}

// Pour rendre un livre, emprunte par un adherent, à une bibliotheque
void Bibliotheque::recupererLivre(Adherent& adherent, string codeLivre) {
    cout << "\nREQUEST -> Livre " << codeLivre << " a rendre par " << adherent.getNom()<< endl;
    if (adherent.aEmprunte(codeLivre)){
        Livre* livreTrouve = nullptr;
        Element<Livre*>* courant = stock.getTete();
        while (courant != nullptr) {
            if (courant->donnee->getCode() == codeLivre) {
                livreTrouve = courant->donnee;
                livreTrouve->setEtat(LIBRE);
                adherent.rendreLivre(livreTrouve);
                cout << "ACCEPTED : Livre " << codeLivre << " rendu par " << adherent.getNom() << endl;
                return;
            }
            courant = courant->suivant;
        }
        throw Erreur("Livre irrecuperable"); // cas où le livre n'a pas ete emprunte dans la bonne bibliotheque ou livre perdu
    }else{
        throw Erreur("Livre non emprunte"); // cas où l'adherent n'a pas emprunte le livre 
    }
    
}

void Bibliotheque::supprimerLivre(string codeLivre, string motif) {
    cout << "\nREQUEST -> Livre (" << codeLivre << ") a supprimer de "<< nom <<endl;
    Element<Livre*>* courant = stock.getTete();
    
    while (courant != nullptr) {
        // On cherche le livre par son code
        if (courant->donnee->getCode() == codeLivre) {
            Livre* aSupprimer = courant->donnee;
            
            // On le retire de la liste chainée du stock
            stock.supprimer(aSupprimer);
            
            cout << "ACCEPTED : Livre " << codeLivre << " supprime du stock. Motif : " << motif << endl;
            
            // On libère la mémoire
            delete aSupprimer; 
            return;
        }
        courant = courant->suivant;
    }
    throw Erreur("Livre introuvable/inconnu");
}

Livre* Bibliotheque::trouverLivre(string isbn) {
    Element<Livre*>* courant = stock.getTete();
    while (courant != nullptr) {
        // On vérifie l'isbn et si le livre est LIBRE
        if (courant->donnee->getISBN() == isbn && courant->donnee->estLibre()) {
            return courant->donnee;
        }
        courant = courant->suivant;
    }
    return nullptr; // Pas trouvé
}

// Pour demander un livre à une autre bibliotheque
void Bibliotheque::demanderLivre(string isbn, Bibliotheque& autreBiblio) {
    cout << "\nREQUEST -> Livre (" << isbn << ") demande a "<< autreBiblio.nom << " par " << nom << endl;
    // On cherche le livre dispo dans l'autre bibliothèque
    Livre* livrePrete = autreBiblio.trouverLivre(isbn);

    if (livrePrete != nullptr) {
        livrePrete->setEtat(PRETE);
        this->stock.ajouter(livrePrete);
        cout << "ACCEPTED : Livre prete" <<endl;
    } else {
        throw Erreur("Livre indisponible");
    }
}

void Bibliotheque::rendreLivresPretes() {
    Element<Livre*>* courant = stock.getTete();
    
    cout << "--- Retour des livres inter-bibliotheques ---" << endl;

    while (courant != nullptr) {
        Livre* l = courant->donnee;
        Element<Livre*>* suivantSauvegarde = courant->suivant; // Sauvegarde pour ne pas perdre le fil

        if (l->getProprio() != this->code && l->getEtat()==PRETE) {
            stock.supprimer(l);
            l->setEtat(LIBRE);
            
            cout << "Le livre " << l->getCode() << " est rendu a " << l->getProprio() << endl;
        }

        courant = suivantSauvegarde;
    }
}
