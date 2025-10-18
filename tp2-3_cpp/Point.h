#ifndef POINT_H
#define POINT_H


class Point {
private :
    double x;
    double y;
    double z;
    static int compteur;


public :
    Point(double x = 0.0, double y = 0.0, double z = 0.0);
    Point (const Point &p);
    ~Point();

    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double new_x);
    void setY(double new_y);
    void setZ(double new_z);

    static int getCompteur(){
        return compteur;
    }

    Point saisie();
    void Afficher();
    void Translate(double dist);
    double Distance(Point B);
    

};
#endif