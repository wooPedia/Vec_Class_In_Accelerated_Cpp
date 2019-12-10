#ifndef GUARD_VEC_H
#define GUARD_VEC_H

template <class T> 
class Vec
{
public:
	using size_type  = size_t;
	using value_type = T;
	using iterator   = T*;
	using reference  = T&;
	using const_iterator  = const T*;
	using const_reference = const T&;
	using difference = std::ptrdiff_t;


	Vec() { create(); } // 기본 생성자
	explicit Vec(size_type n, const T& value = T()) { create(n, value); } // n개의 value를 요소로 갖는 배열 생성
	Vec(const_iterator first, const_iterator last) { create(first, last); } // [first, last) 범위의 컨테이너 생성


	// 복사 생성자, 할당 연산자, 소멸자
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	Vec& operator=(const Vec& v);
	~Vec() { uncreate(); }

	// 인덱스 연산자
	T& operator[](size_type i) { return first[i]; } // *(first+i)
	const T& operator[](size_type i) { return first[i]; }

	// push_back()
	void push_back(const T& value);

	// size()
	size_type size() const { return avail - first; }


	// begin(), end()
	iterator begin() { return first; }
	const_iterator begin() const { return first; }

	iterator end() { return last; }
	const_iterator end() const { return last; }



private:
	iterator first; // 첫 요소를 가리킵니다.
	iterator avail; // 할당된 공간 중 사용되지 않은 첫 요소를 가리킵니다. 
	iterator last;  // 마지막 요소의 이후를 가리킵니다.
	
	// allocator 클래스 객체
	// 메모리 할당을 다룸
	std::allocator<T> alloc;

	// 배열 할당 및 초기화
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// 배열의 모든 요소를 삭제하고 메모리 공간 해제
	void uncreate();

	// push_back() 내부 함수
	void grow();
	void unchecked_append(const T&);

};

#endif // !define GUARD_VEC_H

