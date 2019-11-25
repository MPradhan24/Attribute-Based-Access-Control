//Check ReadMe file for input and output format

#include <iostream>
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pb push_back
#define N 400005

using namespace std;

ll merged[N];

int main(){
	//IOS
	freopen("Data.txt","r",stdin);
	freopen("Output.txt","w",stdout) ;
	freopen("Statistics.txt","a",stderr);
	int SR,SA,SC=0,OR,OA,OC=0;//s=subject, o=object, r=row, c=column
	cin>>SR>>SA;//SA=no. of attributes
	ll val1[SA];
	ll cum1[SA];//cumulative
	//cum1[-1]=0;
	for(ll i=0;i<SA;i++){
		cin>>val1[i];
		SC+=val1[i];
		cum1[i]=SC;
	}
	int s[SR][SC];
	string sub[SR][SA];
	string temp="";
	for(int i=0;i<SR;i++){
		for(int j=0;j<SC;j++)
			cin>>s[i][j];
		//cout<<"****"<<temp<<"****\n";
	}
	/*cout<<sub[1][0]<<endl;
	for(int i=0;i<SR;i++){
		for(int j=0;j<SA;j++){
			cin>>s[i][j];
		}
	}*/
	cin>>OR>>OA;
	ll val2[OA],cum2[OA];
	for(ll i=0;i<OA;i++){
		cin>>val2[i];
		OC+=val2[i];
		cum2[i]=OC;
	}
	ll value[SA+OA];
	temp="";
	int o[OR][OC];
	string ob[OR][OA];
	// objects in rows, attribute in columns(it will store value of that attribute for that object)
	for(int i=0;i<OR;i++){
		for(int j=0;j<OC;j++)
			cin>>o[i][j];
	}
	ll cum[SA+OA];
	for(ll i=0;i<SA;i++){
		value[i]=val1[i];
	}
	for(ll i=0;i<OA;i++){
		value[i+SA]=val2[i];
	}
	ll sum=0;
	for(ll i=0;i<SA+OA;i++){
		sum+=value[i];
		cum[i]=sum;
	}
	int AR,AC;
	cin>>AR>>AC;// ACL Row and Col,rows will be same as no. of subjects and cols as no. of objects
	int a[AR][AC];
	int perm_max=-1e8;// to hold max value in permission table
	//not a binary matrix, to condense values, we use decimal nos. only
	for(int i=0;i<AR;i++){
		for(int j=0;j<AC;j++){
			cin>>a[i][j];
			perm_max=max(perm_max,a[i][j]);
		}
	}
	
	//output could contain max. 9 rows: 0(=000) to 7(=111) some permission combination might repeat
	//some permission combination might not be possible to deduce from given data
	//atleast the no. of unique entries in ACL Matrix will be no. of rules
	int r=SR*OR,c=SC+OC+1;// 1 is for permission
	//not entirely boolean matrix
	int rules[r][c];
	int val=perm_max;
	int ind=0;
	string ruleStr[r][SA+OA+1];
	//considering mutually exclusive attribute-values
	auto clk=clock();
	while(val>0){// we don't want rules for no permission, waste
		vector <int> user;
		vector <int> object;
		for(int i=0;i<AR;i++){
			for(int j=0;j<AC;j++){
				if(a[i][j]==val){
					user.pb(i);
					object.pb(j);
				}
			}
		}
		int size=user.size();
		temp="";
		//cout<<"*****"<<size<<"******\n";
		for(int i=0;i<size;i++){
			temp="";
			for(int j=0;j<SC;j++){
				rules[ind][j]=s[user[i]][j];
				char c=rules[ind][j]+'0';
				temp+=c;
			}
			for(int j=0;j<OC;j++){
				rules[ind][SC+j]=o[object[i]][j];
				char c=rules[ind][SC+j]+'0';
				temp+=c;
			}
			rules[ind][SC+OC]=val;
			char c=val+'0';
			temp+=c;
			for(int j=0;j<OA+SA;j++){
				ll strt=(j==0)?0:cum[j-1];
				ruleStr[ind][j]=temp.substr(strt,value[j]);
			}
			//string f=temp.substr(cum[OA+SA-2]);
			ruleStr[ind][OA+SA]=c;
			ind++;
			//cout<<"\n\n"<<f<<"\n\n";
		}
		val--;
	}
	//cout<<"IND"<<ind<<"\n";
	/*cout<<"\n\n****Rules in Strings*****\n\n";
	for(int i=0;i<ind;i++){
		for(int j=0;j<SA+OA+1;j++){
			cout<<ruleStr[i][j]<<" ";
		}
		cout<<endl;
	}*/

	cout<<"\n\n****Before Merging*****\n\n";
	for(int i=0;i<ind;i++){
		for(int j=0;j<c;j++){
			cout<<rules[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"*****No. of rules: "<<ind<<"******\n";
	//Merging Process
	ll flag=0,diff=0;
	for(ll i=0;i<ind;i++){
		if(merged[i])
			continue;
		for(ll j=i+1;j<ind;j++){
			flag=0,diff=0;
			for(ll k=0;k<SA+OA+1;k++){
				if(ruleStr[i][k]!=ruleStr[j][k]){
					flag++;
					diff=k;
				}
				if(flag>1)
					break;
			}
			if(flag>1)
				continue;
			else if(flag==1){
				if(diff!=OA+SA+1){
					for(ll k=0;k<c;k++)
							rules[i][k]=rules[i][k]|rules[j][k];
				}
				else{
					rules[i][diff]=rules[i][diff]|rules[j][diff];//extended permission case
				}
				merged[j]=1;
			}
		}
	}
	cerr<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
	//Output the rules
	cout<<"\n\n****After Merging*****\n\n";
	int num_rules=0;
	for(int i=0;i<ind;i++){
		if(merged[i])
			continue;
		for(int j=0;j<c;j++){
			cout<<rules[i][j]<<"\t";
			
		}
		cout<<endl;
		num_rules++;
	}
	cout<<"*********No. of rules: "<<num_rules<<"*********"<<endl;
	cerr<<"No. of rules: "<<num_rules<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}