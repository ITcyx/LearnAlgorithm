#include <stdio.h>

int main()
{
	int abc, def, ghi, a, b, c, d, e, f, g, h, i;
	for (abc = 123; abc <= 321; ++abc)
	{
		a = abc / 100;
		b = (abc / 10) % 10;
		c = abc % 100;
		if (b == 0 || b == a)
			continue;
		else if (c == 0 || c == b || c == a)
			continue;
		def = abc * 2;
		d = def / 100;
		e = (def / 10) % 10;
		f = def % 10;
		if (d == b || d == c)
			continue;
		else if (e == 0 || e == d || e == a || e == b || e == c)
			continue;
		else if (f == 0 || f == d || f == e || f == a || f == b || f == c)
			continue;
		ghi = abc * 3;
		g = ghi / 100;
		h = (ghi / 10) % 10;
		i = ghi % 10;
		if (g == b || g == c || g == e || g == f)
			continue;
		else if (h == 0 || h == g || h == a || h == b || h == c || h == d || h == e || h == f)
			continue;
		else if (i == 0 || i == g || i == h || i == a || i == b || i == c || i == d || i == e || i == f)
			continue;
		printf("%d %d %d\n", abc, def, ghi);
	}
	return 0;
}