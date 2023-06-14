// range.h - ranges for iteration (c) Christian Balkenius 2023

#ifndef RANGE
#define RANGE

#include <string>
#include <vector>

namespace ikaros
{
    class range
    {
    public:
        std::vector<int>    inc_;
        std::vector<int>    a_;
        std::vector<int>    b_;
        std::vector<int>    index_;

        range();
        range(int a);
        range(int a, int b, int inc=1);
        range(std::string s);                            // parse range string: [a:b:inc]

        range & push(int a, int b, int inc=1);
        range & push(int a);
        range & push();

        int rank();
        int size();
        std::vector<int> extent();
        std::vector<int> & index() ;
        std::vector<int> operator++(int);

        void reset(int d=0);
        void clear();
        
        range trim();

        bool more(int d=0);
        bool empty();

        operator std::vector<int> &();

        range & set(int d, int a, int b, int inc);

        void operator=(const std::vector<int> & v);

        friend void operator|=(range & r, range & s);

        void print_index();

        operator std::string();

        friend bool operator==(range & a, range & b);
        friend bool operator!=(range & a, range & b);
        friend bool operator<(range & a, range & b);

        friend std::ostream& operator<<(std::ostream& os, const range & x);
    };
}; // namespace ikaros

#endif

