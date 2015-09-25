#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#define F 12
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    if(F-n<=5)
        printf("YES\n");
    else
        printf("NO\n");
}
