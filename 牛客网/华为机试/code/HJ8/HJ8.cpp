#include <iostream>

using namespace std;

struct kv
{
	int key;
	int value;
};

bool hash_add(kv h[1000], int const& k, int const& v)
{
	int i, j;
	for (i = 0; i < 1000; ++i)
	{
		j = (k % 1361 + (k % 503)*i) % 1000;
		if (h[j].key < 0)
		{
			h[j].key = k;
			h[j].value = v;
			return true;
		}
		else if (h[j].key == k)
		{
			h[j].value += v;
			return false;
		}
	}
	return true;
}

int hash_find(kv h[1000], int const& k)
{
	int i, j;
	for (i = 0; i < 1000; ++i)
	{
		j = (k % 1361 + (k % 503)*i) % 1000;
		if (h[j].key == k)
			return h[j].value;
	}
	return 0;
}

void qs(int kb[1000], int const& i, int const& j)
{
	if (j - i <= 1)
		return;
	int p = i, c;
	for (int s = i + 1; s < j; ++s)
		if (kb[s] < kb[i])
		{
			++p;
			c = move(kb[s]);
			kb[s] = move(kb[p]);
			kb[p] = move(c);
		}
	c = move(kb[i]);
	kb[i] = move(kb[p]);
	kb[p] = move(c);
	qs(kb, i, p);
	qs(kb, p + 1, j);
}

int main()
{
	int num, i, k, v, kbc = 0;
	kv h[1000];
	int kb[1000];
	cin >> num;
	for (i = 0; i < 1000; ++i)
		h[i].key = -1;
	for (i = 0; i < num; ++i)
	{
		cin >> k >> v;
		if (hash_add(h, k, v))
		{
			kb[kbc] = k;
			++kbc;
		}
	}
	qs(kb, 0, kbc);
	for (i = 0; i < kbc; ++i)
		cout << kb[i] << " " << hash_find(h, kb[i]) << endl;
	return 0;
}