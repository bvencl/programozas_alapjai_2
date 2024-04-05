#include "test.h"
#include <cmath>

FallingObject::FallingObject(double H, double G)
{
    SetInitialHeight(H);
    SetGravity(G);
}

void FallingObject::SetInitialHeight(double H)
{
    InitialHeight = H > 0 ? H : 1;
}

void FallingObject::SetGravity(double G)
{
    Gravity = G > 0 ? G : 9.81;
}

double FallingObject::GetInitialHeight() const
{
    return InitialHeight;
}

double FallingObject::GetGravity() const
{
    return Gravity;
}
double FallingObject::GetHeight(double Time) const
{
    if (Time > GetFallTime())
        return 0;

    return InitialHeight - (0.5 * Gravity * (Time * Time));
}

double FallingObject::GetSpeed(double Time) const
{
    if (Time > GetFallTime())
        return 0;
    return Gravity * Time;
}

double FallingObject::GetFallTime() const
{
    return std::sqrt((2 * InitialHeight) / Gravity);
}