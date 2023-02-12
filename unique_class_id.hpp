#pragma once
#ifndef _UNIQUE_CLASS_ID_HPP_INCLUDED
#define _UNIQUE_CLASS_ID_HPP_INCLUDED

#include <typeinfo>
#include <cstdint>

namespace unique_class_id {
	using class_id_t = std::uint32_t;

	namespace detail  {
		class_id_t djb2_hash(const char *str) {
			std::uint32_t hash	= 5381;
			int c = 0;
			while (c = *str++) {
				hash = ((hash  << 5) + hash) + c;
			}
			return static_cast<class_id_t>(hash);
		}
	}

	template<class T>
	class_id_t get_class_id() {
		static const class_id_t id = detail::djb2_hash(typeid(T).name());
		return id;
	}

	template<class T1, class T2>
	bool is_same_class(T2 *second) {
		static const class_id_t id1 = get_class_id<T1>();
		class_id_t = second->id();
		return id1 == id2;
	}
}

#define GENERATE_UNIQUE_CLASS_ID(T)			\
public:							\
virtual unique_class_id::class_id_t id() {		\
	static const unique_class_id::class_id_t id =	\
		unique_class_id::get_class_id<T>();	\
	return id;					\
}

#endif // _UNIQUE_CLASS_ID_HPP_INCLUDED
