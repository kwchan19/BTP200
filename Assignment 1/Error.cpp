//Error.cpp

#define _CRT_SECURE_NO_WARNINGS 

#include "Error.h"
#include <cstring>

namespace ict {
	Error::Error() {
		this->m_message = nullptr;
	}

	Error::Error(const char* errorMessage) {
		this->m_message = nullptr;
		message(errorMessage);
	}

	void Error::operator=(const char* errorMessage) {
		clear();
		message(errorMessage);
	}

	void Error::clear() {
		delete[] this->m_message;
		this->m_message = nullptr;

	}


	bool Error::isClear()const {
		bool clear;
		if (this->m_message == nullptr) {
			clear = true;
		}
		else {
			clear = false;
		}

		return clear;
	}

	void Error::message(const char* value) {
		clear();
		this->m_message = new char[strlen(value + 1)];
		strcpy(this->m_message, value);
	}

	Error::operator const char*() const {
		return this->m_message;
	}

	Error::operator bool()const {
		return isClear();
	}

	std::ostream& operator<<(std::ostream& ostr, const Error& em) {

		if (em.isClear()) {

		}
		else {
			ostr << "error";
		}

		return ostr;
	}

}