#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

class STRING
{
	char *str;
	public:
	STRING(){
		str=0;
	}


	STRING(const char *s){
		if(s==0){
			str=new char[1];
			str[0]='\0';
		}
		str=new char[strlen(s)+1];
		for(int i=0;i<strlen(s)+1;i++)
			str[i]=s[i];
		
	}


	STRING(const STRING &s){
		str=new char[strlen(s.str)+1];
		for(int i=0;i<strlen(s.str)+1;i++)
			str[i]=s.str[i];	
	
	}


	void get_data(){
		cout<<str<<endl;
	}


	STRING &operator =(STRING &s2){
		if(this != &s2)
		{
			delete[] str;
			str=new char[strlen(s2.str)+1];
			strcpy(str,s2.str);
		}
		return *this;
	}



	STRING operator +(STRING s2){
		STRING temp;
		delete[] temp.str; 
		temp.str=new char[strlen(str)+strlen(s2.str)+1];
		strcpy(temp.str,str);
		strcat(temp.str,s2.str);
		return temp;
	}



	char& operator [](int pos){
		return str[pos];
	}


	~STRING(){
		delete[] str;
	}


	bool operator>(const STRING &s) const
	{
		return strcmp(str, s.str) > 0;
	}

	bool operator<(const STRING &s) const
	{
		return strcmp(str, s.str) < 0;
	}

	bool operator>=(const STRING &s) const
	{
		return strcmp(str, s.str) >= 0;
	}

	bool operator<=(const STRING &s) const
	{
		return strcmp(str, s.str) <= 0;
	}

	bool operator!=(const STRING &s) const
	{
		return strcmp(str, s.str) != 0;
	}

	bool operator==(const STRING &s) const
	{
		return strcmp(str, s.str) == 0;
	}







	friend istream &operator >>(istream &in,STRING &s);
	friend ostream &operator <<(ostream &out,STRING &S);
	friend void strcpy(STRING &s1,const STRING &s2);
	friend void strncpy(STRING &s1,const STRING &s3,int n);
	friend int strncmp(const STRING &s2, const STRING &s1, int n);
	friend void strcat(STRING &s2, const STRING &s1);
	friend int strcmp(const STRING &s2,const STRING &s1);
	friend void strncat(STRING &s2, const STRING &s1, int n);
	friend void strrev(STRING &s1);
	friend void strupr(STRING &s1);
	friend void strlwr(STRING &s1);
	friend int strchr(const STRING &s1, char ch);
	friend int strrchr(const STRING &s1, char ch);
	friend int strstr(const STRING &s1, const char *sub);
	friend int strlen(const STRING &s1);
};




ostream &operator <<(ostream &out,STRING &s)
{
	out<<s.str;
	return out;
}



istream &operator >>(istream &in,STRING &s)
{
	char temp[100];
	in>>temp;
	delete[] s.str;
	s.str=new char[strlen(temp)+1];
	for(int i=0;i<=strlen(temp);i++)
		s.str[i]=temp[i];
	return in;
}



void strcpy(STRING &s1,const STRING &s2)
{
	delete[] s1.str;
	s1.str=new char[strlen(s2.str)+1];
	for(int i=0;i<=strlen(s2.str);i++)
		s1.str[i]=s2.str[i];
}



void strncpy(STRING &s1, const STRING &s3,int n)
{
	int count;
	delete[] s1.str;
	if(strlen(s3.str)<n)
		count=strlen(s3.str);
	else
		count=n;
	s1.str=new char[count+1];
	int i;
	for(i=0;i<count;i++)
		s1.str[i]=s3.str[i];
	s1.str[i]='\0';
}



int strcmp(const STRING &s2, const STRING &s1)
{
	int i=0;
	while(s2.str[i]!='\0' && s1.str[i]!='\0')
	{
		if(s2.str[i]!=s1.str[i])
			return s2.str[i]-s1.str[i];
		i++;
	}
	return s2.str[i]-s1.str[i];
}




int strncmp(const STRING &s2, const STRING &s1, int n)
{
	for(int i=0;i<n;i++){
		if(s2.str[i]!=s1.str[i])
			return s2.str[i]-s1.str[i];
		if(s2.str[i]=='\0' || s1.str[i]=='\0')
			return 0;
	}
	return 0;
}





void strcat(STRING &s2, const STRING &s1)
{
	int newLen=strlen(s2.str)+strlen(s1.str);
	char *temp=new char[newLen+1];
	for(int i=0;i<strlen(s2.str);i++){
		temp[i]=s2.str[i];
	}
	for(int i=0;i<strlen(s1.str);i++){
		temp[strlen(s2.str)+i]=s1.str[i];
	}
	temp[newLen]='\0';
	delete[] s2.str;
	s2.str=temp;
}





void strncat(STRING &s2, const STRING &s1, int n)
{
	int count;
	if(strlen(s1.str)< n)
		count=strlen(s1.str);
	else
		count=n;
	int newLen=strlen(s2.str)+count;
	char *temp=new char[newLen+1];
	for(int i=0;i<strlen(s2.str);i++){
		temp[i]=s2.str[i];
	}
	for(int i=0;i<count;i++){
		temp[strlen(s2.str)+i]=s1.str[i];
	}
	temp[newLen]='\0';
	delete[] s2.str;
	s2.str=temp;
}




void strrev(STRING &s1)
{
	int start=0;
	int end=strlen(s1.str)-1;
	while(start<end){
		char temp=s1.str[start];
		s1.str[start]=s1.str[end];
		s1.str[end]=temp;
		start++;
		end--;
	}
}




void strupr(STRING &s1)
{
	for(int i=0;i<strlen(s1.str);i++){
		if(s1.str[i]>=97 && s1.str[i]<=122){
			s1.str[i]=s1.str[i]-32;
		}
	}
}





void strlwr(STRING &s1)
{
	for(int i=0;i<strlen(s1.str);i++){
		if(s1.str[i]>=65 && s1.str[i]<=90){
			s1.str[i]=s1.str[i]+32;
		}
	}
}




int strchr(const STRING &s1, char ch)
{
	for(int i=0;i<strlen(s1.str);i++){
		if(s1.str[i]==ch)
			return i;
	}
	return -1;
}




int strrchr(const STRING &s1, char ch)
{
	for(int i=strlen(s1.str)-1;i>=0;i--){
		if (s1.str[i]==ch)
			return i;
	}
	return -1;
}


int strstr(const STRING &s1, const char *sub)
{
	if(sub==NULL)
		return -1;
	int subLen=strlen(sub);
	if(subLen==0)
		return 0;
	for(int i=0;i<=strlen(s1.str)-subLen;i++){
		int j=0;
		while(j<subLen && s1.str[i+j]==sub[j]){
			j++;
		}
		if(j==subLen)
			return i;
	}
	return -1;
}



int strlen(const STRING &s1)
{
	return strlen(s1.str);
}




int main()
{
	
	STRING s1;

	
	STRING s2("vector");
	STRING s3("india");

	
	STRING s4(s2);
	s4.get_data();

	
	s1=s3;
	s1.get_data();

	
	STRING s5=s2+s3;
	s5.get_data();

	
	cout<<"s2[3]= "<<s2[3]<<endl;

	
	cout<<"Enter a string"<<endl;
	cout<<s5<<endl;;
	cin>>s5;
	cin.ignore (1000,'\n');

	STRING a("Apple");
	STRING b("Banana");

	

	cout << "\nComparison:" << endl;
	cout << "a > b  : " << (a > b) << endl;
	cout << "a < b  : " << (a < b) << endl;
	cout << "a >= b : " << (a >= b) << endl;
	cout << "a <= b : " << (a <= b) << endl;
	cout << "a == b : " << (a == b) << endl;
	cout << "a != b : " << (a != b) << endl;	


	string s,d;
	cout<<"Enter a string"<<endl;
	getline(cin,s);
	cout<<"Enter a second string"<<endl;
	getline(cin,d);
	STRING x(s.c_str());
	STRING y(d.c_str());
	STRING result;


	strcpy(result, x);
	cout << "\nstrcpy(result, x) : " << result << endl;

	
	strncpy(result, y, 3);
	cout << "strncpy(result, y, 3) : " << result << endl;

	
	cout<<"compare both string: "<<endl;
	int i=strcmp(x, y);
	if(i==0)
		cout<<"both are same "<<endl;
	else
		cout<<"Both are different "<<endl;

	
	int n;
	cout<<"compare both string upto Nth position : "<<endl;
	cout<<"Enter pos: ";
	cin>>n;
	i=strncmp(x,y,n);
	cout<<i<<endl;	


	
	strcat(x, y);
	cout << "strcat(x, y) : " << x << endl;


	strncat(s5, y, 3);
	cout << "strncat(s5, y, 3) : " << s5 << endl;

	cin.ignore(1000, '\n');

	string k;
	cout<<"Enter a string: ";
	getline(cin,k);
	cout<<k<<endl;;
	STRING rev(k.c_str());
	strrev(rev);
	cout << "strrev : " << rev << endl;



	STRING upper(k.c_str());
	strupr(upper);
	cout << "strupr : " << upper << endl;


	STRING lower(k.c_str());
	strlwr(lower);
	cout << "strlwr : " << lower << endl;


	
	STRING search(k.c_str());
	cout << "strchr(rev, 'o') index : "
		<< strchr(search, 'o') << endl;


	
	cout << "strrchr(search, 'o') index : "
		<< strrchr(rev, 'o') << endl;


	
	cout << "strstr(search, \"World\") index : "
		<< strstr(s5, "chi") << endl;


	
	cout << "strlen(rev) : "
		<< strlen(rev) << endl;

	return 0;
}
























