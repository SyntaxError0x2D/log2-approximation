#include <stdio.h>

const int mask = (1 << 23) -1;
const int expmnt = -1 - mask;

int binLeng( unsigned int bin ) {
    for (int i = sizeof(int) * 8-1; i > 0; i--) {
        if ( ( bin & (1 << i) ) > 0) {
            return(i+1);
        }
    };
    return(0);
}


float log2a( int n ) {
    if (n == 0) {return(0.0F);}
    
    int l = binLeng(n);
    float r = (n & ( 1 << ( l - 1 ) ) - 1 );
    int tmp = (( (* (int *) &r) & expmnt) -((l-1)  << 23))  | (( (* (int *) &r) & mask));
   

    return( ((float) l - 1) + * (float *) &tmp );

}
