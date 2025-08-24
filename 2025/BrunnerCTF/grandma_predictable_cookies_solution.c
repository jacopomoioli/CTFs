#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) {
    char ciphertext[] = {0x3e, 0xc6, 0x3c, 0xc4, 0x1f, 0x1a, 0xc1,0x98, 0x06, 0x51, 0x72, 0x6a, 0xb3, 0xce, 0x29, 0x48, 0x88, 0x2b, 0x87, 0x9c, 0x19, 0x67, 0x12, 0x69, 0x96, 0x3e, 0x39, 0x10, 0x3c, 0x83, 0xeb, 0xd6, 0xef, 0x17, 0x3d, 0x60, 0xc7, 0x6e, 0xe5};
    char cleartext[200];
    int approx = 1755860000;
    int seed_time;
    int random;

    // approx is calculated by truncating the last 4 digits
    // we need to test all the digits that could have been truncated
    for (int delta = 0; delta <= 9999; delta++){
        seed_time = approx + delta;
        srand(seed_time);
        for (int i=0; i<=999; ++i){
            rand();
        }
        int i;
        for(i=0; i<39; ++i){
            random = rand();
            cleartext[i] = (ciphertext[i] ^ (random & 0xFF));
            if(cleartext[0] != 'b'){
                break;
            }
        }
        cleartext[i+1] = 0;
        if(cleartext[0] == 'b' && cleartext[1] == 'r'){
            printf("%s\n", cleartext);
        }

    }

}
