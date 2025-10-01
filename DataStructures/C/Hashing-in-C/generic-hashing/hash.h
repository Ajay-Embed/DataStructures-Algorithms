#ifndef HASH_H
#define HASH_H

// #include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Warning: This implementation is not thread-safe, and is for educational purposes only.

uint64_t hash_sip(const void *data, size_t len, uint64_t seed0, uint64_t seed1);
uint64_t hash_murmur(const void *data, size_t len, uint64_t seed);
uint64_t hash_xxhash3(const void *data, size_t len, uint64_t seed);

#endif  // HASHSET_H