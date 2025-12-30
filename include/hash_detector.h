#ifndef HASH_DETECTOR_H
#define HASH_DETECTOR_H

#include "types.h"

HashType detect_hash_type(const string& hash);
string hash_type_to_string(HashType type);

#endif
