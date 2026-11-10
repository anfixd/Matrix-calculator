#pragma once

#include "types.h"

#include <vector>

class Matrix {
    private: 
        ll N = 0, M = 0;
        std::vector<std::vector<double>> V;

    public:
        void SetSize(ll n, ll m);
        void Create(ll n, ll m);
        void Resize(ll n, ll m);
        void Fill();
        void SilentSetVal(ll x, ll y, double val);
        void SetVal(ll x, ll y, double val);
        void Print();
        double GetVal(ll x, ll y);
        bool IsEmpty();
        std::pair<ll, ll> GetSize();
};