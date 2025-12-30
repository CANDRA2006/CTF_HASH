#include "hasher.h"
#include <openssl/evp.h>
#include <sstream>
#include <iomanip>

using namespace std;

string hash_string(const string& input, HashType type) {
    const EVP_MD* md = nullptr;

    switch (type) {
        case HASH_MD5:
            md = EVP_md5();
            break;
        case HASH_SHA1:
            md = EVP_sha1();
            break;
        case HASH_SHA256:
            md = EVP_sha256();
            break;
        default:
            return "";
    }

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int len = 0;

    EVP_DigestInit_ex(ctx, md, nullptr);
    EVP_DigestUpdate(ctx, input.c_str(), input.size());
    EVP_DigestFinal_ex(ctx, hash, &len);
    EVP_MD_CTX_free(ctx);

    stringstream ss;
    for (unsigned int i = 0; i < len; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    return ss.str();
}
