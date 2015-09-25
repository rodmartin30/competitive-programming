#include <iostream>
#include <bitset>
using namespace std;
#define SWAP(a,b) a=a^b, b=a^b, a=a^b //swap the values of a and b!


// An int has 32 bits or 4 bytes.
// A char has 8 bits or 1 byte.
// An array c of 4 chars has 32 bits or 4 bytes with the n-th byte as c[n-1]

// A pointer pi of type int * can be converted to a pointer pc of type char
// by the explicit conversion: pc = (char *) pc;

// Remember that p=&a (a is type int) is a pointer to a, (i.e., p holds the position in memory of a)

int main (void) {
    int n,m;
    while(cin >> n){
        m = n;
        char * bytes = (char *) &m;
        SWAP(bytes[0],bytes[3]);
        SWAP(bytes[1],bytes[2]);
        cout << n << " converts to " << m << endl;
    }
    return 0;
}
