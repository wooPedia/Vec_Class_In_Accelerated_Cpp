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


	Vec() { create(); } // �⺻ ������
	explicit Vec(size_type n, const T& value = T()) { create(n, value); } // n���� value�� ��ҷ� ���� �迭 ����
	Vec(const_iterator first, const_iterator last) { create(first, last); } // [first, last) ������ �����̳� ����


	// ���� ������, �Ҵ� ������, �Ҹ���
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	Vec& operator=(const Vec& v);
	~Vec() { uncreate(); }

	// �ε��� ������
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
	iterator first; // ù ��Ҹ� ����ŵ�ϴ�.
	iterator avail; // �Ҵ�� ���� �� ������ ���� ù ��Ҹ� ����ŵ�ϴ�. 
	iterator last;  // ������ ����� ���ĸ� ����ŵ�ϴ�.
	
	// allocator Ŭ���� ��ü
	// �޸� �Ҵ��� �ٷ�
	std::allocator<T> alloc;

	// �迭 �Ҵ� �� �ʱ�ȭ
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// �迭�� ��� ��Ҹ� �����ϰ� �޸� ���� ����
	void uncreate();

	// push_back() ���� �Լ�
	void grow();
	void unchecked_append(const T&);

};

#endif // !define GUARD_VEC_H

