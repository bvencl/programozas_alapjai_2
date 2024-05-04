#pragma once

class SharedPtr
{
private:
    double *obj;
    int *refcount;

public:
    SharedPtr();
    SharedPtr(double *);
    SharedPtr(const SharedPtr &);
    ~SharedPtr();

    double operator*();
    bool operator==(const SharedPtr &);
    SharedPtr &operator=(const SharedPtr &);
};
