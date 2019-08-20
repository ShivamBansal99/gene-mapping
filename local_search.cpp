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
	infile>>s;
	infile>>s;
	
	char vocab[V];
	//TO-DO : CONVERT STRING TO ARRAY
	
	infile>>K;
	
	string genes[K];
	infile>>s;
	for(int i=0;i<K;i++){
		infile>>genes[i];
	}
	infile>>CC;
	float MC[V+1][V+1];
	for(int i=0;i<=V;i++){
		for(int j=0;j<=V;j++){
			infile>>MC[i][j];
		}
	}
	infile>>s;
	infile>>s;
	if(s!="#"){
		printf("Corrupt input file...");
		return 0;
	}
	
	
	return 0;
}