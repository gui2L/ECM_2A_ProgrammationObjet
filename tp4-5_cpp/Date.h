#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int jour;
        int mois;
        int annee;

        static bool checkDate(int j, int m, int a){
            return ((j >= 1 && j <= 31) && (m >= 1 && m <= 12) && (a >= 2000 && a <= 2050));
        }

    public:
        Date(int j = 1, int m = 1, int a = 2000);
        Date(Date &d);
        ~Date();
        void affiche();

        int getJour();
        int getMois();
        int getAnnee();

        static bool public_checkDate(int jour, int mois, int annee){
            return checkDate(jour, mois, annee);
        }

        void setJour(int j);
        void setMois(int m);
        void setAnnee(int a);

        bool estEgale(const Date &d);

};

#endif