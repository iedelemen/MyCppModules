#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <deque>
using std::deque;
#include <sstream>
#include <algorithm>
#include <iomanip>

class PmergeMe
{
	private:
		vector<int> _vector;
		deque<int> _deque;

	public:
		PmergeMe(char** arg);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void check(string arg);
		void lets_sort();
		template <typename T>
		void print(T &arr)
		{
			for (size_t i = 0; i < arr.size(); i++)
			{
				cout << arr[i];
				if (i + 1 < arr.size())
					cout << " ";
				if (i == 9){
					cout << "[...]";
					break;
				}
			}
			cout << endl;
		}

		template <typename T>
		void my_insert(T &arr)
		{
			for (size_t i = 1; i < arr.size(); ++i)
			{
				int key = arr[i];
				int j = i - 1;
				while (j >= 0 && arr[j] > key)
				{
					arr[j + 1] = arr[j];
					j = j - 1;
				}
				arr[j + 1] = key;
			}
		}

		template <typename T>
		void my_sort(T &arr)
		{
			size_t mid = arr.size() / 2;
			T left(arr.begin(), arr.begin() + mid);
			T right(arr.begin() + mid, arr.end());

			if (left.size() > 10)
				my_sort(left);
			else
				my_insert(left);
			if (right.size() > 10)
				my_sort(right);
			else
				my_insert(right);
			size_t i = 0, j = 0, k = 0;
			while (i < left.size() && j < right.size())
			{
				if (left[i] < right[j])
					arr[k++] = left[i++];
				else
					arr[k++] = right[j++];
			}
			while (i < left.size())
				arr[k++] = left[i++];
			while (j < right.size())
				arr[k++] = right[j++];
		}

};


#endif
