#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back 
#define ff first
#define ss second
#define int long long
#define pi 3.14159265358979323846
#define watch(xxx) cerr<<(#xxx)<<" is "<<xxx<<"\n";
using namespace std;

struct project{
    string pname;
    ll days;
    ll score;
    ll bb;
    ll nroles;
    vector<pair<string,ll>> pr;
};


signed main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll c,p;
    cin>>c>>p;
    vector<pair<string,vector<pair<string,ll>>>> vc;
    map<string,vector<pair<pair<string,ll>,bool>>> mp;
    map<string,string> person;
    for(int i=0;i<c;i++){
    	string name;
    	cin>>name;
    	ll nskill;
    	cin>>nskill;
    	vector<pair<string,ll>>temp;
    	for(int j=0;j<nskill;j++){
    		string s; ll level;
    		cin>>s>>level;
    		temp.pb({s,level});
    		mp[s].pb({{name,level},0});
    	}

    	vc.pb({name,temp});
    }

//////// contibutor hogya ////////


    	vector<project> vp;

    	for(int i=0;i<p;i++){
    		string tname;
    		ll tdays;
    		ll tscore;
    		ll tbb;
    		ll t;
    		vector<pair<string,ll>>tpr;
    		cin>>tname>>tdays>>tscore>>tbb>>t;
    		for(int j=0;j<t;j++){
    			string s; ll level;
    			cin>>s>>level;
    			tpr.pb({s,level});
    		}
    		vp.pb({tname,tdays,tscore,tbb,t,tpr});

    	}

// ///////IP hogye//////////

    	vector<pair<string,vector<string>>> op;
    		for(auto it:vp){
    			ll nr=it.nroles;
    			vector<string> top;
    			int flag=0;
    			for(int i=0;i<nr;i++){
    				string rskl= it.pr[i].ff;
    				ll rlvl=it.pr[i].ss;

    				vector<pair<pair<string,ll>,bool>> vt;

    				vt=mp[rskl];
    				
    				for(int j=0;j<vt.size();j++){
    					if(vt[j].ff.ss >= rlvl && vt[j].ss==0 && person[vt[j].ff.ff]!= it.pname){
    						vt[j].ss=1;
    						top.pb(vt[j].ff.ff);
    						person[vt[j].ff.ff]=it.pname;
    						flag=1;
    						break;
    					}
    				}
    			}
    				if(flag==0){
    					continue;
    				}
    				if(top.size()==nr)
    				op.pb({it.pname,top});
    		}

cout<<op.size()<<"\n";
for(auto it:op){
	cout<<it.ff<<"\n";
	for(int i=0;i<it.ss.size();i++){
		cout<<it.ss[i]<<" ";
	}
	cout<<"\n";
}




}