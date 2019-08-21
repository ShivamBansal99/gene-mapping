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
	for(int i=0;i<K;i++){
		max+=str[i].size();
	}
	for(int i=0;i<K;i++){
		while(str[i].size()<max){
			str[i].push_back(V);
		}
		random_shuffle(str[i].begin(), str[i].end());
	}
	return;
}
void print_gene(vector<int> str[],int K){
	for(int i=0;i<K;i++){
		for(int j=0;j<str[i].size();j++){
			printf("%d ",str[i][j]);
		}
		printf("\n");
	}
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
	char vocab[V];
	for(int i=0;i<V;i++){
		infile>>s;		  
		vocab[i]=s[0];
	}
	map<char,int> m;
	for(int i=0;i<V;i++){
	  m.insert(pair<char,int>(vocab[i],i));
	}
	infile>>K;
	
	string genes[K];
	for(int i=0;i<K;i++){
		infile>>genes[i];
	}
	vector<int> arr[K];
	for(int i=0;i<K;i++){
	  for(int j=0;j<genes[i].length();j++){
	    arr[i].push_back(m[(genes[i][j])]);
	  }
	}
	infile>>CC;
	vector<vector<float> > MC;
	vector<float> v;
	float f;
	for(int i=0;i<=V;i++){
		MC.push_back(v);
		for(int j=0;j<=V;j++){
		  infile>>f;
		  MC[i].push_back(f);
		}
	}
	infile>>s;
	if(s!="#"){
		printf("Corrupt input file...");
		return 0;
	}
	random_init(arr,K,V);
	//print_gene(arr,K);
	//printf("%f",cost(arr,MC,CC,K,V));
	return 0;
}
