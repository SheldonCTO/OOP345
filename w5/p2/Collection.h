#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
namespace sdds
{
	template <typename T>
	class Collection
	{
		std::string m_name;
		T *m_items{};
		size_t m_size{};
		void (*m_observer)(const Collection<T> &, const T &){};

	public:
		Collection(const std::string &name)
		{
			m_name = name;
		}

		Collection(const Collection &obj) = delete;
		Collection &operator=(const Collection &obj) = delete;

		~Collection()
		{
			delete[] m_items;
		}

		const std::string &name() const
		{
			return m_name;
		}
		size_t size() const
		{
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T> &, const T &))
		{
			m_observer = observer;
		}

		Collection<T> &operator+=(const T &item)
		{
			bool needCopy = true;
			for (size_t i{0}; i < m_size && needCopy; i++)
			{
				if (item.title() == m_items[i].title())
				{
					needCopy = false;
				}
			}
			if (needCopy)
			{
				T *temp = new T[++m_size];
				for (size_t i{0}; i < m_size - 1; i++)
				{
					temp[i] = m_items[i];
				}
				delete[] m_items;
				temp[m_size - 1] = item;
				m_items = temp;

				if (m_observer)
					m_observer(*this, item);
			}
			return *this;
		}

		T &operator[](size_t idx) const
		{
			if (idx >= m_size)
			{
				std::string err = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.\n";
				throw std::out_of_range(err);
			}
			return m_items[idx];
		}

		T *operator[](const std::string &title) const
		{

			// if not match return nullptr
			// default nullptr
			T *temp{};
			for (size_t i{0}; i < m_size; i++)
			{
				if (m_items[i].title() == title)
				{
					temp = &m_items[i];
				}
			}
			return temp;
		}
	};
	// helper function
	// declare template
	template <typename T>
	std::ostream &operator<<(std::ostream &os, const Collection<T> &right)
	{
		for (size_t i{0}; i < right.size(); i++)
		{
			os << right[i];
		}
		return os;
	}
}

#endif