/*
 * Base64 encoding/decoding (RFC1341)
 * Copyright (c) 2005, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef BASE64_H
#define BASE64_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>  // For boolean data type (bool, true, false)

int base64_encode(const unsigned char *src, size_t len, unsigned char *out);
int base64_decode(const unsigned char *src, size_t len, unsigned char *out);

#endif /* BASE64_H */