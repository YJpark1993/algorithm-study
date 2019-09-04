## MyString 클래스 설계

### 헤더 파일

```c++
#pragma once
namespace assignment1
{
	class MyString
	{
	public:
		MyString(const char* s);
		MyString(const MyString& other);
		~MyString();

		unsigned int GetLength() const;
		const char* GetCString() const;
		void Append(const char* s);
		MyString operator+(const MyString& other) const;
		int IndexOf(const char* s);
		int LastIndexOf(const char* s);
		void Interleave(const char* s);
		bool RemoveAt(unsigned int i);
		void PadLeft(unsigned int totalLength);
		void PadLeft(unsigned int totalLength, const char c);
		void PadRight(unsigned int totalLength);
		void PadRight(unsigned int totalLength, const char c);
		void Reverse();
		bool operator==(const MyString& rhs) const;
		MyString& operator=(const MyString& rhs);
		void ToLower();
		void ToUpper();


	private:
		size_t mSize;
		size_t mCapacity;
		char* mAllocator;
		void Realloc(size_t size, bool newMem = true);
	};

	void Memcpy(char* dest, const char* src, unsigned int size);
	bool Strcmp(const char* src1, const char* src2, size_t size);
}
```



### 명세서

- 멤버 변수

```c++
size_t mSize : 개체에 담긴 문자열 갯수
size_t mCapacity : 문자열 최대 길이
char* mAllocator : 동적할당 된 문자열 포인터
```



- 메서드

```c++
- MyString(const char* s) : // 생성자
- MyString(const MyString& other) : // 복사생성자
- ~MyString() : // 소멸자
- MyString& operator=(const MyString& rhs) : // 대입 연산자

- unsigned int GetLength() const : 문자열의 길이 반환

- const char* GetCString() const : 개체 내부에 저장된 C 스타일 문자열 반환

- void Append(const char* s) : 현재 문자열에 매개변수로 들어온 C 스타일 문자열 덧붙임

- MyString operator+(const MyString& other) const :
	- 현재 문자열과 매개변수로 들어온 C 스타일 문자열을 합친 뒤 새로운 문자열 개체 반환

- int IndexOf(const char* s) :
	- 현재 문자열 안에서 매개 변수로 들어온 C 스타일 문자열을 찾아 그 위치를 반환

- int LastIndexOf(const char* s) :
	- 현재 문자열 안에서 매개 변수로 들어온 C 스타일 문자열을 찾아 그 위치를 반환
	- 찾는 문자열이 여럿 있다면 마지막 위치만 반환

- void Interleave(const char* s) :
	- 두 문자열을 한 글자씩 번갈아가며 결합

- bool RemoveAt(unsigned int i) :
	- 현재 문자열에서 i 위치의 글자를 하나 제거

- void PadLeft(unsigned int totalLength) :
- void PadLeft(unsigned int totalLength, const char c) :
	- 문자열의 길이가 totalLength와 같아지도록 문자열의 왼쪽에 글자를 반복해서 붙임

- void PadRight(unsigned int totalLength) :
- void PadRight(unsigned int totalLength, const char c) :
	- 문자열의 길이가 totalLength와 같아지도록 문자열의 오른쪽에 글자를 반복해서 붙임

- void Reverse() :
	- 문자열을 좌우로 뒤집음

- bool operator==(const MyString& rhs) const : // 비교 연산자 오버로딩
	- 두 MyString 개체 안에 저장된 문자열이 같은지 검사

- void ToLower() :
	- 문자열 안에 있는 모든 문자를 소문자로 바꿈. ASCII 문자만 사용

- void ToUpper() :
	- 문자열 안에 있는 모든 소문자를 대문자로 바꿈. ASCII 문자만 사용

- void Realloc(size_t size, bool newMem) :
	- 메모리를 재할당 해야하는 경우 메모리 재할당
```



- 그 외

```c++
- void Memcpy(char* dest, const char* src, unsigned int size) :
	- dest에 src 데이터를 size 길이 만큼 복사 (깊은 복사)

- bool Strcmp(const char* src1, const char* src2, size_t size) :
	- size 크기 만금 문자열 비교
```



- 각종 생성자

