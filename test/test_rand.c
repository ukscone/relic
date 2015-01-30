/*
 * RELIC is an Efficient LIbrary for Cryptography
 * Copyright (C) 2007-2015 RELIC Authors
 *
 * This file is part of RELIC. RELIC is legal property of its developers,
 * whose names are not listed here. Please refer to the COPYRIGHT file
 * for contact information.
 *
 * RELIC is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * RELIC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with RELIC. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file
 *
 * Tests for random number generation.
 *
 * @version $Id$
 * @ingroup test
 */

#include <stdio.h>

#include "relic.h"
#include "relic_test.h"

#if RAND == HASH

/*
 * Test vectors taken from:
 * - http://csrc.nist.gov/groups/ST/toolkit/documents/Examples/Hash_DRBG.pdf
 */

#if MD_MAP == SHONE

#define FUNCTION "sha-1"

uint8_t seed1[60];

uint8_t result1[] = {
	0x9F, 0x7C, 0xFF, 0x1E, 0xCA, 0x23, 0xE7, 0x50, 0xF6, 0x63,
	0x26, 0x96, 0x9F, 0x11, 0x80, 0x0F, 0x12, 0x08, 0x8B, 0xA6,
	0x8E, 0x44, 0x1D, 0x15, 0xD8, 0x88, 0xB3, 0xFE, 0x12, 0xBF,
	0x66, 0xFE, 0x05, 0x74, 0x94, 0xF4, 0x54, 0x6D, 0xE2, 0xF1,
	0xB7, 0x7A, 0xA5, 0xC0, 0xCD, 0x55, 0xBB, 0xCE, 0xED, 0x75,
	0x74, 0xAF, 0x22, 0x3A, 0xFD, 0x98, 0x8C, 0x7E, 0xEC, 0x8E,
	0xFF, 0x4A, 0x94, 0xE5, 0xE8, 0x9D, 0x26, 0xA0, 0x4F, 0x58,
	0xFA, 0x79, 0xF5, 0xE0, 0xD3, 0x70, 0x2D, 0x7A, 0x9A, 0x6A,
};

uint8_t result2[] = {
	0x56, 0xEF, 0x49, 0x13, 0x37, 0x39, 0x94, 0xD5, 0x53, 0x9F,
	0x4D, 0x7D, 0x17, 0xAF, 0xE7, 0x44, 0x8C, 0xDF, 0x5E, 0x72,
	0x41, 0x6C, 0xC6, 0xA7, 0x1A, 0x34, 0x00, 0x59, 0xFA, 0x0D,
	0x5A, 0xE5, 0x26, 0xB2, 0x32, 0x50, 0xC4, 0x6C, 0x09, 0x44,
	0x57, 0x5B, 0x37, 0xA2, 0x73, 0x98, 0x14, 0xF9, 0x66, 0xC6,
	0x3B, 0x60, 0xA2, 0xC4, 0xF1, 0x49, 0xCA, 0x9A, 0xCC, 0x84,
	0xFC, 0x4B, 0x25, 0x49, 0x32, 0x89, 0xB0, 0x85, 0xC6, 0x7B,
	0x2E, 0x30, 0xF5, 0xF0, 0xB9, 0x9A, 0x2C, 0x34, 0x9E, 0x2A,
};

#elif MD_MAP == SH224

#define FUNCTION "sha-224"

uint8_t seed1[62];

uint8_t result1[] = {
	0x5E, 0x68, 0xBD, 0xE0, 0x9A, 0xAA, 0x08, 0xBC, 0x11, 0xB3,
	0x27, 0x90, 0x2C, 0x82, 0xF0, 0x11, 0x4C, 0xBA, 0x0F, 0x9C,
	0xCC, 0xA6, 0x20, 0x3B, 0xA3, 0x94, 0x00, 0x91, 0x3E, 0xCD,
	0x36, 0x71, 0xA5, 0xB6, 0x0E, 0xF9, 0x22, 0x99, 0x9D, 0x90,
	0xFC, 0xEE, 0xEC, 0x5C, 0x22, 0x7E, 0x5D, 0x25, 0xC5, 0x69,
	0x21, 0xEE, 0x57, 0x2E, 0xD4, 0x72, 0xDC, 0x05, 0x6F, 0xCB,
	0x35, 0xFF, 0x51, 0xD7, 0xD9, 0xFB, 0x72, 0xFD, 0x4F, 0xD1,
	0xB1, 0xD2, 0x46, 0x45, 0x1D, 0xB5, 0x6C, 0xD4, 0xF8, 0x89,
	0xE4, 0x32, 0xE3, 0x27, 0x3F, 0x9E, 0xD8, 0x2D, 0xE3, 0xEF,
	0x7C, 0xD2, 0x8B, 0x6A, 0x9C, 0x0F, 0x4D, 0x78, 0xE5, 0xC8,
	0x45, 0x1D, 0x36, 0x34, 0x0A, 0x2B, 0xD7, 0xE6, 0x9F, 0xAB,
	0x32, 0xEB
};

uint8_t result2[] = {
	0x3F, 0xE2, 0xAD, 0x85, 0x24, 0xCE, 0x60, 0xE7, 0xC2, 0x1C,
	0x38, 0xA1, 0xDA, 0xB0, 0x2F, 0x3C, 0x20, 0x50, 0x11, 0x82,
	0xF3, 0x89, 0xEE, 0x69, 0x9F, 0x03, 0xFD, 0x87, 0x79, 0xED,
	0x17, 0xC6, 0x5B, 0x87, 0xAC, 0xEE, 0xEB, 0xF1, 0xD1, 0x46,
	0xE7, 0xEE, 0x10, 0x6C, 0xEC, 0x89, 0x55, 0xEE, 0xAF, 0xC1,
	0x8A, 0xBB, 0xC5, 0x62, 0xA5, 0x66, 0x8B, 0xB4, 0x9B, 0x0B,
	0x9C, 0x2F, 0xC7, 0x01, 0x89, 0xB2, 0x4E, 0x02, 0x73, 0x59,
	0x54, 0x58, 0xCD, 0x78, 0x0F, 0xBF, 0xA5, 0xF2, 0x16, 0x12,
	0x24, 0x21, 0xB8, 0x0B, 0xF7, 0x73, 0xD7, 0x36, 0xE6, 0xE1,
	0x1D, 0xEB, 0xB4, 0x24, 0x77, 0xD6, 0x96, 0x68, 0xD2, 0xF9,
	0x40, 0xC6, 0x60, 0xF6, 0xA2, 0xC1, 0xC9, 0xB4, 0x17, 0x95,
	0x92, 0xE0
};

#elif MD_MAP == SH256

uint8_t seed1[63];

#define FUNCTION "sha-256"

uint8_t result1[] = {
	0x77, 0xE0, 0x5A, 0x0E, 0x7D, 0xC7, 0x8A, 0xB5, 0xD8, 0x93,
	0x4D, 0x5E, 0x93, 0xE8, 0x2C, 0x06, 0xA0, 0x7C, 0x04, 0xCE,
	0xE6, 0xC9, 0xC5, 0x30, 0x45, 0xEE, 0xB4, 0x85, 0x87, 0x27,
	0x77, 0xCF, 0x3B, 0x3E, 0x35, 0xC4, 0x74, 0xF9, 0x76, 0xB8,
	0x94, 0xBF, 0x30, 0x1A, 0x86, 0xFA, 0x65, 0x1F, 0x46, 0x39,
	0x70, 0xE8, 0x9D, 0x4A, 0x05, 0x34, 0xB2, 0xEC, 0xAD, 0x29,
	0xEC, 0x04, 0x4E, 0x7E, 0x5F, 0xF4, 0xBA, 0x49, 0x3C, 0x40,
	0xCF, 0xFF, 0x3B, 0x01, 0xE4, 0x72, 0xC5, 0x75, 0x66, 0x8C,
	0xCE, 0x38, 0x80, 0xB9, 0x29, 0x0B, 0x05, 0xBF, 0xED, 0xE5,
	0xEC, 0x96, 0xED, 0x5E, 0x9B, 0x28, 0x98, 0x50, 0x8B, 0x09,
	0xBC, 0x80, 0x0E, 0xEE, 0x09, 0x9A, 0x3C, 0x90, 0x60, 0x2A,
	0xBD, 0x4B, 0x1D, 0x4F, 0x34, 0x3D, 0x49, 0x7C, 0x60, 0x55,
	0xC8, 0x7B, 0xB9, 0x56, 0xD5, 0x3B, 0xF3, 0x51
};

uint8_t result2[] = {
	0x92, 0x27, 0x55, 0x23, 0xC7, 0x0E, 0x56, 0x7B, 0xCF, 0x9B,
	0x35, 0xEC, 0x50, 0xB9, 0x33, 0xF8, 0x12, 0x61, 0x6D, 0xF5,
	0x86, 0xB7, 0xF7, 0x2E, 0xE1, 0xBC, 0x77, 0x35, 0xA5, 0xC2,
	0x65, 0x43, 0x73, 0xCB, 0xBC, 0x72, 0x31, 0x6D, 0xFF, 0x84,
	0x20, 0xA3, 0x3B, 0xF0, 0x2B, 0x97, 0xAC, 0x8D, 0x19, 0x52,
	0x58, 0x3F, 0x27, 0x0A, 0xCD, 0x70, 0x05, 0xCC, 0x02, 0x7F,
	0x4C, 0xF1, 0x18, 0x7E, 0x68, 0x1A, 0x46, 0xB2, 0xAA, 0x86,
	0x94, 0xA0, 0xFE, 0x4D, 0xEE, 0xA7, 0x20, 0x92, 0x7A, 0x84,
	0xEA, 0xAA, 0x98, 0x5E, 0x59, 0xC1, 0x9F, 0x8B, 0xE0, 0x98,
	0x4D, 0x8C, 0xBE, 0xF8, 0xC6, 0x9B, 0x75, 0x41, 0x67, 0x64,
	0x19, 0x46, 0xE0, 0x40, 0xEE, 0x20, 0x43, 0xE1, 0xCC, 0xB2,
	0x9D, 0xCF, 0x06, 0x3C, 0x0A, 0x50, 0x83, 0x0E, 0x42, 0x8E,
	0x6D, 0xCA, 0x26, 0x2E, 0xCD, 0x77, 0xC5, 0x42
};

#elif MD_MAP == SH384

#define FUNCTION "sha-384"

uint8_t seed1[123];

uint8_t result1[] = {
	0x04, 0xFF, 0x23, 0xAD, 0x15, 0xE7, 0x87, 0x90, 0xAD, 0xD3,
	0x6B, 0x43, 0x8B, 0xBC, 0x09, 0x7C, 0x7A, 0x11, 0x74, 0x7C,
	0xC2, 0xCC, 0xEE, 0xDE, 0x2C, 0x97, 0x8B, 0x23, 0xB3, 0xDC,
	0x63, 0xB7, 0x32, 0xC9, 0x53, 0x06, 0x1D, 0x77, 0x64, 0x99,
	0x0A, 0xBF, 0xEF, 0xC4, 0x7A, 0x58, 0x1B, 0x92, 0x1B, 0xC0,
	0x42, 0x8C, 0x4F, 0x12, 0x21, 0x24, 0x60, 0xE4, 0x06, 0xA0,
	0xF0, 0x65, 0x1E, 0x7F, 0x0C, 0xB9, 0xA9, 0x0A, 0xBF, 0xDB,
	0x07, 0xB5, 0x25, 0x56, 0x5C, 0x74, 0xF0, 0xAA, 0x08, 0x50,
	0x82, 0xF6, 0xCF, 0x21, 0x3A, 0xAF, 0xAD, 0x0C, 0x06, 0x46,
	0x89, 0x50, 0x78, 0xF1, 0xE1, 0xFE, 0x4F, 0x35, 0xB8, 0x5F,
	0x95, 0xDE, 0xE3, 0xE8, 0x73, 0x05, 0x49, 0x05, 0xCF, 0xD0,
	0x23, 0x41, 0x65, 0x3E, 0x18, 0xF5, 0x29, 0x93, 0x0C, 0xBE,
	0x14, 0xD9, 0x09, 0xF3, 0x7F, 0xEA, 0xF2, 0xC7, 0x90, 0xD2,
	0x2F, 0xAE, 0x75, 0x16, 0xB4, 0x59, 0x0B, 0xE3, 0x5D, 0x53,
	0xE2, 0xFE, 0x1A, 0x35, 0xAF, 0xE4, 0xB6, 0x60, 0x7C, 0xB3,
	0x58, 0x58, 0x9C, 0x3B, 0x4D, 0x09, 0x4A, 0x1D, 0x81, 0xFE,
	0x07, 0x17, 0xF1, 0xDF, 0x5B, 0xDD, 0xEB, 0x3E, 0x11, 0x4F,
	0x13, 0x0B, 0xB7, 0x81, 0xE6, 0x6C, 0x22, 0xB5, 0xB7, 0x70,
	0xE8, 0xAE, 0x11, 0x5F, 0xF3, 0x9F, 0x8A, 0xDA, 0xF6, 0x6D,
	0xEE, 0xDF
};

uint8_t result2[] = {
	0x97, 0x99, 0x3B, 0x78, 0xF7, 0xC3, 0x1C, 0x0E, 0x87, 0x6D,
	0xC9, 0x2E, 0xB7, 0xD6, 0xC4, 0x08, 0xE0, 0x9D, 0x60, 0x8A,
	0xD6, 0xB9, 0x9D, 0x0E, 0xA2, 0x22, 0x9B, 0x05, 0xA5, 0x78,
	0xC4, 0x26, 0x33, 0x4F, 0xCC, 0x8A, 0x1C, 0x7E, 0x67, 0x6E,
	0xD2, 0xD8, 0x9A, 0x5B, 0x4C, 0xDF, 0x5B, 0x3F, 0x4A, 0xDF,
	0x11, 0x93, 0x6B, 0xF1, 0x4F, 0x4E, 0x10, 0x90, 0x9D, 0xBA,
	0x9C, 0x24, 0xF4, 0xFD, 0xFF, 0xDE, 0x72, 0x35, 0x1D, 0xA8,
	0xE2, 0xCC, 0x3B, 0x13, 0x5A, 0x39, 0x53, 0x73, 0x89, 0x9E,
	0x5F, 0x1A, 0x59, 0x55, 0xB8, 0x80, 0xCA, 0x9B, 0x9E, 0x9D,
	0xD4, 0xC9, 0xCA, 0x7F, 0xA4, 0xD4, 0xF5, 0x98, 0x39, 0x46,
	0x32, 0x0E, 0x36, 0xC6, 0x4E, 0xF2, 0x83, 0xCA, 0x1F, 0x65,
	0xD1, 0x97, 0xCF, 0x81, 0x62, 0x4E, 0xC6, 0x77, 0x8E, 0x77,
	0x0E, 0x78, 0x94, 0x9D, 0x84, 0xEF, 0x21, 0xA4, 0x5C, 0xDD,
	0x62, 0xD1, 0xDB, 0x76, 0x92, 0x0D, 0x4C, 0x28, 0x36, 0xFC,
	0x6A, 0xE5, 0x29, 0x9F, 0xAF, 0x13, 0x57, 0xD9, 0x70, 0x1F,
	0xAD, 0x10, 0xFB, 0xD8, 0x8D, 0x1E, 0x28, 0x32, 0x23, 0x94,
	0x36, 0xD7, 0x6E, 0xB2, 0x71, 0xBD, 0xC3, 0xCA, 0x04, 0x42,
	0x5E, 0xC8, 0x8B, 0xC0, 0xE8, 0x9A, 0x4D, 0x5C, 0x37, 0xFF,
	0xCE, 0x7C, 0x6C, 0x3A, 0xBD, 0xE9, 0xC4, 0x13, 0xAE, 0x6D,
	0x3F, 0xEA
};

#elif MD_MAP == SH512

#define FUNCTION "sha-512"

uint8_t seed1[127];

uint8_t result1[] = {
	0x17, 0x0C, 0xC7, 0x07, 0xC7, 0x1C, 0x69, 0xCE, 0x45, 0xC4,
	0x3C, 0xBA, 0xFF, 0x52, 0x10, 0x14, 0x05, 0x72, 0xD4, 0x78,
	0x59, 0x52, 0x1B, 0xA1, 0x31, 0x41, 0xBA, 0xDD, 0x2E, 0x5B,
	0x9A, 0x7B, 0x3E, 0x80, 0x20, 0x62, 0x5C, 0xD8, 0x89, 0x3F,
	0xD6, 0xA4, 0x73, 0x9C, 0x58, 0x1E, 0xD5, 0xBE, 0x7F, 0xA3,
	0x14, 0x8A, 0x05, 0xD7, 0xF5, 0x4A, 0xE9, 0xEA, 0xDA, 0xE8,
	0xF1, 0xA7, 0x19, 0x4D, 0xF9, 0x4B, 0x6B, 0x75, 0x5B, 0x94,
	0x8E, 0x0C, 0x27, 0xE1, 0x74, 0x7F, 0x02, 0xF6, 0x63, 0xD6,
	0xB5, 0x14, 0xA0, 0xF5, 0x86, 0xF9, 0x4E, 0x53, 0xD3, 0x21,
	0x69, 0xE1, 0xCC, 0xC6, 0x21, 0x1A, 0xD0, 0x34, 0x81, 0x24,
	0x19, 0xB6, 0xBA, 0x8F, 0x3C, 0x82, 0x93, 0x04, 0x89, 0x83,
	0x93, 0xBF, 0x39, 0xE5, 0x7E, 0x2F, 0xED, 0xF7, 0x75, 0xFC,
	0x6E, 0x5E, 0xB0, 0xE3, 0x07, 0xED, 0xCA, 0x0B, 0xD5, 0x15,
	0xB9, 0x2B, 0x18, 0x11, 0xF5, 0xAA, 0xD0, 0x2A, 0xAC, 0x9B,
	0x39, 0xDF, 0xA5, 0xB8, 0xB1, 0xA9, 0x50, 0x48, 0x7D, 0x34,
	0x29, 0xB1, 0x08, 0x1D, 0x0F, 0xEC, 0x28, 0xD5, 0x76, 0x86,
	0xD8, 0x5B, 0xC6, 0xB4, 0x5A, 0xB8, 0xB8, 0x4C, 0x54, 0xDD,
	0x80, 0xB2, 0x82, 0x59, 0x1F, 0x55, 0x07, 0xED, 0x9B, 0x3F,
	0xB1, 0xCD, 0xEE, 0xFD, 0x58, 0xAD, 0x5A, 0x98, 0x12, 0xED,
	0x92, 0x9C, 0x77, 0x9B, 0x0F, 0x54, 0xBA, 0xDF, 0x2C, 0xAF,
	0xBA, 0xCF, 0xAC, 0xB3, 0xEC, 0xAC, 0xC1, 0x27, 0xC7, 0x64,
	0x0C, 0xBB, 0x67, 0x15, 0x4F, 0x54, 0x5A, 0x62, 0x2B, 0xE0,
	0xA9, 0xB5, 0x52, 0xA2, 0x42, 0x08, 0x31, 0x3B, 0xFA, 0x49,
	0x1F, 0x53, 0xAA, 0xA3, 0x07, 0x4B, 0xDC, 0x48, 0xBC, 0x5B,
	0xDB, 0x3F, 0xF0, 0xE2, 0xD0, 0x5B, 0xB4, 0x77, 0xB5, 0x9F,
	0x87, 0xE3, 0xA1, 0xEA, 0xB3, 0xE6
};

uint8_t result2[] = {
	0xF9, 0x3C, 0xA6, 0x85, 0x55, 0x90, 0xA7, 0x7F, 0x07, 0x35,
	0x40, 0x97, 0xE9, 0x0E, 0x02, 0x66, 0x48, 0xB6, 0x11, 0x5D,
	0xF0, 0x08, 0xFF, 0xED, 0xBD, 0x9D, 0x98, 0x11, 0xF5, 0x4E,
	0x82, 0x86, 0xEF, 0x00, 0xFD, 0xD6, 0xBA, 0x1E, 0x58, 0xDF,
	0x25, 0x35, 0xE3, 0xFB, 0xDD, 0x9A, 0x9B, 0xA3, 0x75, 0x4A,
	0x97, 0xF3, 0x6E, 0xE8, 0x33, 0x22, 0x15, 0x82, 0x06, 0x0A,
	0x1F, 0x37, 0xFC, 0xE4, 0xEE, 0x88, 0x26, 0x63, 0x6B, 0x28,
	0xEA, 0xD5, 0x89, 0x59, 0x3F, 0x4C, 0xA8, 0xB6, 0x47, 0x38,
	0x8F, 0x24, 0xEB, 0x3F, 0x0A, 0x34, 0x79, 0x69, 0x68, 0xD2,
	0x1B, 0xDE, 0xE6, 0xF8, 0x1F, 0xD5, 0xDF, 0x93, 0x53, 0x6F,
	0x93, 0x59, 0x37, 0xB8, 0x02, 0x5E, 0xC8, 0xCB, 0xF5, 0x7D,
	0xDB, 0x0C, 0x61, 0xF2, 0xE4, 0x14, 0x63, 0xCC, 0x15, 0x16,
	0xD6, 0x57, 0xDA, 0x28, 0x29, 0xC6, 0xBF, 0x90, 0x48, 0x17,
	0x61, 0x8F, 0x48, 0xC6, 0x0F, 0xB1, 0xCE, 0x5B, 0xFB, 0xDA,
	0x0C, 0xAF, 0x45, 0x91, 0x88, 0x2A, 0x31, 0xF6, 0xEE, 0x3F,
	0xE0, 0xF7, 0x87, 0x79, 0x99, 0x2A, 0x06, 0xEC, 0x60, 0xF3,
	0x7F, 0xB9, 0xA8, 0xD6, 0x10, 0x8C, 0x23, 0x1F, 0x0A, 0x92,
	0x77, 0x54, 0xB0, 0x59, 0x9F, 0xA4, 0xFA, 0x27, 0xA4, 0xE2,
	0x5E, 0x06, 0x5E, 0xF0, 0x30, 0x85, 0xB8, 0x92, 0x97, 0x9D,
	0xC0, 0xE7, 0xA1, 0x08, 0x08, 0x83, 0xCA, 0xEB, 0xFD, 0xFD,
	0x36, 0x65, 0xA8, 0xF2, 0xD0, 0x61, 0xC5, 0x21, 0xF7, 0xD6,
	0xE3, 0xDA, 0x2A, 0xF8, 0xB9, 0x7B, 0x6B, 0x43, 0xB6, 0xEC,
	0x83, 0x1A, 0xF5, 0x15, 0x07, 0x0A, 0x83, 0xBB, 0xB9, 0xAC,
	0x95, 0xED, 0x4E, 0xF4, 0x9B, 0x75, 0x6A, 0x23, 0x77, 0xA5,
	0xF0, 0x83, 0x3D, 0x84, 0x7E, 0x27, 0xA8, 0x8D, 0xDB, 0x0C,
	0x2C, 0xE4, 0xAD, 0x78, 0x2E, 0x7B
};

#endif

static int test(void) {
	int i, len = 2 * MD_LEN, size = (RAND_SIZE - 1) / 2, code = STS_ERR;
	uint8_t out[len], seed2[size], seed3[size];

	for (i = 0; i < (RAND_SIZE - 1) / 2; i++) {
		seed1[i] = i;
		seed2[i] = 0x80 + i;
		seed3[i] = 0xC0 + i;
	}
	for (; i < sizeof(seed1); i++) {
		seed1[i] = 0x20 + (i - (RAND_SIZE - 1) / 2);
	}

	TEST_ONCE("hash-dbrg (" FUNCTION ") random generator is correct") {
		rand_clean();
		rand_seed(seed1, sizeof(seed1));
		rand_bytes(out, len);
		TEST_ASSERT(memcmp(out, result1, len) == 0, end);
		rand_bytes(out, len);
		TEST_ASSERT(memcmp(out, result1 + len, len) == 0, end);
	}
	TEST_END;

	TEST_ONCE("hash-dbrg (" FUNCTION ") reseeding is correct") {
		rand_clean();
		rand_seed(seed1, sizeof(seed1));
		rand_seed(seed2, sizeof(seed2));
		rand_bytes(out, len);
		TEST_ASSERT(memcmp(out, result2, len) == 0, end);
		rand_seed(seed3, sizeof(seed3));
		rand_bytes(out, len);
		TEST_ASSERT(memcmp(out, result2 + len, len) == 0, end);
	}
	TEST_END;

	code = STS_OK;

  end:
	return code;
}

#elif RAND == FIPS

/*
 * Test vectors taken from:
 * - http://csrc.nist.gov/encryption/dss/Examples-1024bit.pdf
 * - http://www.ietf.org/rfc/rfc4186.txt
 */

uint8_t test1[20] = {
	0xBD, 0x02, 0x9B, 0xBE, 0x7F, 0x51, 0x96, 0x0B, 0xCF, 0x9E,
	0xDB, 0x2B, 0x61, 0xF0, 0x6F, 0x0F, 0xEB, 0x5A, 0x38, 0xB6
};

uint8_t test2[20] = {
	0xE5, 0x76, 0xD5, 0xCA, 0x33, 0x2E, 0x99, 0x30, 0x01, 0x8B,
	0xF1, 0xBA, 0xEE, 0x27, 0x63, 0xC7, 0x95, 0xB3, 0xC7, 0x12
};

uint8_t result1[40] = {
	0x20, 0x70, 0xb3, 0x22, 0x3D, 0xBA, 0x37, 0x2F, 0xDE, 0x1C,
	0x0F, 0xFC, 0x7B, 0x2E, 0x3B, 0x49, 0x8B, 0x26, 0x06, 0x14,
	0x3C, 0x6C, 0x18, 0xBA, 0xCB, 0x0F, 0x6C, 0x55, 0xBA, 0xBB,
	0x13, 0x78, 0x8E, 0x20, 0xD7, 0x37, 0xA3, 0x27, 0x51, 0x16
};

uint8_t result2[160] = {
	0x53, 0x6E, 0x5E, 0xBC, 0x44, 0x65, 0x58, 0x2A, 0xA6, 0xA8,
	0xEC, 0x99, 0x86, 0xEB, 0xB6, 0x20, 0x25, 0xAF, 0x19, 0x42,
	0xEF, 0xCB, 0xF4, 0xBC, 0x72, 0xB3, 0x94, 0x34, 0x21, 0xF2,
	0xA9, 0x74, 0x39, 0xD4, 0x5A, 0xEA, 0xF4, 0xE3, 0x06, 0x01,
	0x98, 0x3E, 0x97, 0x2B, 0x6C, 0xFD, 0x46, 0xD1, 0xC3, 0x63,
	0x77, 0x33, 0x65, 0x69, 0x0D, 0x09, 0xCD, 0x44, 0x97, 0x6B,
	0x52, 0x5F, 0x47, 0xD3, 0xA6, 0x0A, 0x98, 0x5E, 0x95, 0x5C,
	0x53, 0xB0, 0x90, 0xB2, 0xE4, 0xB7, 0x37, 0x19, 0x19, 0x6A,
	0x40, 0x25, 0x42, 0x96, 0x8F, 0xD1, 0x4A, 0x88, 0x8F, 0x46,
	0xB9, 0xA7, 0x88, 0x6E, 0x44, 0x88, 0x59, 0x49, 0xEA, 0xB0,
	0xFF, 0xF6, 0x9D, 0x52, 0x31, 0x5C, 0x6C, 0x63, 0x4F, 0xD1,
	0x4A, 0x7F, 0x0D, 0x52, 0x02, 0x3D, 0x56, 0xF7, 0x96, 0x98,
	0xFA, 0x65, 0x96, 0xAB, 0xEE, 0xD4, 0xF9, 0x3F, 0xBB, 0x48,
	0xEB, 0x53, 0x4D, 0x98, 0x54, 0x14, 0xCE, 0xED, 0x0D, 0x9A,
	0x8E, 0xD3, 0x3C, 0x38, 0x7C, 0x9D, 0xFD, 0xAB, 0x92, 0xFF,
	0xBD, 0xF2, 0x40, 0xFC, 0xEC, 0xF6, 0x5A, 0x2C, 0x93, 0xB9,
};

static int test(void) {
	int code = STS_ERR;
	uint8_t out[160];

	TEST_ONCE("fips 186-2 (cn1) random generator is correct") {
		rand_seed(test1, 20);
		rand_bytes(out, 40);
		TEST_ASSERT(memcmp(out, result1, 40) == 0, end);
		rand_seed(test2, 20);
		rand_bytes(out, 160);
		TEST_ASSERT(memcmp(out, result2, 160) == 0, end);
	}
	TEST_END;

	code = STS_OK;

  end:
	return code;
}

#elif RAND == UDEV

static int test(void) {
	uint8_t out[20], digit;

	TEST_ONCE("reading from /dev/urandom is correct") {
		digit = 0;
		memset(out, 0, sizeof(out));
		rand_bytes(out, sizeof(out));
		for (int j = 0; j < sizeof(20); j++) {
			digit ^= out[j];
		}
		TEST_ASSERT(digit != 0, end);
	}
	TEST_END;
  end:
	return STS_OK;
}

#elif RAND == RDRND

static int test(void) {
	uint8_t out[64];
	int len = sizeof(out) / 2, code = STS_ERR;

	TEST_ONCE("rdrand hardware generator is non-trivial") {
		memset(out, 0, 2 * len);
		rand_bytes(out, len);
		/* This fails with negligible probability. */
		TEST_ASSERT(memcmp(out, out + len, len) != 0, end);
	}
	TEST_END;

	code = STS_OK;

  end:
	return code;	
}

#elif RAND == CALL

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

static void test_bytes(uint8_t *buf, int size, void *args) {
	int c, l, fd = *(int *)args;
	
	if (fd == -1) {
		THROW(ERR_NO_FILE);
	}

	l = 0;
	do {
		c = read(fd, buf + l, size - l);
		l += c;
		if (c == -1) {
			THROW(ERR_NO_READ);
		}
	} while (l < size);
}

static int test(void) {
	uint8_t out[20], digit;
	int fd = open("/dev/urandom", O_RDONLY);

	TEST_ONCE("callback to reading /dev/urandom is correct") {
		digit = 0;
		memset(out, 0, sizeof(out));
		rand_bytes(out, sizeof(out));
		for (int j = 0; j < sizeof(20); j++) {
			digit ^= out[j];
		}
		TEST_ASSERT(digit != 0, end);
		rand_seed(&test_bytes, (void *)&fd);
		rand_bytes(out, sizeof(out));
		for (int j = 0; j < sizeof(20); j++) {
			digit ^= out[j];
		}
		TEST_ASSERT(digit != 0, end);
	}
	TEST_END;
  end:
  	close(fd);
	return STS_OK;
}

#endif

int main(void) {
	if (core_init() != STS_OK) {
		core_clean();
		return 1;
	}

	util_banner("Tests for the RAND module:\n", 0);

	if (test() != STS_OK) {
		core_clean();
		return 1;
	}

	util_banner("All tests have passed.\n", 0);

	core_clean();
	return 0;
}
