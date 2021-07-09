	#include <iostream>
	using namespace std;
	bool checkallnine(string s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != '9')
				return false;
		}
		return true;
	}
	int main()
	{
		int t;
		cin >> t;
		while (t--)
		{
			int no;
			cin >> no;
			string s = to_string(no);
			//find the next smallest palindrom
			//case 1 if all digits are 9
			if (checkallnine(s))
			{
				cout << 1;
				for (int i = 1; i < s.length(); i++)
					cout << 0;
				cout << 1 << endl;
			}
			//if not all 9
			else
			{
				int left, right;
				left = right = s.size() / 2;
				if (s.size() % 2 == 0)
					left--;
				while (left >= 0 and s[left] == s[right])
				{
					left--;
					right++;
				}
				if (left < 0 || s[left] < s[right])
				{
					left = s.size() / 2;
					right = s.size() / 2;
					if (s.size() % 2 == 0)
						left--;
					int carry = 1;

					while (left >= 0)
					{
						int num = (s[left] - '0') + carry;
						carry = num / 10;
						s[left] = (num % 10) + '0';
						s[right] = s[left];
						left--;
						right++;
					}
				}
				else
				{
					while (left >= 0)
					{
						s[left] = s[right];
						left++;
						right--;
					}
				}
				cout << stoi(s) << endl;
			}
		}
	}
