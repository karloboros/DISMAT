#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    cout << "Unesite redom, odvojene razmakom, parametre n, a i b: ";
    cin>>n>>a>>b;

    int cesta[n][n];
    int prvi = 0, zadnji = 0;
    int mini = 1e9;

    for (int i = 0; i<n; i++) {
    	for (int j = 0; j<n; j++) {
    		if(i==j) cesta[i][j] = 1e9;
    		else {
    			cesta[i][j] = (a*(min(i,j)+1) + b*(max(i,j)+1))*
								(a*(min(i,j)+1) + b*(max(i,j)+1)) +1;
    			if(cesta[i][j] < mini) {
    				mini = cesta[i][j];
    				prvi = i;
    				zadnji = j;
				}
			}
		}
	}

// 	Pohlepni
    vector<int> vrhovi;
    int rez=mini;

    for(int i=0;i<n;i++)
        if(i!=prvi && i!=zadnji)	vrhovi.push_back(i);

    while (vrhovi.size() != 0) {
        mini = 1e9;
        int vrhic;
        int smjer = 0;

        for(int i=0;i<vrhovi.size();i++) {
            if (mini != min(mini,cesta[zadnji][vrhovi[i]])) {
                    mini = min(mini,cesta[zadnji][vrhovi[i]]);
                    vrhic = i;
                    smjer = 1;
                }
            if (mini != min(mini,cesta[prvi][vrhovi[i]])) {
                    mini = min(mini,cesta[prvi][vrhovi[i]]);
                    vrhic = i;
                    smjer = -1;
                }
        }

        if(smjer==1) 
            zadnji=vrhovi[vrhic];
        if(smjer==-1)
            prvi=vrhovi[vrhic];
        rez+=mini;
        vrhovi.erase(vrhovi.begin()+vrhic);
    }
    rez+=cesta[prvi][zadnji];
    cout<<"Pohlepni algoritam nalazi ciklus duljine "<<rez<<endl;
    
//	Iscrpni
    for(int i=1;i<n;i++)
        vrhovi.push_back(i);
	mini = 1e9;
   	
    do
    {
        int rez2=0;
        zadnji = 0;
        for(int i = 0;i<vrhovi.size();i++)
        {
            rez2+=cesta[zadnji][vrhovi[i]];
        	zadnji = vrhovi[i];
        }
        //cout<<rez2 << " "<< mini <<endl;
        rez2+=cesta[0][zadnji];
        mini=min(mini,rez2);
    }while(next_permutation(vrhovi.begin(),vrhovi.end()));
    cout<<"Iscrpni algoritam nalazi ciklus duljine "<<mini<<endl;
    
// 	Optimalni    
    if(rez==mini)
    {
        cout<<"Pohlepni algoritam na ovom grafu daje optimalno rješenje!"<<endl;
    }
    else
    {
        cout<<"Pohlepni algoritam na ovom grafu ne daje optimalno rješenje!"<<endl;
    }
}
