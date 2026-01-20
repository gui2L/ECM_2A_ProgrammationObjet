#include <iostream>
#include <string>
using namespace std;
#include "Bibliotheque.h"


int main() {  
    // -------- Instanciation des objets --------
    // Création des bibliothèques
    Bibliotheque bib1("Mediatheque Centrale", "12 rue de la Paix", "B001");
    Bibliotheque bib2("Bibliotheque l'Alcaraz", "58 Cours Belsunce", "B002");
    // Création des livres 
    Livre* ro1 = new Roman("RO01", "1984", "Orwell", "Gallimard", "978-2", ADULTE, "Anticipation");
    Livre* ro2 = new Roman("RO02", "Le Petit Prince", "St Exupery", "Folio", "978-3", TOUT_PUBLIC, "Conte");
    Livre* ro3 = new Roman("RO03", "Harry Potter a l'ecole des sorciers", "J.K. Rowling", "Gallimard", "978-2070643028", JEUNESSE, "Fantasy");
    Livre* bd1 = new BandeDessinee("BD01", "Tintin au Tibet", "Herge", "Casterman", "978-2203001209", TOUT_PUBLIC, "Herge");
    Livre* bd2 = new BandeDessinee("BD02", "Asterix le Gaulois", "Goscinny", "Hachette", "978-2012100010", TOUT_PUBLIC, "Uderzo");
    Livre* po1 = new RecueilPoesie("PO01", "Les Fleurs du Mal", "Charles Baudelaire", "Livre de Poche", "978-2253007102", ADULTE, "VERS");
    Livre* po2 = new RecueilPoesie("PO02", "Le Spleen de Paris", "Charles Baudelaire", "Gallimard", "978-2070419357", ADULTE, "PROSE");
    Livre* th1 = new PieceTheatre("TH01", "Le Malade Imaginaire", "Moliere", "Larousse", "978-2035868244", TOUT_PUBLIC, 17);
    Livre* th2 = new PieceTheatre("TH02", "Romeo et Juliette", "William Shakespeare", "Librio", "978-2290334884", ADULTE, 16);
    Livre* al1 = new Album("AL01", "Max et les Maximonstres", "Maurice Sendak", "Ecole des Loisirs", "978-2211026225", JEUNESSE, "DESSINS");
    Livre* al2 = new Album("AL02", "La Terre vue du ciel", "Yann Arthus-Bertrand", "De La Martiniere", "978-2732428678", TOUT_PUBLIC, "PHOTOS");
    // Création des adhérents
    Adherent adh1("Dupont", "Jean", "Paris", &bib1);
    Adherent adh2("Pat", "Bob", "Paris", &bib1);
    Adherent adh3("Lin", "Alice", "Marseille", &bib2);

    cout<< "\n";
    cout<< "\n-------- Achat de livres --------\n";

    // -------- Achat de livres --------
    bib1.acheterLivre(ro1);bib1.acheterLivre(ro2);bib2.acheterLivre(ro3);
    bib2.acheterLivre(bd1);bib1.acheterLivre(bd2);
    bib1.acheterLivre(po1);bib2.acheterLivre(po2);
    bib2.acheterLivre(th1);bib1.acheterLivre(th2);
    bib2.acheterLivre(al1);bib1.acheterLivre(al2);
    // Test Achat Impossible
    try{bib1.acheterLivre(ro1); // cas livre deja achete 
    } catch (const exception& e) {cerr << "DENIED : " << e.what() << endl;}
    try{bib2.acheterLivre(al2); // cas livre deja achete par une autre bibliotheque
    } catch (const exception& e) {cerr << "DENIED : " << e.what() << endl;}

    cout<< "\n";
    cout<< "\n-------- Affichage des stocks --------\n";

    // -------- Affichage du stock (complet) --------
    bib1.afficherStock();
    bib2.afficherStock();
    // -------- Affichage du stock (par categorie) --------
    bib1.afficherParCategorie("Roman");bib2.afficherParCategorie("Roman");
    /*bib1.afficherParCategorie("Album");bib2.afficherParCategorie("Album");
    bib1.afficherParCategorie("BandeDessinee");bib2.afficherParCategorie("BandeDessinee");
    bib1.afficherParCategorie("RecueilPoesie");bib2.afficherParCategorie("RecueilPoesie");
    bib1.afficherParCategorie("PieceTheatre");bib2.afficherParCategorie("PieceTheatre");*/

    cout<< "\n";
    cout<< "\n-------- Emprunts de livres --------\n";

    // -------- Emprunts de livres -------- 
    bib1.preterLivre(adh1, "RO01");bib1.preterLivre(adh1, "TH02");bib1.preterLivre(adh1, "PO01");
    bib1.preterLivre(adh2, "RO02");bib1.preterLivre(adh2, "AL02");
    bib2.preterLivre(adh3, "RO03");bib2.preterLivre(adh3, "BD01");
    //Test Emprunt Impossible
    try{ bib1.preterLivre(adh2, "RO01"); // cas livre deja prete/emprunte
    } catch (const exception& e) {cerr << "DENIED : " << e.what() << endl;}
    try{bib1.preterLivre(adh1, "BD02"); // cas quota de livres atteint
    } catch (const exception& e) {cerr << "DENIED : " << e.what() << endl;}
    try{bib1.preterLivre(adh1, "RO03"); // cas livre inconnu/introuvable
    } catch (const exception& e) {cerr << "DENIED : " << e.what() << endl;}
    
    cout<< "\n";
    cout<< "\n-------- Retour de livres --------\n";

    // -------- Retour de livres -------- 
    bib1.recupererLivre(adh1, "TH02");
    bib1.recupererLivre(adh2, "AL02");
    bib2.recupererLivre(adh3, "RO03");
    // Test Retour Impossible
    try{bib1.recupererLivre(adh3, "BD01"); // cas non-adherent ou livre perdu
    } catch (const exception& e) {cerr << "DENIED : " << e.what() << endl;}
    try{bib2.recupererLivre(adh1, "BD02"); // cas adherent mais livre non emprunte
    } catch (const exception& e) {cerr << "DENIED : " << e.what() << endl;}
    
    cout<< "\n";
    cout<< "\n-------- Suppression de livres --------\n";

    // -------- Suppression de livres --------
    bib1.supprimerLivre("PO01", "Perdu par l'adherent");
    bib2.supprimerLivre("RO03", "Part au pilon");
    // Test Suppression Impossible
    try{bib1.supprimerLivre("RO03", "Part au pilon");
    } catch (const exception& e) {cerr << "DENIED : " << e.what() << endl;}

    cout<< "\n";
    cout<< "\n-------- Echange de livres entre Bibliotheque --------\n";

    bib1.afficherStock();
    bib2.afficherStock();

    // -------- Echange de livres entre Bibliotheque --------
    bib1.demanderLivre("978-2070419357", bib2); //livre de code "PO02"
    bib2.demanderLivre("978-2290334884", bib1); //livre de code "TH02"
    
    // Test Echange Impossible
    try{bib1.demanderLivre("192-0145771351", bib2); // cas isbn non reconnu/indisponible
    } catch (const exception& e) {cerr << "DENIED : " << e.what() << endl;}
    try{bib1.demanderLivre("978-2203001209", bib2); // cas livre non-libre (deja emprunte par un adherent)
    } catch (const exception& e) {cerr << "DENIED : " << e.what() << endl;}
    
    bib1.afficherStock(); //bib2.afficherStock();
    
    // Test Changement d'état du livre PRETE <-> EMPRUNTE 
    bib1.preterLivre(adh1, "PO02"); // cas livre prete par une autre bibliotheque donc peut etre emprunter par un adherent
    bib1.afficherStock(); // passe d'un état PRETE à EMPRUNTE
    bib1.recupererLivre(adh1, "PO02"); // cas : livre prete par une autre bib, emprunte par un adherent, repasse à un etat PRETE apres rendu par l'adherent
    // Test Emprunt Impossible
    try{bib2.preterLivre(adh3, "PO02"); // cas livre prete a une autre bibliotheque donc non empruntable
    } catch (const exception& e) {cerr << "DENIED : " << e.what() << endl;}
    
    bib1.afficherStock(); //bib2.afficherStock();

    // Livre prete par bib2 à rendre par bib1 
    bib1.rendreLivresPretes();

    bib1.afficherStock();
    bib2.afficherStock();

    // Livre prete par bib1 à rendre par bib2 
    bib2.rendreLivresPretes();

    bib1.afficherStock();
    bib2.afficherStock();
        

    return 0;
}