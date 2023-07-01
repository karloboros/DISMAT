#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> S;
bool neighbours[20][20];

bool check(int v,int colours[], int colour) {
    for(int i = 0; i < n; i++)
        if (neighbours[v][i] && colour == colours[i]) 	return false; // susjed vrha v nema odredenu boju
    return true; //susjed vrha v ima odredenu boju
}

bool node_colour( int crom_num,int colours[], int v) {
    if (v == n)	return true; 	// svi vrhovi su oznaceni

    for(int c = 1; c <= crom_num; c++) {
        if (check(v, colours, c)) {
            // ako tu boju mozemo dati vrhu, to napravimo dok nam se ne dokaze suprotno
			colours[v] = c;
			
            if (node_colour( crom_num, colours, v + 1) == true) 	return true;
			// ako ne dobijemo rjesenje, vrh nije boje c
            colours[v] = 0;
        }
    }
    // ako nijedna boja nije dana vrhu, nemamo ih dovoljno za sve
    return false;
}

int main() {
    string q;
    
    cout<<"unesite ime datoteke: ";
    cin>>q;
    
	ifstream myfile;
    myfile.open(q);
    string s;
    getline(myfile,s);
    n = stoi(s);
	getline(myfile,s);
	int m = stoi(s);
    getline(myfile,s);
    
    int num=0, i=0, br=0;
    while(br<m && i<s.length()) {
    	if(s[i] != ' ') {
    		num = num*10+int(s[i]-'0');
    		i++;
		}
		else {
			S.push_back(num);
			num=0;
			br++;
			i++;
		}
	}
    S.push_back(num);
    
	for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(count(S.begin(), S.end(), j-i)) {
                neighbours[i][j]=1;
                neighbours[j][i]=1;
            }
        }
    }
    
    myfile.close();
    for(int i=1; i<=n; i++) {
        int colours[n];
        for(int i = 0; i < n; i++) { colours[i] = 0; }
        if (node_colour(i, colours, 0) == false) 	continue;
        cout<<"Kromatski broj zadanog grafa je "<< i <<endl;
        return 0;
    }
}
