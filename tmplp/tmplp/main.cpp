#include <iostream>     
#include <algorithm>    
#include <vector> 
#include "gtest\gtest.h"

using namespace std;

class tmpl;
bool cmpa(const tmpl & i, const  tmpl & z);
template <class RandomAccessIterator, class compare>

void sortk(const RandomAccessIterator & first, const RandomAccessIterator & last, compare cmp);

class tmpl
{
public:
	tmpl(int i)
	{
		z = i;
	}
	bool operator<(const tmpl& right)const
	{
		return(z < right.z);
	}


	int z;

};



TEST(cmpr, tmpl)
{
	tmpl k1(1), k2(2);
	ASSERT_TRUE(cmpa(k1, k2));
	ASSERT_FALSE(cmpa(k2, k1));
}

TEST(sort)
{
	vector<int> vec;
	vec.push_back(30);
	vec.push_back(90);
	vec.push_back(1);
	vec.push_back(35);
	sortk(vec.begin(), vec.end(), cmpa);
	ASSERT_TRUE(vec[0] == 1);
	ASSERT_TRUE(vec[1] == 30);
	ASSERT_TRUE(vec[2] == 35);
	ASSERT_TRUE(vec[3] == 90);
}


bool cmpa(const tmpl & i, const  tmpl & z)
{
	return (i<z);
}





template <class RandomAccessIterator, class compare> void sortk(const RandomAccessIterator & first, const RandomAccessIterator & last, compare cmp)
{
	auto next = first + 1;
	auto current = first;
	auto mark = first;
	bool out = true;
	while (out)
	{
		next = first + 1;
		current = first;
		out = false;
		while (next != last)
		{
			if (cmp(*(next), *(current))) // Ели будет хоть одна замена значит возможно массив еще не отсортирован, если замен не будет, значит массив отсортирован.
			{
				swap(*current, *next);
				out = true;
			}
			++next;
			++current;
		}
	}
}



int main(int argc, char ** argv)
{
	tmpl z = 10;
	vector<tmpl>_vect;
	_vect.push_back(z);
	z = 24;
	_vect.push_back(z);
	z = 5;
	_vect.push_back(z);
	z = 7;
	_vect.push_back(z);

	for (auto&elem : _vect)
	{
		cout << elem.z << endl;
	}
	cout << endl;
	sortk(_vect.begin(), _vect.end(), cmpa);
	for (auto&elem : _vect)
	{
		cout << elem.z << endl;
	}

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	cin.get();
}
