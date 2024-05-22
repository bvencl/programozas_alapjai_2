/*4. Egy erdei kisvasutat üzemeltető cég különböző árkategóriájú jegyeket (Ticket) ad el. Jelenleg három típust
értékesítenek: normál (StandardTicket), diák (StudentTicket) és nyugdíjas jegy (SeniorTicket). A jegyek ára a
konkrét távolságtól függ, amelyet kilométerben megadva állítanak be egy-egy jegyhez. Egy kiadott jegyen utólag
az érvényes távolságot nem lehet módosítani. A távolságdíj normál alapértéke (basePrice) kilométerenként 30
Ft., amely a programfutás során nem változik. A különböző kategóriájú jegyek esetén az ár az alapérték
konstansszorosa, értéke rendre 1.0 (normalFactor), 0.5 (studentFactor) és 0.3 (seniorFactor). A jegyeket
reprezentáló osztályoktól a konkrét ár lekérdezhető (getPrice() fv. adja vissza az árat). Szoftverünk az adott
napon kiadott jegyeket egy kategóriától független közös tömbben tárolja. A célunk ez alapján a tömb alapján
összegezni és kiírni a napi bevételt.
▪ Tervezze meg és vázolja fel az osztályok öröklési hierarchiáját! Használja fel a fenti dőlt betűs osztály-,
függvény- és változóneveket! Az osztályok téglalapjaiban tüntesse fel a kategóriával és árral kapcsolatos
tagváltozók és/vagy tagfüggvények deklarációját és láthatóságát! Ügyeljen az elegáns OO megoldásokra!
▪ Implementálja az osztályokat és konstansokat, figyelve arra, hogy esetlegesen egyes konstansokat is tagként
vagy statikus tagként érdemes implementálni. Ne legyen egy függvénytörzsben sem felesleges, nem használt
kód! Egy új jegytípus esetleges felvételéhez ne kelljen a már meglévő osztályokat módosítani!
Írjon egy egyszerű programrészletet (nem dinamikus) tömbbel, ami megmutatja a három különböző típusú jegy
felvételét, valamint egy ciklusban kiszámolja, majd kiírja a tömbben tárolt jegyek összegét.*/

#include <iostream>

class Ticket
{
private:
    const double distance;

public:
    Ticket(double pdisatnce = 0) : distance(pdisatnce){};
    double getDistance() const { return distance; }
    static int basePrice;
    virtual double getPrice() const = 0;
};

int Ticket::basePrice = 30;

class StandardTicket : public Ticket
{
public:
    StandardTicket(double pdistance) : Ticket(pdistance){};
    static double normalFactor;
    double getPrice() const override { return normalFactor * Ticket::basePrice * getDistance(); }
};

double StandardTicket::normalFactor = 1.0;

class StudentTicket : public Ticket
{
public:
    StudentTicket(double pdistance) : Ticket(pdistance){};
    static double studentFactor;
    double getPrice() const override { return studentFactor * Ticket::basePrice * getDistance(); }
};

double StudentTicket::studentFactor = 0.5;

class SeniorTicket : public Ticket
{
public:
    SeniorTicket(double pdistance) : Ticket(pdistance){};
    static double seniorFactor;
    double getPrice() const override { return seniorFactor * Ticket::basePrice * getDistance(); }
};

double SeniorTicket::seniorFactor = 0.3;

int main(int argc, char *argv[])
{
    SeniorTicket sentic(1. / 30);
    StudentTicket studtic(1. / 30);
    StandardTicket stantic(1. / 30);

    Ticket *tickets[3];
    tickets[0] = &sentic;
    tickets[1] = &studtic;
    tickets[2] = &stantic;

    double sum = 0.0;
    for (int i = 0; i < 3; i++)
    {
        sum += tickets[i]->getPrice();
    }

    std::cout << sum << std::endl;

        return 0;
}