#include "Personne.h"
#include "Eleve.h"
#include "Personnel.h"
#include "PersonnelAdmin.h" 
#include "EnseignantPermanent.h"
#include "EnseignantVacataire.h"
#include "ListePersonnel.h"

#include <iostream>

int main(){
    std::cout << "\n";
    std::cout << "  __Test class Personne__" << "\n";
    Personne p1("", "");
    p1.affiche();
    p1.setNom("Baker");
    p1.setPrenom("Colson");
    p1.setAdresse("Earth");
    p1.setTelephone("0024");
    p1.affiche();

    Personne p2("Santa", "Claus", "Antartica", "0025122025");
    std::cout << p2.getNom() << "\n" << p2.getPrenom() << "\n" << p2.getAdresse() << "\n" << p2.getTelephone() << "\n";
    std::cout << "\n";

    std::cout << "  __Test class Eleve__" << "\n";
    Eleve e1("Punk", "Daft");
    e1.affiche();
    e1.setAdresse("AroundTheWorld");
    e1.setTelephone("0033");
    e1.setPromotion("1A");
    e1.setGroupeTD("3");
    e1.setGPA(4);

    e1.affiche();
    std::cout << e1.getNom() << "\n" << e1.getPrenom() << "\n" << e1.getAdresse() << "\n" << e1.getTelephone() << "\n" << e1.getPromotion() << "\n" << e1.getGroupeTD() << "\n" << e1.getGPA() << "\n";
    std::cout << "\n";

   /* std::cout << "  __Test class Personnel__" << "\n"; //classe abstraite maintenant
    Personnel personel1("X", "Y", 1500);
    std::cout << personel1.getSalaire() << "\n";
    personel1.setSalaire(3000);
    personel1.affiche();
    std::cout << "\n";*/

    std::cout << "  __Test class PersonnelAdmin__" << "\n";
    PersonnelAdmin personeladmin1("X", "Y", 15, 2300, 13);
    personeladmin1.setSalaire(2000);
    personeladmin1.setHeuresSup(10);
    personeladmin1.affiche();
    std::cout << "\n";

    std::cout << "  __Test class EnseignantPermanent__" << "\n";
    EnseignantPermanent enseignantperm1("A", "B", 3000, 3, 50);
    enseignantperm1.affiche();
    std::cout << "\n";

    std::cout << "  __Test class EnseignantVacataire__" << "\n";
    EnseignantVacataire enseignantvac1("A", "B", 3000, "04", 17);
    enseignantvac1.affiche();
    std::cout << "\n";

    //Personnel* personnel1 = new Personnel("Dupont", "Marie",2000); //classe abstraite maintenant
    
    PersonnelAdmin* pAdmin = new PersonnelAdmin("Lefevre", "Jean", 1800, 15, 10);
    
    EnseignantPermanent* pEP = new EnseignantPermanent("Dubois", "Luc", 3500, 3, 50);
    
    EnseignantVacataire* pEV = new EnseignantVacataire("Leroy", "Sophie", 50, "A12", 40);


    std::cout << "  __Test methode calculSalaire__" << "\n";
    //std::cout << "Salaire Personnel : " << personnel1->calculSalaire() << "\n"; //classe abstraite maintenant
    std::cout << "Salaire Admin : " << pAdmin->calculSalaire() << "\n";
    std::cout << "Salaire EP : " << pEP->calculSalaire() << "\n";
    std::cout << "Salaire EV : " << pEV->calculSalaire() << "\n";
    // salaires corrects car méthode fille appelée
    

    ListePersonnel maListe;
    //maListe.ajoutPersonnel(personnel1); //classe abstraite maintenant
    maListe.ajoutPersonnel(pAdmin);
    maListe.ajoutPersonnel(pEP);
    maListe.ajoutPersonnel(pEV);
    maListe.afficherSalaires();
    // si la méthode calculSalaire() de la classe Personnel est non virtuel, tous les salaires sont ceux de base car le compilateur utilise la méthode 'calculSalaire()' de la classe Personnel (la mère) à travers le pointeur Personnel*

    //delete personnel1; //classe abstraite maintenant
    delete pAdmin;
    delete pEP;
    delete pEV;

    return 0;
}