Another useful feature is the bit modifier:

typedef union
{
    struct {
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char reserved:4;
    } bits;
    unsigned char byte;
} HW_RegisterB;
HW_RegisterB reg;