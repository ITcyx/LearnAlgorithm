class MyHashMap
{
private:
	int hash_table[100000][2];

public:
	/** Initialize your data structure here. */
	MyHashMap()
	{
		for (int i = 0; i < 100000; ++i)
			hash_table[i][0] = -1;
	}

	/** value will always be non-negative. */
	void put(int const& key, int const& value)
	{
		int nj = key % 100043, ni = key % 100019, s;
		for (int i = 0; i < 100000; ++i)
		{
			s = (nj + ni * i) % 100000;
			if (hash_table[s][0] < 0)
			{
				hash_table[s][0] = key;
				hash_table[s][1] = value;
				return;
			}
			else if (hash_table[s][0] == key)
			{
				hash_table[s][1] = value;
				return;
			}
		}
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int const& key)
	{
		int nj = key % 100043, ni = key % 100019, s;
		for (int i = 0; i < 100000; ++i)
		{
			s = (nj + ni * i) % 100000;
			if (hash_table[s][0] < 0)
				return -1;
			else if (hash_table[s][0] == key)
				return hash_table[s][1];
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int const& key)
	{
		int nj = key % 100043, ni = key % 100019, s;
		for (int i = 0; i < 100000; ++i)
		{
			s = (nj + ni * i) % 100000;
			if (hash_table[s][0] < 0)
				return;
			else if (hash_table[s][0] == key)
			{
				hash_table[s][0] = -1;
				return;
			}
		}
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */