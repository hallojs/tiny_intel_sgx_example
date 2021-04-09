#include "Enclave_t.h"

/**
 * Securely (completely pointless) compute fibonacci numbers inside the enclave.
 *
 * sgx_edger_8r will generate an untrusted proxy function, which will be called from the
 * application later.
 *
 * @param buf
 * @param len
 */
void ecall_gen_fibonacci_numbers(int *buf, size_t len) {
    buf[0] = 1;
    buf[1] = 1;
    int max = (int)((int)len/(int)sizeof(int));
    for(int i = 2; i < max; i++) {
        buf[i] = buf[i-1] + buf[i-2];
    }
}