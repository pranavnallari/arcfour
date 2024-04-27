#include "arcfour.h"

#define F fflush(stdout)

int main(void);



void printbin(int8 *input, const int16 size)
{
    int16 i;
    int8 *p;
    assert(size > 0);

    for (i=size, p=input; i; i--, p++) {
        if(!(i % 2)) printf(" ");
        printf("%02x", *p);
    }
    printf("\n");
    return;
}


int main() {
    Arcfour *rc4;
    int16 skey, stext;
    skey = stext = 0;
    const char *key, *from, *to;
    int8 *encrypted, *decrypted;
    key = from = to = 0;
    encrypted = decrypted = 0;
    key = "tomatoes"; //CREATE REAL ENCYRTION KEY from 8 to 2048 bits
    skey = strlen(key);
    from = "Hello World. This is a test file";
    stext = strlen(from);


    printf("Initializing Encryption...."); F;
    rc4 = rc4init((int8 *)key, skey);
    printf("Initializing Done....\n");
    printf("'%s'\n->",from);
    encrypted = rc4encrypt(rc4, (int8 *)from, stext);
    printbin(encrypted, stext);

    rc4uninit(rc4);

    printf("Initializing Decryption...."); F;
    rc4 = rc4init((int8 *)key, skey);
    printf("Initializing Done....\n");
    decrypted = rc4encrypt(rc4, encrypted, stext);
    printf("    -> '%s'\n",decrypted);

    rc4uninit(rc4);
    return 0;
}