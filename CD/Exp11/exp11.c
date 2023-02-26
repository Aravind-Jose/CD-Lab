#include<iostream>
#include <string>
#define MAX_ROW 50
using namespace std;

class LEXICALANALYZER {
private:
string input;
string output [MAX_ROW][2];
int tokenize(){
string temp;
int row=0;
for(int i=0; i<input.size();i++){
if(isalpha(input[i]) || isdigit(input[i])){
temp.append(1, input[i]);
}
else
{
output[row++][0] = temp;
temp.clear();
if(input[i] == '+' || input[i] == '*') {
temp.append(1, input[i]);
output[row++][0] = temp;
temp.clear();
}
}
}
output[row++][0] = temp;
return row;
}
public:
void recognize(){
int token_n;
token_n = this->tokenize();
//cout<<token_n;
for(int i=0; i<token_n;i++){
string s = output[i][0];
int state = 0;
bool flag = true;
for(int j=0; j<s.size() && flag; j++){
switch(state)
{
case 0 :
if(s[j] == 'i')
state = 1;
else if(s[j] == 'e')
state = 3;
else if(s[j] == 'c')
state = 9;
else
flag = false;
break;
case 1 :
if(s[j] == 'n')
state = 7;
else if(s[j] == 'f')
state = 2;
else
flag = false;
break;
case 2 :
flag = false;
break;
case 3 :
if(s[j] == 'l')
state = 4;
else
flag = false;
break;
case 4 :
if(s[j] == 's')
state = 5;
else
flag = false;
break;
case 5 :
if(s[j] == 'e')
state = 6;
else
flag = false;
break;
case 6 :
flag = false;
break;
case 7 :
if(s[j] == 't')
state = 8;
else
flag = false;
break;
case 8 :
flag = false;
break;
case 9 :
if(s[j] == 'h')
state = 10;
else
flag = false;
break;
case 10 :
if(s[j] == 'a')
state = 11;
else
flag = false;
break;
case 11:
if(s[j] == 'r')
state = 12;
else
flag = false;
break;
case 12 :
flag = false;
break;
}
}
if(flag == true && (state == 8 || state == 2 || state == 6 ||state == 12 )){
output[i][1] = "keyword";
continue;
}
flag = true;
state = 0;
for(int j=0; j<s.size() && flag; j++){
switch(state)
{
case 0 :
if(isalpha(s[j]))
state = 1;
else
flag = false;
break;
case 1 :
if(isalpha(s[j]) || isdigit(s[j]))
state = 1;
else
flag = false;
break;
}
}
if(flag == true && state == 1){
output[i][1] = "identifier";
continue;
}
flag = true;
state = 0;
for(int j=0; j<s.size() && flag; j++){
switch(state)
{
case 0 :
if(s[j] == '+')
state = 1;
else if(s[j] == '*')
state = 2;
else break;
flag =2;
}
}
if(flag == true && (state == 1 || state == 2)){
output[i][1] = "operator";
continue;
}
output[i][1] = "invalid";
continue;
}
cout<<"------------------------"<<endl;
for(int i=0; i<token_n;i++){
cout<<output[i][0]<<" "<<output[i][1]<<endl;
}
cout<<"------------------------"<<endl;
}
LEXICALANALYZER(string inp_string) {
input.clear();
for(int i=0 ; i<MAX_ROW; i++)
for(int j=0; j<2; j++)
output[i][j].clear();
input = inp_string;
}
};
int main(){
string inp_string;
cout<<"Enter the input string \n";
cin>>inp_string; LEXICALANALYZER obj(inp_string); obj.recognize();
return 0;
}


