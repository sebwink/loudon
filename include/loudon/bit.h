#ifndef LOUDON_BIT_H
#define LOUDON_BIT_H

int bit_get(const unsigned char *bits,
            int pos);

int bit_set(const unsigned char *bits,
            int pos,
            int state);

void bit_xor(const unsigned char *bits1,
             const unsigned char *bits2,
             unsigned char *bitsx,
             int size);

void bit_rot_left(unsigned char *bits,
                  int size,
                  int count);

#endif
