#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include "Book.h"
#include <iomanip>
#include <iostream>
namespace sdds
{
    /// set T to Class obj, C to the size of arr
    template <typename T, unsigned int C>

    class Collection
    {
    private:
        T m_items[C]{};
        unsigned int m_size{};
        static T m_smallestItem;
        static T m_largestItem;

    protected:
        void setSmallestItem(const T &item)
        {
            if (item < m_smallestItem)
            {
                m_smallestItem = item;
            }
        }

        void setLargestItem(const T &item)
        {
            if (item > m_largestItem)
            {
                m_largestItem = item;
            }
        }

    public:
        static T getSmallestItem()
        {
            return m_smallestItem;
        }

        static T getLargestItem()
        {
            return m_largestItem;
        }

        /// @brief The class is to be always instantiated through default constructor.
        /// @brief
        Collection() : m_size(0) {}

        /// @brief
        /// @return current number of items
        unsigned int size() const
        {
            return m_size;
        }
        /// @brief capacity of the collection
        /// @return template C
        unsigned int capacity() const
        {
            return C;
        }

        /// @brief receive  unmod T
        /// if the size is the same as capacity
        /// return false
        /// updates the smallest/largest to parameter
        /// by calling the respective private member functions.

        /// @param temp T item
        /// @return bool
        bool operator+=(const T &item)
        {
            if (m_size < C)
            {
                setSmallestItem(item);
                setLargestItem(item);
                // adds the received object as a new item
                // rvalue
                m_items[m_size] = item;
                ++m_size;
            }
            return m_size == C ? false : true;
        }

        void print(std::ostream &os) const
        {
            os << "[";
            for (unsigned int i = 0; i < m_size; ++i)
            {
                os << m_items[i];
                // print"," between each value
                if (i < m_size - 1)
                {
                    os << ",";
                }
            }
            os << "]" << std::endl;
        }
    };
    template <typename T, unsigned int C>
    T Collection<T, C>::m_smallestItem = static_cast<T>(9999);

    template <typename T, unsigned int C>
    T Collection<T, C>::m_largestItem = static_cast<T>(-9999);

    // Template specialization for T = Book and C = 10
    template <>
    Book Collection<Book, 10>::m_smallestItem("", 1, 10000);
    template <>
    Book Collection<Book, 10>::m_largestItem("", 10000, 1);

}
#endif