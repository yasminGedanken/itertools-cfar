# pragma once
#include <string>
#include "range.hpp"
#include <vector>
#include <iostream>
using namespace std;


namespace itertools {

    typedef struct {
        template <typename T>
        T operator()(T a, T b) { return a + b; }
    }addFun;

    template<typename T, typename Fun = addFun>
    class accumulate {
        T values;
        Fun func;
        typedef typename T::value_type value_type;

    public:
        accumulate(T val, Fun fun_ = addFun()): values(val), func(fun_){}
        
        class iterator {
       
            typename T::value_type value_data;
            typename T::iterator it;
            typename T::iterator end;
            Fun function;

        public:
            iterator(typename T::iterator it_, typename T::iterator end_, Fun fun)
                : it(it_),end(end_), function(fun){
                if (it != end) {
                    value_data = *it;
                }
                }

            auto operator*()const {
                return value_data; }


            //++i
            iterator& operator++() {
               ++it;
                if (it != end) {
                    value_data = function(value_data, *it);
                }
                return *this;
            }

            //i++
            const iterator operator++(int) {
                iterator temp = *this;
                ++(*this);
                if (it != end) {
                    value_data = function(value_data, *it);
                }
                return temp;
            }
            bool operator ==(const iterator& other) const {
                return  it== other.it;
            }
            bool operator !=(const iterator& other) const {
                return !(it == other.it);
            }
            iterator& operator=(const iterator& other) {
                if (this != &other) {
                    this->value_data = other.value_data;
                    this->it = other.it;
                    this->end = other.end;
                    this->function = other.function;
                }
                return *this;
            }

        };
        iterator begin() {
            return iterator(values.begin(), values.end(), func);
        }
        iterator end() {
            return iterator(values.end(), values.end(), func);
        }


    };

}