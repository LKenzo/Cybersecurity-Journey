#include <stdio.h>

long long hash(unsigned char *param_1) {
    unsigned char *local_20;
    long long local_10;
  
    local_10 = 0x1505;
    local_20 = param_1;
    
    while(1) {
        if (*local_20 == 0) break;
        local_10 = *local_20 + local_10 * 0x21;
        local_20++;
    }
    return local_10;
}

int main(void) {
    unsigned char obs_bytes[] = {0xc3, 0xff, 0xc8, 0xc2, 0x92, 0x9b, 0x8b, 0xc0, 0x80, 0xc2, 0xc4, 0x8b, 0x00};
    unsigned char param_1[14];
    int i;

    for (i = 0; obs_bytes[i] != '\0'; i++) {
        param_1[i] = obs_bytes[i] ^ 0xaa;
    }

    param_1[i] = '\0';
    

    printf("hash: %lld", hash(param_1));

    return 0;
}