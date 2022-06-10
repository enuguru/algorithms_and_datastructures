#include<stdio.h>

int main() {
    char* buffer = "Hello 20";
    char store_string[10];
    int store_integer;
    int total_read;

    total_read = sscanf(buffer, "%s %d" , store_string, &store_integer);

    printf("String value in buffer: %s" ,store_string);
    printf(" \nInteger value in buffer: %d",store_integer);
    printf("\nTotal items read: %d",total_read);
    return 0;
}