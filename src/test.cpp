// copyright defined in LICENSE.txt

#include "lib-database.hpp"

#include "test-common.hpp"

const unsigned char foo[] = {
    0x10, 0x42, 0xc8, 0x58, 0xe5, 0x49, 0x7b, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xa8, 0xed, 0x32, 0x32, 0x00, 0x00, 0x00, 0x00, 0x80, 0xab,
    0x26, 0xa7, 0x01, 0x00, 0x00, 0x00, 0x43, 0x00, 0x02, 0x05, 0x80, 0xd8, 0x46, 0x09, 0x0c, 0xbe, 0x71, 0x72, 0x36, 0x71, 0xcd, 0xc4,
    0xef, 0x7b, 0xfe, 0x96, 0x49, 0x47, 0xa6, 0x83, 0xbf, 0xe0, 0x5e, 0xb9, 0x6d, 0x90, 0x05, 0xc9, 0xb1, 0xf2, 0x2f, 0x01, 0x00, 0x00,
    0x02, 0x09, 0x3a, 0x46, 0xe3, 0xdb, 0x9f, 0xd8, 0x99, 0x22, 0x21, 0xc4, 0xff, 0x53, 0x9d, 0x23, 0x96, 0x36, 0xe2, 0x57, 0x5f, 0x93,
    0xf7, 0x41, 0x8d, 0x9a, 0x72, 0xbc, 0xf6, 0x44, 0x49, 0xdb, 0x76, 0x01, 0x00, 0x00, 0x02, 0x15, 0xa3, 0xf0, 0xc9, 0x98, 0x50, 0x64,
    0xb0, 0x70, 0x91, 0x21, 0xbe, 0xdf, 0x2e, 0xf4, 0x68, 0xe4, 0x07, 0xf5, 0xdd, 0xf5, 0x75, 0x2f, 0x60, 0xa6, 0x1c, 0xdf, 0x26, 0xbe,
    0x73, 0x5b, 0x1c, 0x01, 0x00, 0x00, 0x02, 0x1c, 0x2b, 0xaf, 0x23, 0x33, 0x8c, 0xb2, 0x9c, 0x84, 0x1b, 0x08, 0x73, 0x94, 0x8d, 0x3c,
    0xdf, 0x1a, 0x86, 0xe9, 0x4e, 0x7a, 0x7f, 0x8f, 0x8a, 0xf8, 0x18, 0x59, 0x1d, 0x13, 0x91, 0x0f, 0xf4, 0x01, 0x00, 0x00, 0x02, 0x2c,
    0xb5, 0x87, 0x68, 0x63, 0x33, 0x10, 0xaf, 0x22, 0xc4, 0x3d, 0x24, 0x1b, 0x37, 0x4b, 0x34, 0x54, 0xd2, 0x3d, 0x10, 0x96, 0x5f, 0xb2,
    0x23, 0x2f, 0xfe, 0xba, 0xb0, 0x9f, 0x70, 0x91, 0x50, 0x01, 0x00, 0x00, 0x02, 0x31, 0xd4, 0x82, 0xfe, 0xeb, 0x49, 0x94, 0xb1, 0x92,
    0x98, 0xd8, 0xf4, 0xf4, 0x06, 0xc6, 0x36, 0x52, 0x54, 0xab, 0x4b, 0xf8, 0xf9, 0x0c, 0xcd, 0xe6, 0x12, 0x05, 0xb9, 0xb5, 0x09, 0xaa,
    0x94, 0x01, 0x00, 0x00, 0x02, 0x35, 0x8b, 0xd5, 0xcd, 0x49, 0x6e, 0x85, 0xc1, 0x17, 0x73, 0x4d, 0xbc, 0xfa, 0x48, 0xd8, 0xfd, 0xf0,
    0xe0, 0xe5, 0xc3, 0x99, 0xd2, 0x60, 0x52, 0xe0, 0x11, 0xbe, 0x4e, 0x87, 0x0e, 0xe2, 0x03, 0x01, 0x00, 0x00, 0x02, 0x39, 0xfd, 0xc1,
    0x4e, 0x03, 0x28, 0xac, 0xa8, 0x0d, 0x7e, 0xeb, 0x0b, 0x16, 0x52, 0xc0, 0x5c, 0x50, 0x95, 0xe1, 0x47, 0xab, 0x47, 0xad, 0xb9, 0x8c,
    0x42, 0xa2, 0x6b, 0x91, 0xb1, 0x79, 0xeb, 0x01, 0x00, 0x00, 0x02, 0x3b, 0x8a, 0x64, 0x93, 0x52, 0xfb, 0x6f, 0x78, 0x7d, 0xf0, 0x75,
    0x4e, 0xb8, 0x03, 0x33, 0x1c, 0x19, 0x85, 0x0e, 0x71, 0xbe, 0x27, 0xba, 0x80, 0xa5, 0x6f, 0xf1, 0x73, 0x49, 0x6b, 0xd0, 0x00, 0x01,
    0x00, 0x00, 0x02, 0x42, 0x69, 0x72, 0xe0, 0xf8, 0x99, 0x6a, 0xc2, 0x35, 0xaf, 0x0a, 0xe3, 0x02, 0xc4, 0xd3, 0x7c, 0xbd, 0xe0, 0x9a,
    0xff, 0x39, 0xc4, 0x57, 0x53, 0x3e, 0x61, 0xd1, 0x3f, 0x3a, 0x16, 0xdf, 0x5a, 0x01, 0x00, 0x00, 0x02, 0x4c, 0x7b, 0xe5, 0x3c, 0x98,
    0xc2, 0xaf, 0xde, 0x85, 0x94, 0xdf, 0x30, 0xd6, 0x68, 0x50, 0x72, 0x07, 0xe7, 0xad, 0x69, 0xa0, 0xa7, 0x7a, 0x8b, 0x19, 0x96, 0x6d,
    0x89, 0xe6, 0x6a, 0x1a, 0x1e, 0x01, 0x00, 0x00, 0x02, 0x4c, 0x7f, 0x9f, 0x99, 0x1a, 0x64, 0x09, 0xcc, 0xa1, 0xc5, 0x08, 0x0c, 0x0d,
    0xb4, 0x3b, 0x77, 0xd9, 0xa7, 0x6e, 0xe1, 0xaf, 0x37, 0x62, 0x71, 0x0b, 0xd0, 0x72, 0x92, 0x9b, 0x8e, 0xb0, 0x33, 0x01, 0x00, 0x00,
    0x02, 0x63, 0x26, 0x63, 0xef, 0x84, 0x50, 0x87, 0x6e, 0x00, 0x80, 0xcc, 0x91, 0x59, 0x88, 0x44, 0xb9, 0x2f, 0x73, 0x4a, 0x01, 0x6c,
    0x1e, 0x02, 0x12, 0x3f, 0x3a, 0x29, 0xe8, 0x0e, 0xcf, 0x48, 0x43, 0x01, 0x00, 0x00, 0x02, 0x77, 0x37, 0x6d, 0x68, 0x7d, 0x67, 0x0c,
    0xc9, 0x32, 0x08, 0xbb, 0xbb, 0x00, 0xa0, 0x77, 0x53, 0x32, 0xeb, 0xb5, 0x26, 0x32, 0xb5, 0xb0, 0xf5, 0xd1, 0xd3, 0x31, 0x07, 0x0c,
    0x04, 0xab, 0x81, 0x01, 0x00, 0x00, 0x02, 0x7a, 0x7a, 0xff, 0x79, 0x85, 0xbf, 0x85, 0xaf, 0xcb, 0xa9, 0xaa, 0x34, 0x5a, 0xdc, 0xad,
    0x34, 0x7a, 0x30, 0xaa, 0xe0, 0xcc, 0x3d, 0x50, 0x93, 0xc3, 0x91, 0x68, 0xac, 0x34, 0xdd, 0x07, 0x2b, 0x01, 0x00, 0x00, 0x02, 0x7e,
    0xdc, 0xc8, 0x9a, 0x73, 0x26, 0x7c, 0x8c, 0x00, 0x87, 0x98, 0x50, 0x03, 0xa2, 0x47, 0x62, 0xe5, 0x13, 0xdb, 0x4a, 0x37, 0x07, 0xde,
    0xb1, 0x0f, 0xd9, 0xc9, 0xba, 0x3e, 0x7d, 0xf1, 0x49, 0x01, 0x00, 0x00, 0x02, 0x99, 0x35, 0xc4, 0x5c, 0xa0, 0xa7, 0x03, 0xc4, 0x57,
    0x1d, 0x99, 0x94, 0x26, 0xa1, 0xa7, 0x9d, 0xad, 0x2a, 0xe6, 0x2d, 0x26, 0x10, 0xe7, 0xa0, 0x26, 0xa3, 0x36, 0x3f, 0xf5, 0xe2, 0x99,
    0x14, 0x01, 0x00, 0x00, 0x02, 0x9b, 0xbd, 0xaf, 0xd1, 0x81, 0x53, 0x23, 0xe0, 0x32, 0x45, 0xef, 0x0b, 0xe9, 0x7a, 0x19, 0xb3, 0xd1,
    0xc9, 0xf0, 0x05, 0xd5, 0x5a, 0x60, 0x46, 0x4f, 0xeb, 0xda, 0x8c, 0x62, 0x80, 0xe3, 0x68, 0x01, 0x00, 0x00, 0x02, 0xa1, 0x08, 0xdd,
    0x25, 0x3d, 0x71, 0x44, 0x3e, 0xa6, 0xfb, 0xb7, 0x95, 0x31, 0x31, 0xa5, 0xf0, 0x47, 0x9e, 0x05, 0xec, 0x0b, 0x2b, 0xdb, 0x33, 0x41,
    0xe0, 0x97, 0xb8, 0x4b, 0xc0, 0x47, 0x39, 0x01, 0x00, 0x00, 0x02, 0xb0, 0xc4, 0x75, 0xf7, 0x18, 0xa1, 0xa2, 0xfc, 0xee, 0x96, 0xa1,
    0x57, 0xa9, 0xd8, 0xa3, 0x0d, 0x79, 0x1b, 0xb7, 0xc4, 0x7f, 0x44, 0x4d, 0xb4, 0xf9, 0x75, 0x3d, 0x88, 0xa4, 0x85, 0xfe, 0x2d, 0x01,
    0x00, 0x00, 0x02, 0xb4, 0xa1, 0xd6, 0x82, 0xc1, 0xf4, 0xb8, 0x48, 0x94, 0x1c, 0x09, 0xea, 0xde, 0x05, 0xf3, 0x5c, 0x6f, 0x11, 0x99,
    0x28, 0xc7, 0x9d, 0xff, 0x8f, 0xad, 0x20, 0xbe, 0xd2, 0xda, 0xa7, 0x0e, 0x66, 0x01, 0x00, 0x00, 0x02, 0xc0, 0x0e, 0x34, 0xb6, 0xb8,
    0x5d, 0xe9, 0x45, 0xbb, 0x43, 0x36, 0x77, 0xac, 0x7b, 0xc9, 0xe5, 0x31, 0xa0, 0xd7, 0x89, 0x05, 0xa4, 0x24, 0x70, 0x07, 0xa2, 0x9f,
    0x6c, 0xe2, 0xfd, 0x78, 0x8a, 0x01, 0x00, 0x00, 0x02, 0xc9, 0xce, 0xa5, 0x41, 0x62, 0x9e, 0x53, 0x30, 0x34, 0xa1, 0x58, 0x9d, 0x6b,
    0x1c, 0xa4, 0xd2, 0x77, 0x7d, 0xf7, 0xe3, 0x07, 0x01, 0x11, 0xa0, 0x72, 0x6d, 0xc0, 0x90, 0xe1, 0xb4, 0x07, 0xdb, 0x01, 0x00, 0x00,
    0x02, 0xcf, 0x08, 0xc4, 0x6a, 0x2a, 0x6a, 0xbf, 0xbd, 0xda, 0xb5, 0x28, 0x28, 0xf5, 0x3d, 0x30, 0x3a, 0xe8, 0x6a, 0x0e, 0xbf, 0xab,
    0x20, 0xdb, 0x4e, 0x2a, 0xd0, 0xf1, 0x6e, 0x5e, 0x1a, 0x83, 0x66, 0x01, 0x00, 0x00, 0x02, 0xcf, 0x56, 0x61, 0x94, 0x76, 0x79, 0xbf,
    0x38, 0xc1, 0x56, 0xbd, 0xad, 0x7b, 0xaa, 0x88, 0x88, 0x17, 0x28, 0xdd, 0x9c, 0x4a, 0x72, 0x2a, 0xb8, 0x49, 0x7f, 0x6d, 0xeb, 0x45,
    0xa7, 0x94, 0x8d, 0x01, 0x00, 0x00, 0x02, 0xec, 0xc6, 0xd7, 0x99, 0xac, 0xc0, 0xfc, 0xe1, 0xdd, 0xb5, 0x01, 0xf7, 0x12, 0x07, 0x2c,
    0x05, 0x9e, 0x23, 0xcf, 0xfd, 0x60, 0x1a, 0x8c, 0x9e, 0x82, 0x4d, 0x04, 0xe2, 0xf6, 0xf3, 0xf2, 0xa3, 0x01, 0x00, 0x00, 0x02, 0xed,
    0x62, 0x11, 0x2d, 0x8c, 0x81, 0xb7, 0x9d, 0x08, 0x07, 0x90, 0xb2, 0x39, 0x69, 0xc5, 0x7f, 0xe3, 0xd2, 0x77, 0x05, 0xc6, 0x94, 0xb9,
    0xe5, 0x46, 0xdb, 0x2e, 0xd7, 0x50, 0x31, 0x0d, 0x36, 0x01, 0x00, 0x00, 0x02, 0xf3, 0x73, 0x00, 0xe0, 0xf2, 0x24, 0x17, 0xb0, 0x37,
    0x60, 0xb4, 0x28, 0x58, 0x6d, 0xc9, 0x4d, 0x73, 0x82, 0xee, 0x45, 0x80, 0x4d, 0xfa, 0x85, 0x60, 0x07, 0x0e, 0x53, 0x0d, 0xe1, 0xe3,
    0xfe, 0x01, 0x00, 0x00, 0x02, 0xf7, 0x01, 0x51, 0xc2, 0x91, 0xef, 0xcf, 0x2f, 0x4c, 0xd1, 0x4a, 0xcc, 0x0e, 0xf1, 0x10, 0x11, 0x1e,
    0x7b, 0xaf, 0x15, 0x30, 0xcb, 0x73, 0x64, 0xf9, 0x76, 0xd8, 0x57, 0x8e, 0x44, 0x81, 0x40, 0x01, 0x00, 0x00, 0x02, 0xf8, 0x1c, 0x92,
    0x8a, 0xfb, 0x93, 0x53, 0x55, 0x9b, 0x91, 0x18, 0xa1, 0x52, 0xb0, 0x20, 0x32, 0x5d, 0xfd, 0x22, 0x30, 0xe8, 0xac, 0x52, 0x91, 0x12,
    0x80, 0x76, 0x18, 0x7e, 0x57, 0xe2, 0xd7, 0x01, 0x00, 0x00, 0x02, 0xf8, 0xfc, 0x2f, 0xf3, 0xb9, 0x75, 0xe9, 0x9e, 0x45, 0x3f, 0xd0,
    0xf9, 0x1c, 0x2e, 0x4d, 0xb9, 0xf2, 0xdc, 0x19, 0x8a, 0xfe, 0x3a, 0xe2, 0x7f, 0x53, 0x5a, 0xf8, 0xf2, 0x89, 0x53, 0xd8, 0xd0, 0x01,
    0x00, 0x00, 0x02, 0xfc, 0x1a, 0x79, 0x55, 0xd4, 0x98, 0x87, 0x2f, 0xac, 0xb6, 0x37, 0x4e, 0x95, 0x07, 0xb7, 0x32, 0x36, 0xbf, 0x9a,
    0x60, 0x66, 0xe7, 0x66, 0xee, 0x05, 0x13, 0x23, 0xea, 0xc3, 0xd0, 0x93, 0xa7, 0x01, 0x00, 0x00, 0x03, 0x05, 0x95, 0x6d, 0x3c, 0x02,
    0x0b, 0x3a, 0x0b, 0x79, 0xa2, 0xea, 0xa9, 0x81, 0xbf, 0xba, 0xc2, 0xcb, 0x49, 0x2b, 0xb2, 0x38, 0x22, 0x40, 0x69, 0xcf, 0x56, 0x3a,
    0x73, 0xa3, 0xd7, 0x4b, 0x26, 0x01, 0x00, 0x00, 0x03, 0x14, 0x53, 0xef, 0xeb, 0xa2, 0x61, 0xc5, 0x24, 0x06, 0x03, 0xbb, 0x0f, 0x8e,
    0xca, 0xe0, 0x1d, 0xaa, 0x4e, 0x7d, 0xd8, 0x9b, 0xcc, 0x2f, 0x5e, 0x24, 0x6e, 0xf5, 0x64, 0x21, 0x1f, 0x1a, 0x95, 0x01, 0x00, 0x00,
    0x03, 0x17, 0xfc, 0xd3, 0xc1, 0x4f, 0xfe, 0x44, 0x8e, 0x8c, 0xdf, 0x5e, 0x1f, 0x06, 0x75, 0xbc, 0x19, 0x43, 0xc8, 0x94, 0x82, 0x08,
    0x7f, 0xb4, 0x68, 0x16, 0xcd, 0xb5, 0x8c, 0xcc, 0xbc, 0xae, 0x8c, 0x01, 0x00, 0x00, 0x03, 0x19, 0xfc, 0x9f, 0xba, 0xb0, 0xa5, 0xea,
    0xc4, 0xc7, 0x32, 0xaa, 0xb1, 0x13, 0xb0, 0x6d, 0x8d, 0x89, 0x37, 0xce, 0x53, 0x72, 0xef, 0xd8, 0x45, 0x60, 0xa4, 0x8b, 0x8c, 0xf8,
    0x1f, 0xcc, 0x5a, 0x01, 0x00, 0x00, 0x03, 0x1b, 0xdc, 0x6f, 0xf5, 0xb1, 0x9b, 0xc9, 0xbe, 0x21, 0x30, 0xc4, 0x16, 0x87, 0x71, 0xcb,
    0xf0, 0x4f, 0x31, 0x4d, 0x46, 0x61, 0x8b, 0xa1, 0x86, 0xbf, 0xe4, 0xe5, 0xac, 0x37, 0x08, 0x63, 0xfa, 0x01, 0x00, 0x00, 0x03, 0x1f,
    0xf5, 0xb1, 0x33, 0x56, 0xb1, 0x18, 0xc5, 0xe9, 0x01, 0xa5, 0x7a, 0x07, 0xa6, 0x5a, 0xeb, 0x86, 0x55, 0x0b, 0xad, 0xba, 0xdc, 0xfa,
    0xd8, 0x79, 0x2e, 0x04, 0x6c, 0x55, 0x82, 0x2e, 0xaf, 0x01, 0x00, 0x00, 0x03, 0x33, 0x27, 0xb3, 0x4d, 0xcd, 0xe2, 0x56, 0xd8, 0x3c,
    0xa0, 0x55, 0xdb, 0xd8, 0x72, 0xe8, 0xc3, 0x56, 0x25, 0xc4, 0x0f, 0x5d, 0xa6, 0xa2, 0x48, 0x69, 0x99, 0x83, 0x15, 0x18, 0x26, 0xb3,
    0xea, 0x01, 0x00, 0x00, 0x03, 0x4c, 0xff, 0x9d, 0x4c, 0x80, 0xed, 0x16, 0x92, 0x75, 0x43, 0x23, 0x47, 0xf5, 0x97, 0x44, 0x93, 0x98,
    0x62, 0x25, 0xac, 0x28, 0x4c, 0xc3, 0xb3, 0xdc, 0x0a, 0xd1, 0x06, 0x41, 0x45, 0x72, 0x43, 0x01, 0x00, 0x00, 0x03, 0x5a, 0x24, 0x9b,
    0x2f, 0xb4, 0xf1, 0x43, 0x53, 0x10, 0x1c, 0x69, 0x69, 0xf3, 0xb1, 0x10, 0xe4, 0xd9, 0x1d, 0xc1, 0xbd, 0x77, 0xa1, 0x05, 0x13, 0x76,
    0x6c, 0xc9, 0xe1, 0xef, 0xb2, 0x11, 0x3b, 0x01, 0x00, 0x00, 0x03, 0x5b, 0x00, 0xa5, 0x54, 0x1e, 0x94, 0x0c, 0xdf, 0xcf, 0x81, 0xf9,
    0xa3, 0x8d, 0x54, 0x43, 0xf6, 0x3c, 0x10, 0x0c, 0x9a, 0x35, 0xd4, 0xe7, 0x34, 0xad, 0x51, 0xab, 0xb1, 0x37, 0xcd, 0x55, 0xf1, 0x01,
    0x00, 0x00, 0x03, 0x5d, 0xba, 0xdd, 0x20, 0xff, 0xc3, 0x90, 0xfc, 0x18, 0x6d, 0x4b, 0x49, 0x25, 0x6e, 0x9b, 0xe1, 0x00, 0x01, 0xbf,
    0x55, 0x8f, 0xc4, 0x84, 0x4e, 0xbb, 0x1c, 0x3d, 0x90, 0x35, 0x9e, 0xeb, 0x2c, 0x01, 0x00, 0x00, 0x03, 0x6c, 0xb9, 0xc7, 0xf7, 0x05,
    0xb5, 0xcc, 0xc5, 0x71, 0x37, 0x2b, 0x32, 0xba, 0xb4, 0xb0, 0xb5, 0x71, 0x2b, 0x4d, 0x98, 0x40, 0x9e, 0x54, 0x5d, 0xff, 0xbe, 0xd7,
    0xa5, 0x49, 0x61, 0x2b, 0x85, 0x01, 0x00, 0x00, 0x03, 0x7b, 0x26, 0x67, 0x17, 0x11, 0x23, 0xad, 0xff, 0x6f, 0x45, 0xb7, 0x53, 0x44,
    0xdd, 0xf1, 0xc5, 0xf5, 0x41, 0x0b, 0x88, 0xb2, 0x69, 0x90, 0x5b, 0x58, 0xd5, 0xfc, 0xe7, 0xb0, 0x90, 0x62, 0xef, 0x01, 0x00, 0x00,
    0x03, 0x7b, 0x92, 0xab, 0x2a, 0x85, 0x91, 0xf3, 0xa6, 0x8d, 0xc9, 0xff, 0x56, 0xb8, 0xfc, 0xdc, 0xbe, 0xb8, 0xb9, 0xc9, 0x3c, 0x8e,
    0x71, 0xb2, 0x02, 0x76, 0x48, 0x0b, 0x4c, 0xe2, 0xf4, 0x08, 0x1b, 0x01, 0x00, 0x00, 0x03, 0x8e, 0x93, 0xf4, 0xad, 0x35, 0x3a, 0x21,
    0x9f, 0x5b, 0x7a, 0x71, 0x32, 0xda, 0x76, 0xaa, 0x34, 0xda, 0x1a, 0xec, 0xf9, 0xa1, 0xff, 0x8a, 0x3a, 0x67, 0x8e, 0x2b, 0xa4, 0x71,
    0x8d, 0x78, 0x06, 0x01, 0x00, 0x00, 0x03, 0x90, 0x06, 0xda, 0x6b, 0xaf, 0x3a, 0x6e, 0xe8, 0x92, 0x34, 0xcd, 0x31, 0xd9, 0x94, 0x6b,
    0x02, 0x01, 0xaf, 0x95, 0x63, 0xed, 0x22, 0x79, 0xcf, 0xd1, 0xee, 0xf8, 0x63, 0x92, 0xc2, 0x9c, 0xc8, 0x01, 0x00, 0x00, 0x03, 0x98,
    0x1c, 0x01, 0x95, 0x92, 0x11, 0x78, 0x80, 0x3f, 0xfa, 0xac, 0x66, 0x64, 0xfe, 0x6b, 0x32, 0x62, 0x9e, 0x9e, 0xa5, 0x1d, 0xca, 0xf1,
    0x18, 0xcb, 0xb8, 0x7d, 0x66, 0xc6, 0x26, 0xf9, 0x88, 0x01, 0x00, 0x00, 0x03, 0xa4, 0xb8, 0xe7, 0x48, 0x1a, 0xed, 0xb8, 0xc9, 0xaf,
    0x42, 0xc2, 0xe2, 0x91, 0x68, 0xf1, 0x80, 0x64, 0x56, 0x01, 0x03, 0x16, 0x1b, 0x53, 0xe4, 0x71, 0xf5, 0xce, 0x38, 0xe2, 0xa4, 0x4c,
    0xba, 0x01, 0x00, 0x00, 0x03, 0xa9, 0x46, 0xca, 0x86, 0xf0, 0x63, 0xf2, 0xe2, 0x58, 0x08, 0xa2, 0x53, 0x37, 0xae, 0xc0, 0xa1, 0xdf,
    0x21, 0x7f, 0x81, 0x6d, 0xc3, 0xe3, 0xee, 0x76, 0xd8, 0x3c, 0x74, 0x03, 0x27, 0x4d, 0x2e, 0x01, 0x00, 0x00, 0x03, 0xac, 0x88, 0xca,
    0xc3, 0xfb, 0x9c, 0x6c, 0x86, 0x51, 0xd0, 0x37, 0xfe, 0xe1, 0x35, 0xac, 0x27, 0x44, 0x4f, 0x15, 0x4c, 0xb9, 0x28, 0x89, 0xfc, 0x4f,
    0xeb, 0x7e, 0x6d, 0xd4, 0xd8, 0x6c, 0x5a, 0x01, 0x00, 0x00, 0x03, 0xb2, 0x5a, 0x9d, 0xd8, 0x1e, 0x16, 0x16, 0xd6, 0x81, 0x65, 0xe0,
    0xe6, 0xa1, 0xcd, 0x48, 0xd8, 0x87, 0x09, 0x2c, 0xcc, 0x39, 0xa0, 0x5f, 0xe0, 0x53, 0xca, 0x18, 0xc1, 0xf4, 0x55, 0xbd, 0x4b, 0x01,
    0x00, 0x00, 0x03, 0xb6, 0x1f, 0xfc, 0x56, 0x3f, 0x13, 0x2d, 0xcb, 0xaa, 0xcc, 0x2e, 0x2a, 0x91, 0x10, 0x24, 0xad, 0x1a, 0x83, 0x67,
    0xe1, 0x3b, 0xb9, 0x6d, 0x2d, 0x8c, 0x3a, 0xeb, 0xd6, 0xa6, 0x74, 0xef, 0x47, 0x01, 0x00, 0x00, 0x03, 0xbe, 0xea, 0xcd, 0xd1, 0xed,
    0x1e, 0x39, 0x81, 0x28, 0x1a, 0x41, 0x88, 0xcd, 0xe1, 0xaa, 0x0d, 0xb3, 0x6e, 0x75, 0xec, 0x90, 0xaa, 0x93, 0xdd, 0x44, 0x9c, 0xd9,
    0x64, 0x89, 0xb8, 0x45, 0xd6, 0x01, 0x00, 0x00, 0x03, 0xd2, 0x33, 0x06, 0x55, 0x52, 0x5a, 0x07, 0x61, 0x1b, 0xdb, 0x0e, 0xea, 0x92,
    0x63, 0xb1, 0x34, 0xdd, 0x0a, 0x8f, 0x07, 0x8b, 0x2a, 0xa3, 0x08, 0x8d, 0xbd, 0x0d, 0x87, 0x14, 0xca, 0xdc, 0x70, 0x01, 0x00, 0x00,
    0x03, 0xd4, 0x8b, 0x08, 0xa0, 0xb3, 0x22, 0xd8, 0x79, 0xa9, 0x7c, 0x5a, 0xb5, 0x5f, 0x40, 0x7b, 0xc4, 0xd7, 0x9d, 0x04, 0x80, 0xab,
    0x1e, 0x2b, 0xee, 0x12, 0x98, 0xb0, 0x8c, 0x23, 0x29, 0xcb, 0x3f, 0x01, 0x00, 0x00, 0x03, 0xd4, 0x8b, 0xf4, 0x09, 0xa3, 0xf7, 0x9a,
    0xdf, 0x5b, 0x93, 0xdc, 0x35, 0xff, 0x41, 0x83, 0xee, 0x4e, 0x18, 0x84, 0x41, 0x8b, 0x2b, 0x4c, 0x00, 0x67, 0x3e, 0xe1, 0xcb, 0xff,
    0x2d, 0xe5, 0x2f, 0x01, 0x00, 0x00, 0x03, 0xda, 0x86, 0xb7, 0xa3, 0xe5, 0xa4, 0xcd, 0xa4, 0x68, 0xea, 0xb9, 0x71, 0x40, 0xa1, 0xcf,
    0xe8, 0xdd, 0xba, 0x24, 0x37, 0x9f, 0xbe, 0xb5, 0x2f, 0x82, 0x93, 0xb9, 0x45, 0x27, 0xd4, 0x60, 0xc6, 0x01, 0x00, 0x00, 0x03, 0xdd,
    0x98, 0x7d, 0x4d, 0x83, 0xbc, 0x06, 0x4e, 0xb1, 0x0e, 0xa5, 0xdc, 0x22, 0x94, 0x45, 0xcf, 0xa1, 0xe8, 0x2d, 0xe6, 0xaa, 0xa0, 0x5f,
    0x60, 0x1e, 0xf4, 0xdb, 0xa5, 0xb1, 0x62, 0xcb, 0x37, 0x01, 0x00, 0x00, 0x03, 0xe8, 0xf9, 0xc5, 0x63, 0x2a, 0x5f, 0x35, 0x45, 0x23,
    0x85, 0xbb, 0x18, 0xb9, 0x9a, 0x41, 0x10, 0x89, 0xeb, 0xdd, 0x50, 0x1f, 0x48, 0xdb, 0xc5, 0xb0, 0x6a, 0xd0, 0x2f, 0x53, 0x6d, 0x43,
    0x5f, 0x01, 0x00, 0x00, 0x03, 0xea, 0xc6, 0xcb, 0xca, 0x53, 0xc3, 0x2d, 0xab, 0xb6, 0x2d, 0x98, 0xaa, 0x27, 0xb6, 0xe0, 0x9c, 0xc8,
    0x9d, 0xfb, 0x0e, 0x33, 0x1a, 0xb5, 0x9d, 0x7e, 0x59, 0x05, 0xa7, 0x34, 0x56, 0x1d, 0xde, 0x01, 0x00, 0x00, 0x03, 0xf1, 0xf3, 0xb7,
    0x84, 0x67, 0x18, 0x0b, 0x39, 0x06, 0xdb, 0x52, 0x58, 0x0f, 0x28, 0x31, 0xe8, 0x89, 0xd1, 0x21, 0x27, 0xe5, 0xfb, 0xcf, 0xb7, 0xba,
    0xac, 0x6a, 0x65, 0x19, 0x19, 0x49, 0xa6, 0x01, 0x00, 0x00, 0x03, 0xf7, 0x58, 0x66, 0x72, 0xdb, 0x27, 0x18, 0x9c, 0x8b, 0x5d, 0x8d,
    0xe7, 0xbd, 0x92, 0xaf, 0x25, 0x33, 0x29, 0xf9, 0x3a, 0x36, 0x0e, 0xb4, 0xc7, 0xe0, 0x88, 0xbc, 0x63, 0x6f, 0x68, 0x7e, 0x47, 0x01,
    0x00, 0x00, 0x03, 0xf9, 0x38, 0x6b, 0xc8, 0xa2, 0xc3, 0xa2, 0x94, 0x95, 0x89, 0x09, 0xbc, 0x21, 0xc8, 0xf6, 0x78, 0x3a, 0xa4, 0xa6,
    0xcc, 0xa9, 0x81, 0x58, 0x60, 0xb0, 0x00, 0x0e, 0xc2, 0x1f, 0x28, 0x4c, 0x3b, 0x01, 0x00, 0x00, 0x03, 0xfa, 0x6d, 0xb5, 0xfe, 0x2d,
    0xb9, 0x15, 0x03, 0x2a, 0xfa, 0xeb, 0xfc, 0x3c, 0xc0, 0x6d, 0x61, 0xdd, 0x7d, 0x9b, 0x39, 0x4b, 0xc9, 0x28, 0xf0, 0xa8, 0x3e, 0x03,
    0x27, 0x10, 0x62, 0x5f, 0x1d, 0x01, 0x00, 0x00, 0x03, 0xff, 0xa9, 0x72, 0x98, 0xdb, 0x6f, 0xd3, 0xce, 0x47, 0x9d, 0xcf, 0x27, 0x1d,
    0x87, 0xe3, 0x76, 0x28, 0x46, 0xf1, 0x3a, 0xef, 0xc2, 0xc2, 0x35, 0xb7, 0xf5, 0xa5, 0x41, 0xfe, 0x2f, 0xea, 0x69, 0x01, 0x00, 0x00,
    0x00,
};

struct transfer {
    eosio::name      from     = {};
    eosio::name      to       = {};
    eosio::asset     quantity = {};
    std::string_view memo     = {nullptr, 0};
};

struct newaccount {
    eosio::name creator;
    eosio::name name;
    // authority owner;
    // authority active;
};

void process(outgoing_transfers_request& req) {
    print("    outgoing_transfers\n");
    auto s = exec_query(query_action_trace_nonnotify_executed_range_name_le8_0_account_block_trans_action{
        .max_block_index = req.max_block_index,
        .first =
            {
                .name           = "transfer"_n,
                .le8_0          = eosio::pack(req.first_key.account),
                .account        = req.first_key.contract,
                .block_index    = req.first_key.block_index,
                .transaction_id = req.first_key.transaction_id,
                .action_index   = req.first_key.action_index,
            },
        .last =
            {
                .name           = "transfer"_n,
                .le8_0          = eosio::pack(req.last_key.account),
                .account        = req.last_key.contract,
                .block_index    = req.last_key.block_index,
                .transaction_id = req.last_key.transaction_id,
                .action_index   = req.last_key.action_index,
            },
        .max_results = req.max_results,
    });

    print(s.size(), "\n");
    outgoing_transfers_response response;
    for_each_query_result<action_trace>(s, [&](action_trace& at) {
        print("   ", at.block_index, " ", at.action_index, " ", at.account, " ", at.name, "\n");
        auto unpacked = eosio::unpack<transfer>(at.data.pos(), at.data.remaining());
        response.rows.push_back(outgoing_transfers_row{
            .key =
                outgoing_transfers_key{
                    .account        = unpacked.from,
                    .contract       = at.account,
                    .block_index    = at.block_index,
                    .transaction_id = at.transaction_id,
                    .action_index   = at.action_index,
                },
            .from     = unpacked.from,
            .to       = unpacked.to,
            .quantity = unpacked.quantity,
            .memo     = unpacked.memo,
        });
        return true;
    });
    if (!response.rows.empty()) {
        response.more = response.rows.back().key;
        ++*response.more;
    }
    set_output_data(pack(example_response{std::move(response)}));
    print("\n");
}

void process(balances_for_multiple_accounts_request& req) {
    print("    balances_for_multiple_accounts\n");
    auto s = exec_query(query_contract_row_range_code_table_pk_scope{
        .max_block_index = req.max_block_index,
        .first =
            {
                .code        = req.code,
                .table       = "accounts"_n,
                .primary_key = req.sym.raw(),
                .scope       = req.first_account.value,
            },
        .last =
            {
                .code        = req.code,
                .table       = "accounts"_n,
                .primary_key = req.sym.raw(),
                .scope       = req.last_account.value,
            },
        .max_results = req.max_results,
    });

    balances_for_multiple_accounts_response response;
    for_each_contract_row<asset>(s, [&](contract_row& r, asset* a) {
        print("        ", r.block_index, " ", r.present, " ", r.code, " ", name{r.scope}, " ", r.payer);
        response.more = name{r.scope + 1};
        if (r.present && a) {
            print(" ", asset_to_string(*a));
            response.rows.push_back({.account = name{r.scope}, .amount = extended_asset{*a, req.code}});
        }
        print("\n");
        return true;
    });
    set_output_data(pack(example_response{std::move(response)}));
    print("\n");
}

void proposals(uint32_t max_block_index, name first_account, name first_prop, name last_account, name last_prop, uint32_t max_results) {
    print("    proposals\n");
    auto s = exec_query(query_contract_row_range_code_table_scope_pk{
        .max_block_index = max_block_index,
        .first =
            {
                .code        = "eosio.msig"_n,
                .table       = "proposal"_n,
                .scope       = first_account.value,
                .primary_key = first_prop.value,
            },
        .last =
            {
                .code        = "eosio.msig"_n,
                .table       = "proposal"_n,
                .scope       = last_account.value,
                .primary_key = last_prop.value,
            },
        .max_results = max_results,
    });
    for_each_query_result<contract_row>(s, [&](contract_row& r) {
        print("        ", r.block_index, " ", r.present, " ", name{r.scope}, " ", name{r.primary_key});
        if (r.present)
            print(" ", r.value.remaining(), " bytes");
        print("\n");
        return true;
    });
    print("\n");
}

void process(balances_for_multiple_tokens_request& req) {
    print("    balances_for_multiple_tokens\n");
    auto s = exec_query(query_contract_row_range_scope_table_pk_code{
        .max_block_index = req.max_block_index,
        .first =
            {
                .scope       = req.account.value,
                .table       = "accounts"_n,
                .primary_key = req.first_key.sym.raw(),
                .code        = req.first_key.code,
            },
        .last =
            {
                .scope       = req.account.value,
                .table       = "accounts"_n,
                .primary_key = req.last_key.sym.raw(),
                .code        = req.last_key.code,
            },
        .max_results = req.max_results,
    });

    balances_for_multiple_tokens_response response;
    for_each_query_result<contract_row>(s, [&](contract_row& r) {
        response.more = ++bfmt_key{.sym = symbol_code{r.primary_key}, .code = r.code};
        if (!r.present || r.value.remaining() != 16)
            return true;
        asset a;
        r.value >> a;
        if (!a.is_valid() || a.symbol.code().raw() != r.primary_key)
            return true;
        print("        ", name{r.scope}, " ", r.code, " ", asset_to_string(a), "\n");
        if (!response.more->code.value)
            response.more->sym = symbol_code{response.more->sym.raw() + 1};
        if (r.present)
            response.rows.push_back({.account = name{r.scope}, .amount = extended_asset{a, r.code}});
        return true;
    });
    set_output_data(pack(example_response{std::move(response)}));
    print("\n");
}

void creators(uint32_t max_block_index, uint32_t max_results) {
    print("    creators\n");
    auto s = exec_query(query_action_trace_range_receiver_name_account{
        .max_block_index = max_block_index,
        .first =
            {
                .receipt_receiver = "eosio"_n,
                .name             = "newaccount"_n,
                .account          = "eosio"_n,
            },
        .last =
            {
                .receipt_receiver = "eosio"_n,
                .name             = "newaccount"_n,
                .account          = "eosio"_n,
            },
        .max_results = max_results,
    });
    for_each_query_result<action_trace>(s, [&](action_trace& t) {
        if (t.transaction_status != transaction_status::executed)
            return true;
        newaccount na;
        t.data >> na;
        print("        ", na.creator, ", ", na.name, "\n");
        return true;
    });
    print("\n");
}

#include "updateauth.hpp"

void bar() {
    datastream<const char*> ds{(const char*)foo, sizeof(foo)};
    updateauth              action_data;
    ds >> action_data;
    auto s = to_html(std::move(action_data));
    print_range(s.v.data(), s.v.data() + s.v.size());
}

extern "C" void startup() {
    auto request = unpack<example_request>(get_input_data());
    print("request: ", example_request::keys[request.value.index()], "\n");
    std::visit([](auto& x) { process(x); }, request.value);
}
