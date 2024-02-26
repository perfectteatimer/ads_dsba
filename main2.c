#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, n; // Inputs
    scanf("%d %d %d", &A, &B, &n);
    long long scale = 1;
    for (int i = 0; i < n; i++) {
        scale *= 10; // Compute 10^n
    }

    // Step 1 and 3: Scale A and add half of B for rounding
    long long scaledA = A * scale + B / 2;

    // Step 2: Divide by B
    long long result = scaledA / B;

    // Divide result into integer and decimal parts
    long long integerPart = result / scale;
    long long decimalPart = result % scale;

    // Output the integer part
    printf("%lld", integerPart);

    // Output the decimal part with 'n' digits
    if (n > 0) {
        printf(".");
        long long leadingZerosScale = scale / 10;
        while (leadingZerosScale > 0 && (decimalPart / leadingZerosScale) == 0) {
            printf("0");
            leadingZerosScale /= 10;
        }
        printf("%lld", decimalPart);
    }

    return 0;
}
