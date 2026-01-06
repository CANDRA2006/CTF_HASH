#include "hasher.h"
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

using std::string;

string hash_string(const string& input, HashType type) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    if (type == HASH_MD5) {
        MD5(
            reinterpret_cast<const unsigned char*>(input.c_str()),
            input.length(),
            hash
        );
        std::ostringstream oss;
        for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
            oss << std::hex << std::setw(2) << std::setfill('0')
                << static_cast<int>(hash[i]);
        }
        return oss.str();
    }

    if (type == HASH_SHA1) {
        SHA1(
            reinterpret_cast<const unsigned char*>(input.c_str()),
            input.length(),
            hash
        );
        std::ostringstream oss;
        for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
            oss << std::hex << std::setw(2) << std::setfill('0')
                << static_cast<int>(hash[i]);
        }
        return oss.str();
    }

    if (type == HASH_SHA256) {
        SHA256(
            reinterpret_cast<const unsigned char*>(input.c_str()),
            input.length(),
            hash
        );
        std::ostringstream oss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            oss << std::hex << std::setw(2) << std::setfill('0')
                << static_cast<int>(hash[i]);
        }
        return oss.str();
    }

    return "";
}
