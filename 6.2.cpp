#include <iostream>
#include <stack>
#include <string>

bool pol ()
{
    std::cout << "Input string \n";
    std::deque <char> d;
    std::string s;
    std::getline(std::cin , s); 
    for (int i = 0 ; i < s.length(); i ++)
    {
        d.push_back(tolower(s[i]));
    }
    for (int i = 0; i < str.length() / 2; i++) 
    {
		if (pol.size() == 1) return true;
		if (pol.front() == ' ') pol.pop_front();
		if(pol.back() == ' ') pol.pop_back();
		if (pol.back() == pol.front()) 
		{
			if (pol.size() == 1) return true;
			pol.pop_front();
			pol.pop_back();
		}
		else return false;
	}
	return true;
}


double rotate(std::pair <int,int> A, std::pair <int,int> B, std::pair <int,int> C)
{
	return (B.first - A.first) * (C.second - B.second) - (B.second - A.second) * (C.first - B.first);
}

void sort(std::pair <int,int>* A, std::deque<int>& P) {
	int temp, j;
	for (int i = 2; i < P.size(); i++) {
		j = i;
		while (j > 1 && rotate(A[P[0]], A[P[j - 1]], A[P[j]]) < 0) {
			temp = P[j];
			P[j] = P[j - 1];
			P[j - 1] = temp;
			j--;
		}
	}
}


void z2() {
	int n, min;
	double x, y;
	std::deque<int> P, S;
	std::cout << "How much t : ";
	std::cin >> n;
	pair <int,int> p[n];
	for (int i = 0; i < n; i++) {
		std::cout << "Inp coord " << i + 1 << " point: ";
		std::cin >> x >> y;
		p[i].first = x;
		p[i].second = y;
	}
	min = 0;
	for (int i = 1; i < n; i++) if (p[min].first > p[i].first) min = i;
	P.push_back(min);
	for (int i = 0; i < n; i++) if (i != min) P.push_back(i);
	sort(p, P);
	S.push_back(P[0]);
	S.push_back(P[1]);
	for (int i = 2; i < P.size(); i++) {
		while (rotate(p[S[S.size() - 2]], p[S[S.size() - 1]], p[P[i]]) < 0)
			S.pop_back();
		S.push_back(P[i]);
	}
	for (auto x : S) {
		std::cout << p[x].first << "; " << p[x].second << std::endl;
	}
}

int main()
{
    int choise;
    while (true)
    {
        std::cout << "Input choise\n1.palindrom\n2.Greckhem \n";
        std::cin >> choise;
        
        switch (choise)
        {
            case 1:
                std::cout << pol();
                break;
            case 2:
		z2;
		break;
            case 3: 
		break;
        }
    }
    
    
}