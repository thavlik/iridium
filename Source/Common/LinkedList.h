#pragma once

namespace Ir {
	template<class T>
	class LinkedList {
	public:
		LinkedList(unsigned maxItems)
			: _maxItems(maxItems)
			, _nextItem(0)
			, _items(new T[maxItems]) {
			Reset();	
		}

		~LinkedList() {
			delete[] _items;
			_items = nullptr;
		}

		T* Reserve() {
			T* item = _items+_nextItem;
			_nextItem = item->Next;
			return item;
		}

		void Free(T* item) {
			item->Next = _nextItem;
			_nextItem = item->Index;
		}

		void Reset() {
			for(unsigned i = 0; i < _maxItems; ++i) {
				_items[i].Index = i;
				_items[i].Next = i+1;
			}
			_items[_maxItems-1].Next = _items[_maxItems-1].Index;
		}

	private:
		unsigned _maxItems, _nextItem;
		T* _items;
	};
}