
# RC4 Encryption Library in C

## Introduction

This is a simple implementation of the RC4 (Rivest Cipher 4) algorithm in C. RC4 is a symmetric stream cipher known for its simplicity and speed in software implementations. It is commonly used in various cryptographic protocols and applications.

## Usage

### Compilation

To compile the library and the test program, you can use the provided Makefile. Simply run:

```bash
make
```

This will compile both the library (`arcfour.so`) and the test program (`test`). 

### Testing

You can run the test program to verify the functionality of the library:

```bash
make run
```

### Cleaning

To clean up the compiled files, you can use:

```bash
make clean
```

## Library API

### Initialization

To initialize the RC4 encryption, use the `rc4init` function:

```c
Arcfour *rc4init(int8 *key, int16 size);
```

This function takes the encryption key (`key`) and its size (`size`) in bytes as input parameters. It returns a pointer to the initialized `Arcfour` structure.

### Encryption

To encrypt a plaintext using RC4, use the `rc4encrypt` function:

```c
int8 *rc4encrypt(Arcfour *p, int8 *plaintext, int16 size);
```

This function takes the initialized RC4 structure (`p`), plaintext (`plaintext`), and its size (`size`) in bytes as input parameters. It returns a pointer to the encrypted ciphertext.

### Decryption

Since RC4 is a symmetric cipher, decryption is the same as encryption. You can use the `rc4encrypt` function for decryption as well.

### Cleanup

To free the memory allocated for the RC4 structure after use, use the `rc4uninit` macro:

```c
rc4uninit(rc4);
```
