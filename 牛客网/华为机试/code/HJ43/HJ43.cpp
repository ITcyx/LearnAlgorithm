#include <iostream>

using namespace std;

class queue_ds
{
private:
	size_t xy[100];
	size_t i, j;

public:
	queue_ds() :i(0), j(0)
	{}

	void add(size_t const& x, size_t const& y)
	{
		if (j < 100)
		{
			xy[j] = (x << 8) + y;
			++j;
		}
		else
		{
			xy[0] = (x << 8) + y;
			j = 0;
		}
	}

	void pop(size_t& x, size_t& y)
	{
		x = xy[i] >> 8;
		y = xy[i] & 0xFF;
		if (i < 99)
			++i;
		else
			i = 0;
	}

	int size()
	{
		if (i <= j)
			return j - i;
		else
			return 100 - i + j;
	}

	void reset()
	{
		i = j = 0;
	}
};

class stack_ds
{
private:
	size_t xy[100];
	size_t j;

public:
	stack_ds() : j(0)
	{}

	void add(size_t const& x, size_t const& y)
	{

		xy[j] = (x << 8) + y;
		++j;
	}

	void pop(size_t& x, size_t& y)
	{
		--j;
		x = xy[j] >> 8;
		y = xy[j] & 0xFF;
	}

	int size()
	{
		return j;
	}

	void reset()
	{
		j = 0;
	}
};

int main()
{
	queue_ds qe;
	stack_ds st;
	int maze[10][10];
	size_t x, y, i, j;
	while (cin >> x >> y)
	{
		for (i = 0; i < x; ++i)
			for (j = 0; j < y; ++j)
				cin >> maze[i][j];
		maze[0][0] = 2;
		qe.reset();
		st.reset();
		qe.add(0, 0);
		while (qe.size())
		{
			qe.pop(i, j);
			if (j < y - 1 && maze[i][j + 1] == 0)
			{
				maze[i][j + 1] = maze[i][j] + 1;
				qe.add(i, j + 1);
			}
			if (i < x - 1 && maze[i + 1][j] == 0)
			{
				maze[i + 1][j] = maze[i][j] + 1;
				qe.add(i + 1, j);
			}
			if (i > 0 && maze[i - 1][j] == 0)
			{
				maze[i - 1][j] = maze[i][j] + 1;
				qe.add(i - 1, j);
			}
			if (j > 0 && maze[i][j - 1] == 0)
			{
				maze[i][j - 1] = maze[i][j] + 1;
				qe.add(i, j - 1);
			}
		}
		i = x - 1;
		j = y - 1;
		st.add(i, j);
		while (i != 0 || j != 0)
		{
			if (j < y - 1 && maze[i][j + 1] == maze[i][j] - 1)
			{
				++j;
				st.add(i, j);
			}
			else if (i < x - 1 && maze[i + 1][j] == maze[i][j] - 1)
			{
				++i;
				st.add(i, j);
			}
			else if (i > 0 && maze[i - 1][j] == maze[i][j] - 1)
			{
				--i;
				st.add(i, j);
			}
			else
			{
				--j;
				st.add(i, j);
			}
		}
		while (st.size())
		{
			st.pop(i, j);
			cout << "(" << i << "," << j << ")" << endl;
		}
	}
	return 0;
}