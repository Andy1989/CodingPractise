/* Implement int sqrt(int x).
 * Compute and return the square root of x.
 * Use Babylonian method:
 *   1. Begin with an arbitrary positive starting value x0 (the closer to the actual square root of S, the better).
 *   2. Let xn+1 be the average of xn and S / xn (using the arithmetic mean to approximate the geometric mean).
 *   3. Repeat step 2 until the desired accuracy is achieved.
 */

int sqrt(int x) {
    
    if(x == 0)
        return 0;
        
    float x0 = 1.0, x1;
    x1 = (x0 + x / x0) / 2;
    while(abs(x1 - x0) >= 1.0) {
        x0 = x1;
        x1 = (x0 + x / x0) / 2;
    }
    
    int rv = static_cast<int>(floor(x1));
    while(rv * rv > x) {
        rv --;
    }
    return rv;
}

