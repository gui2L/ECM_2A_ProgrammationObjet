#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int jour;
        int mois;
        int annee;
        bool checkDate(int j, int m, int a);

    public:
        Date(int j, int m, int a);
        Date(Date &d);
        ~Date();
        void affiche();

        int getJour();
        int getMois();
        int getAnnee();

        void setJour(int j);
        void setMois(int m);
        void setAnnee(int a);

};

#endif