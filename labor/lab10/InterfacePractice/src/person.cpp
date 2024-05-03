#include "person.h"

using namespace std;

Person::Person(unsigned char age, double height, double weight) : age(age), height(height), weight(weight) {}

void Person::setAge(unsigned char age)
{
	this->age = age;
}

int Person::getAge() const
{
	return age;
}

bool Person::setHeight(double height)
{
	if (height < 10 || height > 300)
		return false;
	this->height = height;
	return true;
}

double Person::getHeight() const
{
	return height;
}

bool Person::setWeight(double weight)
{
	if (weight < 0 || weight > 400)
		return false;

	this->weight = weight;

	return true;
}

double Person::getWeight() const
{
	return weight;
}

void Person::serialize(ostream &os) const
{
	// unsigned char -> int, különben karakterként írja ki
	os << (int)age << '\t' << height << '\t' << weight << endl;
}

void Person::deserialize(istream &is)
{
	int age, height, weight;
	is >> age;
	if (!is)
	{
		return;
	}

	is >> height >> weight;
	if (is)
	{
		this->age = age;
		this->weight = weight;
		this->height = height;
	}
	else
		throw("could not read person");
}

bool Person::operator==(Comparable const &rhs) const
{
	return true;
}

bool Person::operator<(Comparable const &rhs) const
{

	Person const *prhs = dynamic_cast<Person const *>(&rhs);
	if (prhs == nullptr)
		throw "Invalid comparision";
	// return height < ((Person const &)rhs).height; // DOWNCAST, lefelé kasztolok (ősből példányba), ILYET NEM CSINÁLUNK
	return height < prhs->height;
}

/*
ostream& operator<<(ostream& os, const Person& right)
{
	//TODO
	return os;
}
*/