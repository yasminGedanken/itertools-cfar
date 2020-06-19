# pragma once
namespace itertools {

	template<typename Fun, typename T >
		class filterfalse {
		
		Fun fun;
		T values;
		typename T::value_type value_type;

		public:
			filterfalse(Fun fun_, T val): fun(fun_), values(val){}

			class iterator {
				typename T::iterator it;
				typename T::iterator end;
				Fun fun;

			public:
				iterator(typename T::iterator it_, typename T::iterator end_, Fun function)
					:it(it_), end(end_), fun(function)
				{
					while (it != end && fun(*it))
						++it;
				}
				auto operator*() const {
					return *it;
				}

				//++i
				iterator& operator++() {
					do {
						++it;
					} while (it != end && fun(*it));
					return *this;
				}

				//i++
				const iterator operator++(int) {
					iterator temp = *this;
					it++;
					while (it != end && fun(*it))
						it++;
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
				return iterator(values.begin(), values.end(), fun);
			}
			iterator end() {
				return iterator(values.end(), values.end(), fun);
			}
	};

}