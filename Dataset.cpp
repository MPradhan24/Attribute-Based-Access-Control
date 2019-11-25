#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	freopen("Data.txt","w",stdout);
	ll r1=150;//rand()%5+3;
	ll a1=10;//rand()%5+3;
	ll c1=0;
	// int me=0;
	int arr[10];// to store no. of values for each attribute
	cout<<r1<<endl;
	cout<<a1<<endl;
	for(ll i=0;i<a1;i++){
		ll x=rand()%5+1;
		c1+=x;
		arr[i]=x;
		cout<<x<<" ";
	}
	cout<<endl<<endl;
	/*
	for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			cout<<(rand()%2)<<" ";
		}
		cout<<endl;
	}*/
	for(int i=0;i<r1;i++){
		int c2=0;
		for(int j=0;j<5;j++){		// M.E. Attribute Values
			int one=0;//1 flag
			for(int k=0;k<arr[j];k++){
				c2++;
				int temp=(rand()%2);
				if(one==0 && temp==1){
					cout<<1<<" ";
					one=1;
				}
				else if(one==1)
					cout<<0<<" ";
				else if(one==0 && temp==0){
					cout<<0<<" ";
				}

			}
		}
		for(int j=c2;j<c1;j++){		//Non M.E. Attribute Values
			cout<<(rand()%2)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	ll r2=60;//rand()%5+3;
	ll a2=8;//rand()%5+3;
	ll c2=0;
	int arr2[8];
	cout<<r2<<endl;
	cout<<a2<<endl;
	for(ll i=0;i<a2;i++){
		ll x=rand()%5+1;
		c2+=x;
		arr2[i]=x;
		cout<<x<<" ";
	}
	cout<<endl<<endl;
	/*for(int i=0;i<r2;i++){
		for(int j=0;j<c2;j++){
			cout<<(rand()%2)<<" ";
		}
		cout<<endl;
	}*/
	for(int i=0;i<r2;i++){
		int c3=0;
		for(int j=0;j<4;j++){		// M.E. Attribute Values
			int one=0;//1 flag
			for(int k=0;k<arr2[j];k++){
				c3++;
				int temp=(rand()%2);
				if(one==0 && temp==1){
					cout<<1<<" ";
					one=1;
				}
				else if(one==1)
					cout<<0<<" ";
				else if(one==0 && temp==0){
					cout<<0<<" ";
				}

			}
		}
		for(int j=c3;j<c2;j++){		//Non M.E. Attribute Values
			cout<<(rand()%2)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<r1<<endl;
	cout<<r2<<endl;
	cout<<endl;
	for(int i=0;i<r1;i++){
		for(int j=0;j<r2;j++){
			cout<<(rand()%8)<<" ";
		}
		cout<<endl;
	}
	fclose(stdout);
	return 0;
}