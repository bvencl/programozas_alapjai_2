#include <string>

class Partner
{
    char privateKey[2001];
    long id;

public:
    Partner(long id) : id(id)
    {
        // key generalasa
    }
};

class Person : public Partner
{
    std::string firstName, lastName;
    std::string taxNumber;

public:
    Person(long id, std::string &const firstName, std::string &const lastName, std::string &const taxNumber)
    : Partner(id), firstName(firstName), lastName(lastName), taxNumber(taxNumber)
    {
    }

    Person(Person const &other)
     : Partner(other), firstName(other.firstName), lastName(other.lastName), taxNumber(other.taxNumber)
    {
    }
};

class Company : public Partner
{
    std::string businessName;
    std::string VATIN;
    Company(long id, std::string &const businessName, std::string &const VATIN)
    : Partner(id), businessName(businessName), VATIN(VATIN)
    {
    }
};

void f(Partner const& prtnr)
{


}

int main()
{
    Person p(23, "horvath", "karcsi", "1234567");
    f(p);
}