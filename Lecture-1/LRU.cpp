// LRU.cpp
class LRUCache {
public:
	int size;
	list<int> l;
	// list<int>::iterator
	unordered_map<int, pair<list<int> :: iterator, int> > h;

	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		// Jo bhi value ko read krenge, linked list mei
		// head par jaegi vo value
		if (h.count(key)) { //m.count() == 0, if key is not present
			bringFront(key);
			return h[key].second;
		}
		return -1;
	}

	void bringFront(int key) {
		l.erase(h[key].first);
		l.push_front(key);
		h[key].first = l.begin();
	}

	void put(int key, int value) {
		if (h.find(key) != h.end()) {
			// This means key exists inside the map
			h[key].second = value;
			bringFront(key);
		}
		else {
			// Key dont exists in the map
			if (l.size() == size) {
				// if size full hai cache ka
				// Toh least used ko hatao, and then new key,value add kro
				h.erase(l.back());
				l.pop_back();
			}
			// Agar size cache ka full nhi hai
			// toh LL mei insert krdo
			l.push_front(key);
			h[key] = make_pair(l.begin(), value);
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */