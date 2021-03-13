class MyHashSet
{
private:
	int hash_table[100000];

public:
	/** Initialize your data structure here. */
	MyHashSet()
	{
		for (int i = 0; i < 100000; ++i)
			hash_table[i] = -1;
	}

	void add(int const& key)
	{
		int nj = key % 100043, ni = key % 100019, s;
		for (int i = 0; i < 100000; ++i)
		{
			s = (nj + ni * i) % 100000;
			if (hash_table[s] < 0)
			{
				hash_table[s] = key;
				return;
			}
			else if (hash_table[s] == key)
				return;
		}
	}

	void remove(int const& key)
	{
		int nj = key % 100043, ni = key % 100019, s;
		for (int i = 0; i < 100000; ++i)
		{
			s = (nj + ni * i) % 100000;
			if (hash_table[s] < 0)
				return;
			else if (hash_table[s] == key)
			{
				hash_table[s] = -1;
				return;
			}
		}
	}

	/** Returns true if this set contains the specified element */
	bool contains(int const& key)
	{
		int nj = key % 100043, ni = key % 100019, s;
		for (int i = 0; i < 100000; ++i)
		{
			s = (nj + ni * i) % 100000;
			if (hash_table[s] < 0)
				return false;
			else if (hash_table[s] == key)
				return true;
		}
		return false;
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */