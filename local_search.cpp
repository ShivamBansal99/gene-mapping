#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
float updated_cost(vector<int> str[],vector<vector<float> > MC,float CC,int K,int V, int p,int q, int r){
	  float cost1=0;
  	  for(int i=0;i<K;i++){	
		if(i!=p){
			cost1+=MC[str[i][q]][r];
		}	  
	  }
  	  for(int i=0;i<K;i++){	
		if(i!=p){
			cost1-=MC[str[i][q]][V];
		}	  
	  }
	  return cost1;
}

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
vector<int> random_init(vector<int> vs,int max,int V,int seed){
	vector<int> v;
	for(int i=0;i<max;i++){
		v.push_back(V);	
	}
	srand(unsigned(time(0))*seed);
	int r=0; 
	for(int j=0;j<vs.size();j++){
		r=r+1+((rand())%(max-vs.size()+j-r));
		v[r]=vs[j];							
	}		
	return v;
}
void print_gene(vector<vector<char> > char_str,int K){
	for(int i=0;i<K;i++){
		for(int j=0;j<char_str[i].size();j++){
			printf("%c ",char_str[i][j]);
		}
		printf("\n");
	}
}
void print_num(vector<int> str[],int K){
	for(int i=0;i<K;i++){
		for(int j=0;j<str[i].size();j++){
			printf("%d ",str[i][j]);
		}
		printf("\n");
	}
}
bool greedy(vector<int> str[],vector<vector<float> > MC,float CC,int K,int V){
	int flag=0;
	for(int i=0;i<K;i++){
		int min=0,max=0;
		while(str[i][max]==V && max<str[i].size()) max++;
		max++;
		while(str[i][max]==V && max<str[i].size()) max++;
		while(max<=str[i].size()){
			int n=-1,prev=-1;
			float min_cost=FLT_MAX;
			int min_index=min;	
			for(int j=min;j<max && j<str[i].size();j++){
				if(str[i][j]!=V){						
					n=str[i][j];
					prev=j;
					str[i][j]=V;
					break;
				}
				if(j==max-1 || j==str[i].size()-1){
					cout<<j<<' '<<i<<' '<<min<<' '<<max<<' '<<str[i][j]<<endl;
					//print_gene(str,K);
					printf("ERROR in greedy");
					return false;
				}
			}
			for(int j=min;j<max && j<str[i].size();j++){
				str[i][j]=n;
				float temp = updated_cost(str,MC,CC,K,V,i,j,n);
				if(temp<=min_cost){							//CAN ADD PROBABILITY FOR EQUAL CASE
					min_cost = temp;
					min_index=j;
				}
				str[i][j]=V;
			}
			if(prev!=min_index) flag=1;
			str[i][min_index]=n;
			min=min_index+1;			
			max++;	
			while(str[i][max]==V && max<str[i].size()) max++;
		}
	}
	if(flag==1) return true;
	return false;
}
void remove_hyp(vector<int> str[],int K,int V){
	for(int i=0;i<str[0].size();){
		int flag=0;
		for(int j=0;j<K;j++){
			if(str[j][i]!=V){
				flag=1;
				break;
			}
		}
		if(flag==0){	
			for(int j=0;j<K;j++){
				str[j].erase(str[j].begin()+i);
			}
		}else{
			i++;
		}
	}
}
vector<vector<char> > convert(vector<int> str[],char vocab[],int K,int V){
	vector<vector<char> > v;
	vector<char> v1;
	for(int i=0;i<K;i++){
		v.push_back(v1);
		for(int j=0;j<str[i].size();j++){
			v[i].push_back(str[i][j]!=V?vocab[str[i][j]]:'-');		
		}
	}

	return v;
}
int main(int argc,char* argv[]){
	cout<<unsigned(time(0))<<endl;
	if(argc<3) return 0;
	ifstream infile;
	infile.open(argv[1]);
	ofstream outfile;
        outfile.open (argv[2]);
	if(!infile.is_open()){
		printf("error opening file...\n");
		return 0;
	}
	int V,K;
	float timet, CC;
	infile>>timet;
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
	int max=0;
	vector<int> str[K];
	vector<int> min_str[K];
	for(int i=0;i<K;i++){
		max+=arr[i].size();
	}
	for(int i=0;i<K;i++){
		min_str[i]=random_init(arr[i],max,V,0);
	}
	float c;
	float min;
	vector<int> store;
	float min_cost=FLT_MAX;
	vector<vector<char> > char_str2 = convert(min_str,vocab,K,V);
	print_gene(char_str2,K);
	for(int j=0;j<300;j++){
		for(int i=0;i<K;i++){
		  str[i]=random_init(arr[i],max,V,2000*(i+1)+j+i*j+i+1);
		}
		if(j%100==99){
			for(int i=0;i<K;i++){
			  min=FLT_MAX;
				for(int q=0;q<10;q++){
					str[i]=random_init(arr[i],max,V,(i+1)*(q+1)*200+2000*(j+1));
					c=cost(str,MC,CC,K,V);
					if(min>=c){
					  min=c;
					  store=str[i];
					}
				}
				str[i]=store;
			}
		}	
		for(int i=0;greedy(str,MC,CC,K,V);i++){
			if(i%10==9) remove_hyp(str,K,V);		
		}
		remove_hyp(str,K,V);
		
		float pop=cost(str,MC,CC,K,V);
		if(min_cost>pop){
			for(int i=0;i<K;i++){
				min_str[i]=str[i];
			}
		}		
		min_cost=min_cost>pop?pop:min_cost;
	}
	cout<<min_cost<<endl;
	cout<<unsigned(time(0))<<endl;
	//print_num(min_str,K);
	vector<vector<char> > char_str = convert(min_str,vocab,K,V);
	print_gene(char_str,K);
	for(int i=0;i<K;i++){
		for(int j=0;j<char_str[i].size();j++){
			outfile<<char_str[i][j];
		}
		outfile<<'\n';
	}
	return 0;
}
