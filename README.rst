Tiny Intel SGX Example
======================
This super duper minimal Intel SGX example is based on the sample code from the Intel SGX for Linux Repository [1]_.

**Do not expect the code in this repository to be secure, it's just experimental!**

What happens here?
------------------

1. The application initializes an enclave.
2. The application performs an enclave call to securely compute the first ten fibonacci numbers inside the enclave.
4. The application destroys the enclave.
3. The application prints the computed fibonacci numbers to the standard output.

Yeah, it's completely pointless :D

How to Build/Execute?
---------------------

*This section is from the Intel SGX for Linux Repository* [1]_.

1. Install Intel(R) SGX SDK for Linux* OS
2. Make sure your environment is set:

   ``$ source ${sgx-sdk-install-path}/environment``

3. Build the project with the prepared Makefile:

   a. Hardware Mode, Debug build:

      1) Enclave with no mitigation:

         ``$ make``

      2) Enclave with mitigations for indirects and returns only:

         ``$ make MITIGATION-CVE-2020-0551=CF``

      3) Enclave with full mitigation:

         ``$ make MITIGATION-CVE-2020-0551=LOAD``

   b. Hardware Mode, Pre-release build:

      1) Enclave with no mitigation:

         ``$ make SGX_PRERELEASE=1 SGX_DEBUG=0``

      2) Enclave with mitigations for indirects and returns only:

         ``$ make SGX_PRERELEASE=1 SGX_DEBUG=0 MITIGATION-CVE-2020-0551=CF``

      3) Enclave with full mitigation:

         ``$ make SGX_PRERELEASE=1 SGX_DEBUG=0 MITIGATION-CVE-2020-0551=LOAD``

   c. Hardware Mode, Release build:

      1) Enclave with no mitigation:

         ``$ make SGX_DEBUG=0``

      2) Enclave with mitigations for indirects and returns only:

         ``$ make SGX_DEBUG=0 MITIGATION-CVE-2020-0551=CF``

      3) Enclave with full mitigation:

         ``$ make SGX_DEBUG=0 MITIGATION-CVE-2020-0551=LOAD``

   d. Simulation Mode, Debug build:

      ``$ make SGX_MODE=SIM``

   e. Simulation Mode, Pre-release build:

      ``$ make SGX_MODE=SIM SGX_PRERELEASE=1 SGX_DEBUG=0``

   f. Simulation Mode, Release build:

      ``$ make SGX_MODE=SIM SGX_DEBUG=0``

4. Execute the binary directly:

   ``$ ./secure_fibonacci``

5. Remember to "make clean" before switching build mode


How to create your own key?
---------------------------

*See also the Intel SGX SDK for Linux Developer Reference* [2]_.

``openssl genrsa -out private_key.pem -3 3072``


Explanation about Configuration Parameters
------------------------------------------

*This section is from the Intel SGX for Linux Repository* [1]_.

TCSMaxNum, TCSNum, TCSMinPool

    These three parameters will determine whether a thread will be created
    dynamically  when there is no available thread to do the work.


StackMaxSize, StackMinSize

    For a dynamically created thread, StackMinSize is the amount of stack available
    once the thread is created and StackMaxSize is the total amount of stack that
    thread can use. The gap between StackMinSize and StackMaxSize is the stack
    dynamically expanded as necessary at runtime.

    For a static thread, only StackMaxSize is relevant which specifies the total
    amount of stack available to the thread.


HeapMaxSize, HeapInitSize, HeapMinSize

    HeapMinSize is the amount of heap available once the enclave is initialized.

    HeapMaxSize is the total amount of heap an enclave can use. The gap between
    HeapMinSize and HeapMaxSize is the heap dynamically expanded as necessary
    at runtime.

    HeapInitSize is here for compatibility.

References
----------

.. [1] `https://github.com/intel/linux-sgx <https://github.com/intel/linux-sgx>`_

.. [2] `https://01.org/intel-softwareguard-extensions <https://01.org/intel-softwareguard-extensions>`_

License
-------

All Intel code is licensed under BSD (find the license `here <https://github.com/intel/linux-sgx/blob/master/License.txt>`_).
