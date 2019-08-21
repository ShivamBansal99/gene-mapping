#include<bits/stdc++.h>
#include<iostream>
using namespace std;
float cost(vector<int> str[],vector<vector<float> > MC,float CC,int K,int V){
	  int max=0;
	  for(int i=0;i<K;i++){
		    for(int j=0;j<str[i].size();j++){
		      	if(str[i][j]!=V && max<j) max=j;
		    }
	  }
	  float cost1=0;
	  for(int i=0;i<K;i++){
		    for(int j=i+1;j<K;j++){
			      for(int k=0;k<=max;k++){
					cost1+=MC[str[i][k]][str[j][k]];
			      }
		    }
	  	    for(int k=0;k<=max;k++){
			if(str[i][k]==V) cost1+=CC;
		    }
	  }
	  return cost1;
}
void random_init(vector<int> str[],int K,int V){
	int max=0;
	for(int i=0;i<k;i++){
		max+=str[i].size();
	}
	for(int i=0;i<k;i++){
		while(str[i].size()<max){
			str[i].push_back(V);
		}
		random_shuffle(str[i].begin(), str[i].end());
	}
	return;
}
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
	
	char vocab[V];
	//TO-DO : CONVERT STRING TO ARRAY
	
	infile>>K;
	
	string genes[K];
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
	if(s!="#"){
		printf("Corrupt input file...");
		return 0;
	}
	
	
	return 0;
}
