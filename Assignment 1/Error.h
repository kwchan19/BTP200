#ifndef ICT_ERROR_H_
#define ICT_ERROR_H_

#include <iostream>
namespace ict {
	class Error {
		char* m_message;
	public:

		Error();
		Error(const char* errorMessage);
		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;
												  
		void operator=(const char* errorMessage);
		virtual ~Error() { delete[] m_message; m_message = nullptr; };
		void clear();
		bool isClear()const;
		void message(const char* value);
		operator const char*() const;
		operator bool()const;

	};

	std::ostream& operator<<(std::ostream& ostr, const Error& em);
}
#endif