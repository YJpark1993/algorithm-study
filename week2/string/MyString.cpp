#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mSize(0)
		, mCapacity(15)
	{
		// 글자 수 판별하기
		while (*(s + mSize))
		{
			mSize++;
		}

		// 동적으로 크기 설정하기
		while (mSize > mCapacity)
		{
			mCapacity = mCapacity * 2 + 1;
		}
		mAllocator = new char[mCapacity]();	// 모든값 0(NULL)으로 초기화
		Memcpy(mAllocator, s, mSize);
	}

	MyString::MyString(const MyString& other)
		: mSize(other.mSize)
		, mCapacity(other.mCapacity)
	{
		mAllocator = new char[mCapacity]();
		Memcpy(mAllocator, other.mAllocator, mSize + 1);
	}

	MyString::~MyString()
	{
		delete[] mAllocator;
	}

	unsigned int MyString::GetLength() const
	{
		return mSize;
	}

	const char* MyString::GetCString() const
	{
		//char* result = new char[mCapacity];
		//Memcpy(result, mAllocator, mSize + 1);
		return mAllocator;
	}

	void MyString::Append(const char* s)
	{
		size_t size = 0;
		while (*(s + size))
		{
			size++;
		}

		// 기존 사이즈 보다 커질 때
		Realloc(size);

		// 널 포인터 위치
		char* ptr = mAllocator + mSize;
		for (size_t i = 0; i < size; i++)
		{
			* (ptr++) = *(s + i);
		}
		*ptr = '\0';
		mSize += size;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString result(mAllocator);
		result.Append(other.GetCString());
		return result;
	}

	int MyString::IndexOf(const char* s)
	{
		size_t size = 0;
		while (*(s + size))
		{
			size++;
		}
		if (mSize < size)
		{
			return -1;
		}

		for (size_t i = 0; i < mSize - size + 1; i++)
		{
			if (Strcmp(mAllocator + i, s, size))
			{
				return i;
			}
		}

		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		int size = 0;
		while (*(s + size))
		{
			size++;
		}
		if ((int)mSize < size)
		{
			return -1;
		}

		for (int i = (int)mSize - size; i >= 0; i--)
		{
			if (Strcmp(mAllocator + i, s, size))
			{
				return i;
			}
		}

		return -1;
	}

	void MyString::Interleave(const char* s)
	{
		int size = 0;
		while (*(s + size))
		{
			size++;
		}

		if (size == 0)
		{
			return;
		}

		//Realloc(size, false);

		char* after = new char[mCapacity];
		char* aptr = after;
		mSize += size;

		char* ptr = mAllocator;
		int countPtr = 0;
		int countS = 0;
		while (*(ptr + countPtr) || *(s + countS))
		{
			// NULL 문자가 아니면
			if (*(ptr + countPtr))
			{
				*aptr++ = *(ptr + countPtr);
				countPtr++;
			}
			if (*(s + countS))
			{
				* aptr++ = *(s + countS);
				countS++;
			}
		}
		*aptr = '\0';
		
		delete[] mAllocator;
		mAllocator = after;
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (mSize == 0 || index > mSize - 1)
		{
			return false;
		}

		// 메모리 재할당이 궂이 필요하진 않을듯?
		char* after = new char[mCapacity];
		int count = 0;
		for (size_t i = 0; i < mSize; i++)
		{
			if (i == index)
				continue;
			*(after + count) = *(mAllocator + i);
			count++;
		}
		mSize--;
		*(after + mSize) = '\0';

		delete[] mAllocator;
		mAllocator = after;

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (mSize > totalLength)
		{
			return;
		}

		size_t size = totalLength - mSize;

		Realloc(size, false);
		mSize += size;
		char* after = new char[mCapacity];

		size_t count = 0;
		char* ptr = mAllocator;
		char* ptrAfter = after;
		while (*ptr)
		{
			if (count < size)
			{
				*ptrAfter++ = c;
				count++;
			}
			else
				*ptrAfter++ = *ptr++;
		}
		*ptrAfter = '\0';

		delete[] mAllocator;
		mAllocator = after;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (mSize > totalLength)
			return;

		size_t size = totalLength - mSize;

		Realloc(size, false);
		mSize += size;
		char* after = new char[mCapacity];

		size_t count = 0;
		char* ptr = mAllocator;
		char* ptrAfter = after;
		while (*ptr)
			*ptrAfter++ = *ptr++;
		for (size_t i = 0; i < size; i++)
			*ptrAfter++ = c;
		*ptrAfter = '\0';

		delete[] mAllocator;
		mAllocator = after;
	}

	void MyString::Reverse()
	{
		char* ptrStart = mAllocator;
		char* ptrEnd = mAllocator + mSize - 1;
		char temp;
		while (ptrStart < ptrEnd)
		{
			temp = *ptrStart;
			*ptrStart = *ptrEnd;
			*ptrEnd = temp;

			ptrStart++;
			ptrEnd--;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		return Strcmp(mAllocator, rhs.mAllocator, mSize + 1);
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (this == &rhs)
			return *this;

		delete[] mAllocator;

		mSize = rhs.mSize;
		mCapacity = rhs.mCapacity;
		mAllocator = new char[mCapacity];
		Memcpy(mAllocator, rhs.mAllocator, mSize + 1);

		return *this;
	}

	void MyString::ToLower()
	{
		char* ptr = mAllocator;
		while (*ptr)
		{
			if (*ptr >= 'A' && *ptr <= 'Z')
				* ptr += 32;
			ptr++;
		}
	}

	void MyString::ToUpper()
	{
		char* ptr = mAllocator;
		while (*ptr)
		{
			if (*ptr >= 'a' && *ptr <= 'z')
				* ptr -= 32;
			ptr++;
		}
	}

	void MyString::Realloc(size_t size, bool newMem)
	{
		if (mSize + size > mCapacity)
		{
			while (mSize + size > mCapacity)
				mCapacity = mCapacity * 2 + 1;
			if (!newMem)
			{
				return;
			}
			char* newChar = new char[mCapacity];
			Memcpy(newChar, mAllocator, mSize + 1);
			delete[] mAllocator;
			mAllocator = newChar;
		}
	}

	void Memcpy(char* dest, const char* src, unsigned int size)
	{
		for (size_t i = 0; i < size; i++)
			* (dest + i) = *(src + i);
	}
	
	bool Strcmp(const char* src1, const char* src2, size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (*(src1 + i) != *(src2 + i))
				return false;
		}

		return true;
	}
}