#pragma once

class FallingObject
{

private:
    double InitialHeight, Gravity;

public:
    FallingObject(double H, double G = 9.81);

    double GetInitialHeight() const;

    double GetGravity() const;

    void SetInitialHeight(double H);

    void SetGravity(double G);

    double GetHeight(double Time) const;

    double GetSpeed(double Time) const;

    double GetFallTime() const;
};