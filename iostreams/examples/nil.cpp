template<class A, class B>
class C
{
};

template<class A, class B>
class D
{
};


template <class A, class B>
C<A,B> f(D<A,B>&)
{
	return C<A,B>();
};

int main()
{
	f(D<int,char>());

	return 0;
}