
class Spray
{
    unsigned type;
    bool used;

public:
    Spray(unsigned type = 0) : type(type), used(false){};
    ~Spray(){};
    void vaporize();
};

class Tractor
{
    Spray *sprays;
    unsigned numOfSprays;

public:
    Tractor() : sprays(nullptr), numOfSprays(0){};
    ~Tractor() { delete[] sprays; };

    void addSpray(Spray const &);

    Spray &operator[](unsigned index) const;
};
