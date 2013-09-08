#pragma once

#include <cstring>

namespace Ir
{
typedef unsigned __int64 uint64_t;

typedef uint64_t hash_t;

hash_t murmur_hash(const void * key, int len, hash_t seed);

class StringHash
{
public:
	inline StringHash() : _h(0) { }

	inline StringHash(const StringHash& other) : _h(other._h) { }

	inline StringHash(const hash_t& u) : _h(u) { }

	explicit StringHash(const char* str)
		: _h(str ? murmur_hash(str, strlen(str), 0) : 0) { }

	explicit StringHash(const char* str, size_t len)
		: _h(str ? murmur_hash(str, len, 0) : 0) { }

public:
	inline operator hash_t() const { return _h; }
	inline bool operator==(const StringHash& b) { return _h == b._h; };
	inline bool operator!=(const StringHash& b) { return _h != b._h; };
	inline bool operator<(const StringHash& b) { return _h < b._h; }
	inline bool operator>(const StringHash& b) { return _h > b._h; }

	struct Hasher {
		inline size_t operator()(const StringHash& s) const { return (size_t)s._h; }
	};

private:
	hash_t _h;
};
}