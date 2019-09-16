//Los errores/dudas que tenía han sido solucionados, funciona y tiene semáforo verde :)

#include <iostream>
#include <map>
using namespace std;

int main(){
	cout.setf(ios::fixed);
	cout.precision(4);

	map<int,int> s;
	//numero identificador y contador
	string act;
	double tot = 0;
	int tam = 0;
	//minimo en s.begin(); maximo en s.end() -1
	while(cin >> act){
		auto it = s.begin();
		auto fin = s.end();
		if(act == "delete"){
			if(tam == 0) cout << "no elements" << endl;
			//si el map está vacío no hace nada
			else{
				//modificamos tamaño, total y el contador del menor, si ese menor queda vacío (it-second = 0) lo eliminamos
				--tam;
				it = s.begin();
				tot-= (it->first);
				--(it->second);
				if((it->second) == 0) s.erase(it);
				//si el tamaño es 0 no hace nada
				if(tam == 0) cout << "no elements" << endl;
				else{
					//si al eliminar el menor no queda vacío colocamos el puntero en s.end()-1 (maximo) e imprimimos
					--fin;
					cout << "minimum: " << (s.begin())->first << ", maximum: " << fin->first << ", average: " << tot/tam << endl;
				}
			}
		}
		else if(act == "number"){
			//aumentamos el tamaño en uno, añadimos n al total y lo buscamos
			++tam;
			int n;
			cin >> n;
			tot+=n;
			it = s.find(n);
			//si n no está lo añadimos, sino aumentamos el contador
			if(it == s.end()) s.insert({n,1});
			else ++(it->second);
			//colocamos el puntero en s.end()-1 (maximo) e imprimimos
			--fin;
			cout << "minimum: " << (s.begin())->first << ", maximum: " << fin->first << ", average: " << tot/tam << endl;
		}
	}
}
