class CQueue
{
private:
	int p[20000], i, j;
public:
	CQueue() :i(0), j(0)
	{}

	void appendTail(int const& value)
	{
		p[i + j] = value;
		++j;
	}

	int deleteHead()
	{
		if (j == 0)
			return -1;
		++i;
		--j;
		return p[i - 1];
	}
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */