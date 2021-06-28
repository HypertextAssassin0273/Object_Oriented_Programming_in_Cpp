#include<iostream>
#include<iomanip>
using namespace std;

template<unsigned long long n>
long double atoif(const char (&num)[n],bool space_flag=false){//i.e. converts string to float
	if (n==-1||!n)
		return 0;
    short sign=1,i=0; int integer_part=0; bool fraction_flag=false;
	if (num[i]=='-'){// Take care of +/- sign
		++i;
		sign=-1;
	}
	else if(num[i]=='+')
		++i;
	while(i<n-1){
		if(space_flag&&num[i]==' ')
			break;
		if (num[i]>='0'&&num[i]<='9')
			integer_part=integer_part*10+(num[i]-'0');
		else if(num[i]=='.'){
			fraction_flag=true;
			i++;
			break;
		}
		++i;
	}
	long double fraction_part=0;
	if (fraction_flag){
		long double exponent=0.1;
        while (i<n-1){
			if (num[i]<'0'||num[i]>'9')
				break;
			fraction_part+=exponent*(num[i]-'0');
			exponent*=0.1;
			++i;
		}
	}
	return sign*integer_part+fraction_part;
}

int main(){
	cout<<setprecision(12)<<atoif("51224.765432");
	return 0;
}
