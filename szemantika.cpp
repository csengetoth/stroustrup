#include<iostream>  
#include<stdio.h>  
  
using namespace std;  
  
class csipet 
{  
private: int* szam;
public: 
    csipet(int a) {
	szam = new int(a);
	cout<<"Meghívódik a konstruktor"<<endl;
    }  

    ~csipet() {
	delete szam;
	cout<<"Meghívódik a destruktor"<<endl;
    }
    
    csipet(const csipet &a) : szam (new int) {
	*szam=*(a.szam);
        cout<<"Másoló konstruktor meghívódik"<<endl;  
    }  
      
    csipet& operator = (const csipet &t) 
    { 
	int *szam2 = new int();
	*szam2 = *(t.szam);
	delete szam;
	szam = szam2;
        cout<<"Másoló értékadás meghívódik"<<endl; 
        return *this; 
    }  

    csipet (csipet && t) : szam (nullptr) {
    	*this = std::move(t);
	cout<<"Mozgató konstruktor meghívódik"<<endl;
    }

    csipet& operator = (csipet && t){
	swap(szam,t.szam);
	cout<<"Mozgató értékadás meghívódik"<<endl;

	return *this;
    }
    
};  
  
int main()  
{  
    csipet a1(1);
    csipet a2(2);
    csipet a3(3);
 
    csipet a4(a2);
    a3=a2;

    a4=std::move(a3);
    csipet a5=std::move(a2);
      
    return 0;  
}  
