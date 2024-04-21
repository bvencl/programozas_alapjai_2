#include <iostream>

// Permetező folyadékok szétterítésére is alkalmas traktorok (Tractor) bevetését támogató alkalmazást készítünk.
// A traktorok korlátozás nélküli számú permetező tartályt (Spray) tudnak hordozni. Minden tartály a benne levő
// folyadéktípus azonosítására rendelkezik egy típussal (type), ezt egész számmal azonosítjuk. A tartályok
// tartalmát szét is lehet permetezni (vaporize()), ami kiír egy szöveget és a permet típusát (pl. “Permet: 1”). A
// traktorokhoz permetező tartályokat (Spray) tudunk hozzáadni (addSpray), a tartályok elvételével nem kell
// jelenleg tördődnünk. A permetezőszert szétteríteni (permetezni) a lenti kódban (*)-gal jelölt módon, a traktor
// osztályán keresztül szeretnénk megvalósítani. Ha a tartályban tárolt permetezőszert már felhasználták egyszer
// (used), onnantól ezt kell kiírnia (pl. “Mar felhasznaltak.”). A traktor maga nem tudja, hogy az adott
// permetezőszerét már használták-e.

class Spray
{

private:
    int type;
    bool isUsed;

public:
    Spray(int type = 0) : type(type), isUsed(false){};
    void vaporize()
    {
        if (!isUsed)
        {
            std::cout << "Permet: " << type << std::endl;
            isUsed = true;
        }
        else
            std::cout << "Mar felhasznaltak" << std::endl;
    }

    friend class Tractor;
};

class Tractor
{
private:
    Spray *sprays;
    int spraycnt;

public:
    Tractor() : sprays(nullptr){};
    ~Tractor()
    {
        delete[] sprays;
    }
    void addSpray(const Spray &spray)
    {

        Spray *tmp = new Spray[spraycnt + 1];
        for (int i = 0; i < spraycnt; i++)
        {
            tmp[i] = sprays[i];
        }
        tmp[spraycnt] = spray;
        delete[] sprays;
        sprays = tmp;
        spraycnt++;
    }

    Spray &operator[](unsigned idx)
    {
        return sprays[idx];
    }
};

int main()
{
    Tractor zetor;
    Spray s1(1); // 1-es tipus, pl. csigaolo permet
    Spray s2(2); // 2-es tipus, pl. bekataszito permet
    zetor.addSpray(s1);
    zetor.addSpray(s2);
    zetor[0].vaporize(); //(*) “Permet: 1”
    // A túlcímzéssel nem kell foglalkoznunk.
    zetor[0].vaporize(); // “Mar felhasznaltak.”
    zetor[1].vaporize(); // ”Permet: 2”
}

// Tervezze meg és implementálja a szükséges osztályokat. Vázolja fel az osztályok hierarchiáját, tartalmazást stb.
// UML jelöléssel, az ábrán feltűntetve az esetleges tagfüggvények fejlécét és láthatóságát. Használja a dőlt betűs
// osztály- és tag neveket. Ügyeljen az elegáns OO megoldásokra!