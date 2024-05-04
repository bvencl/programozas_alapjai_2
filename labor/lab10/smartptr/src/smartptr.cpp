
#include "smartptr.h"

SharedPtr::SharedPtr() : obj(nullptr), refcount(new int(0)){};

SharedPtr::SharedPtr(double *objectValue) : obj(objectValue), refcount(new int(1))
{
    if (obj == nullptr)
    {
        *refcount = 0;
    }
}

SharedPtr::SharedPtr(const SharedPtr &other)
{
    obj = other.obj;
    refcount = other.refcount;
    (*refcount)++;
}

SharedPtr::~SharedPtr()
{
    if (refcount && --(*refcount) == 0) // talán nem túl elegáns (?), de annál frappánsabb az && sorrendiségét kihasználni
    {
        delete obj;
        delete refcount;
    }
    obj = nullptr;
    refcount = nullptr;
}

double SharedPtr::operator*()
{
    if (obj != nullptr)
        return *obj;
    return 0;
}

bool SharedPtr::operator==(const SharedPtr &other)
{
    if (obj == other.obj || *obj == *(other.obj))
        return true;
    return false;
    // Ez most csak azt vizsgálja, hogy ugyan arra az objektumra, vagy ugyan arra az értékre mutatnak-e
}

SharedPtr &SharedPtr::operator=(const SharedPtr &other)
{
    if (this != &other)
    {
        this->~SharedPtr(); // Ezt tényleg nem gondolom túl elegánsnak, de talán még mindig jobb ebben az esetben mint a kódmásolás, kíváncsi lennék a véleményére!
        obj = other.obj;
        refcount = other.refcount;
        if (refcount)      // ha nullptr lenne akkor nem szeretnénk növelni (kis időbe telt kitalálni, hogy nem szabad / ez az amit nem szabad :) )
            (*refcount)++; // mennyire elegáns egy sorral feljebb a nullpointer ilyen módon való vizsgálata, az if(*refcount == 0), vagy if(refcount == nullptr) helyett?
    }
    return *this;
}
