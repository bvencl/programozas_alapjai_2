#include <iostream>
#include <ostream>
#include <string>

// 5. Tervezési feladat (10p) Egy edzésre szolgáló gokartpálya üzemeltetéséhez készítünk szoftvert. Az egyes versenyautóknak (Car) van egy
// egyedi, egész szám azonosítójuk (number), amit vásárláskor örökre hozzájuk rendelnek. Az edzések során az
// egyes versenyautók esetén fontos, hogy az autókat reprezentáló objektumok tudják, hogy hányadikként (order)
// hajtottak a pályára. A pályára hajtás esetén az egyes Car objektumoknak meghívjuk az entersTrack függvényét.
// (Nem kell törődnünk vele, hogy edzés végén hogyan állítjuk alaphelyzetbe ezt a számot, mint ahogy azt is
// adottnak vesszük, hogy egy autó egy edzés során egyszer kerül a pályára).
// Célunk, hogy a (*) sorban jelölt módon ki tudjuk íratni az autó adatait (azonosítóval (number), pályára lépés
// sorszámával (order)). Amíg az autó nem lép pályára, az order értéke lehet -1. Emellett a (**) sorban jelölt
// módon össze tudjuk vetni, hogy melyik autó lépett korábban pályára.

class Car
{
private:
    const int number;
    int order;
    static int carsOnTrack;

public:
    Car(const int number) : number(number), order(0){};

    void entersTrack()
    {
        Car::carsOnTrack++;
        order = carsOnTrack;
    }

    int getNumber() const
    {
        return number;
    }

    int getOrder() const
    {
        return order;
    }

    bool operator<(const Car& theOther) const
    {
        if(order < theOther.order)
        {
            return true;
        }
        return false;
    }

    void print(std::ostream& os = std::cout) const
    {
        os << "bazzeg";
    }

};

int Car::carsOnTrack = 0;

std::ostream &operator<<(std::ostream &os, const Car &car)
{
    os << "Car #" << car.getNumber() << "entered the track as the " << car.getOrder() << ". car" << std::endl;
    return os;
}

int main()
{
    Car c1(107);
    Car c2(999);
    Car c3(2000);
    c1.entersTrack();
    c3.entersTrack(); // a 2000-s azonosítójú autó másodikként lép pályára
    c2.entersTrack();
    std::cout << c3; //(*) Kiirjuk c3 adatait: "Car #2000 entered the track as the 2. car"
    if (c3 < c2)     //(**) Ha c3 előbb került pályára, mint c2
    {
        std::cout << c3.getNumber() << " entered the track earlier.";
    }


    return 0;
}

// Készítse el a Car osztályt és a szükséges (tag)függvényeket, amelyekkel a leírt működés megvalósítható!
// Ügyeljen a helyes és elegáns objektumorientált tervezési elvekre!
// Használja a dőlt betűs osztály- és tag neveket.