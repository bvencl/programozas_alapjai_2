/*1. Készítsen egy sablon osztályt, amely szállításra való konténerek (Container) reprezentálására képes. Minden
konténernek van egy azonosítója (id). Az osztályt úgy szeretnénk megírni, hogy bármilyen azonosító típussal
működhessen (egész szám, sztring, tetszőleges saját osztály stb.), és az azonosítója lekérdezhető legyen (getId()).
Készítsen egy (több konténerből álló) rakományokat reprezentáló osztálysablont (Cargo), amely bármilyen,
azonos azonosító-típusú konténereket tud nyilvántartani (például csupa egész számmal azonosított Container).
Nem tudjuk előre, mi lesz a tárolt konténerek azonosító típusa. A szállítmányhoz tetszőleges számú konténert
adhatunk egyesével (az addContainer tagfüggvénnyel), kivenni viszont nem kell tudni belőle.
Célunk, hogy a Cargo osztályból lekérdezzük egy adott azonosítójú konténert (visszakapjunk a megfelelő, eltárolt
objektumra pointert) a getContainerWithId tagfüggvénnyel. Ha nincs megfelelő azonosítójú konténer, nullptr-t
adjunk vissza. (Példa: myCargo.getContainerWithId("ABCD123")).
Milyen követelményeket támaszt az azonosító típusával szemben? Mutassa meg a megfelelő kódrészletet.
Egy teljes példán mutassa be konténerek létrehozását egy szabadon választott azonosító típussal. Hozzon létre
hozzá egy szállítmányt, helyezze el benne az elemeket, majd kérjen vissza a szállítmánytól egy adott azonosítójú
konténer elemet. A feladat során ne használjon STL-t.*/

template <class T>
class Container
{
private:
    T id;

public:
    Container(T pid = 0) : id(pid){};
    const T &getId() const { return id; }
};
template <class U>
class Cargo
{
private:
    Container<U> *containers;
    unsigned size = 0;

public:
    Cargo() : containers(nullptr), size(0){};
    ~Cargo() { delete[] containers; }

    void addContainer(Container<U> newContainer)
    {
        Container<U> *tmp = new Container<U>[size + 1];
        for (int i = 0; i < size; i++)
        {
            tmp[i] = containers[i]; // Az azonosítóval lehessen értéket adni
        }
        tmp[size] = newContainer;
        delete[] containers;
        size++;
        containers = tmp;
    }
    Container<U> *getContainerWithId(U lookupId) const
    {
        for (int i = 0; i < size; i++)
        {
            if (lookupId == containers[i].getId()) // Az azonosíthatónak összehasonlíthatónak kell lennie
            {
                return &containers[i];
            }
        }
        return nullptr;
    }
};

int main(int argc, char *argv[])
{
    Container<int> cont1(1);
    Container<int> cont2(69);
    Container<int> cont3(420);
    Cargo<int> myCargo;

    myCargo.addContainer(cont1);
    myCargo.addContainer(cont2);
    myCargo.addContainer(cont3);

    Container<int> *cont1cpy = myCargo.getContainerWithId(69);
    Container<int> *nemjo = myCargo.getContainerWithId(69420);

    if (1)
        ;

    return 0;
}
