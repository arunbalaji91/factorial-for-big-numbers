void facto(string &fact, string num)
{
	int carry = 0, count = 1;
	int r = 0, c = 0;
	string *t1 = NULL;
	t1 = new string[num.size()];
	string res = "";

	for (int i = num.size() - 1; i >= 0; i--, c++)
	{
		for (int k = 0; k < c; k++)
		{
			t1[c] += 48;
		}
		for (int j = fact.size() - 1; j >= 0; j--)
		{
			int r = ((fact[j] - 48) * (num[i] - 48)) + carry;
			carry = 0;
			if (r > 9)
			{
				if (j == 0)
				{
					t1[c] += (r % 10) + 48;
					t1[c] += (r / 10) + 48;
				}
				else
				{
					t1[c] += (r % 10) + 48;
					carry = r / 10;
				}
			}
			else
			{
				t1[c] += r + 48;
			}
		}
		//cout << "inter: " << t1[c] << endl;
	}
	carry = 0;
	r = 0;
	count = 0;
	int count1 = 0;
	while (count1 != num.size())
	{
		count1 = 0;
		for (int i = 0; i < num.size(); i++)
		{
			if (count < t1[i].size())
			{
				r += (t1[i][count] - 48);
			}
			else
			{
				count1++;
			}
		}
		if (count1 != num.size())
		{
			r += carry;
			carry = 0;
			if (r > 9)
			{
				res += ((r % 10) + 48);
				carry = r / 10;
			}
			else
			{
				res += (r + 48);
			}
			count++;
			r = 0;
		}
		else if (carry > 0)
		{
			res += (carry + 48);
		}
	}
	fact = "";
	for (int i = res.size() - 1; i >= 0; i--)
		fact += res[i];
}

int main()
{
	string f = "1";
	for (int i = 1; i <= 100; i++)
	{
		ostringstream convert;
		convert << i;
		facto(f, convert.str());
	}
	cout << "result: " << f << endl;
	return 0;
}
