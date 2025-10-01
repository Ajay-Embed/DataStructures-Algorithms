#include "hash.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*
 * Reference: https://github.com/tidwall/hashmap.c/blob/master/hashmap.c
 */

//-----------------------------------------------------------------------------
// SipHash reference C implementation
//
// Copyright (c) 2012-2016 Jean-Philippe Aumasson
// <jeanphilippe.aumasson@gmail.com>
// Copyright (c) 2012-2014 Daniel J. Bernstein <djb@cr.yp.to>
//
// To the extent possible under law, the author(s) have dedicated all copyright
// and related and neighboring rights to this software to the public domain
// worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along
// with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
//
// default: SipHash-2-4
//-----------------------------------------------------------------------------
static uint64_t SIP64(const uint8_t *in, const size_t inlen, uint64_t seed_0, uint64_t seed_1) {
#define U8TO64_LE(p)                                            \
    {(((uint64_t)((p)[0])) | ((uint64_t)((p)[1]) << 8) |        \
      ((uint64_t)((p)[2]) << 16) | ((uint64_t)((p)[3]) << 24) | \
      ((uint64_t)((p)[4]) << 32) | ((uint64_t)((p)[5]) << 40) | \
      ((uint64_t)((p)[6]) << 48) | ((uint64_t)((p)[7]) << 56))}

#define U64TO8_LE(p, v)                            \
    {                                              \
        U32TO8_LE((p), (uint64_t)((v)));           \
        U32TO8_LE((p) + 4, (uint64_t)((v) >> 32)); \
    }

#define U32TO8_LE(p, v)                \
    {                                  \
        (p)[0] = (uint8_t)((v));       \
        (p)[1] = (uint8_t)((v) >> 8);  \
        (p)[2] = (uint8_t)((v) >> 16); \
        (p)[3] = (uint8_t)((v) >> 24); \
    }

#define ROTL(x, b) (uint64_t)(((x) << (b)) | ((x) >> (64 - (b))))

#define SIPROUND           \
    {                      \
        v0 += v1;          \
        v1 = ROTL(v1, 13); \
        v1 ^= v0;          \
        v0 = ROTL(v0, 32); \
        v2 += v3;          \
        v3 = ROTL(v3, 16); \
        v3 ^= v2;          \
        v0 += v3;          \
        v3 = ROTL(v3, 21); \
        v3 ^= v0;          \
        v2 += v1;          \
        v1 = ROTL(v1, 17); \
        v1 ^= v2;          \
        v2 = ROTL(v2, 32); \
    }

    uint64_t k0 = U8TO64_LE((uint8_t *)&seed_0);
    uint64_t k1 = U8TO64_LE((uint8_t *)&seed_1);
    uint64_t v3 = UINT64_C(0x7465646279746573) ^ k1;
    uint64_t v2 = UINT64_C(0x6c7967656e657261) ^ k0;
    uint64_t v1 = UINT64_C(0x646f72616e646f6d) ^ k1;
    uint64_t v0 = UINT64_C(0x736f6d6570736575) ^ k0;

    const uint8_t *end = in + inlen - (inlen % sizeof(uint64_t));

    for (; in != end; in += 8) {
        uint64_t m = U8TO64_LE(in);
        v3 ^= m;
        SIPROUND;
        SIPROUND;
        v0 ^= m;
    }

    const int left = inlen & 7;

    uint64_t b = ((uint64_t)inlen) << 56;

    switch (left) {
        case 7:
            b |= ((uint64_t)in[6]) << 48; /* fall through */
        case 6:
            b |= ((uint64_t)in[5]) << 40; /* fall through */
        case 5:
            b |= ((uint64_t)in[4]) << 32; /* fall through */
        case 4:
            b |= ((uint64_t)in[3]) << 24; /* fall through */
        case 3:
            b |= ((uint64_t)in[2]) << 16; /* fall through */
        case 2:
            b |= ((uint64_t)in[1]) << 8; /* fall through */
        case 1:
            b |= ((uint64_t)in[0]);
            break;
        case 0:
            break;
    }

    v3 ^= b;
    SIPROUND;
    SIPROUND;

    v0 ^= b;
    v2 ^= 0xff;
    SIPROUND;
    SIPROUND;
    SIPROUND;
    SIPROUND;

    b = v0 ^ v1 ^ v2 ^ v3;
    uint64_t out = 0;

    U64TO8_LE((uint8_t *)&out, b);

    return out;
}

//-----------------------------------------------------------------------------
// MurmurHash3 was written by Austin Appleby, and is placed in the public
// domain. The author hereby disclaims copyright to this source code.
//
// Murmur3_86_128
//-----------------------------------------------------------------------------
static uint64_t MM86128(const void *key, const int len, uint64_t seed) {
#define ROTL32(x, r) ((x << r) | (x >> (32 - r)))

#define FMIX32(h)    \
    h ^= h >> 16;    \
    h *= 0x85ebca6b; \
    h ^= h >> 13;    \
    h *= 0xc2b2ae35; \
    h ^= h >> 16;

    const uint8_t *data = (const uint8_t *)key;
    const int nblocks = len / 16;

    uint64_t h1 = seed;
    uint64_t h2 = seed;
    uint64_t h3 = seed;
    uint64_t h4 = seed;

    uint64_t c1 = 0x239b961b;
    uint64_t c2 = 0xab0e9789;
    uint64_t c3 = 0x38b34ae5;
    uint64_t c4 = 0xa1e38b93;

    const uint64_t *blocks = (const uint64_t *)(data + nblocks * 16);

    for (int i = -nblocks; i; i++) {
        uint64_t k1 = blocks[i * 4 + 0];
        uint64_t k2 = blocks[i * 4 + 1];
        uint64_t k3 = blocks[i * 4 + 2];
        uint64_t k4 = blocks[i * 4 + 3];

        k1 *= c1;
        k1 = ROTL32(k1, 15);
        k1 *= c2;
        h1 ^= k1;
        h1 = ROTL32(h1, 19);
        h1 += h2;
        h1 = h1 * 5 + 0x561ccd1b;
        k2 *= c2;
        k2 = ROTL32(k2, 16);
        k2 *= c3;
        h2 ^= k2;
        h2 = ROTL32(h2, 17);
        h2 += h3;
        h2 = h2 * 5 + 0x0bcaa747;
        k3 *= c3;
        k3 = ROTL32(k3, 17);
        k3 *= c4;
        h3 ^= k3;
        h3 = ROTL32(h3, 15);
        h3 += h4;
        h3 = h3 * 5 + 0x96cd1c35;
        k4 *= c4;
        k4 = ROTL32(k4, 18);
        k4 *= c1;
        h4 ^= k4;
        h4 = ROTL32(h4, 13);
        h4 += h1;
        h4 = h4 * 5 + 0x32ac3b17;
    }

    const uint8_t *tail = (const uint8_t *)(data + nblocks * 16);

    uint64_t k1 = 0;
    uint64_t k2 = 0;
    uint64_t k3 = 0;
    uint64_t k4 = 0;

    switch (len & 15) {
        case 15:
            k4 ^= tail[14] << 16; /* fall through */
        case 14:
            k4 ^= tail[13] << 8; /* fall through */
        case 13:
            k4 ^= tail[12] << 0;
            k4 *= c4;
            k4 = ROTL32(k4, 18);
            k4 *= c1;
            h4 ^= k4;
        /* fall through */
        case 12:
            k3 ^= tail[11] << 24; /* fall through */
        case 11:
            k3 ^= tail[10] << 16; /* fall through */
        case 10:
            k3 ^= tail[9] << 8; /* fall through */
        case 9:
            k3 ^= tail[8] << 0;
            k3 *= c3;
            k3 = ROTL32(k3, 17);
            k3 *= c4;
            h3 ^= k3;
        /* fall through */
        case 8:
            k2 ^= tail[7] << 24; /* fall through */
        case 7:
            k2 ^= tail[6] << 16; /* fall through */
        case 6:
            k2 ^= tail[5] << 8; /* fall through */
        case 5:
            k2 ^= tail[4] << 0;
            k2 *= c2;
            k2 = ROTL32(k2, 16);
            k2 *= c3;
            h2 ^= k2;
        /* fall through */
        case 4:
            k1 ^= tail[3] << 24; /* fall through */
        case 3:
            k1 ^= tail[2] << 16; /* fall through */
        case 2:
            k1 ^= tail[1] << 8; /* fall through */
        case 1:
            k1 ^= tail[0] << 0;
            k1 *= c1;
            k1 = ROTL32(k1, 15);
            k1 *= c2;
            h1 ^= k1;
            /* fall through */
    };

    h1 ^= len;
    h2 ^= len;
    h3 ^= len;
    h4 ^= len;

    h1 += h2;
    h1 += h3;
    h1 += h4;
    h2 += h1;
    h3 += h1;
    h4 += h1;

    FMIX32(h1);
    FMIX32(h2);
    FMIX32(h3);
    FMIX32(h4);

    h1 += h2;
    h1 += h3;
    h1 += h4;
    h2 += h1;
    h3 += h1;
    h4 += h1;

    return (((uint64_t)h2) << 32) | h1;
}

//-----------------------------------------------------------------------------
// xxHash Library
// Copyright (c) 2012-2021 Yann Collet
// All rights reserved.
//
// BSD 2-Clause License (https://www.opensource.org/licenses/bsd-license.php)
//
// xxHash3
//-----------------------------------------------------------------------------
#define XXH_PRIME_1 11400714785074694791ULL
#define XXH_PRIME_2 14029467366897019727ULL
#define XXH_PRIME_3 1609587929392839161ULL
#define XXH_PRIME_4 9650029242287828579ULL
#define XXH_PRIME_5 2870177450012600261ULL

static uint64_t XXH_read64(const void *memptr) {
    uint64_t val;

    memcpy(&val, memptr, sizeof(val));

    return val;
}

static uint64_t XXH_read32(const void *memptr) {
    uint64_t val;

    memcpy(&val, memptr, sizeof(val));

    return val;
}

static uint64_t XXH_rotl64(uint64_t x, int r) {
    return (x << r) | (x >> (64 - r));
}

static uint64_t xxh3(const void *data, size_t len, uint64_t seed) {
    const uint8_t *p = (const uint8_t *)data;
    const uint8_t *const end = p + len;

    uint64_t h64;

    if (len >= 32) {
        const uint8_t *const limit = end - 32;
        uint64_t v1 = seed + XXH_PRIME_1 + XXH_PRIME_2;
        uint64_t v2 = seed + XXH_PRIME_2;
        uint64_t v3 = seed + 0;
        uint64_t v4 = seed - XXH_PRIME_1;

        do {
            v1 += XXH_read64(p) * XXH_PRIME_2;
            v1 = XXH_rotl64(v1, 31);
            v1 *= XXH_PRIME_1;

            v2 += XXH_read64(p + 8) * XXH_PRIME_2;
            v2 = XXH_rotl64(v2, 31);
            v2 *= XXH_PRIME_1;

            v3 += XXH_read64(p + 16) * XXH_PRIME_2;
            v3 = XXH_rotl64(v3, 31);
            v3 *= XXH_PRIME_1;

            v4 += XXH_read64(p + 24) * XXH_PRIME_2;
            v4 = XXH_rotl64(v4, 31);
            v4 *= XXH_PRIME_1;

            p += 32;
        } while (p <= limit);

        h64 = XXH_rotl64(v1, 1) + XXH_rotl64(v2, 7) + XXH_rotl64(v3, 12) +
              XXH_rotl64(v4, 18);

        v1 *= XXH_PRIME_2;
        v1 = XXH_rotl64(v1, 31);
        v1 *= XXH_PRIME_1;
        h64 ^= v1;
        h64 = h64 * XXH_PRIME_1 + XXH_PRIME_4;

        v2 *= XXH_PRIME_2;
        v2 = XXH_rotl64(v2, 31);
        v2 *= XXH_PRIME_1;
        h64 ^= v2;
        h64 = h64 * XXH_PRIME_1 + XXH_PRIME_4;

        v3 *= XXH_PRIME_2;
        v3 = XXH_rotl64(v3, 31);
        v3 *= XXH_PRIME_1;
        h64 ^= v3;
        h64 = h64 * XXH_PRIME_1 + XXH_PRIME_4;

        v4 *= XXH_PRIME_2;
        v4 = XXH_rotl64(v4, 31);
        v4 *= XXH_PRIME_1;
        h64 ^= v4;
        h64 = h64 * XXH_PRIME_1 + XXH_PRIME_4;
    } else {
        h64 = seed + XXH_PRIME_5;
    }

    h64 += (uint64_t)len;

    while (p + 8 <= end) {
        uint64_t k1 = XXH_read64(p);
        k1 *= XXH_PRIME_2;
        k1 = XXH_rotl64(k1, 31);
        k1 *= XXH_PRIME_1;
        h64 ^= k1;
        h64 = XXH_rotl64(h64, 27) * XXH_PRIME_1 + XXH_PRIME_4;
        p += 8;
    }

    if (p + 4 <= end) {
        h64 ^= (uint64_t)(XXH_read32(p)) * XXH_PRIME_1;
        h64 = XXH_rotl64(h64, 23) * XXH_PRIME_2 + XXH_PRIME_3;
        p += 4;
    }

    while (p < end) {
        h64 ^= (*p) * XXH_PRIME_5;
        h64 = XXH_rotl64(h64, 11) * XXH_PRIME_1;
        p++;
    }

    h64 ^= h64 >> 33;
    h64 *= XXH_PRIME_2;
    h64 ^= h64 >> 29;
    h64 *= XXH_PRIME_3;
    h64 ^= h64 >> 32;

    return h64;
}

// hashmap_sip returns a hash value for `data` using SipHash-2-4.
uint64_t hash_sip(const void *data, size_t len, uint64_t seed_0, uint64_t seed_1) {
    return SIP64((uint8_t *)data, len, seed_0, seed_1);
}

// hashmap_murmur returns a hash value for `data` using Murmur3_86_128.
uint64_t hash_murmur(const void *data, size_t len, uint64_t seed) {
    return MM86128(data, len, seed);
}
// hashmap_murmur returns a hash value for `data` using xxHash3.
uint64_t hash_xxhash3(const void *data, size_t len, uint64_t seed) {
    return xxh3(data, len, seed);
}
