#ifndef HASH_DETECTOR_H
#define HASH_DETECTOR_H

#include <string>
#include "hash_types.h"

HashType detect_hash_type(const std::string& hash);
std::string hash_type_to_string(HashType type);

#endif
