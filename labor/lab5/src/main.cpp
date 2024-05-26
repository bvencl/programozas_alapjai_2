#include <iostream>
#include <ostream>
#include <cstring>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <random>

class Person
{
private:
    char lastName[19 + 1];
    char firstName[19 + 1];
    char taxId[9 + 1];
    char *privateKey;
    const Person *contact;

public:
    Person(const char *lastNamep, const char *firstNamep, const char *taxIdp, const Person *other = nullptr) : contact(other), privateKey(nullptr)
    {
        if (strlen(lastNamep) > sizeof(lastName) - 1)
            throw std::runtime_error("vicces fiu vagy");
        strcpy(lastName, lastNamep);

        if (strlen(firstNamep) > sizeof(firstName) - 1)
            throw std::runtime_error("vicces fiu vagy");
        strcpy(firstName, firstNamep);

        if (strlen(taxIdp) > sizeof(taxId) - 1)
            throw std::runtime_error("vicces fiu vagy");
        strcpy(taxId, taxIdp);

        generatePrivateKey();
    }

    ~Person()
    {
        delete[] privateKey;
        contact = nullptr;
    }

    void generatePrivateKey()
    {
        std::random_device rand;
        std::uniform_int_distribution<int> dist(33, 126); // világ legmenőbb privateKey generálása, az openssl elsőre bonyolultnak tűnt

        privateKey = new char[2000 + 1];

        for (int i = 0; i < 2000; i++)
        {
            privateKey[i] = static_cast<char>(dist(rand));

            privateKey[2000] = '\0';
        }
    }

    void print(std::ostream &os) const
    {
        os << lastName << ' ' << firstName << ' ' << taxId << std::endl;
    }
};

int main()
{

    Person Bohoc("Max", "Gyula", "696969690");

    Person Bohoc2("Forstner", "Bertalan", "000000000");

    std::cout << std::endl;
    Bohoc.print(std::cout);
    std::cout << std::endl;

    return 0;
}