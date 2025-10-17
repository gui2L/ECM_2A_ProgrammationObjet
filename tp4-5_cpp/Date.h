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
        void affiche();

};

#endif