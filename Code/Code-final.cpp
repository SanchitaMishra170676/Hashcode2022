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

bool cns(const  project a, const  project b)
{
		if(a.bb==b.bb)
			a.score>b.score;
		return a.bb<b.bb;
    // return (a.nroles < b.nroles);
} 

bool cmp(const  pair<pair<string,ll>,ll> a, const  pair<pair<string,ll>,ll> b)
{
		return a.ss<b.ss;
    // return (a.nroles < b.nroles);
} 

signed main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll c,p;
    cin>>c>>p;
    vector<pair<string,vector<pair<string,ll>>>> vc;
    map<string,vector<pair<pair<string,ll>,ll>>> mp;
    map<string,string> person;
    map<string,ll> pbsy;
    string mrk;
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
    		mrk=s;
    	}

    	pbsy[name]=0;
    	vc.pb({name,temp});
    }

//////// Contributor Input Done ////////


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

/////////Project Input Done//////////

    	sort(vp.begin(),vp.end(),cns);


    	vector<pair<string,vector<string>>> op;
    		for(auto it:vp){
    			ll nr=it.nroles;
    			vector<string> top;
    			int flag=0;
    			for(int i=0;i<nr;i++){
    				string rskl= it.pr[i].ff;
    				ll rlvl=it.pr[i].ss;

    				vector<pair<pair<string,ll>,ll>> vt;

    				vt=mp[rskl];
    				flag=0;
    				ll j;
    				for( j=0;j<vt.size();j++){
    					if(vt[j].ff.ss >= rlvl  && person[vt[j].ff.ff]!= it.pname && it.bb-pbsy[vt[j].ff.ff]>=it.days){
    						
    						pbsy[vt[j].ff.ff]+=it.days-1;
    						vt[j].ss =pbsy[vt[j].ff.ff];
    						top.pb(vt[j].ff.ff);
    						person[vt[j].ff.ff]=it.pname;
    						flag=1;
    						break;
    					}
    				}
    					bool acc=0;
    				if(flag==0){

    					
    					for( j=0;j<vt.size();j++){
    					if(vt[j].ff.ss == (rlvl-1)  && person[vt[j].ff.ff]!= it.pname && it.bb-pbsy[vt[j].ff.ff]>=it.days){
    						
    						for(auto mentor: top){
    							for(int k=0;k<vt.size();k++){
    								if(mentor==vt[k].ff.ff && vt[k].ff.ss>=rlvl){
    										acc=1;
    										break;
    								}
    										
    							}
    						}
    					}
    				}
    					if(acc){
    						pbsy[vt[j].ff.ff]+=it.days-1;
    						vt[j].ss =pbsy[vt[j].ff.ff];
    						top.pb(vt[j].ff.ff);
    						person[vt[j].ff.ff]=it.pname;
    						vt[j].ff.ss++;
    						flag=1;
    						break;
    				}

    				}


    				if(flag==0){
    					if(rlvl==1){

    							for(int k=0;k<vt.size();k++){
    								if( vt[k].ff.ss>=rlvl){
    										acc=1;
    										break;
    								}
    										
    							}
    							if(acc==1){
    								vt= mp[mrk];
    									for( j=0;j<vt.size();j++){
		    									if( person[vt[j].ff.ff]!= it.pname && it.bb-pbsy[vt[j].ff.ff]>=it.days){
		    						
			    						// pbsy[vt[j].ff.ff]+=it.days-1;
			    						// vt[j].ss =pbsy[vt[j].ff.ff];
			    						top.pb(vt[j].ff.ff);
			    						person[vt[j].ff.ff]=it.pname;
			    						flag=1;
			    						mp[rskl].pb({{vt[j].ff.ff,1},it.days-1});
			    						break;
		    					}
		    				}

    							}
    						

    					


    					}
    				}

    				sort(vt.begin(),vt.end(),cmp);
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