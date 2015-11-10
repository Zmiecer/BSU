#ifndef STR10_H
#define STR10_H

#include "Str10.h"
 
int main()
{
	setlocale (LC_ALL,".1251");
	Str* arr[20];
    Str s1, s2, s3, sum;
   /* cout << "Vvedite stroku 1: " << endl;
    getline(cin, s1);
    cout << "Vvedite stroku 2: " << endl;
    getline(cin, s2);
    cout << "Summa strok: " << endl;
    sum = s1 += s2;
    cout<< sum <<endl;
    if(s1>s2)
        cout<<"Pervaja bolshe vtoroj"<<endl;
    if(s1<s2)
        cout<<"Vtoraja bolshe pervoj"<<endl;
    if(s1==s2)
        cout<<"Stroki ravni"<<endl;*/

	Str10 s10, s20;
	int p;
	getline(cin, s10);
	getline(cin, s20);
	cout << s10.Chislo()<<endl;
	cout << s20.Chislo()<<endl;
	cout << (s10 + s20) << endl;
	s10.Sravnim(s20);
	/*cin >> p;
	if (p==0) ;
	else if (p==1) ;
		 else cout << "Error!" << endl;*/
	
	/*getline(cin, s10);
	getline(cin, s20);
	getline(cin, s30);
	arr[0]=&s10;
	arr[1]=&s20;
	arr[2]=&s30;
	for (int i=0; i<3; i++)
		for (int j=0; j<2; j++)
		{
			int a1 = arr[j]->Chislo();
			int a2 = arr[j+1]->Chislo();
			cout << a1 << a2 << endl;
			if (arr[j]->Chislo() > arr[j+1]->Chislo()) swap (arr[j],arr[j+1]);
		}
	cout << arr[0]->str << " " << arr[1]->str << " " << arr[2]->str << endl;
	*/
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);
	arr[0]=&s1;
	arr[1]=&s2;
	arr[2]=&s3;
	for (int i=0; i<3; i++)
		for (int j=0; j<2; j++)
		{
			/*int a1 = arr[j]->Chislo();
			int a2 = arr[j+1]->Chislo();
			cout << a1 << a2 << endl;*/
			if (arr[j] > arr[j+1]) swap (arr[j],arr[j+1]);
		}
	strcat(arr[0]->str, arr[1]->str);
	strcat(arr[0]->str, arr[2]->str);
	cout << arr[0]->str << endl;
    return 0;
}

#endif