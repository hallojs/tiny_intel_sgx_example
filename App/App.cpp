#include <stdio.h>
#include <unistd.h>

#include "sgx_urts.h"
#include "Enclave_u.h"

// Enclave ID
sgx_enclave_id_t global_eid = 0;

/**
 * Initialize an SGX enclave.
 * @return error state
 */
int initialize_enclave(void) {
    sgx_status_t state = SGX_ERROR_UNEXPECTED;

    char enclavefile[256];
    getcwd(enclavefile, sizeof(enclavefile));
    strcat(enclavefile, "/enclave.signed.so");

    state = sgx_create_enclave(enclavefile, SGX_DEBUG_FLAG, NULL, NULL, &global_eid, NULL);

    if (state != SGX_SUCCESS) {
        printf("Can not create enclave, error-code: %d\n", state);
        return -1;
    }

    return 0;
}

/**
 * Main application.
 */
int SGX_CDECL main() {
    size_t len = 10;
    int buf[10] = {0};

    initialize_enclave();
    sgx_status_t state = ecall_gen_fibonacci_numbers(global_eid, buf, len*sizeof(int));

    if (state != SGX_SUCCESS) {
        printf("Can not run enclave call, error-code: %d\n", state);
        return -1;
    }

    sgx_destroy_enclave(global_eid);

    printf("Securely computed fibonacci numbers:\n");
    for(int i = 0; i < (int)len; i++) {
        printf("%d\n", buf[i]);
    }

    return 0;
}
