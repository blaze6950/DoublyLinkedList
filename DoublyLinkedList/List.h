#pragma once

template<typename T>
class list
{
	struct listItem
	{
		listItem* next = nullptr;
		listItem* prev = nullptr;
		T value;
	};

	listItem* _head = nullptr;
	listItem* _tail = nullptr;
	size_t _size = 0;

	listItem* find(size_t index)
	{
		auto current = _head;
		for (size_t i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current;
	}
public:

	list() = default;
	~list()
	{
		while (_size != 0)
			remove(0);
	}

	size_t getSize() const
	{
		return _size;
	}
	bool isEmpty() const
	{
		return _size == 0;
	}

	void add(T value)
	{
		auto newItem = new listItem;
		newItem->value = value;

		if (_head == nullptr)
			_head = newItem;
		else
		{
			_tail->next = newItem;
			newItem->prev = _tail;
		}

		_tail = newItem;
		_size++;
	}
	void remove(size_t index)
	{
		auto delItem = find(index);

		if (delItem->prev == nullptr)
			_head = delItem->next;
		else
			delItem->prev->next = delItem->next;
		
		if (delItem->next == nullptr)
			_tail = delItem->prev;
		else
			delItem->next->prev = delItem->prev;

		delete delItem;
		_size--;
	}

	T& operator[](size_t index)
	{
		return find(index)->value;
	}

	T operator[](size_t index)const
	{
		return find(index)->value;
	}
		
};