#include "deneme.h"

int topla(int a, int b) {
    return a + b;
}

int cikar(int h, int k)
{
    int result = 0;
    if(h > k)
    {
        result = h-k;
    }
    else
    {
        result = k-h;
    }
    return result;

}