#pragma once
namespace itertools {

	template <typename T, typename B>
	class compress {

		T values;
		B boolArray;
		typedef typename T::value_type value_data;

	public:
		compress(T val, B arr): values(val), boolArray(arr){}

		class iterator {

			typename T::iterator it;
			typename T::iterator end;
			typename B::iterator boolA;

		public:
			iterator(typename T::iterator it_, typename T::iterator end_, typename B::iterator arr)
				:it(it_), end(end_), boolA(arr)
			{
				while (it != end && !(*boolA)) {
					++it;
					++boolA;
				}
			}

			auto operator*() const {
				return *it;
			}

			//++i
			iterator& operator++() {
				do {
					++it;
					++boolA;
				} while (it != end && !(*boolA));
				return *this;
			}

			//i++
			const iterator operator++(int) {
				iterator temp = *this;
				++it;
				++boolA;
				while (it != end && !(*boolA)) {
					++it;
					++boolA;
				}
				return temp;
			}

			bool operator ==(const iterator& other) const {
				return  it == other.it;
			}
			bool operator !=(const iterator& other) const {
				return !(it == other.it);
			}
		};
			iterator begin() {
				return iterator(values.begin(), values.end(), boolArray.begin());
			}
			iterator end() {
				return iterator(values.end(), values.end(), boolArray.end());
			}


	};

}