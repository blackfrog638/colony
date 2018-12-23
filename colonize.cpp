#include<iostream>
#include<vector>
#include<fstream>
#include<cassert>
#include<windows.h>
#include<cstring>
#include<string>

// 要开学了，救命 
using namespace std;
char code[10000];
char path[10000];
char g[10000];
long long length;
int space[100000];
string name[100000];
string paths[100000];
vector<string> trees; 
int enter; 
char cpy[100000];
char buf[1000][1000];
int keling; 
int main() {
	void readTxt(string file);
	int detect(int item , int iter);
	char key[] = "tree ";
	strcat(code, key);
	cout<<"请输入复制根目录"; 
	cin.getline(path,10000);
	cout<<"请输入复制的文件";
	cin.getline(cpy,10000);
	strcat(code, path);
	char key2[] = " > c:\\1.txt";
	strcat(code, key2);
	system(code);
	cout<<"successed."<<endl;
	readTxt("c:\\1.txt");
	
//	for(int i =1;i<length;i++){
//		for(int j = 0;j<trees[i].size();j++){
//			cout<<(int)trees[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	//├:-87 -64 1
	//─:-87 -92 0
	//└:-87 -72 2
	//│:-87 -90 3
	for(int i = 1 ; i<length;i++){
		keling = -1;
		for(int j = 0;j< trees[i].size();j++){
			if(keling != 0){
				keling =detect(i,j);
				j++;
			}
			if(keling == 0){
				if(j != trees[i].size()-1)name[i] = name[i] + trees[i][j+1]; 
			}
			else {
				j--;
				if(trees[i][j] == ' '){
					space[i]++;
				}
			}
			
		} 
	}
//	for(int i = 3;i<length;i++){
//		cout<<"name = "<<name[i]<<" \t\t\t\t\t , space = "<<space[i]<<endl;	
//	}
	//讨厌做这部分
	//让我想起了做OI的感觉 
	for(int i = 3;i<length;i++){
		int j;
		j = i;
		int weight;
		weight = space[i];
		
			paths[i] = name[j] + '\\' + paths[i];
		
		while(weight!=0){
			if(weight > space[j]){
				weight = space[j];
				paths[i] = name[j] + '\\' + paths[i];
			}
			j--;
		}
		paths[i] = path + paths[i];
		paths[i] = paths[i];
		paths[i] = paths[i].substr(0,paths[i].size()- 1);
		//turn into char[]
		strcpy(buf[i],paths[i].c_str());
	}
	for(int i = 3;i<length; i++){
		cout<<paths[i]<<endl;
	}
	
	for(int i = 3;i<length; i++){
		code[0] = '\0';
		strcat(code,"copy \"");
		strcat(code,cpy);
		strcat(code,"\" \"");
		strcat(code,buf[i]);
		strcat(code,"\"");
		cout<<code;
		system(code);
	}
	
	system("pause");
	return 0;
}

void readTxt(string file)
{
	ifstream infile;
	infile.open(file.data());
	assert(infile.is_open()); 
	string s;
	while (getline(infile, s))
	{
		length++;
		trees.push_back(s);
	}
	infile.close();
}

//f*CK THIS PART!!!!!!!!!!

int detect(int item , int iter){
	//mkey, I'll remember this f*cking part 
	//├:-87 -64
	//─:-87 -92
	//└:-87 -72
	//│:-87 -90
	if(trees[item][iter] == -87){
		if(trees[item][iter+1] == -64){
			return 1;
		}
		if(trees[item][iter+1] == -92){
			return 0;
		}
		if(trees[item][iter+1] == -72){
			return 2;
		}
		if(trees[item][iter+1] == -90){
			return 3;
		}
	} 
	return 4;
}


