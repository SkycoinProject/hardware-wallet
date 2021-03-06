/*
 * This file is part of the Skycoin project, https://skycoin.net/
 *
 * Copyright (C) 2018-2019 Skycoin Project
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#include "tiny-firmware/firmware/bootloader_integrity.h"
#include "tiny-firmware/memory.h"
#include "skycoin-crypto/tools/sha2.h"
#include "string.h"

int check_bootloader(void) {
    uint8_t hash[SHA256_DIGEST_LENGTH];
    memory_bootloader_hash(hash);
    return !memcmp(hash,
                   "\x63\x30\xfc\xec\x16\x72\xfa\xd3\x0b\x42\x1b\x60\xf7\x4f\x83\x9a\x39\x39\x33\x45\x65\xcb\x70\x3b\x2b\xd7\x18\x2e\xa2\xdd\xa0\x19",
                   SHA256_DIGEST_LENGTH);
}

