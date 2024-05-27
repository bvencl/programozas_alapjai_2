#include <iostream>
#include <ostream>
#include <cstring>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <random>

class Person
{
private:
    char lastName[19 + 1];  // char tömb a stacken
    char firstName[19 + 1]; // char tömb a stacken
    char taxId[9 + 1];      // char tömb a stacken
    char *privateKey;       // dinamukisan foglalt char tömb a heapen
    const Person *contact;  // csak rámutatunk, semmiképpen sem kell törölni

public:
    Person(const char *lastNamep, const char *firstNamep, const char *taxIdp = nullptr, const Person *other = nullptr) : contact(other), privateKey(nullptr)
    {
        if (strlen(lastNamep) > sizeof(lastName) - 1)
            throw std::runtime_error("vicces fiu vagy");
        strcpy(lastName, lastNamep);

        if (strlen(firstNamep) > sizeof(firstName) - 1)
            throw std::runtime_error("vicces fiu vagy");
        strcpy(firstName, firstNamep);

        if (taxIdp != nullptr)
        {
            if (strlen(taxIdp) > sizeof(taxId) - 1)
                throw std::runtime_error("vicces fiu vagy");
            strcpy(taxId, taxIdp);
        }
        else
        {
            taxId[0] = '\0';
        }

        generatePrivateKey();
    }

    Person(const Person &other)
    {
        strcpy(lastName, other.lastName);
        strcpy(firstName, other.firstName);
        strcpy(taxId, other.taxId);
        contact = other.contact;
        privateKey = nullptr;
        generatePrivateKey();
        strcpy(privateKey, other.privateKey);
    }

    ~Person()
    {
        delete[] privateKey;
        contact = nullptr;
    }

    void generatePrivateKey()
    {

        if (privateKey != nullptr)
            delete[] privateKey;
        std::random_device rand;
        std::uniform_int_distribution<int> dist(33, 126); // világ legmenőbb privateKey generálása, az openssl elsőre bonyolultnak tűnt

        privateKey = new char[2000 + 1];

        for (int i = 0; i < 2000; i++)
        {
            privateKey[i] = static_cast<char>(dist(rand));
        }

        privateKey[2000] = '\0';
    }

    void print(std::ostream &os) const
    {
        os << lastName << ' ' << firstName << ' ' << taxId
            << '\n' << privateKey
           << std::endl;
    }
};

int main()
{
    try
    {
        Person Bohoc("Bohoc", "Vagyok", "123456789");
        std::cout << std::endl;
        Bohoc.print(std::cout);
        std::cout << std::endl;
    }
    catch (const std::runtime_error &rtr)
    {
        std::cout << std::endl;
        std::cout << rtr.what() << std::endl;
    }

    Person Bohoc2("EnisBohoc", "Vagyok", "987654321");
    std::cout << std::endl;
    Bohoc2.print(std::cout);
    std::cout << std::endl;

    Person Bohoc3 = Bohoc2;

    std::cout << std::endl;
    Bohoc3.print(std::cout);
    std::cout << std::endl;

    Bohoc3.generatePrivateKey();

    std::cout << std::endl;
    Bohoc3.print(std::cout);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}