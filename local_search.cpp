#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(int argc,char* argv[]){
	if(argc<3) return 0;
	ifstream infile;
	infile.open(argv[1]);
	if(!infile.is_open()){
		printf("error opening file...\n");
		return 0;
	}
	int V,K;
	float time, CC;
	infile>>time;
	infile>>V;
	string s;
	//infile>>s;
	infile>>s;
	
	char vocab[V];
	//TO-DO : CONVERT STRING TO ARRAY
	int j=0;
	for(int i=0;i<s.length();i++){
	  vocab[j]=s[i];
	  j++;
	  i+=3;
	}
	map<char,int> m;
	for(int i=0;i<V;i++){
	  m.insert(pair<char,int>(vocab[i],i));
	}
	infile>>K;
	
	string genes[K];
	//infile>>s;
	for(int i=0;i<K;i++){
		infile>>genes[i];
	}
	vector<int> arr[K];
	for(int i=0;i<K;i++){
	  for(int j=0;j<genes[i].length();j++){
	    arr[i].push_back(m.get(genes[i][j]));
	  }
	}
	infile>>CC;
	vector<vector<float>> MC;
	float f;
	for(int i=0;i<=V;i++){
		for(int j=0;j<=V;j++){
		  infile>>f;
		  MC[i].push_back(f);
		}
	}
	//infile>>s;
	infile>>s;
	if(s!="#"){
		printf("Corrupt input file...");
		return 0;
	}
	
	
	return 0;
}
