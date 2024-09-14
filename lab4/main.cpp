#include <iostream>
#include <vector>
#include <string>
#include <sstream>
 
using namespace std;
 
void imedy(vector<pair<long long, long long>>& s, long long& beforeT){
	long long n = (long long) s.size();
	vector<long long> z(n);
	for (long long i=1, l=0, r=0; i<n; ++i){

		if (i <= r){
		    long long minh = min(r-i+1, z[i-l]);
		    z[i] = minh;
		}
	while (i+z[i] < n && s[z[i]].first == s[i+z[i]].first){
			z[i]++;
	}
		if (i+z[i] - 1 > r){
			l = i;  
			r = i+z[i] - 1;
		}
	}
		long long linenow;
	    long long lineprev = 0;
	    long long find = 1;
	for(long long i = beforeT; i < n; ++i){
	    linenow = s[i].second;
        if(linenow > lineprev && lineprev != 0){
            find = 1;
        }
	    if (z[i] == beforeT - 1){
	        cout << s[i].second << ", " << find << "\n";
	    }
	    lineprev = linenow;
	    ++find;
	}
	
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long long line = 0; string s;
    getline(cin, s);
    vector <pair<long long, long long>> prov;
    stringstream ss(s);
    long long num;
    while (ss >> num){
        prov.push_back(make_pair(num, line));
    } 
    ++line;
    
    prov.push_back(make_pair(-1, -1));

    long long beforeT = prov.size();
    while(getline(cin, s)){
    stringstream ss(s);
    
        while (ss >> num){
        prov.push_back(make_pair(num, line));
        } 
        ++line;
    }
    imedy(prov, beforeT);

    return 0;
}