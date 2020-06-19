# pragma once
#include <iostream>
#include <vector>
using namespace std;


namespace itertools {

	class range {

		int begin_, end_;

	public:
		range(int be = 0, int en = 0) : begin_(be), end_(en) {}

		class iterator {
			int current;

		public:
			iterator(int cur) : current(cur) {}

			int operator*() const  { return current; }

			//++i
			iterator& operator++() {
				current++;
				return *this;
			}

			//i++
			const iterator operator++(int) {
				iterator temp = *this;
				current++;
				return temp;
			}
			bool operator ==(const iterator& other) const{
				return current == *other;
			}
			bool operator !=(const iterator& other) const {
				return !(current==*other);
			}


		};

		iterator begin() { return iterator(begin_); }
		iterator end() { return iterator(end_); }
		typedef int value_type;

	};
	
		
	
}