template <class T>
struct range{
    range(T first, T step, unsigned int length) : first(first), step(step), length(length){}

    struct iterator{
        using value_type = T;
        using difference_type = long;
        using pointer = void;
        using reference = void;
        using iterator_category = std::random_access_iterator_tag;
        explicit iterator(T first, T step, unsigned current = 0) : first(first), step(step), current(current){}

        iterator operator++(int){ current++; return *this;}
        iterator & operator++(){ current++;  return *this;}
        T operator*(){ return static_cast<T>(current) * step + first; }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }

        difference_type operator-(const iterator &other) const {
            return static_cast<long>(current) - static_cast<long>(other.current);
        }

        // ------
        unsigned current;
        T first;
        T step;
    };

    iterator begin() const { return iterator(first, step, 0);    }
    iterator end() const { return iterator(first, step, length); }

    T first;
    T step;
    unsigned length;
};
