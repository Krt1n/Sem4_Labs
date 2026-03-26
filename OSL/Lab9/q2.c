#include <stdio.h>
#include <math.h>

int main() {
    int logical_address;
    int page_size = 32;

    int offset_bits = log2(page_size); 
    int page_number, offset;

    printf("Enter logical address: ");
    scanf("%d", &logical_address);

    page_number = logical_address / page_size;
    offset = logical_address % page_size;

    printf("\nPage Number: %d\n", page_number);
    printf("Offset: %d\n", offset);

    int total_memory = 256;
    int total_bits = log2(total_memory);

    printf("\nTotal bits required to represent address: %d bits\n", total_bits);

    return 0;
}